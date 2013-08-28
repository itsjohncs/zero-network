#include "message.h"

#include "error.h"

#include "stdint.h"

error_t Message_read8(Message * msg, uint offset, uint8_t * result) {
	if (msg == NULL) {
		LOG_ERR_RET(INVALID_ARGS, "msg is NULL");
		return INVALID_ARGS;
	}

	if (offset >= msg->size) {
		LOG_ERR_RET(OUT_OF_BOUNDS,
			"offset[%u] is out of bounds of msg->size[%u]",
			offset, msg->size);
		return OUT_OF_BOUNDS;
	}

	*result = msg->data[offset];
	LOG_INFO_RET(NO_ERROR, "result[%u]", *result);
	return NO_ERROR;
}

error_t Message_read32(Message * msg, uint offset, uint32_t * result) {
	if (msg == NULL) {
		LOG_ERR_RET(INVALID_ARGS, "msg is NULL");
		return INVALID_ARGS;
	}

	if (offset + sizeof(uint32_t) >= msg->size) {
		LOG_ERR_RET(OUT_OF_BOUNDS,
			"offset[%u] + %u is out of bounds of msg->size[%u]",
			offset, sizeof(uint32_t), msg->size);
		return OUT_OF_BOUNDS;
	}

	void * start = (void *)(msg->data + offset);
	*result = *((uint32_t *)start)
	LOG_INFO_RET(NO_ERROR, "result[%u]", *result);
	return NO_ERROR;
}
