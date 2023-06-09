//
// Created by Manaki ITO on 2023/06/09.
//

#include "aes128.h"


unsigned char Multiply(unsigned char x, unsigned char y) {
    // z = 0
    unsigned char z = 0;

    // until y == 0
    while (y != 0x00) {
        // if y の bit 0 が 1 then
        if (y & 0x01) {
            // z = z xor x
            z ^= x;
        }

        // y を 1 bit 右シフト
        y >>= 1;

        // if x の bit 7 が 1 then
        if (x & 0x80) {
            // x = x << 1
            x <<= 1;
            // x = x xor 0x1b
            x = x ^ 0x1b;
        } else {
            // x を 1 bit 左シフト
            x <<= 1;
        }
    }
    return z;
}
