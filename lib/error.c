#include "error.h"

static char const * const error_descriptions_k[] = {
	"NO_ERROR",
	"GENERIC_FAILURE",
	"INVALID_ARGS",
	"NOT_ENOUGH_DATA",
	"OUT_OF_BOUNDS",
	"OVERFLOW"
};

char const * error_name(error_t error_num) {
	return error_descriptions_k[(unsigned)error_num];
}
