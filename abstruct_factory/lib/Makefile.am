#load common setting

lib_LTLIBRARIES = libabstruct_factory.la

libabstruct_factory_la_SOURCES = abstruct_factory.c product1.c product2.c
libabstruct_factory_la_CPPFLAGS = -I../include
#for static library
libabstruct_factory_la_LDFLAGS=-shared
libabstruct_factory_la_LDFLAGS+=-Wl,--version-script,abstruct_factory.map
