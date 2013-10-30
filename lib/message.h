#ifndef IG_MESSAGE_H
#define IG_MESSAGE_H

#include "error.h"

#include <stdint.h>

typedef struct Message {
	uint32_t allocated;
	uint32_t size;
	uint32_t position;
	uint8_t * data;
} Message;

error_t Message_expand(Message * msg, unsigned delta);
error_t Message_read8(Message * msg, uint8_t * result);
error_t Message_write8(Message * msg, uint8_t data);
// error_t Message_read24(Message * msg, uint32_t * result);

#endif // Inclusion guard
