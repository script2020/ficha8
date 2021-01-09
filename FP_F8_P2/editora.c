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

void inserirEditora(Livros *livros){
    lerString(livros->livros[livros->contador].infoEditora.nome, MAX_COMP_STRINGS, MSG_OBTER_NOME_EDITORA);
    lerString(livros->livros[livros->contador].infoEditora.morada, MAX_COMP_STRINGS, MSG_OBTER_MORADA);    
}

void imprimirEditora(Livro livro) {
    printf("\n %s %s",livro.infoEditora.nome,livro.infoEditora.morada);
}

void listarEditoras(Livros livros) {
    if (livros.contador > 0) {
        int i;
        for (i = 0; i < livros.contador; i++) {
            imprimirEditora(livros.livros[i]);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}

