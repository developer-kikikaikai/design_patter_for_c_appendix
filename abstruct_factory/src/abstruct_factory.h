/**
 * @file abstruct_factory.h
**/
#ifndef ABSTRUCT_FACTORY_H
#define ABSTRUCT_FACTORY_H

#include "products_factory.h"

struct factory_manager_t {
	AbstructFactory factory;
};
typedef struct factory_manager_t *FactoryManager;

FactoryManager factory_manager_new(const char * factory_libname);
void factory_manager_free(FactoryManager this);
#endif
