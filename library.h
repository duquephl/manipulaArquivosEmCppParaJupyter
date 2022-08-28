/* UNIFEI - Universidade Federal de Itajubá - Campus Itabira
Nome: Natan Ferreira Rosa de Jesus Vaz R.A: 2020019620
      Pedro Henrique de Lima Duque R.A: 2020027480 */

#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#endif

//Bibliotecas
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;

//Constantes de cores que usamos para uma saida agradavel para o Usuario
const string txtVermelho = "\033[1;31m";
const string txtVerde = "\033[1;32m";
const string txtAzul = "\033[1;34m";
const string txtMagenta = "\033[1;35m";
const string txtPadrao = "\033[0m";

//Constantes do programa
const string entrada = "Arq01.txt"; //Arquivo para entrada de dados
const string saida = "Arq02.txt";   //Arquivo para saida de dados
const char separador = ' ';         //Caracter separador de dados no arquivo
const int n = 500;                  //Constante dos numeros a ser carregado 

//Declaracao das Variavel que guardara os valores de X e Y
struct plano
{
    float x;
    float y;
};

//Struct vetor
plano p[n];

//Verifica a existencia do arquivo
bool arquivoExiste(const std::string &name)
{
    return (access(name.c_str(), F_OK) != -1);
}

//Comando para abrir o arquivo
bool abrirArquivo(ifstream &ifs, const std::string &name)
{
    ifs.open(name.c_str());
    return ifs.is_open();
}

//Comando para abrir o arquivo
bool abrirArquivo(ofstream &ifs, const std::string &name)
{
    ifs.open(name.c_str());
    return ifs.is_open();
}

//Converte o conteudodo do arquivo de string para float
void lerLinhaFloat(stringstream &line, float &field, char separator)
{
    string inread;
    getline(line, inread, separator);
    field = (float)strtod(inread.c_str(), NULL);
}
