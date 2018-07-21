/*EWERTON PATRICK SILVA DO AMARAL n10346975 USP-ICMC*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<readLine.h>

void freeInfo(char* line){
	if (line != NULL)
		free(line);
		line = NULL;
	return;
}

char* getInfo() {
    	int tamLinha = 100;
    	char* line = NULL;
	char letra;
	int num;

	line = (char *) malloc (sizeof(char) * tamLinha);
    	if (line == NULL) {
    		printf("ERRO NA ALOCACAO");
 	      	return NULL;
    	}
	letra = getc(stdin);
	num = 0;
	
	if(letra == ' ')
		letra = getc(stdin);
	while (letra != EOF && letra != '\n' && (int)letra != 13 && letra != ' ') {
		if (num % tamLinha == 0) {
	        	tamLinha += 100;
	        	line =(char*) realloc(line, sizeof(char)*tamLinha);
			if (line == NULL) {
	        		printf("ERRO DE REALOCACAO");
		                return NULL;
       	     		}
       	 	}
		if(letra != ' '){
			line[num] = letra;
			num++;
		}
		letra = getc(stdin);
    	}

	line[num] = '\0';
	line =(char*) realloc(line,sizeof(char)*(num+1));
	return line;
}

