#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "base.h"
#define MAXSIZE (9)

int main() {
	int num_list[]={9, 4, 6, 5, 3, 2, 1, 7, 8};
	int num=sizeof(num_list)/sizeof(num_list[0]);

	BaseClass instance;
	/*int sort*/
	instance = int_sorter_new(num_list, num);
	printf("before sort\n");
	instance->show(instance);
	instance->sorter->sort(instance);
	printf("after sort\n");
	instance->show(instance);
	int_sorter_free(instance);

	struct timespec time_list[MAXSIZE];
	int i;
	memset(time_list, 0, sizeof(time_list));
	for(i = MAXSIZE-1; 0 <= i; i --) {
		clock_gettime(CLOCK_REALTIME, &time_list[i]);
		usleep(300000);
	}

	/*quick sort*/
	instance = time_sorter_new(time_list, MAXSIZE);
	printf("before sort\n");
	instance->show(instance);
	instance->sorter->sort(instance);
	printf("after sort\n");
	instance->show(instance);
	time_sorter_free(instance);
	return 0;
}
