#!/bin/bash
g++ main.cpp ../../glad.c -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl && ./a.out