#include "message.h"
#include "varint.h"

#include <stdio.h>
#include <stdint.h>

uint32_t try_read_uvarint8_32(uint8_t * data, size_t data_size) {
	Message msg = {
		.size = data_size,
		.consumed = 0,
		.data = data
	};

	uint32_t result;
	read_uvarint8_32(&msg, &result);

	return result;
}

int main() {
	// uint8_t test_data[] = {0x02}; // 2
	// uint8_t test_data[] = {0x82, 0x01}; // 130
	// uint8_t test_data[] = {0x82, 0x81, 0x8F}; // NOT_ENOUGH_DATA
	// uint8_t test_data[] = {0x82, 0x81, 0x8F, 0x01}; // 2343042
	// uint8_t test_data[] = {0x82, 0x81, 0x8F, 0x81, 0x81}; // OVERFLOW
	// uint8_t test_data[] = {0x82, 0x81, 0x8F, 0x81, 0x31}; // OVERFLOW
	// uint8_t test_data[] = {0x82, 0x81, 0x8F, 0x81, 0x01}; // 270778498
	// try_read_uvarint8_32(test_data, sizeof(test_data) / sizeof(*test_data));

	return 0;
}
