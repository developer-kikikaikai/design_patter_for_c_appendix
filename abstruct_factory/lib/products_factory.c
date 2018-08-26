#include <stdlib.h>
#include "product1.h"
#include "product2.h"

typedef struct abstruct_factory_imple_t {
	ABSTRUCT_FACTORY_IF
	/*write private member if you want*/
	AbstructProduct1 (*create_product1)();
	AbstructProduct2 (*create_product2)();
} *AbstructFactoryImple;

static AbstructProduct1 abi_get_product1(AbstructFactory this) {
	return ((AbstructFactoryImple)this)->create_product1();
}

static AbstructProduct2 abi_get_product2(AbstructFactory this) {
	return ((AbstructFactoryImple)this)->create_product2();
}

AbstructFactory abstruct_factory_new(void) {
	AbstructFactoryImple instance = calloc(1, sizeof(*instance));
	if(!instance) return NULL;

	/*set own method*/
	instance->get_product1 = abi_get_product1;
	instance->get_product2 = abi_get_product2;

	/*set own member*/
	instance->create_product1 = product1_new;
	instance->create_product2 = product2_new;

	return (AbstructFactory)instance;
err:
	abstruct_factory_free((AbstructFactory)instance);
	return NULL;
}

void abstruct_factory_free(AbstructFactory this) {
	free(this);
}
