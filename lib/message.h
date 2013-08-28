#pragma once

#include "errors.h"

typedef struct Message {
	uint size;
	uint consumed;
	uint8_t * data;
} Message;

error_t Message_read8(Message const * msg, uint offset, uint8_t * result);
error_t Message_read32(Message const * msg, uint offset, uint32_t * result);
