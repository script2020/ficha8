/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>

#include "livro.h"
#include "editora.h"
#include "input.h"
#include "logs.h"

#define LOGS_FILE "logs.txt"
#define LIVROS_DB_FILE "livros.bin"
/*
 * 
 */

int main(){
    int op;
    
    Livros livros = {.contador = 0};
    
    void carregarLivro(&livros, LIVROS_DB_FILE);
    
    do{
        puts("BIBLIOTECA - BASE DE DADOS");
        puts("-----------------");
        puts("1 - Inserir livro");
        puts("2 - Listar livros");
        puts("3 - Listar editoras");
        puts("4 - Listar autores");
        puts("0 - Sair");
        puts("-----------------");
        
        printf("\Nº Livros: %d/%d", livros.contador, MAX_LIVROS);

        puts("Insira a sua opção:");
        scanf("%d", &op);
        
        switch (op) {
            case 0:
                exit(0);
                break;
            case 1:
                inserirLivro(&livros);
                logMsg("Inserir Livro",LOGS_FILE);
                break;
            case 2:
                listarLivros(livros);
                logMsg("Listar Livros",LOGS_FILE);
                break;
            case 3:
                listarEditoras(livros);
                logMsg("Listar Editoras",LOGS_FILE);
                break;
            case 4:
                listarAutores(livros);
                logMsg("Listar Autores",LOGS_FILE);
                break;
            default:
                puts("Opção inválida!");
                break;
        }
        
    }while(op!=0);
    
    return 0;
}    