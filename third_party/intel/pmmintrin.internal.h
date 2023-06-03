#ifndef _PMMINTRIN_H_INCLUDED
#define _PMMINTRIN_H_INCLUDED
#ifdef __x86_64__
#include "third_party/intel/emmintrin.internal.h"

#ifndef __SSE3__
#pragma GCC push_options
#pragma GCC target("sse3")
#define __DISABLE_SSE3__
#endif /* __SSE3__ */

#define _MM_DENORMALS_ZERO_MASK 0x0040
#define _MM_DENORMALS_ZERO_ON   0x0040
#define _MM_DENORMALS_ZERO_OFF  0x0000

#define _MM_SET_DENORMALS_ZERO_MODE(mode) \
  _mm_setcsr((_mm_getcsr() & ~_MM_DENORMALS_ZERO_MASK) | (mode))
#define _MM_GET_DENORMALS_ZERO_MODE() (_mm_getcsr() & _MM_DENORMALS_ZERO_MASK)

__funline __m128 _mm_addsub_ps(__m128 __X, __m128 __Y) {
  return (__m128)__builtin_ia32_addsubps((__v4sf)__X, (__v4sf)__Y);
}

__funline __m128 _mm_hadd_ps(__m128 __X, __m128 __Y) {
  return (__m128)__builtin_ia32_haddps((__v4sf)__X, (__v4sf)__Y);
}

__funline __m128 _mm_hsub_ps(__m128 __X, __m128 __Y) {
  return (__m128)__builtin_ia32_hsubps((__v4sf)__X, (__v4sf)__Y);
}

__funline __m128 _mm_movehdup_ps(__m128 __X) {
  return (__m128)__builtin_ia32_movshdup((__v4sf)__X);
}

__funline __m128 _mm_moveldup_ps(__m128 __X) {
  return (__m128)__builtin_ia32_movsldup((__v4sf)__X);
}

__funline __m128d _mm_addsub_pd(__m128d __X, __m128d __Y) {
  return (__m128d)__builtin_ia32_addsubpd((__v2df)__X, (__v2df)__Y);
}

__funline __m128d _mm_hadd_pd(__m128d __X, __m128d __Y) {
  return (__m128d)__builtin_ia32_haddpd((__v2df)__X, (__v2df)__Y);
}

__funline __m128d _mm_hsub_pd(__m128d __X, __m128d __Y) {
  return (__m128d)__builtin_ia32_hsubpd((__v2df)__X, (__v2df)__Y);
}

__funline __m128d _mm_loaddup_pd(double const *__P) {
  return _mm_load1_pd(__P);
}

__funline __m128d _mm_movedup_pd(__m128d __X) {
  return _mm_shuffle_pd(__X, __X, _MM_SHUFFLE2(0, 0));
}

__funline __m128i _mm_lddqu_si128(__m128i const *__P) {
  return (__m128i)__builtin_ia32_lddqu((char const *)__P);
}

__funline void _mm_monitor(void const *__P, unsigned int __E, unsigned int __H) {
  __builtin_ia32_monitor(__P, __E, __H);
}

__funline void _mm_mwait(unsigned int __E, unsigned int __H) {
  __builtin_ia32_mwait(__E, __H);
}

#ifdef __DISABLE_SSE3__
#undef __DISABLE_SSE3__
#pragma GCC pop_options
#endif /* __DISABLE_SSE3__ */

#endif /* __x86_64__ */
#endif /* _PMMINTRIN_H_INCLUDED */