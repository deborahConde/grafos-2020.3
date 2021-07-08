#!/bin/bash

# Variaveis usadas
# Alterar o local onde os arquivos estão armazanados
path="/home/romulo/www/Grafos/arquivos" 
inputFile=$path"/inputFile.txt"
outputFile=$path"/outputFile.txt"

printf "g++ *.c* -o grafos-2021-1 \n"
g++ *.c* -o grafos-2021-1
 
 printf "Executando o codigo ... \n"
./grafos-2021-1 ${inputFile} ${outputFile} 0 1 0


# ./grafos-2021-1 "/home/romulo/www/Grafos/arquivos/inputFile.txt" "/home/romulo/www/Grafos/arquivos/outputFile.txt" 0 0 0

