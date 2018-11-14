#include <stdio.h>
#include "component_imple.h"

int main(int argc, char **argv) {
	if(argc<2) {
		return -1;
	}

	char *uri = argv[1];
	char header[8192]={0};
	char body[8192]={0};

	HTTPResponseComponent component = base_component_new();
	component = (HTTPResponseComponent)header_decorator_new(component);
	component = (HTTPResponseComponent)body_decorator_new(component);

	component->response_append(component, uri, header, body);
	printf("## request uri\n%s\n", uri);
	printf("## response\n");
	printf("%s\r\n%s", header, body);
	component->free(component);
	return 0;
}
