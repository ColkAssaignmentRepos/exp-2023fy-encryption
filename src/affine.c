//
// Created by Manaki ITO on 2023/06/09.
//

#include "aes128.h"

#define N 8


unsigned char exorBits(unsigned char data) {
    unsigned char result = 0;
    for (int i = 0; i < 8; ++i) {
        result ^= (data >> i) & 1;
    }
    return result;
}


unsigned char Affine(unsigned char b) {
    // [b0, b1, ..., b7] に対してかかる係数
    // 最下位ビットから順に 0 であることに注意
    // ( factor[][] * b[] )
    unsigned char factor = 0b11110001;
    // factor[][] * b[] の結果
    unsigned char temp = 0;
    // 最後に足す行列
    const unsigned char constant = 0b01100011;
    // 結果
    unsigned char result;

    for (int i = 0; i < N; i++) {
        // factor & b の各 bit の exor をとって temp の i bit 目に代入する
        temp ^= exorBits(factor & b) << i;

        // factor を 1 bit 左シフトする
        // あふれた bit は捨てないでサイクリックに右に戻す
        factor = (factor << 1) | ((factor >> (N - 1)) & 1);
    }

    // 最後に定数を足す
    result = temp ^ constant;

    return result;
}
