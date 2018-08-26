#load common setting

lib_LTLIBRARIES = libproducts_factory.la

libproducts_factory_la_SOURCES = products_factory.c product1.c product2.c
libproducts_factory_la_CPPFLAGS = -I../include
#for static library
libproducts_factory_la_LDFLAGS=-shared
libproducts_factory_la_LDFLAGS+=-Wl,--version-script,abstruct_factory.map
