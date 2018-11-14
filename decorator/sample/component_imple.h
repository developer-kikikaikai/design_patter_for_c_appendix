/**
 * @file component_imple.h
**/
#ifndef COMPONENT_IMPLE_H
#define COMPONENT_IMPLE_H
#include "http_response_component.h"

HTTPResponseComponent base_component_new(void);

typedef struct decorator_t {
	HTTP_RESPONSE_COMPONENT_IF
	HTTPResponseComponent component;
} *Decorator;

/*ここを変更・拡張していく感じ*/
Decorator header_decorator_new(HTTPResponseComponent component);
Decorator body_decorator_new(HTTPResponseComponent component);

#endif
