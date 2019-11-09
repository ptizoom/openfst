AM_CPPFLAGS = -I$(srcdir)/../../include $(ICU_CPPFLAGS)

libopenfstdir = @libfstdir@
libopenfst_LTLIBRARIES = libngram-fst.la

libngram_fst_la_SOURCES = bitmap-index.cc ngram-fst.cc nthbit.cc
#ngram_fst_la_LDFLAGS = -module

#lib_LTLIBRARIES = libfstngram.la
#libfstngram_la_SOURCES = bitmap-index.cc ngram-fst.cc nthbit.cc
#libfstngram_la_LDFLAGS = -version-info 10:0:0
#libfstngram_la_LIBADD = $(builddir)/../../lib/libopenfst.la -lm $(DL_LIBS)
#libfstngram_la_DEPENDENCIES = $(builddir)/../../lib/libopenfst.la
#$(libfstngram_la_DEPENDENCIES):;echo $(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
