//
// Created by Manaki ITO on 2023/06/23.
//

#include <printf.h>
#include "aes128.h"


int main() {
    unsigned char res;
    unsigned char factor;

    // ユーザーに factor を入力させる ( 形式は 0x?? )
    printf("Factor: ");
    scanf("%x", &factor);

    printf("unsigned mbox%02x[256] = {", factor);

    for (int b = 0; b < 256; b++) {
        res = Multiply(b, factor);

        printf("0x%02x", res);

        if (b != 255) {
            printf(", ");
        }
    }

    printf("};\n");
}
