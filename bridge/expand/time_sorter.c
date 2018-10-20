#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "sorter.h"

typedef struct TimeSorter_t {
	BASE_CLASS;
	struct timespec *time_list;
	int num;
} *TimeSorter;

static void time_swap(BaseClass baseinfo, int place1, int place2) {
	TimeSorter instance = (TimeSorter)baseinfo;
	struct timespec stash_val = instance->time_list[place1];
	printf("\t\tswap %ld.%09ld and %ld.%09ld, at %d and %d\n", instance->time_list[place1].tv_sec, instance->time_list[place1].tv_nsec, instance->time_list[place2].tv_sec, instance->time_list[place2].tv_nsec, place1, place2);
	instance->time_list[place1] = instance->time_list[place2];
	instance->time_list[place2] = stash_val;
}

static void time_show(BaseClass this) {
	TimeSorter instance = (TimeSorter)this;
	int i;
	for(i=0; i<instance->num; i++) {
		printf("%ld.%09ld ", instance->time_list[i].tv_sec, instance->time_list[i].tv_nsec);
	}
	printf("\n");
}

static bool time_operator_large(BaseClass this, int src, int dist) {
	TimeSorter instance = (TimeSorter)this;
	if( instance->time_list[src].tv_sec < instance->time_list[dist].tv_sec ) return true;

	if( instance->time_list[src].tv_sec > instance->time_list[dist].tv_sec ) return false;

	return (instance->time_list[src].tv_nsec < instance->time_list[dist].tv_nsec );
}

static int time_get_size(BaseClass this) {
	TimeSorter instance = (TimeSorter)this;
	return instance->num;
}

BaseClass time_sorter_new(struct timespec *time_list, int num) {
	TimeSorter instance = malloc(sizeof(*instance) + sizeof(struct timespec)*num);
	if(!instance) return NULL;
	instance->time_list = (struct timespec *)(instance + 1);

	instance->sorter = quick_sorter_new();
	instance->get_size = time_get_size;
	instance->operator_large = time_operator_large;
	instance->swap = time_swap;
	instance->show = time_show;
	memcpy(instance->time_list, time_list, sizeof(struct timespec)*num);
	instance->num = num;
	return (BaseClass)instance;
}

void time_sorter_free(BaseClass this) {
	TimeSorter instance = (TimeSorter)this;
	quick_sorter_free(instance->sorter);
	free(this);
}
