#ifndef IG_VARINT_H
#define IG_VARINT_H

#include "error.h"

#include <stdint.h>

typedef struct Message Message; // Forward declaration.

error_t read_uvarint8_32(Message * msg, uint32_t * num);

#endif
