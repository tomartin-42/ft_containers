#!/bin/bash
clang++ -Wall -Wextra -Werror -DFT -std=c++98 main.cpp test*.cpp -o a.out && clang++ -Wall -Wextra -Werror -DSTD -std=c++98 main.cpp test*.cpp -o b.out;
./a.out > a ; ./b.out > b ; diff -y a b > deepthought;
rm a a.out b b.out
cat deepthought | grep '|'
