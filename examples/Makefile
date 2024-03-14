# Copyright 2024 ks75vl
# 
# Filename: examples/Makefile
#   Author: ks75vl
#  Created: 03/14/2024 21:55:54 +07:00

all: lib
	gcc -o example.o -I../include -DKLIBC_LOG_LEVEL_ALL=1 -c example.c
	gcc -o example example.o log.o

lib:
	gcc -o log.o -I../include -c ../src/log.c