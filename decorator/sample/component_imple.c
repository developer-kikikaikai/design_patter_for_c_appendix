#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "component_imple.h"

#define FIXED_HEADER "server: sample_server\r\n"
#define FIXED_HEADER_LEN (strlen(FIXED_HEADER))

static void fixed_response_append_imple(HTTPResponseComponent this, char *request_uri, char *header, char *body) {
	memmove(&header[FIXED_HEADER_LEN], header, strlen(header));
	memcpy(header, FIXED_HEADER, FIXED_HEADER_LEN);
};

static void base_component_free(HTTPResponseComponent this) {
	free(this);
}

HTTPResponseComponent base_component_new(void) {
	HTTPResponseComponent instance = calloc(1, sizeof(*instance));
	if(!instance) return NULL;

	instance->response_append = fixed_response_append_imple;
	instance->free = base_component_free;
	return instance;
}

static void header_response_append(HTTPResponseComponent this, char *request_uri, char *header, char *body) {
	char response[128]={0};
	snprintf(response, sizeof(response), "referer: %s\r\n", request_uri);
	memmove(&header[strlen(response)], header, strlen(header));
	memcpy(header, response, strlen(response));

	Decorator decorator = (Decorator)this;
	decorator->component->response_append(decorator->component, request_uri, header, body);
}

#define RESPONSE_BODY "Hello World!!\r\n"
#define RESPONSE_BODY_LEN (strlen(RESPONSE_BODY))
static void body_response_append(HTTPResponseComponent this, char *request_uri, char *header, char *body) {
	char response[256]={0};
	snprintf(response, sizeof(response), "status:200\r\ncontent_length: %lu\r\n", RESPONSE_BODY_LEN);
	memmove(&header[strlen(response)], header, strlen(header));
	memcpy(header, response, strlen(response));
	/*body*/
	memmove(&body[RESPONSE_BODY_LEN], body, strlen(body));
	memcpy(body, RESPONSE_BODY, RESPONSE_BODY_LEN);

	Decorator decorator = (Decorator)this;
	decorator->component->response_append(decorator->component, request_uri, header, body);
}

static void decorator_free(HTTPResponseComponent this) {
	Decorator instance = (Decorator)this;
	instance->component->free(instance->component);
	free(instance);
}

static Decorator decorator_initialize(HTTPResponseComponent component, void (*response_append)(HTTPResponseComponent this, char *request_uri, char *header, char *body)) {
	Decorator instance = calloc(1, sizeof(*instance));
	if(!instance) return NULL;

	instance->component = component;
	instance->response_append = response_append;
	instance->free = decorator_free;
	return instance;
}

Decorator header_decorator_new(HTTPResponseComponent component) {
	return decorator_initialize(component, header_response_append);
}

Decorator body_decorator_new(HTTPResponseComponent component) {
	return decorator_initialize(component, body_response_append);
}
