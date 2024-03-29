// Copyright 2024 ks75vl
//
// Filename: include/klibc/log.h
//   Author: ks75vl
//  Created: 03/14/2024 21:08:43 +07:00

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define _KLIBC_LOG_LEVEL_ERROR    0
#define _KLIBC_LOG_LEVEL_INFO     1
#define _KLIBC_LOG_LEVEL_DEBUG    2
#define _KLIBC_LOG_LEVEL_DEBUGNTS 3
#define _KLIBC_LOG_LEVEL_ALL      4

typedef enum klibc_log_level {
    KLIBC_LOG_ERROR    = _KLIBC_LOG_LEVEL_ERROR,
    KLIBC_LOG_INFO     = _KLIBC_LOG_LEVEL_INFO,
    KLIBC_LOG_DEBUG    = _KLIBC_LOG_LEVEL_DEBUG,
    KLIBC_LOG_DEBUGNTS = _KLIBC_LOG_LEVEL_DEBUGNTS,
    KLIBC_LOG_ALL      = _KLIBC_LOG_LEVEL_ALL,
} klibc_log_level_t;

typedef size_t (*get_timestamp_func)(void);

typedef int (*printf_func)(const char *format, ...);

#define KLIBC_LOG_MAX_LEVEL KLIBC_LOG_ALL

#ifdef KLIBC_LOG_LEVEL_ALL
#define KLIBC_LOG_LEVEL KLIBC_LOG_ALL
#endif

#ifdef KLIBC_LOG_LEVEL_ERROR
#define KLIBC_LOG_LEVEL KLIBC_LOG_ERROR
#endif

#ifdef KLIBC_LOG_LEVEL_INFO
#define KLIBC_LOG_LEVEL KLIBC_LOG_INFO
#endif

#ifndef KLIBC_LOG_LEVEL
#define KLIBC_LOG_LEVEL KLIBC_LOG_ALL
#endif

#define _KLIBC_LOG_PRINTF(fmt, ...)                                                                                    \
    {                                                                                                                  \
        for (; _g_b_printf_busy;) {                                                                                    \
        }                                                                                                              \
        _g_b_printf_busy = true;                                                                                       \
        _g_printf(fmt, ##__VA_ARGS__);                                                                                 \
        _g_b_printf_busy = false;                                                                                      \
    }

#if KLIBC_LOG_LEVEL <= KLIBC_LOG_LEVEL_ALL && KLIBC_LOG_LEVEL >= KLIBC_LOG_LEVEL_DEBUG
#define _KLIBC_LOG_DEBUG(fmt, ...) _KLIBC_LOG_PRINTF(fmt, ##__VA_ARGS__)
#else
#define _KLIBC_LOG_DEBUG(fmt, ...)
#endif

#if KLIBC_LOG_LEVEL <= KLIBC_LOG_LEVEL_ALL && KLIBC_LOG_LEVEL >= KLIBC_LOG_LEVEL_INFO
#define _KLIBC_LOG_INFO(fmt, ...)         _KLIBC_LOG_PRINTF(fmt, ##__VA_ARGS__)
#define _KLIBC_LOG_INFO_NO_LOCK(fmt, ...) _g_printf(fmt, ##__VA_ARGS__)
#else
#define _KLIBC_LOG_INFO(fmt, ...)
#define _KLIBC_LOG_INFO_NO_LOCK(fmt, ...)
#endif

#if KLIBC_LOG_LEVEL <= KLIBC_LOG_LEVEL_ALL && KLIBC_LOG_LEVEL >= KLIBC_LOG_LEVEL_ERROR
#define _KLIBC_LOG_ERROR(fmt, ...) _KLIBC_LOG_PRINTF(fmt, ##__VA_ARGS__)
#else
#define _KLIBC_LOG_ERROR(fmt, ...)
#endif

#define _KLIBC_LOG_COLOR_BLACK  "30"
#define _KLIBC_LOG_COLOR_RED    "31"
#define _KLIBC_LOG_COLOR_GREEN  "32"
#define _KLIBC_LOG_COLOR_BROWN  "33"
#define _KLIBC_LOG_COLOR_BLUE   "34"
#define _KLIBC_LOG_COLOR_PURPLE "35"
#define _KLIBC_LOG_COLOR_CYAN   "36"
#define _KLIBC_LOG_COLOR(COLOR) "\033[0;" COLOR "m"
#define _KLIBC_LOG_BOLD(COLOR)  "\033[1;" COLOR "m"
#define _KLIBC_LOG_RESET_COLOR  "\033[m"
#define _KLIBC_LOG_COLOR_E      _KLIBC_LOG_COLOR(_KLIBC_LOG_COLOR_RED)
#define _KLIBC_LOG_COLOR_W      _KLIBC_LOG_COLOR(_KLIBC_LOG_COLOR_BROWN)
#define _KLIBC_LOG_COLOR_I      _KLIBC_LOG_COLOR(_KLIBC_LOG_COLOR_GREEN)
#define _KLIBC_LOG_COLOR_D
#define _KLIBC_LOG_COLOR_V

#define _KLIBC_LOG_FORMAT(letter, format)                                                                              \
    _KLIBC_LOG_COLOR_##letter #letter " (%" PRIu32 ") %s: " format _KLIBC_LOG_RESET_COLOR "\n"

#define KLIBC_LOG_PRINTF(level, format, ...)                                                                           \
    {                                                                                                                  \
        if (level <= KLIBC_LOG_DEBUG) {                                                                                \
            if (level == KLIBC_LOG_ERROR) {                                                                            \
                _KLIBC_LOG_ERROR(_KLIBC_LOG_FORMAT(E, format), _g_get_timestamp(), TAG, ##__VA_ARGS__);                \
            } else if (level == KLIBC_LOG_INFO) {                                                                      \
                _KLIBC_LOG_INFO(_KLIBC_LOG_FORMAT(I, format), _g_get_timestamp(), TAG, ##__VA_ARGS__);                 \
            } else {                                                                                                   \
                _KLIBC_LOG_DEBUG(_KLIBC_LOG_FORMAT(I, format), _g_get_timestamp(), TAG, ##__VA_ARGS__);                \
            }                                                                                                          \
        }                                                                                                              \
    }

#define KLIBC_LOG_HEXDUMP(level, title, buff, n_bytes_buff)                                                            \
    _klibc_log_hexdump(title, _g_get_timestamp(), TAG, buff, n_bytes_buff)

#define KLIBC_LOG_INIT(get_timestamp_function, printf_function)                                                        \
    {                                                                                                                  \
        _g_get_timestamp = get_timestamp_function;                                                                     \
        _g_printf        = printf_function;                                                                            \
    }

#if defined(__GNUC__) && __GNUC__ >= 7
#define ATTRIBUTE_FALLTHROUGH __attribute__((fallthrough))
#else
#define ATTRIBUTE_FALLTHROUGH ((void)0)
#endif

extern bool               _g_b_printf_busy;
extern get_timestamp_func _g_get_timestamp;
extern printf_func        _g_printf;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief
 *
 * @param title
 * @param ts
 * @param tag
 * @param buff
 * @param n_bytes_buff
 */
void _klibc_log_hexdump(const char *title, uint32_t ts, const char *tag, const uint8_t *buff, size_t n_bytes_buff);

#ifdef __cplusplus
}
#endif