#include "varint.h"

#include <stdint.h>
#include <stdbool.h>

error_t read_uvarint8_32(Message const * msg, uint32_t * num)
{
	uint8_t current_byte;
	uint32_t result = 0;
	uint bits_read = 0;
	do {
		error_t read_ret = Message_read8(msg, msg->consumed, &current_byte);
		if (read_ret != NO_ERROR) {
			LOG_ERR_RET(INTERNAL_CALL_FAILED, "Could not read msg.");
			return INTERNAL_CALL_FAILED;
		}

		uint8_t current_byte_stripped = current_byte & 0x7F;
		if (result + current_byte_stripped)

		result += current_byte & 0x7F;
	} while ((current_byte & 0x80) != 0);
}
