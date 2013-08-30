#ifndef IG_ERROR_H
#define IG_ERROR_H

typedef enum error_t {
	NO_ERROR = 0,
	GENERIC_FAILURE,
	INVALID_ARGS,
	NOT_ENOUGH_DATA,
	OUT_OF_BOUNDS,
	OVERFLOW,
} error_t;

char const * error_name(error_t error_num);

#endif // Inclusion guard
