PHP_ARG_ENABLE(sample3,
  [Whether to enable the "sample3" extension],
  [  --enable-sample3        Enable "sample3" extension support])

if test $PHP_SAMPLE3 != "no"; then
  PHP_SUBST(SAMPLE3_SHARED_LIBADD)
  PHP_NEW_EXTENSION(sample3, sample3.c, $ext_shared)
fi
