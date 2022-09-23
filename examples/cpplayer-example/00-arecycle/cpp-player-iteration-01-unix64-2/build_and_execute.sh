#!/bin/bash

## Compilo el Binario
g++ -Wall -std=c++11 main.cpp -o ./cpplayer.bin -I./include ./lib/libsfml-system.so.2.5 ./lib/libsfml-audio.so.2.5

## Permisos de Ejecución para el binario
chmod +x ./cpplayer.bin

## Exporto un valor nuevo para la variable golbal de sistema LD_LIBRARY_PATH para que encuentre las bibliotecas
## en el directorio local
export LD_LIBRARY_PATH='./lib/'

## Ejecuto el binario:
./cpplayer.bin