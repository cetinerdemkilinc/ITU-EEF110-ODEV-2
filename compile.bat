@echo off
gcc -g main.c student.c -o main -Wpedantic -Wextra  -Wall -Warray-bounds -Wreturn-type  -Werror
