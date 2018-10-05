#load common setting
include $(top_srcdir)/am.conf

noinst_PROGRAMS = test

test_CXXFLAGS = -g -O0
test_CFLAGS = -g -O0
test_SOURCES = main.c nissan_factory.c  toyota_factory.c
test_LDADD= $(top_srcdir)/design_pattern_util/lib/libdputil.la
