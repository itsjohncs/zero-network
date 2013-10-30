#include "varint-test.h"

#include "varint.h"
#include "error.h"

static error_t try_read_uvarint8_32(uint8_t * data, uint32_t data_size,
		uint32_t & result) {
	Message msg = {
		.size = data_size,
		.consumed = 0,
		.data = data
	};
	return read_uvarint8_32(&msg, result);
}

void test_read_uvarint8_32() {
	#define TRY(data, answer) do { \
		uint32_t result; \
		uint8_t test_data[] = data \
		ASSERT_NO_ERROR(try_read_uvarint8_32(test_data, \
			sizeof(test_data) / sizeof(*test_data), &result)); \
		ASSERT_EQUAL(answer, result); \
	} while(false);

	#define TRY_ERROR(data, error_code) do { \
		uint32_t result; \
		uint8_t test_data[] = data \
		ASSERT_ERROR(error_code,try_read_uvarint8_32(test_data, \
			sizeof(test_data) / sizeof(*test_data), &result)); \
	} while(false);

	TRY({0x02}, 2);
	TRY({0x82, 0x01}, 130);
	TRY_ERROR({0x82, 0x81, 0x8F}, NOT_ENOUGH_DATA);
	TRY({0x82, 0x81, 0x8F, 0x01}, 2343042);
	TRY_ERROR({0x82, 0x81, 0x8F, 0x81, 0x81}, OVERFLOW);
	TRY_ERROR({0x82, 0x81, 0x8F, 0x81, 0x31}, OVERFLOW);
	TRY({0x82, 0x81, 0x8F, 0x81, 0x01}, 270778498);
}
