/*EWERTON PATRICK SILVA DO AMARAL n10346975 USP-ICMC*/

#ifndef _READLINE_H_
#define _READLINE_H_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/* Desaloca a palavra
 * Parametros:
 *	char* line: Palavra alocada dinamicamente*/
void freeInfo(char* line);

/* Obtem uma palavra e aloca dinamicamente
 * Retorno:
 *	char* line: Palavra alocada dinamicamente */
char* getInfo() ;

#endif
