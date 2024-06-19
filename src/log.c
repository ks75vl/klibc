// Copyright 2024 ks75vl
//
// Filename: src/log.c
//   Author: ks75vl
//  Created: 03/14/2024 21:19:36 +07:00

#include "klibc/log.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#include <ctype.h>
#include <stdbool.h>

#include "klibc/macro.h"

#define N_BYTES_PER_LINE 16

#ifdef _WIN32
CRITICAL_SECTION _g_critical_section;
#endif

bool               _g_b_printf_busy = false;
get_timestamp_func _g_get_timestamp = NULL;
printf_func        _g_printf        = NULL;

static inline char DEREF(_byte_to_hex(char DEREF(buff), uint8_t value)) {
    uint8_t lo = (value >> 0) & 0xf;
    uint8_t hi = (value >> 4) & 0xf;

    buff = SET_UINT8(buff, hi + (hi < 0xa ? 0x30 : 0x61 - 0xa));
    buff = SET_UINT8(buff, lo + (lo < 0xa ? 0x30 : 0x61 - 0xa));

    return buff;
}

void _klibc_log_hexdump(const char *title, uint32_t ts, const char *tag, const uint8_t *buff, size_t n_bytes_buff) {
    // 0x00000000   00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00   |................|
    char          hex[sizeof(size_t) * 2 + N_BYTES_PER_LINE * 4 + 12] = { 0 };
    const uint8_t DEREF(dump)                                         = NULL;
    size_t        n_bytes_dump                                        = 0;
    size_t        i                                                   = 0;
    char          DEREF(ptr)                                          = NULL;
    uint8_t       value                                               = 0;

#ifdef _WIN32
    EnterCriticalSection(REF(_g_critical_section));
#else
    for (; _g_b_printf_busy;) {
    }
#endif

    _g_b_printf_busy = true;

    _KLIBC_LOG_INFO_NO_LOCK(_KLIBC_LOG_FORMAT(I, "%s, length=0x%" PRIxMAX "(%" PRIdMAX ")"), ts, tag, title,
                            n_bytes_buff, n_bytes_buff);

    for (; n_bytes_buff;) {
        n_bytes_dump = n_bytes_buff > N_BYTES_PER_LINE ? N_BYTES_PER_LINE : n_bytes_buff;
        dump         = buff;
        ptr          = CAST_FROM_TYPE(hex, char);

        // ptr += sprintf(ptr, "%" PRIxPTR " ", buff);
        ptr = SET_UINT16(ptr, 0x7830);
        for (i = 0; i < sizeof(size_t); i++) {
            value = CAST_FROM_TYPE(REF(buff), uint8_t)[sizeof(size_t) - 1 - i];
            ptr   = _byte_to_hex(ptr, value);
        }
        ptr = SET_UINT16(ptr, 0x2020);

        for (i = 0; i < N_BYTES_PER_LINE; i++) {
            ptr = ((i & 7) == 0) ? SET_UINT8(ptr, 0x20) : ptr;
            ptr = (i < n_bytes_dump) ? _byte_to_hex(ptr, dump[i]) : SET_UINT16(ptr, 0x2020);
            ptr = SET_UINT8(ptr, 0x20);
        }

        ptr = SET_UINT32(ptr, 0x7c202020);
        for (i = 0; i < n_bytes_dump; i++) {
            ptr = SET_UINT8(ptr, isprint((int)dump[i]) ? dump[i] : 0x2e);
        }
        for (i = n_bytes_dump; i < 16; i++) {
            ptr = SET_UINT8(ptr, 0x20);
        }
        ptr = SET_UINT8(ptr, 0x7c);

        _KLIBC_LOG_INFO_NO_LOCK(_KLIBC_LOG_FORMAT(I, "|  %s"), ts, tag, hex);

        buff += n_bytes_dump;
        n_bytes_buff -= n_bytes_dump;
    }

    _g_b_printf_busy = false;

#ifdef _WIN32
    LeaveCriticalSection(REF(_g_critical_section));
#else
#endif
}