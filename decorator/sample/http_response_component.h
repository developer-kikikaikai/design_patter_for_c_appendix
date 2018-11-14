/**
 * @file http_response_component.h
**/
#ifndef HTTP_RESPONSE_COMPONENT_H
#define HTTP_RESPONSE_COMPONENT_H

/*共通インターフェースクラス定義*/
struct http_response_component_t;
typedef struct http_response_component_t http_response_component_t, *HTTPResponseComponent;
struct http_response_component_t {
	/*data実体は固定長で用意してください*/
	void (*response_append)(HTTPResponseComponent this, char *request_uri, char *header, char *body);
	/*freeが面倒なので継承してしまう。本来は生成した場所で解放するのがベター*/
	void (*free)(HTTPResponseComponent this);
};

#define HTTP_RESPONSE_COMPONENT_IF \
	void (*response_append)(HTTPResponseComponent this, char *request_uri, char *header, char *body);\
	void (*free)(HTTPResponseComponent this);

#endif
