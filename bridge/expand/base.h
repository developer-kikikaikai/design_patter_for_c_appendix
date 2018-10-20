#ifndef _BASE_H_
#define _BASE_H_
#include <time.h>
#include <stdbool.h>
struct BaseSorter_t;
typedef struct BaseSorter_t *BaseSorter;
struct BaseClass_t;
typedef struct BaseClass_t BaseClass_t, *BaseClass;

struct BaseSorter_t {
	void (*sort)(BaseClass baseinfo);
};

#define BASE_SORTER \
	void (*sort)(BaseClass baseinfo);

struct BaseClass_t{
	BaseSorter sorter;
	int (*get_size)(BaseClass this);
	bool (*operator_large)(BaseClass this, int src, int dist);
	void (*swap)(BaseClass this, int place1, int place2);
	void (*show)(BaseClass this);
};

#define BASE_CLASS\
	BaseSorter sorter;\
	int (*get_size)(BaseClass this);\
	bool (*operator_large)(BaseClass this, int src, int dist);\
	void (*swap)(BaseClass this, int place1, int place2);\
	void (*show)(BaseClass this);

BaseClass int_sorter_new(int *num_list, int num);
void int_sorter_free(BaseClass this);

BaseClass time_sorter_new(struct timespec *time_list, int num);
void time_sorter_free(BaseClass this);

#endif
