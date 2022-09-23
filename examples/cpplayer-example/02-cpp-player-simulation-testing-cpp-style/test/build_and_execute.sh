#!/bin/bash

## Compilo código objeto
g++ -Wall -std=c++11 -c ../src/AudioPlayer.cpp -o AudioPlayer.o -I../include

g++ -Wall -std=c++11 -c AudioPlayerUnitTest.cpp -o AudioPlayerUnitTest.o \
-I../include -I../include/vendors/catch

## Compilo el Binario
g++ -Wall -std=c++11 AudioPlayer.o AudioPlayerUnitTest.o -o AudioPlayerUnitTest.bin

## Permisos de Ejecución para el binario
chmod +x ./AudioPlayerUnitTest.bin

## Limpio los códigos objeto
rm ./*.o

## Ejecuto el binario:
./AudioPlayerUnitTest.bin