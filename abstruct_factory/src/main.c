#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abstruct_factory.h"

int main() {
	AbstructFactory factory = abstruct_factory_new();
	printf("call product1 API:%s\n", get_product1(factory)->get_name1());
	printf("call product2 API:%s\n", get_product2(factory)->get_name2());
	abstruct_factory_free(factory);
	return 0;
}
