cmake_minimum_required(VERSION 3.20) # 본인의 CLion 버전이나 환경에 맞게 조절 가능
project(coding_test)

# C++ 표준 설정 (최신 문법을 위해 17 또는 20 추천)
set(CMAKE_CXX_STANDARD 17)

# ==========================================
# 여기에 실행하고 싶은 파일 이름만 적으세요!
# ==========================================
set(TARGET_FILE "0x09_BFS/boj1926.cpp")

# 타겟 이름을 "OUT"으로 고정하여 생성
add_executable(OUT workbook/BOJ1238.cpp)
