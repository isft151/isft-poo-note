#!/bin/bash
##g++ -Wall -std=c++11 -I./include ./lib/libsfml-system.so.2.5 ./lib/libsfml-audio.so.2.5 Sound.cpp -o ./sound.bin
g++ -Wall -std=c++11 Sound.cpp -o ./sound.bin -I./include -L./lib -lsfml-system -lsfml-audio


