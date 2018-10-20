#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "sorter.h"

typedef struct IntSorter_t {
	BASE_CLASS;
	int *num_list;
	int num;
} *IntSorter;

static void int_swap(BaseClass baseinfo, int place1, int place2) {
	IntSorter instance = (IntSorter)baseinfo;
	int stash_val = instance->num_list[place1];
	printf("\t\tswap %d and %d, at %d and %d\n", instance->num_list[place1], instance->num_list[place2], place1, place2);
	instance->num_list[place1] = instance->num_list[place2];
	instance->num_list[place2] = stash_val;
}

static void int_show(BaseClass this) {
	IntSorter instance = (IntSorter)this;
	int i;
	for(i=0; i<instance->num; i++) {
		printf("%d ", instance->num_list[i]);
	}
	printf("\n");
}

static bool int_operator_large(BaseClass this, int src, int dist) {
	IntSorter instance = (IntSorter)this;
	return instance->num_list[src]<instance->num_list[dist];
}

static int int_get_size(BaseClass this) {
	IntSorter instance = (IntSorter)this;
	return instance->num;
}

BaseClass int_sorter_new(int *num_list, int num) {
	IntSorter instance = malloc(sizeof(*instance) + sizeof(int)*num);
	if(!instance) return NULL;
	instance->num_list = (int *)(instance + 1);

	instance->sorter = bubble_sorter_new();
	instance->get_size = int_get_size;
	instance->operator_large = int_operator_large;
	instance->swap = int_swap;
	instance->show = int_show;
	memcpy(instance->num_list, num_list, sizeof(int)*num);
	instance->num = num;
	return (BaseClass)instance;
}

void int_sorter_free(BaseClass this) {
	IntSorter instance = (IntSorter)this;
	bubble_sorter_free(instance->sorter);
	free(this);
}
