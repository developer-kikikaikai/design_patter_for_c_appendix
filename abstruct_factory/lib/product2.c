#include <stdlib.h>
#include "product2.h"

static char *product2_get_name2() {
	return "product2";
}

void product2_free(AbstructProduct2 this) {
	free(this);
}

AbstructProduct2 product2_new() {
	AbstructProduct2 instance = calloc(1, sizeof(*instance));
	if(!instance) return NULL;

	instance->get_name2 = product2_get_name2;
	instance->free = product2_free;
	return instance;
}
