#!/bin/bash

# Variaveis usadas
path="/home/romulo/www/Grafos/arquivos"
inputFile=$path"/inputFile.txt"
outputFile=$path"/outputFile.txt"

printf "g++ *.c* -o grafos-2021-1 \n"
./script.sh
 
 printf "Executando o codigo ... \n"
./grafos-2021-1 ${inputFile} ${outputFile} 0 0 0


# ./grafos-2021-1 "/home/romulo/www/Grafos/arquivos/inputFile.txt" "/home/romulo/www/Grafos/arquivos/outputFile.txt" 0 0 0

