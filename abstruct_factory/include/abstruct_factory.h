/**
 * @file abstruct_factory.h
**/
#ifndef ABSTRUCT_FACTORY_H
#define ABSTRUCT_FACTORY_H

/*! @struct abstruct_product1_t*/
typedef struct abstruct_product1_t {
	char *(*get_name1)();
} abstruct_product1_t, *AbstructProduct1;

/*! @struct abstruct_product1_t*/
typedef struct abstruct_product2_t {
	char *(*get_name2)();
} abstruct_product2_t, *AbstructProduct2;

struct abstruct_factory_t;
typedef struct abstruct_factory_t *AbstructFactory;

AbstructFactory abstruct_factory_new(void);
void abstruct_factory_free(AbstructFactory this);

AbstructProduct1 get_product1(AbstructFactory this);
AbstructProduct2 get_product2(AbstructFactory this);
#endif
