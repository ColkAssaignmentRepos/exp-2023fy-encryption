//
// Created by Manaki ITO on 2023/06/23.
//
// 事前計算プログラム

#include <stdio.h>

#include "aes128.h"


int main() {
    unsigned char temp;
    unsigned char res;

    printf("unsigned sbox[256] = {");

    for (int b = 0; b < 256; b++) {
        temp = Inverse(b);
        res = Affine(temp);

        printf("0x%02x", res);

        if (b != 255) {
            printf(", ");
        }
    }

    printf("};\n");
}
