#include <stdlib.h>
#include "factory.h"

static void do_product(Factory factory) {
	Product product = factory->product_factory();
	product->show_name(product);
	factory->product_free(product);
}

int main() {
	Factory factory;

	factory = toyota_factory_new();
	do_product(factory);
	free(factory);

	factory = nissan_factory_new();
	do_product(factory);
	free(factory);
	return 0;
}
