#ifndef TESTLIB_GLOBAL_HPP
#define TESTLIB_GLOBAL_HPP

#include <QtCore/qglobal.h>

#if defined(TESTLIB_LIBRARY)
#define TESTLIB_EXPORT Q_DECL_EXPORT
#else
#define TESTLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // TESTLIB_GLOBAL_HPP
