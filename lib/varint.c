#include "varint.h"

#include "error.h"
#include "message.h"
#include "utility.h"
#include "log.h"

#include <stdint.h>
#include <stdbool.h>

error_t read_uvarint8_32(Message * msg, uint32_t * num) {
	if (num == NULL) {
		LOG_ERR_RET(INVALID_ARGS, "num is NULL");
		return INVALID_ARGS;
	}

	// The maximum width of the varint in bytes.
	static const uint_fast8_t max_bytes_k = CEIL_DIVIDE(32, 7);

	// The number of meaningful bits possible in the last byte of a varint.
	static const uint_fast8_t last_meaningful_bits_k = (32 / 7) % 7;

	uint32_t result = 0x00;
	uint_fast8_t bytes_read = 0;
	uint8_t current_byte;
	while (true) {
		error_t read_ret = Message_read8(msg, &current_byte);
		if (read_ret != NO_ERROR) {
			if (read_ret == NOT_ENOUGH_DATA) {
				LOG_ERR_RET(NOT_ENOUGH_DATA, "Not enough data in msg");
				return NOT_ENOUGH_DATA;
			} else {
				LOG_ERR_RET(GENERIC_FAILURE, "Could not read msg");
				return GENERIC_FAILURE;
			}
		}

		// If we are currently processing the last byte and it has too many
		// bits.
		if (bytes_read == max_bytes_k - 1 &&
				(current_byte & (0xFF << last_meaningful_bits_k)) != 0) {
			LOG_ERR_RET(OVERFLOW, "Too many bits for a 32 bit varint");
			return OVERFLOW;
		}

		// Strip the first bit and shift the bits into place in the result.
		result |= (((uint32_t)current_byte) & 0x7F) << (bytes_read * 7);
		++bytes_read;
		LOG_DEBUG("result[%u] after bytes_read[%u]", result, bytes_read);

		if ((current_byte & 0x80) == 0) {
			break;
		} else if (bytes_read == max_bytes_k) {
			LOG_ERR_RET(OVERFLOW, "Too many bytes for a 32 bit varint");
			return OVERFLOW;
		}
	}

	*num = result;

	LOG_INFO_RET(NO_ERROR, "result[%u]", result);
	return NO_ERROR;
}
