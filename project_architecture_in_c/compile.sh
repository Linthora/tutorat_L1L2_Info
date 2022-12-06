#!/bin/bash

gcc -c main.c math.c
gcc math.o main.o -o exe
