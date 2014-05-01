#ifndef HTWSCONFIG_PLATFORM_H_
#define HTWSCONFIG_PLATFORM_H_

#if defined(HTWSC_PLATFORM_LINUX)
#include "platforms/kalilinux64.h"
#elif defined(HTWSC_PLATFORM_WINDOWS)
#if defined(HTWSC_PLATFORM_WINDOWS7)
#include "platforms/windows7.h"
#else
#include "platforms/windows8.h"
#endif
#else
#error no platform defined
#endif

#endif /* HTWSCONFIG_PLATFORM_H_ */
