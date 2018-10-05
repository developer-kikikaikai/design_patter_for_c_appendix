#include <stdio.h>
#include <stdlib.h>
#include "factory.h"
//継承も出来る
typedef struct car_t {
	PRODUCT_CLASS
	char * name;
} *Car;

static void show_carname(Product this) {
	Car instance = (Car)this;
	printf("Nissan:%s\n", instance->name);
}

static  Product nissan_factory(void) {
	Car instance = calloc(1, sizeof(*instance));
	instance->name = "leaf";
	instance->show_name = show_carname;
	return (Product)instance;
}
static  void nissan_factory_free(Product this) {
	free(this);
}

Factory nissan_factory_new() {
	Factory instance = calloc(1, sizeof(*instance));
	instance->product_factory = nissan_factory;
	instance->product_free = nissan_factory_free;
	return instance;
}
