/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>

#include "livro.h"
#include "autor.h"
#include "input.h"

/*
 * 
 */

void inserirAutor(Livros *livros){
    int i,nAutorIns;
    
    nAutorIns = obterInteiro(1, 5, "Quantos autores tem este livro?");
    
    for(i = 0;i < nAutorIns;i++){
        lerString(livros->livros[livros->contador].autores[i].nome, MAX_COMP_STRINGS, "Insira o nome do autor: ");
        lerString(livros->livros[livros->contador].autores[i].pagWeb, MAX_COMP_STRINGS, "Insira a página web do autor: ");    
    }
}

void imprimirAutor(Livro livro) {
    printf("\n %s",livro.autores[0].nome);
}

void listarAutores(Livros livros) {
    if (livros.contador > 0) {
        int i;
        for (i = 0; i < livros.contador; i++) {
            imprimirAutor(livros.livros[i]);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}
