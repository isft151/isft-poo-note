#!/bin/bash

## Compilo código objeto
g++ -Wall -std=c++11 -c ./src/AudioPlayer.cpp -o AudioPlayer.o -I./include
g++ -Wall -std=c++11 -c main.cpp -o main.o -I./include

## Compilo el Binario
g++ -Wall -std=c++11 AudioPlayer.o main.o -o ./cpplayer.bin -I./include ./lib/libsfml-system.so.2.5 ./lib/libsfml-audio.so.2.5
# g++ -Wall -std=c++11 AudioPlayer.o main.o -o ./cpplayer.bin -I./include -L./lib -lsfml-system -lsfml-audio

## Permisos de Ejecución para el binario
chmod +x ./cpplayer.bin

## Limpio los códigos objeto
rm ./*.o

## Exporto un valor nuevo para la variable golbal de sistema LD_LIBRARY_PATH para que encuentre las bibliotecas
## en el directorio local
export LD_LIBRARY_PATH='./lib/'

## Ejecuto el binario:
./cpplayer.bin