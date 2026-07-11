#define BUILD  ""

#ifndef HIDDEN
#if defined(__GNUC__) && !defined(_WIN32)
#define HIDDEN  __attribute__((visibility("hidden")))
#else
#define HIDDEN
#endif
#endif

#undef inline

#ifndef INLINE
#if defined(__GNUC__)
#define INLINE  __inline__ __attribute__((always_inline))
#elif defined(_MSC_VER)
#define INLINE  __forceinline
#else
#define INLINE
#endif
#endif

#if defined(_MSC_VER) && defined(_WIN32)
#define THREAD_LOCAL  __declspec(thread)
#else
#define THREAD_LOCAL  __thread
#endif

#define PACKAGE_NAME  "libjpeg-turbo"
#define VERSION  "3.2.0"

#if defined(__LP64__) || defined(_WIN64)
#define SIZEOF_SIZE_T  8
#else
#define SIZEOF_SIZE_T  4
#endif

#if defined(__GNUC__) && !defined(_WIN32)
#define HAVE_BUILTIN_CTZL
#endif

#if defined(_MSC_VER)
#define HAVE_INTRIN_H  1
#endif

#if defined(_MSC_VER) && defined(HAVE_INTRIN_H)
#if (SIZEOF_SIZE_T == 8)
#define HAVE_BITSCANFORWARD64
#elif (SIZEOF_SIZE_T == 4)
#define HAVE_BITSCANFORWARD
#endif
#endif

#if defined(__has_attribute)
#if __has_attribute(fallthrough)
#define FALLTHROUGH  __attribute__((fallthrough));
#else
#define FALLTHROUGH
#endif
#else
#define FALLTHROUGH
#endif

#ifndef BITS_IN_JSAMPLE
#define BITS_IN_JSAMPLE  8
#endif

#undef C_ARITH_CODING_SUPPORTED
#undef D_ARITH_CODING_SUPPORTED
#undef WITH_SIMD

#if BITS_IN_JSAMPLE == 8

#define C_ARITH_CODING_SUPPORTED 1
#define D_ARITH_CODING_SUPPORTED 1

#if defined(__x86_64__) || defined(_M_X64)
#define WITH_SIMD 1
#define SIMD_ARCHITECTURE  X86_64
#elif defined(__i386__) || defined(_M_IX86)
#define WITH_SIMD 1
#define SIMD_ARCHITECTURE  I386
#elif defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)
#define WITH_SIMD 1
#define SIMD_ARCHITECTURE  ARM64
#elif defined(__arm__) || defined(_M_ARM)
#define WITH_SIMD 1
#define SIMD_ARCHITECTURE  ARM
#else
#define SIMD_ARCHITECTURE  NONE
#endif

#endif
