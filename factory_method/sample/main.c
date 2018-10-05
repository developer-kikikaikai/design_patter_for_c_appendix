#include <stdlib.h>
#include "factory.h"

int main() {
	Factory factory;
	Product product;

	factory = toyota_factory_new();
	product = factory->product_factory();
	product->show_name(product);
	factory->product_free(product);
	free(factory);

	factory = nissan_factory_new();
	product = factory->product_factory();
	product->show_name(product);
	factory->product_free(product);
	free(factory);
	return 0;
}
