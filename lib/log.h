#ifndef IG_LOG_H
#define IG_LOG_H

#include <stdio.h>

#define LOG_DEBUG(msg, ...) printf("DEBUG in %s: " msg "\n", __PRETTY_FUNCTION__, ##__VA_ARGS__)

#define LOG_ERR_RET(return_code, msg, ...) printf("ERROR in %s: %u " msg "\n", __PRETTY_FUNCTION__, return_code, ##__VA_ARGS__)
#define LOG_INFO_RET(return_code, msg, ...) printf("INFO in %s: %u " msg "\n", __PRETTY_FUNCTION__, return_code, ##__VA_ARGS__)

#endif // Inclusion guard
