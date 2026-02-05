cmake_minimum_required(VERSION 3.20)
project(coding_test)

set(CMAKE_CXX_STANDARD 17)

# 아래 줄을 플러그인이 찾아서 파일 경로만 계속 갈아끼울 것입니다.
# 만약 에러가 나면 이 아래에 중복된 줄이 생겼는지 확인하고 지워주면 됩니다.
add_executable(Out sdc/BOJ_sdc/BOJ14500.cpp)
