#!/bin/bash

## Compilo código objeto
g++ -Wall -std=c++11 -c ./src/AudioPlayer.cpp -o AudioPlayer.o -I./include
g++ -Wall -std=c++11 -c main.cpp -o main.o -I./include

## Compilo el Binario
g++ -Wall -std=c++11 AudioPlayer.o main.o -o ./cpplayer.bin -I./include 

## Permisos de Ejecución para el binario
chmod +x ./cpplayer.bin

## Limpio los códigos objeto
rm ./*.o

## Ejecuto el binario:
./cpplayer.bin