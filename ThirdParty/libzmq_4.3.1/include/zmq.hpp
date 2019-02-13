
#if PLATFORM_WINDOWS && !defined(WINDOWS_PLATFORM_TYPES_GUARD)
	#include <AllowWindowsPlatformTypes.h>
	#include "zmq_impl.hpp"
	#include <HideWindowsPlatformTypes.h>
#else
	#include "zmq_impl.hpp"
#endif

