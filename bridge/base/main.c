#include <stdio.h>
#include "base.h"

int main() {
	int num_list[]={9, 4, 6, 5, 3, 2, 1, 7, 8};
	int num=sizeof(num_list)/sizeof(num_list[0]);

	BaseSorter instance;
	/*bubble sort*/
	instance = bubble_sorter_new(num_list, num);
	printf("before sort\n");
	instance->show(instance);
	instance->sort(instance);
	printf("after sort\n");
	instance->show(instance);
	bubble_sorter_free(instance);

	/*quick sort*/
	instance = quick_sorter_new(num_list, num);
	printf("before sort\n");
	instance->show(instance);
	instance->sort(instance);
	printf("after sort\n");
	instance->show(instance);
	quick_sorter_free(instance);
	return 0;
}
