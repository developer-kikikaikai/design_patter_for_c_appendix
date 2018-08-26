/**
 * @file abstruct_factory.h
**/
#ifndef PRODUCTS_FACTORY_H
#define PRODUCTS_FACTORY_H

struct abstruct_product1_t;
typedef struct abstruct_product1_t *AbstructProduct1;
/*! @struct abstruct_product1_t*/
struct abstruct_product1_t {
	char *(*get_name1)();
	void (*free)(AbstructProduct1 this);
};

#define ABSTRUCT_PRODUCT1_IF \
	char *(*get_name1)();\
	void (*free)(AbstructProduct1 this);

/*! @struct abstruct_product1_t*/
struct abstruct_product2_t;
typedef struct abstruct_product2_t *AbstructProduct2;
/*! @struct abstruct_product1_t*/
struct abstruct_product2_t {
	char *(*get_name2)();
	void (*free)(AbstructProduct2 this);
};

#define ABSTRUCT_PRODUCT2_IF \
	 char *(*get_name2)();\
	void (*free)(AbstructProduct2 this);

struct abstruct_factory_t;
typedef struct abstruct_factory_t *AbstructFactory;
struct abstruct_factory_t {
	AbstructProduct1 (*get_product1)(AbstructFactory this);
	AbstructProduct2 (*get_product2)(AbstructFactory this);
};

#define ABSTRUCT_FACTORY_IF \
	AbstructProduct1 (*get_product1)(AbstructFactory this);\
	AbstructProduct2 (*get_product2)(AbstructFactory this);

AbstructFactory abstruct_factory_new(void);
void abstruct_factory_free(AbstructFactory this);

#endif
