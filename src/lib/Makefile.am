AM_CPPFLAGS = -I$(srcdir)/../include $(ICU_CPPFLAGS)

lib_LTLIBRARIES = libopenfst.la
libopenfst_la_SOURCES = compat.cc flags.cc fst.cc fst-types.cc mapped-file.cc \
                    properties.cc symbol-table.cc symbol-table-ops.cc \
                    weight.cc util.cc
libopenfst_la_SOURCES +=  $(srcdir)/../include/fst/fst.h
libopenfst_la_LDFLAGS = -version-info 10:0:0
libopenfst_la_LIBADD = $(DL_LIBS)
if HAVE_SCRIPT
#libopenfst_la_LIBADD += $(builddir)/../script/libfstscript.la
#libopenfst_la_DEPENDENCIES = $(builddir)/../script/libfstscript.la
#PTZ180620 Aucune règle pour fabriquer la cible « ../script/libfstscript.la
#PTZ180908 does create recurrences with libfst.la
#$(libopenfst_la_DEPENDENCIES):;$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
endif
