#!/bin/bash

gcc ./tigr/tigr.c monopoly.c -o compilado/monopoly -I./tigr -lGLU -lGL -lX11
./compilado/monopoly

for i in $(seq 3 -1 1); do
    echo -e "El archivo de ejecucion se borrara en $i"
    sleep 1
    done;

rm compilado/monopoly
echo -e "Se ha borrado y no queda ningun rastro.\n"

