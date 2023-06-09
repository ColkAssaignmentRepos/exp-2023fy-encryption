//
// Created by Manaki ITO on 2023/06/09.
//

#include "aes128.h"

unsigned char Inverse(unsigned char b) {
    unsigned char temp;

    // 0x00 は逆数を持たない
    if (b == 0x00) {
        return 0;
    }

    temp = b;

    // for i = 1 to 253
    for (int i = 1; i < 254; i++) {
        temp = Multiply(temp, b);
    }

    return temp;
}
