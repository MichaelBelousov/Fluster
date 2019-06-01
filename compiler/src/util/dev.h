#ifndef FLUSTER_COMPILER_UTIL_DEV_H
#define FLUSTER_COMPILER_UTIL_DEV_H

#define DO_PRAGMA(x) _Pragma (#x)
#define TODO(x) DO_PGRAGMA(message ("TODO: " $x))
#define NOTE(x) DO_PGRAGMA(message ("NOTE: " $x))
#define HACK(x) DO_PGRAGMA(message ("HACK: " $x))
#define FIXME(x) DO_PGRAGMA(message ("FIXME: " $x))
#define XXX(x) DO_PGRAGMA(message ("XXX: " $x))

#endif  //FLUSTER_COMPILER_UTIL_DEV_H
