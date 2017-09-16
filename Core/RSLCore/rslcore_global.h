#ifndef RSLCORE_GLOBAL_H
#define RSLCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RSLCORE_LIBRARY)
#  define RSLCORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define RSLCORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RSLCORE_GLOBAL_H
