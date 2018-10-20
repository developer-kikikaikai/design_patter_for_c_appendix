#ifndef _BASE_H_
#define _BASE_H_

struct BaseSorter_t;
typedef struct BaseSorter_t *BaseSorter;
struct BaseSorter_t {
	void (*sort)(BaseSorter this);
	void (*show)(BaseSorter this);
};

#define BASE_SORTER \
	void (*sort)(BaseSorter this);\
	void (*show)(BaseSorter this);

BaseSorter bubble_sorter_new(int *num_list, int num);
void bubble_sorter_free(BaseSorter this);

BaseSorter quick_sorter_new(int *num_list, int num);
void quick_sorter_free(BaseSorter this);

#endif
