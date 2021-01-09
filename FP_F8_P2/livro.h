/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   livro.h
 * Author: pedro
 *
 * Created on 28 de dezembro de 2020, 20:54
 */

#ifndef LIVRO_H
#define LIVRO_H

#define MAX_LIVROS              50
#define MAX_AUTORES             5

#define ERRO_LISTA_VAZIA        "A lista está vazia."
#define ERRO_LISTA_CHEIA        "A lista está cheia."

#define MAX_COMP_STRINGS        50
#define MSG_OBTER_TITULO        "Insira o titulo do livro: "
#define MSG_OBTER_NOME_EDITORA  "Insira o nome da editora: "
#define MSG_OBTER_MORADA        "Insira a morada da editora: "

#define MAX_IBSN_LIVRO          17
#define MSG_OBTER_IBSN          "Insira o IBSN do livro: "

#define MIN_DIA                 0
#define MAX_DIA                 31
#define OBTER_DIA_NASC          "Insira o dia da publicação: "

#define MIN_MES                 1
#define MAX_MES                 12
#define OBTER_MES_NASC          "Insira o mês da publicação: "

#define MIN_ANO                 1990
#define MAX_ANO                 2021
#define OBTER_ANO_NASC          "Insira o ano da publicaçãos: "

typedef struct{
    int dia,mes,ano;
} Data;

typedef struct{
    char pagWeb[MAX_COMP_STRINGS],nome[MAX_COMP_STRINGS];
    Data dataNas;
} Autor;

typedef struct{
    char morada[MAX_COMP_STRINGS],nome[MAX_COMP_STRINGS];
}Editora;

typedef enum {FICCAO, TECNICO,ROMANCE,ESTUDO} Tipo;

typedef struct{
    char ISBN[MAX_IBSN_LIVRO],titulo[MAX_COMP_STRINGS];
    Editora infoEditora;
    Data dataPub;
    Autor autores[MAX_AUTORES];
    Tipo tipos;
} Livro;

typedef struct {
    int contador;
    Livro livros[MAX_LIVROS];
} Livros;

int inserirLivro(Livros *livros);

void listarLivros(Livros livro);

void carregarLivro(Livros *livros, char* ficheiro);

#endif /* LIVRO_H */

