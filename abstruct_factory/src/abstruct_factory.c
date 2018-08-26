#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include "abstruct_factory.h"

typedef struct factory_manager_imple_t {
	AbstructFactory factory;
	void *handle;
	void (*factory_free)(AbstructFactory this);
} *FactoryManagerImple;

FactoryManager factory_manager_new(const char * factory_libname) {

	FactoryManagerImple instance = calloc(1, sizeof(*instance));
	if(!instance) return NULL;

	instance->handle = dlopen(factory_libname, RTLD_NOW);
	if(!instance->handle) goto err;

	AbstructFactory (*abstruct_new)(void);
	abstruct_new = dlsym(instance->handle, "abstruct_factory_new");
	if(!abstruct_new) goto err;

	instance->factory_free = dlsym(instance->handle, "abstruct_factory_free");
	if(!instance->factory_free) goto err;

	instance->factory = abstruct_new();
	if(!instance->factory) goto err;

	return (FactoryManager)instance;

err:
	factory_manager_free((FactoryManager)instance);
	return NULL;
}

void factory_manager_free(FactoryManager this) {
	FactoryManagerImple instance = (FactoryManagerImple)this;
	if(instance->factory) instance->factory_free(instance->factory);
	if(instance->handle) dlclose(instance->handle);
	free(instance);
}
