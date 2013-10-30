#include "message.h"

#include "error.h"
#include "log.h"
#include "memory.h"

#include <stdint.h>
#include <stddef.h>

error_t Message_expand(Message * msg, uint32_t delta) {
	if (((uint32_t)-1) - delta < msg->consumed) {
		reallocate(msg->data, (msg->consumed * 3) / 2);
	}
}

error_t Message_read8(Message * msg, uint8_t * result) {
	if (msg == NULL) {
		LOG_ERR_RET(INVALID_ARGS, "msg is NULL");
		return INVALID_ARGS;
	}

	if (msg->position >= msg->size) {
		LOG_ERR_RET(NOT_ENOUGH_DATA,
			"msg->position[%u] is out of bounds of msg->size[%u]",
			msg->position, msg->size);
		return NOT_ENOUGH_DATA;
	}

	*result = msg->data[msg->position];
	++msg->position;
	LOG_INFO_RET(NO_ERROR, "result[%u]", *result);
	return NO_ERROR;
}

error_t Message_write8(Message * msg, uint8_t data) {
	if (msg == NULL) {
		LOG_ERR_RET(INVALID_ARGS, "msg is NULL");
		return INVALID_ARGS;
	}

	if (msg->position + sizeof(data) >= msg->allocated) {

	}
}

// error_t Message_read32(Message * msg, uint32_t * result) {
// 	if (msg == NULL) {
// 		LOG_ERR_RET(INVALID_ARGS, "msg is NULL");
// 		return INVALID_ARGS;
// 	}

// 	if (msg->position + sizeof(*result) >= msg->size) {
// 		LOG_ERR_RET(NOT_ENOUGH_DATA,
// 			"msg->position[%lu] + %zu is out of bounds of msg->size[%lu]",
// 			(long unsigned)msg->position, sizeof(*result),
// 			(long unsigned)msg->size);
// 		return NOT_ENOUGH_DATA;
// 	}

// 	void * start = (void *)(msg->data + msg->position);
// 	*result = *((uint32_t *)start);
// 	msg->position += sizeof(*result);
// 	LOG_INFO_RET(NO_ERROR, "result[%u]", *result);
// 	return NO_ERROR;
// }
