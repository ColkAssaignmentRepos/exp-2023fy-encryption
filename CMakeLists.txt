cmake_minimum_required(VERSION 3.25)
project(exp_2023fy_encryption C)

set(CMAKE_C_STANDARD 17)

add_executable(
        exp_2023fy_encryption

        src/main.c
        src/aes128.h
        src/keyexpand.c
        src/multiply.c
        src/inverse.c)
