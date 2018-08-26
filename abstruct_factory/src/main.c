#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abstruct_factory.h"

int main() {
	FactoryManager manager = factory_manager_new("../lib/.libs/libproducts_factory.so");
	if(!manager) return 0;

	AbstructProduct1 product1 = manager->factory->get_product1(manager->factory);
	AbstructProduct2 product2 = manager->factory->get_product2(manager->factory);
	printf("call product1 API:%s\n", product1->get_name1());
	printf("call product2 API:%s\n", product2->get_name2());
	product1->free(product1);
	product2->free(product2);
	factory_manager_free(manager);
	return 0;
}
