#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "sorter.h"

typedef struct SorterImpl_t {
	BASE_SORTER;
	const char * name;
} *SorterImpl;

static void bubble_sort(BaseClass baseinfo) {
	int size = baseinfo->get_size(baseinfo);
	int i, j;
	for(i=0; i<size-1; i++) {
		for(j=1; j < size - i; j++) {
			if( baseinfo->operator_large(baseinfo, j, j-1) ) {
				printf("\tbubble_sort switch %d and %d\n", j-1, j);
				baseinfo->swap(baseinfo, j-1, j);
			}
		}
	}
}

/*from ja.wikipedia, 2018/11/03*/
/* x, y, z の中間値を返す */
int med3(BaseClass baseinfo, int x, int y, int z) {
    if (baseinfo->operator_large(baseinfo, x, y)) {
        if (baseinfo->operator_large(baseinfo, y, z)) return y; else if (baseinfo->operator_large(baseinfo, z , x)) return x; else return z;
    } else {
        if (baseinfo->operator_large(baseinfo, z, y)) return y; else if (baseinfo->operator_large(baseinfo, x, z)) return x; else return z;
    }
}

/* クイックソート
 * a     : ソートする配列
 * left  : ソートするデータの開始位置
 * right : ソートするデータの終了位置
 */
static void quicksort(BaseClass baseinfo, int left, int right) {
	printf("\tsort left %d and right %d\n", left, right);
    if (left < right) {
        int i = left, j = right;
        int pivot = med3(baseinfo,i, i + (j - i) / 2, j); /* (i+j)/2 ではオーバーフローしてしまう */
        while (1) { /* a[] を pivot 以上と以下の集まりに分割する */
            while (baseinfo->operator_large(baseinfo, i, pivot)) i++; /* a[i] >= pivot となる位置を検索 */
            while (baseinfo->operator_large(baseinfo, pivot, j)) j--; /* a[j] <= pivot となる位置を検索 */
            if (i >= j) break;
			baseinfo->swap(baseinfo, i, j);
            /* a[i], a[j] を交換 */
            i++; j--;
        }
        quicksort(baseinfo, left, i - 1);  /* 分割した左を再帰的にソート */
        quicksort(baseinfo, j + 1, right); /* 分割した右を再帰的にソート */
    }
}

static void quick_sort_base(BaseClass baseinfo) {
	quicksort(baseinfo, 0, baseinfo->get_size(baseinfo) - 1);
}

BaseSorter bubble_sorter_new(void) {
	SorterImpl instance = malloc(sizeof(*instance));
	if(!instance) return NULL;

	instance->sort = bubble_sort;
	instance->name = "bubble_sorter";
	return (BaseSorter)instance;
}

void bubble_sorter_free(BaseSorter this) {
	free(this);
}

BaseSorter quick_sorter_new(void) {
	SorterImpl instance = malloc(sizeof(*instance));
	if(!instance) return NULL;

	instance->sort = quick_sort_base;
	instance->name = "quick_sorter";
	return (BaseSorter)instance;
}

void quick_sorter_free(BaseSorter this) {
	free(this);
}
