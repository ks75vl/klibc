// Copyright 2024 ks75vl
//
// Filename: examples/log.c
//   Author: ks75vl
//  Created: 03/14/2024 21:47:16 +07:00

#include <stdio.h>

#include "klibc/log.h"
#include "klibc/macro.h"

MODULE_LOG_TAG("example");

static size_t get_timestamp(void) { return 0; }

//------------------------------------------------------------
//-----------       Created with 010 Editor        -----------
//------         www.sweetscape.com/010editor/          ------
//
// File    : Untitled1
// Address : 0 (0x0)
// Size    : 1024 (0x400)
//------------------------------------------------------------
unsigned char hexData[1024] = {
    0xE6, 0x3C, 0xA6, 0x01, 0x4B, 0xEE, 0xA4, 0x42, 0xBB, 0x70, 0x11, 0xF1, 0xDD, 0x78, 0x2D, 0xB2, 0xFC, 0x60, 0x78,
    0x21, 0x43, 0x04, 0x6D, 0x45, 0x5B, 0x90, 0x8C, 0x56, 0xAD, 0xD1, 0xDE, 0x44, 0xB6, 0xE0, 0xC9, 0x0E, 0x6B, 0xF9,
    0x85, 0xD3, 0x02, 0xFE, 0x1E, 0x70, 0xCD, 0xBD, 0x4D, 0x7E, 0x72, 0xB2, 0x63, 0xAA, 0x0A, 0x8F, 0x67, 0xFC, 0x05,
    0xDF, 0xAE, 0x70, 0x0D, 0x09, 0xD3, 0x8D, 0x87, 0xCC, 0xC0, 0x2E, 0x4E, 0x0E, 0x14, 0x0B, 0x44, 0x29, 0x3C, 0xCD,
    0x22, 0xF6, 0x22, 0x2C, 0xAF, 0x84, 0x83, 0x52, 0x82, 0x5F, 0x03, 0x6D, 0xEA, 0xC4, 0xA1, 0x46, 0x67, 0x24, 0x44,
    0xA7, 0x09, 0x62, 0xBE, 0x5C, 0x04, 0x64, 0xBF, 0x18, 0x52, 0x6E, 0xE3, 0xDF, 0xB3, 0x61, 0xA4, 0x07, 0xAF, 0x6F,
    0xAB, 0xDD, 0x16, 0x55, 0x1F, 0xC2, 0x43, 0xA7, 0x91, 0x1B, 0x28, 0x7E, 0x1C, 0x14, 0xD6, 0xC2, 0xEA, 0x56, 0x51,
    0xB4, 0xBF, 0x5B, 0xD9, 0x8A, 0x90, 0xF7, 0xC8, 0x34, 0x30, 0xC6, 0x80, 0x07, 0x17, 0x19, 0xA6, 0xDF, 0xFC, 0x57,
    0x89, 0xC6, 0x20, 0x99, 0xF3, 0xAF, 0x80, 0xC6, 0x41, 0x84, 0x9F, 0x2B, 0x6C, 0x1B, 0xBF, 0x45, 0x7D, 0x68, 0x55,
    0xAD, 0x76, 0x49, 0xC5, 0x35, 0x92, 0xF9, 0xEF, 0x5C, 0xBB, 0x38, 0x43, 0x11, 0xBF, 0x26, 0xE0, 0x27, 0x31, 0xD7,
    0xE9, 0xD4, 0x82, 0x7D, 0xF9, 0x7E, 0xD0, 0xAB, 0xB7, 0xE7, 0x88, 0x6A, 0x3C, 0xBB, 0xDA, 0xCB, 0x56, 0xDF, 0x65,
    0x77, 0x8B, 0x23, 0xD6, 0x6F, 0x91, 0x81, 0x02, 0xE9, 0x60, 0xD0, 0x7A, 0x14, 0xCC, 0xD5, 0xDD, 0x0E, 0xB9, 0x02,
    0xD1, 0x64, 0x90, 0xE9, 0x34, 0xEE, 0xFB, 0x2A, 0x13, 0x13, 0x5A, 0x22, 0xA6, 0x31, 0x9E, 0x08, 0xD6, 0x99, 0xA4,
    0x02, 0x16, 0x73, 0xC6, 0x4B, 0x36, 0xD0, 0x22, 0x6E, 0x55, 0x1F, 0x94, 0x75, 0x84, 0x58, 0x6A, 0xF7, 0xA7, 0x9B,
    0x9A, 0xE9, 0x5D, 0x1D, 0x3C, 0xA6, 0xC9, 0x73, 0x1D, 0x88, 0x94, 0xC0, 0x9A, 0xCD, 0x21, 0x6F, 0xD7, 0xF3, 0x82,
    0xC0, 0x3B, 0x22, 0x1B, 0x60, 0x77, 0x9F, 0x13, 0xF2, 0x06, 0x95, 0x56, 0x66, 0x67, 0xDA, 0x78, 0xA7, 0xC6, 0xF5,
    0xD0, 0x04, 0xDF, 0xA0, 0x70, 0x15, 0x9A, 0x71, 0x05, 0xAA, 0xF5, 0xCE, 0x78, 0x75, 0x59, 0x42, 0xAF, 0x2E, 0x68,
    0xA2, 0x4E, 0x76, 0x22, 0x30, 0x75, 0xCE, 0x08, 0x85, 0xC9, 0x93, 0x8A, 0xF6, 0x9D, 0x95, 0x01, 0x9E, 0x55, 0xC4,
    0x54, 0xAD, 0x96, 0x51, 0xAE, 0x2E, 0xD0, 0xD9, 0x84, 0x08, 0xAC, 0x9B, 0x09, 0x10, 0xF2, 0x48, 0xC3, 0xA6, 0xAD,
    0x76, 0xE3, 0x77, 0x9C, 0x04, 0x7A, 0x9A, 0x44, 0x02, 0xCF, 0xBF, 0xD8, 0xCE, 0xE5, 0xFA, 0x69, 0xAF, 0x0F, 0x82,
    0x6F, 0xBF, 0xE2, 0x73, 0x32, 0x63, 0x06, 0xB8, 0x14, 0x4F, 0x64, 0xAB, 0x48, 0x6B, 0x25, 0x9C, 0x5E, 0xB2, 0x9F,
    0x79, 0x2A, 0xC1, 0x39, 0x00, 0xCB, 0x82, 0xF7, 0xF4, 0xD8, 0xE7, 0x14, 0x79, 0xE1, 0x11, 0x74, 0x63, 0xA6, 0x43,
    0x2B, 0xEC, 0xBF, 0x93, 0x5C, 0xEB, 0x59, 0x4A, 0xBA, 0xCD, 0x4D, 0x5A, 0x93, 0x26, 0x06, 0x04, 0x4B, 0xD2, 0x94,
    0x0D, 0x18, 0x51, 0xF7, 0x60, 0xBC, 0x9A, 0xCF, 0xEF, 0x46, 0x5E, 0x33, 0xA5, 0xC1, 0x8A, 0x4B, 0xEC, 0x96, 0x49,
    0x20, 0xFE, 0x48, 0x8D, 0x55, 0x40, 0xF5, 0xCD, 0x29, 0xAF, 0xA0, 0x3C, 0xA9, 0xA0, 0xC1, 0xDE, 0x3D, 0x2A, 0xD7,
    0x33, 0xA9, 0x35, 0xC2, 0x21, 0x0B, 0x06, 0x9D, 0xC4, 0x06, 0x11, 0xAC, 0xC6, 0xEA, 0xAF, 0x3E, 0x64, 0xBC, 0x2D,
    0x04, 0xCB, 0x25, 0xD0, 0x19, 0xD9, 0xF3, 0xE7, 0x26, 0x15, 0xCA, 0x81, 0x5A, 0x1F, 0xE9, 0x5B, 0x42, 0x59, 0xD9,
    0xCF, 0x30, 0x07, 0xD6, 0xFB, 0x8D, 0xA8, 0xB6, 0x84, 0x46, 0xF6, 0xCF, 0x51, 0x8A, 0xFB, 0x74, 0x40, 0x04, 0x80,
    0xCD, 0x31, 0x91, 0x84, 0x75, 0x0A, 0x8C, 0x43, 0x82, 0xCE, 0x9B, 0x91, 0x30, 0x89, 0xF4, 0xAA, 0xEB, 0x1E, 0x3D,
    0x2E, 0x95, 0x92, 0xAD, 0x35, 0xA1, 0xC3, 0xB9, 0x81, 0x01, 0xD2, 0x11, 0xEF, 0xAF, 0xBF, 0x00, 0x58, 0x5F, 0xB6,
    0xE7, 0x46, 0xC3, 0x23, 0xDB, 0x92, 0xB8, 0xF0, 0xF2, 0x6E, 0x27, 0x7E, 0x4E, 0x88, 0xAA, 0x6A, 0x74, 0x15, 0xC1,
    0x6E, 0xEB, 0x98, 0xE6, 0x63, 0xE9, 0xDB, 0x2A, 0xA7, 0x5C, 0x07, 0x11, 0x13, 0xD2, 0xAE, 0x62, 0x1B, 0xA8, 0xD1,
    0xDF, 0x2E, 0x83, 0x18, 0x41, 0x5E, 0x3B, 0x0A, 0x85, 0x3B, 0xF7, 0xAD, 0x3A, 0x8D, 0x78, 0x45, 0x87, 0xF1, 0xB8,
    0x1F, 0x2D, 0x1B, 0x8A, 0x45, 0x23, 0x92, 0x36, 0x5D, 0x00, 0x3B, 0xF8, 0x21, 0x40, 0xE0, 0x25, 0xA1, 0xFB, 0x6D,
    0xC8, 0xDF, 0xE9, 0x06, 0xAE, 0x2B, 0x16, 0x71, 0x9D, 0x4F, 0xEE, 0x43, 0x66, 0x65, 0xD8, 0xD2, 0xC4, 0x67, 0xCE,
    0xA5, 0x03, 0x9B, 0x44, 0x80, 0x1E, 0x93, 0x30, 0x18, 0xBF, 0x02, 0x0F, 0x84, 0x01, 0x45, 0x4B, 0xA1, 0x2A, 0xB9,
    0x9B, 0x34, 0x48, 0x41, 0xC7, 0xE0, 0x76, 0xDA, 0x90, 0x1E, 0xA0, 0x2B, 0x90, 0x20, 0x70, 0x81, 0x7B, 0xC3, 0x55,
    0x4B, 0x43, 0x31, 0xE3, 0xF1, 0x11, 0x89, 0xBF, 0x83, 0x00, 0xFE, 0x34, 0x6C, 0x4B, 0xD0, 0x32, 0xE7, 0xA4, 0x5D,
    0x5B, 0xF2, 0x3A, 0xAC, 0xC8, 0x17, 0xE8, 0x49, 0xB9, 0x68, 0x57, 0xA4, 0x65, 0xB3, 0xFE, 0x5A, 0xAB, 0xF8, 0x8A,
    0x22, 0x44, 0xBD, 0x80, 0x92, 0xA0, 0x91, 0x6F, 0xE1, 0x60, 0x8C, 0x85, 0xF2, 0x1E, 0x6D, 0x6F, 0x27, 0xD3, 0x3B,
    0xD1, 0x94, 0xC9, 0xC8, 0x79, 0x8E, 0x99, 0xB8, 0xBE, 0x62, 0xA7, 0x4E, 0xE7, 0x67, 0x35, 0x3B, 0x59, 0xA0, 0xE5,
    0x98, 0x11, 0xD0, 0x54, 0xB1, 0x5A, 0xD0, 0xB9, 0xA9, 0xA4, 0x95, 0x14, 0x73, 0xB2, 0xB8, 0x2C, 0x7E, 0x2F, 0xCB,
    0x6F, 0x43, 0x47, 0xB6, 0xA2, 0x57, 0xF4, 0x0C, 0x8E, 0x71, 0xD4, 0x27, 0xB1, 0xB2, 0x1C, 0xF7, 0xA1, 0x79, 0x65,
    0xAE, 0xD4, 0x3A, 0xE8, 0x2C, 0x03, 0x39, 0xC1, 0xCC, 0x62, 0x42, 0x17, 0x08, 0xB8, 0xD6, 0x34, 0x9B, 0x7F, 0xFC,
    0xC0, 0xFA, 0xD4, 0x24, 0x27, 0x79, 0x6C, 0x0D, 0x1B, 0xEB, 0xC4, 0xF2, 0xE5, 0xBC, 0xEF, 0xC2, 0x37, 0x73, 0x79,
    0xC0, 0x4D, 0x06, 0xF7, 0xF1, 0x88, 0xEC, 0x43, 0x45, 0x73, 0x1F, 0x39, 0x68, 0xB7, 0x6C, 0xB8, 0xB1, 0x4D, 0x01,
    0x62, 0x75, 0x23, 0x41, 0x59, 0x55, 0x9F, 0xBA, 0x5B, 0x90, 0xC9, 0x7E, 0x90, 0x1B, 0x92, 0xF1, 0xBC, 0x78, 0x15,
    0xC5, 0xC3, 0x70, 0x20, 0x18, 0x25, 0x8F, 0xBC, 0x88, 0xCC, 0xC3, 0x2D, 0xEB, 0x34, 0xEC, 0x40, 0xB5, 0x74, 0xE4,
    0xA5, 0x3F, 0x6C, 0x95, 0xF3, 0xC7, 0x14, 0xCD, 0xD0, 0x5D, 0xCD, 0xA1, 0xE5, 0x1F, 0x04, 0x31, 0x27, 0xB0, 0xAE,
    0x88, 0xC4, 0xA2, 0x15, 0x63, 0xD8, 0x79, 0x7A, 0x86, 0x10, 0x3A, 0xD6, 0xA9, 0xFF, 0x47, 0xCC, 0xC4, 0x25, 0xA5,
    0x97, 0xE6, 0xFB, 0xD4, 0xED, 0xDE, 0x9C, 0xFC, 0xDD, 0x93, 0x00, 0x19, 0xEB, 0xBE, 0x50, 0x88, 0x02, 0x96, 0x69,
    0x49, 0xA7, 0x3B, 0xC1, 0xDC, 0xDF, 0x9D, 0x67, 0x9D, 0x44, 0x6A, 0x3A, 0xED, 0x01, 0xBB, 0xBC, 0x60, 0xDD, 0x2D,
    0xD4, 0x25, 0x44, 0x06, 0x6A, 0x12, 0xBA, 0x2E, 0x79, 0xE5, 0xB0, 0x41, 0xB4, 0x55, 0x2B, 0x84, 0xDD, 0x08, 0x07,
    0xDC, 0xD8, 0xE3, 0xEC, 0x91, 0x48, 0x30, 0xFE, 0x11, 0xBF, 0x70, 0xC0, 0xD0, 0xF4, 0x16, 0xF2, 0xF3
};

int main() {

    KLIBC_LOG_INIT(get_timestamp, printf);

    KLIBC_LOG_PRINTF(KLIBC_LOG_INFO, "hello from example");
    KLIBC_LOG_HEXDUMP(KLIBC_LOG_INFO, "sample data", hexData, sizeof(hexData));

    return 0;
}