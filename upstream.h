#ifndef UPSTREAM_H
#define UPSTREAM_H

#include <sys/types.h>

struct upstream {
	unsigned int errors;
	time_t time;
	unsigned char dead;
};

void upstream_fail (struct upstream *up, time_t now);
void upstream_ok (struct upstream *up, time_t now);
void revive_all_upstreams (void *ups, size_t members, size_t msize);

struct upstream* get_random_upstream   (void *ups, size_t members, size_t msize, 
										time_t now, time_t error_timeout, 
										time_t revive_timeout, size_t max_errors);

struct upstream* get_upstream_by_hash  (void *ups, size_t members, size_t msize, 
										time_t now,  time_t error_timeout, 
										time_t revive_timeout, size_t max_errors,
										char *key, size_t keylen);


#endif /* UPSTREAM_H */
/* 
 * vi:ts=4 
 */
