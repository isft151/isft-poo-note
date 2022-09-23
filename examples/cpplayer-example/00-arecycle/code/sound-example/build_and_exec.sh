#!/bin/bash

g++ -Wall -std=c++11 Sound.cpp -o ./sound.bin -I./include -L./lib -lsfml-system -lsfml-audio
chmod +x ./sound.bin

export LD_LIBRARY_PATH='./lib/'
./sound.bin
