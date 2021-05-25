cmake_minimum_required(VERSION 3.19)
project(L1_S2_Qwirkle C)

set(CMAKE_C_STANDARD 99)

add_executable(L1_S2_Qwirkle main.c qwirkle.c qwirkle.h color.c color.h uni_random.h player.c player.h sha256.c sha256.h unsigned_char_string.c unsigned_char_string.h)