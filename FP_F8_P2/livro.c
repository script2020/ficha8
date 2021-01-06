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

/*
 * 
 */

int inserirLivro(Livros *livros){
    
    lerString(livros->livros[livros->contador].titulo, MAX_COMP_STRINGS, MSG_OBTER_TITULO);
    lerString(livros->livros[livros->contador].ISBN, MAX_COMP_STRINGS, MSG_OBTER_IBSN);
    
    livros->livros[livros->contador].dataPub.dia = obterInteiro(MIN_DIA, MAX_DIA, OBTER_DIA_NASC);
    livros->livros[livros->contador].dataPub.mes = obterInteiro(MIN_MES, MAX_MES, OBTER_MES_NASC);
    livros->livros[livros->contador].dataPub.ano = obterInteiro(MIN_ANO, MAX_ANO, OBTER_ANO_NASC);
    
    switch (livros->livros[livros->contador].tipos){
        case FICCAO:
            livros->livros[livros->contador].tipos = obterChar("FICCAO");
            break;
        case TECNICO:
            livros->livros[livros->contador].tipos = obterChar("TECNICO");
            break;
        case ROMANCE:
            livros->livros[livros->contador].tipos = obterChar("ROMANCE");
            break;
        case ESTUDO:
            livros->livros[livros->contador].tipos  = obterChar("ESTUDO");
            break;
    }   
     
/*
    inserirEditora(Livros *livros);
    
    inserirAutor(Livros *livros);
*/

    
    return livros->contador++;

}

void imprimirLivro(Livro livro) {
    printf("\n %s %s %d-%d-%d",
            livro.ISBN,
            livro.titulo, 
            livro.dataPub.dia, 
            livro.dataPub.mes, 
            livro.dataPub.ano);
}

void listarLivros(Livros livros) {
    if (livros.contador > 0) {
        int i;
        for (i = 0; i < livros.contador; i++) {
            imprimirLivro(livros.livros[i]);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}

void atualizarContadorFile(int contador, char* ficheiro){
    FILE *fp = fopen(ficheiro, "rb");
     
    if (fp == NULL) {
       exit(EXIT_FAILURE);
    }
     
    fwrite(&contador, sizeof (int), 1, fp);
    fclose(fp);
}

void inserirLivroFile(Livros livros, char* ficheiro){
    atualizarContadorFile(livros.contador,ficheiro);
    
    FILE *fp = fopen(ficheiro, "ab");
     
    if (fp == NULL) {
       exit(EXIT_FAILURE);
    }
     
    fwrite(&livros.livros[livros.contador - 1], sizeof (Livro), 1, fp);
    fclose(fp);
}

void carregarLivro(Livros *livros, char* ficheiro){
    FILE *fp = fopen(ficheiro, "rb");
    if (fp != NULL) {
        fread(&livros->contador, sizeof (int), 1 , fp);}
        if (livros->contador > 0) {
            fread(&livros->contador, sizeof (int), livros->contador , fp);
    }else{
        fopen(ficheiro, "wb");
    }
    fclose(fp);
}