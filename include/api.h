#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define HRP5PRLQPController_DLLIMPORT __declspec(dllimport)
#  define HRP5PRLQPController_DLLEXPORT __declspec(dllexport)
#  define HRP5PRLQPController_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define HRP5PRLQPController_DLLIMPORT __attribute__((visibility("default")))
#    define HRP5PRLQPController_DLLEXPORT __attribute__((visibility("default")))
#    define HRP5PRLQPController_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define HRP5PRLQPController_DLLIMPORT
#    define HRP5PRLQPController_DLLEXPORT
#    define HRP5PRLQPController_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef HRP5PRLQPController_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define HRP5PRLQPController_DLLAPI
#  define HRP5PRLQPController_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef HRP5PRLQPController_EXPORTS
#    define HRP5PRLQPController_DLLAPI HRP5PRLQPController_DLLEXPORT
#  else
#    define HRP5PRLQPController_DLLAPI HRP5PRLQPController_DLLIMPORT
#  endif // HRP5PRLQPController_EXPORTS
#  define HRP5PRLQPController_LOCAL HRP5PRLQPController_DLLLOCAL
#endif // HRP5PRLQPController_STATIC
