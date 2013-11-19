#ifndef IG_MEMORY_H
#define IG_MEMORY_H

#include <stdlib.h>

typedef void * (*realloc_t)(void *, size_t);
realloc_t reallocate = realloc;

typedef void * (*malloc_t)(size_t);
malloc_t allocate = malloc;

typedef void (*free_t)(void *);
free_t deallocate = free;

#endif // Inclusion guard.
