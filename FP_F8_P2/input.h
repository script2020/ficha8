/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   input.h
 * Author: pedro
 *
 * Created on 28 de dezembro de 2020, 20:39
 */

#ifndef INPUT_H
#define INPUT_H

int obterInteiro(int minValor, int maxValor, char *msg);

float obterFloat(float minValor, float maxValor, char *msg);

double obterDouble(double minValor, double maxValor, char *msg);

char obterChar(char *msg);

void lerString(char *string, unsigned int tamanho, char *msg);

#endif /* INPUT_H */
