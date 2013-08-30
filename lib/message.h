#ifndef IG_MESSAGE_H
#define IG_MESSAGE_H

#include "error.h"

#include <stdint.h>

typedef struct Message {
	uint32_t size;
	uint32_t consumed;
	uint8_t * data;
} Message;

error_t Message_read8(Message * msg, uint8_t * result);
error_t Message_read32(Message * msg, uint32_t * result);

#endif // Inclusion guard
