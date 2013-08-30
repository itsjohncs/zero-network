#include "message.h"

#include "error.h"
#include "log.h"

#include <stdint.h>
#include <stddef.h>

error_t Message_read8(Message * msg, uint8_t * result) {
	if (msg == NULL) {
		LOG_ERR_RET(INVALID_ARGS, "msg is NULL");
		return INVALID_ARGS;
	}

	if (msg->consumed >= msg->size) {
		LOG_ERR_RET(NOT_ENOUGH_DATA,
			"msg->consumed[%u] is out of bounds of msg->size[%u]",
			msg->consumed, msg->size);
		return NOT_ENOUGH_DATA;
	}

	*result = msg->data[msg->consumed];
	++msg->consumed;
	LOG_INFO_RET(NO_ERROR, "result[%u]", *result);
	return NO_ERROR;
}

error_t Message_read32(Message * msg, uint32_t * result) {
	if (msg == NULL) {
		LOG_ERR_RET(INVALID_ARGS, "msg is NULL");
		return INVALID_ARGS;
	}

	if (msg->consumed + sizeof(*result) >= msg->size) {
		LOG_ERR_RET(NOT_ENOUGH_DATA,
			"msg->consumed[%lu] + %zu is out of bounds of msg->size[%lu]",
			(long unsigned)msg->consumed, sizeof(*result),
			(long unsigned)msg->size);
		return NOT_ENOUGH_DATA;
	}

	void * start = (void *)(msg->data + msg->consumed);
	*result = *((uint32_t *)start);
	msg->consumed += sizeof(*result);
	LOG_INFO_RET(NO_ERROR, "result[%u]", *result);
	return NO_ERROR;
}
