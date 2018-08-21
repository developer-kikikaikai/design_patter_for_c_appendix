#include <stdlib.h>
#include "product1.h"
#include "product2.h"

struct abstruct_factory_t {
	AbstructProduct1 product1;
	AbstructProduct2 product2;
};

AbstructFactory abstruct_factory_new(void) {
	AbstructFactory instance = calloc(1, sizeof(*instance));
	if(!instance) return NULL;

	instance->product1 = product1_new();
	if(!instance->product1) goto err;

	instance->product2 = product2_new();
	if(!instance->product2) goto err;

	return instance;
err:
	abstruct_factory_free(instance);
	return NULL;
}

void abstruct_factory_free(AbstructFactory this) {
	product1_free(this->product1);
	product2_free(this->product2);
	free(this);
}

AbstructProduct1 get_product1(AbstructFactory this) {
	return this->product1;
}

AbstructProduct2 get_product2(AbstructFactory this) {
	return this->product2;
}
