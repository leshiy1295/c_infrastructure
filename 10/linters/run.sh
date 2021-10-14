#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
#cppcheck project --enable=all --inconclusive --error-exitcode=1 -I project/include

print_header "RUN clang-tidy"
#clang-tidy project/**/* -- -Iproject/include

print_header "RUN cpplint.py"
python3 ./linters/cpplint/cpplint.py --extensions=c project/include/* project/src/*

print_header "SUCCESS"