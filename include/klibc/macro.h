// Copyright 2024 ks75vl
//
// Filename: include/klibc/macro.h
//   Author: ks75vl
//  Created: 03/14/2024 21:40:32 +07:00

#pragma once

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#define REF(val)                  (&(val))
#define DEREF(ref)                *(ref)
#define SZ(data)                  (sizeof(data))
#define MODULE_LOG_TAG(tag)       static const char TAG[] = tag
#define MODULE_VERSION(version)   static const uint16_t VERSION = version
#define UNUSED(v)                 (void)(v);

#define CAST(ptr, type)           ((type)(ptr))
#define CAST_FROM_TYPE(ptr, type) ((type *)(ptr))
#define ZERO_INITIALIZE                                                                                                \
    { 0 }
#define NULLPTR                 NULL

#define SET_UINT32(buff, value) (DEREF(CAST_FROM_TYPE(buff, uint32_t)) = CAST(value, uint32_t), buff + 4)
#define SET_UINT16(buff, value) (DEREF(CAST_FROM_TYPE(buff, uint16_t)) = CAST(value, uint16_t), buff + 2)
#define SET_UINT8(buff, value)  (DEREF(CAST_FROM_TYPE(buff, uint8_t)) = CAST(value, uint8_t), buff + 1)

#define MODULE_CTOR(name)       static void __attribute__((constructor)) name()

#ifdef __cplusplus
}
#endif