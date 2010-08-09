#
# Copyright (C) 2010 by Argonne National Laboratory.
#     See COPYRIGHT in top-level directory.
#

liba1_la_SOURCES += $(top_srcdir)/src/adl/adl_initialize.c \
	$(top_srcdir)/src/adl/adl_finalize.c \
	$(top_srcdir)/src/adl/adl_malloc.c \
	$(top_srcdir)/src/adl/adl_free.c \
	$(top_srcdir)/src/adl/adl_flush.c \
	$(top_srcdir)/src/adl/adl_flush_all.c \
	$(top_srcdir)/src/adl/adl_put.c \
	$(top_srcdir)/src/adl/adl_puts.c \
	$(top_srcdir)/src/adl/adl_get.c \
	$(top_srcdir)/src/adl/adl_gets.c \
        $(top_srcdir)/src/adl/adl_putacc.c \
        $(top_srcdir)/src/adl/adl_putaccs.c \
	$(top_srcdir)/src/adl/adl_collectives.c \
	$(top_srcdir)/src/adl/adl_misc.c
