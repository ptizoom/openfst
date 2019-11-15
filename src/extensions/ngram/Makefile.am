AM_CPPFLAGS = -I$(srcdir)/../../include $(ICU_CPPFLAGS)
LIBS = ../../lib/libopenfst.la -lm $(DL_LIBS)

libopenfstdir = @libfstdir@
libopenfst_LTLIBRARIES = libngram-fst.la

#lib_LTLIBRARIES = libfstngram.la

libngram_fst_la_SOURCES = bitmap-index.cc ngram-fst.cc nthbit.cc
libngram_fst_la_LDFLAGS = -avoid-version -module

#libfstngram_la_SOURCES = bitmap-index.cc ngram-fst.cc nthbit.cc
#libfstngram_la_LDFLAGS = -version-info 18:0:0
