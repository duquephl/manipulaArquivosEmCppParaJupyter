/* UNIFEI - Universidade Federal de Itajub√° - Campus Itabira
Nome: Natan Ferreira Rosa de Jesus Vaz R.A: 2020019620
      Pedro Henrique de Lima Duque R.A: 2020027480 */
      
//Bibliotecas
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <windows.h>
#include "library.h"

using namespace std;

//Prototipos das funcoes
void carregaArquivo(ifstream &fileStream, plano p[], int &idx);
void lerArquivo(plano p[], int &idx);
plano carregaItemPorLinha(stringstream &line, plano &p);
void escreveTudoNoArquivo(ofstream &ofs, plano p[], int n);
void escreveArquivo(plano p[], int &j);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int idx = 0;
    
    //Saida agradavel para o usuario
    cout <<txtMagenta<<"Inicializando!!!\n"<<txtPadrao;

    //Condicao para a funcao da entrada de arquivo
    if (arquivoExiste(entrada))
    {
        //funcao da leitura passada e o indice
        lerArquivo(p, idx);
        cout <<txtVerde<<"Arquivo "<< entrada << " encontrado.\n"<<txtPadrao;
    }
    else
    {
        cout << "Arquivo " << entrada << " ainda n„o existe, Ok!";
    }
    cout <<txtAzul<<"Realizando os calculos da funÁ„o:"<<txtVermelho<<" \nf(x) = x.cos(x).sin(x)\n"<<txtPadrao;
    
    //Laco de repeticao com a equacao imbutida
    for (int j = 0; j < n; j++)
    {
        float x = p[j].x;
        p[j] .y= x * cos(x) * sin(x);
    }

    //Gera o arquivo 2 e gera Saida agradavel para o usuario
    escreveArquivo(p, idx);
    cout <<txtVerde<<"OperaÁ„o concluÌda com sucesso!!!\nAtÈ a Proxima.\n"<<txtPadrao;

    return 0;
}

//funcao da geracao do arquivo 2 com base do vetor e indice
void carregaArquivo(ifstream &fileStream, plano p[], int &idx)
{
    //Determina variaveis strings para a manipucao
    string line;
    stringstream ss;
    plano pla;
    while (getline(fileStream, line))
    {
        ss.str(line);
        //Atraves do vetor e seu indice, vai carregando as linhas do arquivo atravess da Funcao e armazena no struct de vetor
        p[idx] = carregaItemPorLinha(ss, pla);
        idx++;
    }
}

//verifica se o arquivo existe e caso existir ele ira ler o arquivo
void lerArquivo(plano p[], int &idx)
{
    ifstream file;
    if (abrirArquivo(file, entrada))
    {
        //carrega os arquivos  a condidicao e depois para de executar
        carregaArquivo(file, p, idx);
        file.close();
    }
    else
    {
        cout << "Erro, arquivo: " << entrada << " n„o pode ser aberto para leitura.\n";
    }
}

//funcao que verifica linha por linha
plano carregaItemPorLinha(stringstream &line, plano &p)
{
    string inread;
    //Conversor de string para float, lembrando que ha um caractere de separacao e √É∆í√Ü‚Äô√É‚Äö√Ç¬© passado como parametro
    lerLinhaFloat(line, p.x, separador);

//Apos isto retorna ao struct vetor
    return p;
}

//Funcao de saida de dados atraves do laco de repeticao. Obs: Tambem acrescenta o caractere de separacao
void escreveTudoNoArquivo(ofstream &ofs, plano p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        ofs << p[i].y << separador <<"\n";
    }
}

//Funcao passada o struct vetor e o indice do for como parametro
void escreveArquivo(plano p[], int &j)
{
    //Saida do arquivo e entrando na condicao
    ofstream file;
    if (abrirArquivo(file, saida))
    {
        escreveTudoNoArquivo(file, p, j);

        //Fecha o arquivo apos a operacao para que o documento nao se corrompa
        file.close();
    }
    else
    {
        cout << "Erro, arquivo: " << saida << " n„o pode ser aberto para escrita.\n";
    }
}
