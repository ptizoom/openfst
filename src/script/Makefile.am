AM_CPPFLAGS = -I$(srcdir)/../include $(ICU_CPPFLAGS)

#if HAVE_SCRIPT
libopenfstdir = @libfstdir@
libopenfst_LTLIBRARIES = libfstscript.la
#libfstscript_la_LDFLAGS = -module

libfstscript_la_SOURCES = arciterator-class.cc arcsort.cc closure.cc        \
compile.cc compose.cc concat.cc connect.cc convert.cc decode.cc             \
determinize.cc difference.cc disambiguate.cc draw.cc encode.cc              \
encodemapper-class.cc epsnormalize.cc equal.cc equivalent.cc fst-class.cc   \
getters.cc info-impl.cc info.cc intersect.cc invert.cc isomorphic.cc map.cc \
minimize.cc print.cc project.cc prune.cc push.cc randequivalent.cc          \
randgen.cc relabel.cc replace.cc reverse.cc reweight.cc rmepsilon.cc        \
shortest-distance.cc shortest-path.cc stateiterator-class.cc synchronize.cc \
text-io.cc topsort.cc union.cc weight-class.cc verify.cc

#libfstscript_la_LIBADD = $(builddir)/../lib/libopenfst.la -lm $(DL_LIBS)
libfstscript_la_LDFLAGS = -version-info 18:0:0
#libfstscript_la_DEPENDENCIES = $(builddir)/../lib/libopenfst.la
#$(libfstscript_la_DEPENDENCIES):;echo $(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
#endif
