#include <stdio.h>
#include <stdlib.h>
#include "factory.h"
//継承も出来る
typedef struct car_t {
	PRODUCT_CLASS
	char * name;
	char * grade;
} *Car;

static void show_carname(Product this) {
	Car instance = (Car)this;
	printf("Toyota:%s(grade %s)\n", instance->name, instance->grade);
}

static  Product toyota_factory(void) {
	Car instance = calloc(1, sizeof(*instance));
	instance->name = "prius";
	instance->grade = "Apremium";
	instance->show_name = show_carname;
	return (Product)instance;
}
static  void toyota_factory_free(Product this) {
	free(this);
}

Factory toyota_factory_new() {
	Factory instance = calloc(1, sizeof(*instance));
	instance->product_factory = toyota_factory;
	instance->product_free = toyota_factory_free;
	return instance;
}
