#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"

typedef struct SorterImpl_t {
	BASE_SORTER;
	int *num_list;
	int num;
	const char * name;
} *SorterImpl;

static void swap(int *num_list, int place) {
	int stash_val = num_list[place];
	printf("\tswap %d and %d at %d\n", num_list[place], num_list[place + 1], place);
	num_list[place] = num_list[place + 1];
	num_list[place + 1] = stash_val;
}

static void bubble_sort(BaseSorter this) {
	SorterImpl instance = (SorterImpl)this;
	int i, j;
	for(i=0; i<instance->num-1; i++) {
		for(j=1; j < instance->num - i; j++) {
			if( instance->num_list[j] < instance->num_list[j -1] ) {
				swap(instance->num_list, j-1);
			}
		}
	}
}

/*from ja.wikipedia, 2018/11/03*/
/* x, y, z の中間値を返す */
int med3(int x, int y, int z) {
    if (x < y) {
        if (y < z) return y; else if (z < x) return x; else return z;
    } else {
        if (z < y) return y; else if (x < z) return x; else return z;
    }
}

/*from ja.wikipedia, 2018/11/03*/
/* クイックソート
 * a     : ソートする配列
 * left  : ソートするデータの開始位置
 * right : ソートするデータの終了位置
 */
static void quicksort(int *a, int left, int right) {
	printf("\tsort left %d and right %d\n", left, right);
    if (left < right) {
        int i = left, j = right;
        int tmp, pivot = med3(a[i], a[i + (j - i) / 2], a[j]); /* (i+j)/2 ではオーバーフローしてしまう */
        while (1) { /* a[] を pivot 以上と以下の集まりに分割する */
            while (a[i] < pivot) i++; /* a[i] >= pivot となる位置を検索 */
            while (pivot < a[j]) j--; /* a[j] <= pivot となる位置を検索 */
            if (i >= j) break;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp; /* a[i], a[j] を交換 */
            i++; j--;
        }
        quicksort(a, left, i - 1);  /* 分割した左を再帰的にソート */
        quicksort(a, j + 1, right); /* 分割した右を再帰的にソート */
    }
}

static void quick_sort_base(BaseSorter this) {
	SorterImpl instance = (SorterImpl)this;
	quicksort(instance->num_list, 0, instance->num - 1);
}

static void show_impl(BaseSorter this) {
	SorterImpl instance = (SorterImpl)this;
	int i;
	printf("[%s]\n", instance->name);
	for(i=0; i<instance->num; i++) {
		printf("%d ", instance->num_list[i]);
	}
	printf("\n");
}

BaseSorter bubble_sorter_new(int *num_list, int num) {
	SorterImpl instance = malloc(sizeof(*instance) + sizeof(int)*num);
	if(!instance) return NULL;
	instance->num_list = (int *)(instance + 1);

	instance->sort = bubble_sort;
	instance->show = show_impl;
	memcpy(instance->num_list, num_list, sizeof(int)*num);
	instance->num = num;
	instance->name = "bubble_sorter";
	return (BaseSorter)instance;
}

void bubble_sorter_free(BaseSorter this) {
	free(this);
}

BaseSorter quick_sorter_new(int *num_list, int num) {
	SorterImpl instance = malloc(sizeof(*instance) + sizeof(int)*num);
	if(!instance) return NULL;
	instance->num_list = (int *)(instance + 1);

	instance->sort = quick_sort_base;
	instance->show = show_impl;
	memcpy(instance->num_list, num_list, sizeof(int)*num);
	instance->num = num;
	instance->name = "quick_sorter";
	return (BaseSorter)instance;
}

void quick_sorter_free(BaseSorter this) {
	free(this);
}
