#include <stdlib.h>
#include "product1.h"

static char *product1_get_name1() {
	return "product1";
}

AbstructProduct1 product1_new() {
	AbstructProduct1 instance = calloc(1, sizeof(*instance));
	if(!instance) return NULL;

	instance->get_name1 = product1_get_name1;
	return instance;
}

void product1_free(AbstructProduct1 this) {
	free(this);
}
