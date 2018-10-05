#ifndef FACTORY_H_
#define FACTORY_H_
struct product_t;
typedef struct product_t *Product;
struct product_t {
	void (*show_name)(Product this);
};
#define PRODUCT_CLASS \
	void (*show_name)(Product this);

//define factory interface
typedef struct factory_t {
	Product (*product_factory)(void);
	void (*product_free)(Product this);
} *Factory;

Factory toyota_factory_new();
Factory nissan_factory_new();
#endif
