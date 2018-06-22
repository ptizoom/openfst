AM_CPPFLAGS = -I$(srcdir)/../include $(ICU_CPPFLAGS)

lib_LTLIBRARIES = libfst.la libopenfst.la
libfst_la_SOURCES = compat.cc flags.cc fst.cc properties.cc \
symbol-table.cc util.cc symbol-table-ops.cc mapped-file.cc
libfst_la_LDFLAGS = -version-info 4:0:0
libfst_la_LIBADD = $(DL_LIBS)
libopenfst_la_SOURCES = ../include/fst/fst.h
libopenfst_la_LIBADD =  $(builddir)/libfst.la
if HAVE_SCRIPT
libopenfst_la_LIBADD += $(builddir)/../script/libfstscript.la
#PTZ180620 Aucune règle pour fabriquer la cible « ../script/libfstscript.la
$(libopenfst_la_LIBADD):;$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
endif
