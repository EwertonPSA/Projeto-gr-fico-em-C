/*EWERTON PATRICK SILVA DO AMARAL n10346975 USP ICMC*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<create_picture.h>
#include<readLine.h>
#include<math.h>
ESTADO** registraCaminhos(int numEstados, int melle_moore, int numSegmentos){
	int i, j, k;
	int present_state, next_state;
	ESTADO** matriz;
	char* passagem,*saida; 
	/* char* passagem: Condicao para passar para o proximo estado
 	   char* saida: Saida quando vai para o proximo estado*/
	
	matriz = (ESTADO**)malloc(sizeof(ESTADO*) * numEstados);
	for(i = 0; i < numEstados; i++)
		matriz[i] = (ESTADO*)malloc(sizeof(ESTADO)*numEstados)
			;
	/*Zerando as informacoes da matriz*/
	for(i = 0; i < numEstados; i++)
		for(j = 0; j < numEstados; j++){
			matriz[i][j].atual = 0;
			matriz[i][j].passagem = NULL;
			matriz[i][j].out = NULL;
		}
		
	printf("Digite as %d ligacoes em cada linha no seguinte formato:\n", numSegmentos);
	printf("Estado atual, o próximo estado, a entrada e a saida\n");
	printf("ATENCAO: A entrada e saida devera' ser composta apenas pelos numeros 1 ou 0\n");
	/*Formacao de matriz de adjacencia para relacionar os estados*/
	for(i = 0; i < numSegmentos; i++){
		scanf("%d",&present_state);
		scanf("%d",&next_state);
				
		/*Verificando se o segmento vai ser criado*/
		if (present_state > 0 && next_state > 0 && present_state <= numEstados && next_state <= numEstados){ 
			matriz[present_state-1][next_state-1].passagem  = getInfo();/*Entrada*/
			matriz[present_state-1][next_state-1].out  = getInfo();/*Saida*/
			/*Flag pra informar que tem informacao pra ser avaliada*/
			matriz[present_state-1][next_state-1].atual = 1;
		}else {
			printf("Essa entrada nao eh aceita\n");
			if(present_state <= 0 || next_state <= 0)
				printf("Os estados sao identificados pelos numeros que vão de 1 a 8, tente novamente!\n");
			else if(present_state > numEstados || next_state > numEstados)
				printf("Foi ultrapassado a quantidade total de estados, tente novamente!\n");
			i--;
			passagem = getInfo();
			saida = getInfo();
			free(passagem);
			free(saida);
		}
	}

	return matriz;
}

int strcmp_My(char* str1, char* str2){
	int num = strlen(str1);
	int i = 0;

	if(str1 == NULL  || str2 == NULL){
		if(str1 == NULL && str2 != NULL) return -1;
		else if (str1 != NULL && str2 == NULL) return 1;
		else return 0;
	}

	while(i <= num){
		if(str1[i] != str2[i]){
			if(str1[i] < str2[i])
				return-1;
			return 1;
		}
		else i++;
	}
	return 0;
}

void preenche_Palavra(double** Pixel, int DimenX, int DimenY, int numEstados){
	int k, i, j, h;
	int deslocax = 3;
	int deslocay = 5;
	for(k = 1; k <= numEstados; k++){
		switch(k){
			case 1:/*Letra I*/
				for(i = 0; i < 10; i++){
					Pixel[k*50-6-deslocay+i][1-deslocax+desX] = 255;	
					Pixel[k*50-6-deslocay+i][-deslocax+desX] = 255;	
				}
				
				break;
			case 2:/*Letra P*/			
				for(i = 0; i < 4; i++){
					Pixel[k*50+i-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50+i-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50+i-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-i-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50-i-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-4-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50-4-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-deslocay][i-deslocax+desX] = 255;	
					Pixel[k*50-1-deslocay][i-deslocax+desX] = 255;
					Pixel[k*50-5-deslocay][i-deslocax+desX] = 255;	
					Pixel[k*50-6-deslocay][i-deslocax+desX] = 255;
				}

				Pixel[k*50-6-deslocay][-deslocax+desX-1] = 255;
				Pixel[k*50-5-deslocay][-deslocax+desX-1] = 255;
				Pixel[k*50-2-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-3-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-1-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-1-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-2-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-3-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-4-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-4-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-5-deslocay][4-deslocax+desX] = 255;
				break;
			case 3:/*Letra F*/	
				for(i = 0; i < 4; i++){
					Pixel[k*50+i-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50+i-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50+i-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-i-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50-i-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-4-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50-4-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-deslocay][i-deslocax+desX] = 255;	
					Pixel[k*50-1-deslocay][i-deslocax+desX] = 255;
					Pixel[k*50-5-deslocay][i-deslocax+desX] = 255;	
					Pixel[k*50-6-deslocay][i-deslocax+desX] = 255;
				}
				Pixel[k*50-6-deslocay][-deslocax+desX-1] = 255;
				Pixel[k*50-5-deslocay][-deslocax+desX-1] = 255;
				break;
			case 4:	/*Letra A*/
				for(i = 0; i < 4; i++){
					Pixel[k*50+i-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50+i-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50+i-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-i-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50-i-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-4-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50-4-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-deslocay][i-deslocax+desX] = 255;	
					Pixel[k*50-1-deslocay][i-deslocax+desX] = 255;
					Pixel[k*50-5-deslocay][i-deslocax+desX] = 255;	
					Pixel[k*50-6-deslocay][i-deslocax+desX] = 255;
				}
				Pixel[k*50-1-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-1-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-2-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-3-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-4-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-4-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-5-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-1-deslocay+4][5-deslocax+desX] = 255;
				Pixel[k*50-2-deslocay+4][5-deslocax+desX] = 255;
				Pixel[k*50-3-deslocay+4][5-deslocax+desX] = 255;
				Pixel[k*50-4-deslocay+4][5-deslocax+desX] = 255;
				Pixel[k*50-4-deslocay+4][4-deslocax+desX] = 255;
				Pixel[k*50-5-deslocay+4][4-deslocax+desX] = 255;
				break;
			case 5:/*Letra R*/
				for(i = 0; i < 4; i++){
					Pixel[k*50+i-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50+i-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50+i-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-i-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50-i-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-4-deslocay][-1-deslocax+desX] = 255;	
					Pixel[k*50-4-deslocay][-deslocax+desX] = 255;	
					Pixel[k*50-deslocay][i-deslocax+desX] = 255;	
					Pixel[k*50-1-deslocay][i-deslocax+desX] = 255;
					Pixel[k*50-5-deslocay][i-deslocax+desX] = 255;	
					Pixel[k*50-6-deslocay][i-deslocax+desX] = 255;
				}
				Pixel[k*50-6-deslocay][-deslocax+desX-1] = 255;
				Pixel[k*50-5-deslocay][-deslocax+desX-1] = 255;
				Pixel[k*50-2-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-3-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-1-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-1-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-2-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-3-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-4-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-4-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-5-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50+2-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50+3-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50+1-deslocay][3-deslocax+desX] = 255;
				Pixel[k*50+1-deslocay][2-deslocax+desX] = 255;
				Pixel[k*50+2-deslocay][3-deslocax+desX] = 255;
				Pixel[k*50+1-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50+2-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50+3-deslocay][5-deslocax+desX] = 255;
				break;
				
			case 6:	/*Letra K*/	
				for(i = 0; i < 10; i++){
					Pixel[k*50-6-deslocay+i][1-deslocax+desX] = 255;	
					Pixel[k*50-6-deslocay+i][-deslocax+desX] = 255;	
				}
				Pixel[k*50+2-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50+3-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50+1-deslocay][3-deslocax+desX] = 255;
				Pixel[k*50+1-deslocay][2-deslocax+desX] = 255;
				Pixel[k*50+2-deslocay][3-deslocax+desX] = 255;
				Pixel[k*50-deslocay][1-deslocax+desX] = 255;
				Pixel[k*50-deslocay][2-deslocax+desX] = 255;
				Pixel[k*50-deslocay][3-deslocax+desX] = 255;
				Pixel[k*50-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50+1-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50+2-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50+3-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-2-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-3-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-1-deslocay][3-deslocax+desX] = 255;
				Pixel[k*50-1-deslocay][2-deslocax+desX] = 255;
				Pixel[k*50-2-deslocay][3-deslocax+desX] = 255;
				Pixel[k*50-1-deslocay][4-deslocax+desX] = 255;
				Pixel[k*50-2-deslocay][5-deslocax+desX] = 255;
				Pixel[k*50-3-deslocay][5-deslocax+desX] = 255;
				break;
			case 7:	/*Letra L*/
				for(i = 0; i < 8; i++){
					Pixel[k*50-6-deslocay+i][1-deslocax+desX] = 255;	
					Pixel[k*50-6-deslocay+i][-deslocax+desX] = 255;	
				}
				for(j = 0; j < 7; j++){
					Pixel[k*50-6-deslocay+i][-deslocax+desX+j] = 255;	
					Pixel[k*50-6-deslocay+i+1][-deslocax+desX+j] = 255;	
				}
				break;
			case 8:	/*Letra U*/
				for(i = 0; i < 7; i++){
                                        Pixel[k*50-6-deslocay+i][1-deslocax+desX] = 255;
                                        Pixel[k*50-6-deslocay+i][-deslocax+desX] = 255;
                                }
                                for(j = 0; j < 7; j++){
                                        Pixel[k*50-6-deslocay+i][-deslocax+desX+j] = 255;
                                        Pixel[k*50-6-deslocay+i+1][-deslocax+desX+j] = 255;
                                }
				j--;
				for(h = 0; h <= 7; h++){
                                        Pixel[k*50-6-deslocay+i-h][-1-deslocax+desX+j] = 255;
                                        Pixel[k*50-6-deslocay+i-h][-deslocax+desX+j] = 255;
                                }
				break;
		}
		
	
		for(i = 0; i < 17; i++){/*Reta que corta o circulo de cada estado na interface grafica*/
			Pixel[k*50][1+desX+i] = 255;	
			Pixel[k*50][1+desX-i] = 255;	
			Pixel[k*50+1][1+desX+i] = 255;	
			Pixel[k*50+1][1+desX-i] = 255;	
		}	
	}
}

void LiberaImagem(double** Pixel, int DimenX, int DimenY, int MaiorPixel){
    int i, y, x;
    FILE* arq;
    arq = fopen("FSM.pgm", "w");
    /*Cabecalho*/
    fprintf(arq,"P2\n");/*Leitura no formato ASCII*/
    fprintf(arq,"# CREATOR: Image Generator Ewerton Patick silva do amaral USP-ICMC 2017\n");/*Comentario*/
    fprintf(arq,"%d %d\n", DimenX, DimenY);/*Dimensoes em X e Y*/
    fprintf(arq,"%d\n",MaiorPixel);/*O maior valor do tom de Pixel na imagem gerada*/
    for(y = 0; y < DimenY; y++ )
            for(x = 0; x < DimenX; x++)
                    fprintf(arq, "%u\n", (unsigned char)Pixel[y][x]);/*Pixels da imagem*/
    fclose(arq);
}

int paint( double** PixelMat, int x, int y, int tom) {
    if(PixelMat[y][x] == 255 || PixelMat[y][x] == tom )/*Delimitacao*/
        return 0;
        
	PixelMat[y][x] = tom;
        paint(PixelMat, x + 1 , y, tom);
        paint(PixelMat, x - 1, y, tom);
        paint(PixelMat, x, y + 1, tom);
        paint(PixelMat, x, y - 1, tom);
        return 1;
}

void escreve_passagem_para_si(double** Pixel, int deslocamentoX, int deslocamentoY, int raio, 
		char* passagem, char* saida, int melle_moore, int pos_estado ){
	int num, aux, desloca;
	int i, j, k;
	int saida_melle;
	/*desloca = Serve para auxiliar a centralizacao da escrita acima da curva que liga os estados 
	  aux = quantidade de letras na saida
	  num = quantidade de letras na passagem*/

	num = strlen(passagem);
	aux = strlen(saida);
			
	/*Passagem entre os estados*/
    for(k = 0; k <= num-1 ; k++){
        if(passagem[k] == '1'){
            for(j = 0; j < 4; j++){//base do 1
                Pixel[deslocamentoY - 4][deslocamentoX-raio+j-(9*(num-1+aux-k))-7] = 200;
                Pixel[deslocamentoY - 4][deslocamentoX-raio-j-(9*(num-1+aux-k))-7] = 200;
            }
            for(j = 0; j < 7; j++)// subida ate o topo do 1
                Pixel[deslocamentoY - 4 - j][deslocamentoX-raio-((num-1+aux-k)*9)-7] = 200;
            for(j = 0; j < 3; j++)// linha inclinada do 1
                Pixel[deslocamentoY - 4 + j - 7][deslocamentoX-raio-j-(9*(num-1+aux-k))-7] = 200;
        }
        else if(passagem[k] == '0'){
            for(i = 0; i < 2; i++){
                Pixel[deslocamentoY - 4][deslocamentoX-raio+i-(9*(num-1+aux-k))-7] = 200;
                Pixel[deslocamentoY - 4][deslocamentoX-raio-i-(9*(num-1+aux-k))-7] = 200;

                Pixel[deslocamentoY - 4 - i][deslocamentoX-raio-i-(9*(num-1+aux-k))-9] = 200;
                Pixel[deslocamentoY - 4 - i][2+deslocamentoX-raio+i-(9*(num-1+aux-k))-7] = 200;
            }
            for(i = 0; i < 5; i++){
                Pixel[deslocamentoY - 4-i-2][3+deslocamentoX-raio-(9*(num-1+aux-k))-7] = 200;
                Pixel[deslocamentoY - 4-i-2][deslocamentoX-raio-(9*(num-1+aux-k))-10] = 200;
            }
            for(i = 0; i < 3; i++){
                Pixel[deslocamentoY - 4 - 7][deslocamentoX-raio+i-(9*(num-1+aux-k))-7] = 200;
                Pixel[deslocamentoY - 4 - 7][deslocamentoX-raio-i-(9*(num-1+aux-k))-7] = 200;
            }
        }
    }

	/*Saida*/
	if(melle_moore == 0){/*Escrita no formato melle*/
		for(i = 0; i < 4; i++){
			Pixel[deslocamentoY - 4 - 2*i][deslocamentoX-raio-i-(9*(aux-1))-6-2] = 200;
			Pixel[deslocamentoY - 4 - 2*i-1][deslocamentoX-raio-i-(9*(aux-1))-6-2] = 200;
		}

		for(k = 0; k <= aux-1 ; k++){
			if(saida[k] == '1'){
				for(j = 0; j < 4; j++){//base do 1
					Pixel[deslocamentoY - 4][deslocamentoX-raio+j-(9*(aux-1-k))-4] = 200;
					Pixel[deslocamentoY - 4][deslocamentoX-raio-j-(9*(aux-1-k))-4] = 200;
				}
				for(j = 0; j < 7; j++)// subida ate o topo do 1
					Pixel[deslocamentoY - 4 - j][deslocamentoX-raio-((aux-1-k)*9)-4] = 200;
				for(j = 0; j < 3; j++)// linha inclinada do 1
					Pixel[deslocamentoY - 4 + j - 7][deslocamentoX-raio-j-(9*(aux-1-k))-4] = 200;
			}else if(saida[k] == '0'){
				for(i = 0; i < 2; i++){
					Pixel[deslocamentoY - 4][deslocamentoX-raio+i-(9*(aux-1-k))-4] = 200;
					Pixel[deslocamentoY - 4][deslocamentoX-raio-i-(9*(aux-1-k))-4] = 200;

					Pixel[deslocamentoY - 4 - i][deslocamentoX-raio-i-(9*(aux-1-k))-6] = 200;
					Pixel[deslocamentoY - 4 - i][2+deslocamentoX-raio+i-(9*(aux-1-k))-4] = 200;
				}
				for(i = 0; i < 5; i++){
					Pixel[deslocamentoY - 4-i-2][3+deslocamentoX-raio-(9*(aux-1-k))-4] = 200;
					Pixel[deslocamentoY - 4-i-2][deslocamentoX-raio-(9*(aux-1-k))-7] = 200;
				}
				for(i = 0; i < 3; i++){
					Pixel[deslocamentoY - 4 - 7][deslocamentoX-raio+i-(9*(aux-1-k))-4] = 200;
					Pixel[deslocamentoY - 4 - 7][deslocamentoX-raio-i-(9*(aux-1-k))-4] = 200;
				}
			}
		}
	}else{/*Escrita no formato moore*/
		desloca = 9;
		for(k = 0; k <= aux-1 ; k++){
			if(saida[k] == '1'){
				for(j = 0; j < 3; j++){//base do 1
					Pixel[pos_estado + desloca][deslocamentoX + j-(7*(aux-1-k))-4 ] = 255;
					Pixel[pos_estado + desloca][deslocamentoX-j-(7*(aux-1-k))-4] = 255;
				}
				for(j = 0; j < 6; j++)// subida ate o topo do 1
					Pixel[pos_estado + desloca-j][ deslocamentoX-((aux-1-k)*7)-4] = 255;
				for(j = 0; j < 3; j++)// linha inclinada do 1
					Pixel[pos_estado + desloca+j-6][deslocamentoX-j-(7*(aux-1-k))-4] = 255;
			}else if(saida[k] == '0'){
				for(i = 0; i < 2; i++){
					Pixel[pos_estado + desloca][deslocamentoX+i-(7*(aux-1-k))-4] = 255;
					Pixel[pos_estado + desloca][deslocamentoX-i-(7*(aux-1-k))-4] = 255;

					//curva do zero parte esquerda inferior
					Pixel[pos_estado + desloca-i][deslocamentoX-i-(7*(aux-1-k))-6] = 255;
					//curva do zero parte direta inferior
					Pixel[pos_estado + desloca-i][2+deslocamentoX+i-(7*(aux-1-k))-5] = 255;

				}
				for(i = 0; i < 4; i++){
					//deslocamento lado direito do 0
					Pixel[pos_estado + desloca-i-2][3 +deslocamentoX-(7*(aux-1-k))-5] = 255;
					//deslocamento lado esquerdo do 0
					Pixel[pos_estado + desloca-i-2][deslocamentoX-(7*(aux-1-k))-7] = 255;
				}
				for(i = 0; i < 3; i++){
					Pixel[pos_estado + desloca-6][deslocamentoX+i-(7*(aux-1-k))-5] = 255;
					Pixel[pos_estado + desloca-6][deslocamentoX-i-(7*(aux-1-k))-4] = 255;
				}
			}
		}
	}
}

void seta_Para_si(double** Pixel, int pos_fsm, int DimenX, int DimenY, char* passagem, char* saida, int melle_moore){
    int x, y, i, j;
	
	/*Circulo para gerar a ligacao do estado indo para si mesmo*/
    for( y = 0; y < DimenY; y++)
        for(x = 0; x < DimenX; x++)
            if( pow(x - (desX+10) , 2) + pow(y - pos_fsm*50+20, 2) < 190 && pow(x - (desX+10) , 2) + pow(y - pos_fsm*50+20 , 2) > 140 )
                    Pixel[y][x] = 254;/*TONALIDADE DIFERENTE*/

	/*Reforcando o circulo que existia do estado,
 	  Isso servira para apagar o circulo que ficou registrado anteriormente
 	  Dentro do estado*/
    for( y = 0; y < DimenY; y++)
        for(x = 0; x < DimenX; x++)
			if( pow(x - desX, 2) + pow(y - 50*pos_fsm , 2) < 300 && pow(x - desX, 2) + pow(y - 50*pos_fsm , 2) > 200 )
                Pixel[y][x] = 255;

    /*Retira a parte do circulo que esta dentro do estado preenchendo com tom=11
	 *Precisa ser preenchido com tom=11 antes pois se for de tom=10 e ja' existir este tom dentro
	 *Do estado a funcao paint nao funcionara*/
    paint(Pixel, desX , pos_fsm* 50, 11);
	paint(Pixel, desX , pos_fsm* 50, 10);

    /*seta sinalizar a ligacao com si mesmo*/
    for(i = 5; i >= 0 ; i--)
        for(j = 0; j <= i; j++){
            Pixel[pos_fsm*50- 17 -i][j+desX-3] = 255;
            Pixel[pos_fsm*50- 17 -i][-j+desX-3] = 255;
        }

	escreve_passagem_para_si(Pixel, desX+10, pos_fsm*50 - 20, 14 , passagem, saida, melle_moore, pos_fsm*50 );
}

void escreve_passagem_menor(int centro, int raio, double** Pixel, char* passagem, char* saida, int melle_moore,int pos_estado){
	int num, deslocamentoX = 10+desX, deslocamentoY;
    int i, j, k, desloca, aux;
	/*deslocamentoX = Serve para ajuste do deslocamento em X na interface grafica
	  deslocamentoY = Serve para ajuste do deslocamento em Y na interface grafica
	  desloca = Serve para auxiliar a centralizacao da escrita acima da curva que liga os estados 
	  aux = quantidade de letras na saida
	  num = quantidade de letras na passagem*/

    num = strlen(passagem);
    aux = strlen(saida);

	/*Passagem entre os estados*/
    for(k = 0; k <= num-1 ; k++){
		/*Deslocamento para que a impressoa da passagem saia de forma centralizada a cima da curva*/
		desloca =-(9*(num-1+aux-k))+13;
     	if(passagem[k] == '1'){
            for(j = 0; j < 8; j++)
                Pixel[centro + desloca][-raio+desX-26+j] = 200;

            for(j = 0; j < 4; j++){
                Pixel[centro + desloca+j][-raio+desX-26] = 200;
                Pixel[centro + desloca-j][-raio+desX-26] = 200;
            }
            for(j = 3; j >= 0; j--)
                Pixel[centro + desloca -j][-raio+desX-26-j+8] = 200;
        }else if(passagem[k] == '0'){
            for(i = 0; i < 2; i++){
                Pixel[desloca+centro-4-i][i-raio+desX-26] = 200;
                Pixel[desloca+centro+i][i-raio+desX-26] = 200;
            }
            for(i = 0; i < 4; i++){
                Pixel[desloca+centro-i][-raio+desX-26] = 200;
                Pixel[desloca+centro-i][-raio+desX-26+8] = 200;
            }
            for(i = 0; i < 6; i++){
                Pixel[desloca+centro+1][-raio+desX-26+i+2] = 200;
                Pixel[desloca+centro-5][-raio+desX-26+i+2] = 200;
            }
		}
    }

	if(melle_moore == 0){
		/*Deslocamento para gerar a seta que separa a entrada da saida em melle*/
		desloca =-(9*(aux))+18;
		for(j = 3; j >= 0; j--){
			Pixel[centro + desloca +j][-raio+desX-26-2*j+7] = 230;
			Pixel[centro + desloca +j][-raio+desX-26-2*j+7-1] = 230;
			Pixel[centro + desloca +j][-raio+desX-26-2*j+7+1] = 230;
			Pixel[centro + desloca +j][-raio+desX-26-2*j+7-2] = 230;
		}
		for(k = 0; k <= aux-1 ; k++){
			/*Deslocamento para que a impressoa da saida saia de forma centralizada a cima da curva*/
			desloca =-(9*(aux-1-k))+18;
			if(saida[k] == '1'){
				for(j = 0; j < 8; j++)
					Pixel[centro + desloca][-raio+desX-26+j] = 200;

				for(j = 0; j < 4; j++){
					Pixel[centro + desloca+j][-raio+desX-26] = 200;
					Pixel[centro + desloca-j][-raio+desX-26] = 200;
				}
				for(j = 3; j >= 0; j--)
					Pixel[centro + desloca -j][-raio+desX-26-j+8] = 200;

			}else if(saida[k] == '0'){
				for(i = 0; i < 2; i++){
					Pixel[desloca+centro-4-i][i-raio+desX-26] = 200;
					Pixel[desloca+centro+i][i-raio+desX-26] = 200;
				}
				for(i = 0; i < 4; i++){
					Pixel[desloca+centro-i][-raio+desX-26] = 200;
					Pixel[desloca+centro-i][-raio+desX-26+8] = 200;
				}
				for(i = 0; i < 6; i++){
					Pixel[desloca+centro+1][-raio+desX-26+i+2] = 200;
					Pixel[desloca+centro-5][-raio+desX-26+i+2] = 200;
				}
			}
		}
	}else{
		deslocamentoY  = 9;      
		for(k = 0; k <= aux-1 ; k++){
			if(saida[k] == '1'){
				for(j = 0; j < 3; j++){//base do 1
					Pixel[pos_estado + deslocamentoY][deslocamentoX + j-(7*(aux-1-k))-4 ] = 255;
					Pixel[pos_estado + deslocamentoY][deslocamentoX-j-(7*(aux-1-k))-4] = 255;
				}
				for(j = 0; j < 6; j++)// subida ate o topo do 1
					Pixel[pos_estado + deslocamentoY-j][ deslocamentoX-((aux-1-k)*7)-4] = 255;
				for(j = 0; j < 3; j++)// linha inclinada do 1
					Pixel[pos_estado + deslocamentoY+j-6][deslocamentoX-j-(7*(aux-1-k))-4] = 255;
			}else if(saida[k] == '0'){
				for(i = 0; i < 2; i++){
					Pixel[pos_estado + deslocamentoY][deslocamentoX+i-(7*(aux-1-k))-4] = 255;
					Pixel[pos_estado + deslocamentoY][deslocamentoX-i-(7*(aux-1-k))-4] = 255;
					
					//curva do zero parte esquerda inferior
					Pixel[pos_estado + deslocamentoY - i][deslocamentoX-i-(7*(aux-1-k))-6] = 255;									      
					//curva do zero parte direta inferior
					Pixel[pos_estado + deslocamentoY - i][2+deslocamentoX+i-(7*(aux-1-k))-5 ] = 255;
				}
				for(i = 0; i < 4; i++){
					//deslocamento lado direito do 0
					Pixel[pos_estado + deslocamentoY-i-2][3+deslocamentoX-(7*(aux-1-k))-5] = 255;
					//deslocamento lado esquerdo do 0
					Pixel[pos_estado + deslocamentoY-i-2][deslocamentoX-(7*(aux-1-k))-7] = 255;				
				}
				for(i = 0; i < 3; i++){
					Pixel[pos_estado + deslocamentoY-6][deslocamentoX+i-(7*(aux-1-k))-5 ] = 255;
					Pixel[pos_estado + deslocamentoY-6][deslocamentoX-i-(7*(aux-1-k))-4 ] = 255;
				}
			}
		}
	}
}

void proximo_estado_eh_menor(double** Pixel, int estado_Atual, int prox, int DimenX, int DimenY, char* passagem, char* saida, int melle_moore){
        int j, k, x, y;
	int centro, raio;

	centro = estado_Atual*50 - 24*(estado_Atual-prox);
	raio = (50/2)*(estado_Atual-prox);
	for( y = 0; y < DimenY; y++)/*Ligacao entre estados*/
		for(x = 0; x < DimenX; x++)
			if( x <= desX && (x - desX)*(x - desX) + (y - centro)*(y - centro) < (raio+2)*(raio+2) && 
				 (x - desX)*(x - desX) + (y - centro)*(y - centro) > (raio)*(raio) )
					Pixel[y][x-15] = 255;

	escreve_passagem_menor(centro, raio, Pixel, passagem, saida, melle_moore, prox*50);

	for(k = 0; k < 10; k++)/*Seta que indica a ligacao*/
		for(j = 0; j <= k; j++){
			Pixel[(centro-raio+5) + j -5][-15 + desX - k] = 255;
			Pixel[(centro-raio+5) - j -5][-15 + desX - k] = 255;
		}
}

void escreve_passagem_maior(int centro, int raio, double** Pixel, char* passagem, char* saida, int melle_moore, int pos_estado){
	int num, aux, deslocamentoX = 10+desX, deslocamento;
	int i, j, k, desloca;
	/*deslocamentoX = Serve para ajuste do deslocamento em X na interface grafica
	  deslocamento = Serve para ajuste do deslocamento em Y na interface grafica
	  desloca = Serve para auxiliar na escrita acima da curva de ligacao entre os estados 
	  aux = quantidade de letras na saida
	  num = quantidade de letras na passagem*/
	num = strlen(passagem);
	aux = strlen(saida);
	
        for(k = 0; k <= num-1 ; k++){
		desloca =-(9*(num-1+aux-k))+15;/*Deslocamento para que a impressoa da passagem saia de forma centralizada a cima da curva*/
                if(passagem[k] == '1'){                        
			for(j = 0; j < 8; j++)
                                Pixel[centro + desloca][raio+desX+20+j] = 200;

                        for(j = 0; j < 4; j++){
                                Pixel[centro + desloca+j][raio+desX+20] = 200;
                                Pixel[centro + desloca-j][raio+desX+20] = 200;
                        }
                        for(j = 3; j >= 0; j--)
                                Pixel[centro + desloca -j][raio+desX+20-j+8] = 200;
                }else if(passagem[k] == '0'){
                        for(i = 0; i < 2; i++){
                                Pixel[desloca+centro-4-i][i+raio+desX+20] = 200;
                                Pixel[desloca+centro+i][i+raio+desX+20] = 200;
                        }
                        for(i = 0; i < 4; i++){
                                Pixel[desloca+centro-i][raio+desX+20] = 200;
                                Pixel[desloca+centro-i][raio+desX+20+8] = 200;
                        }
                        for(i = 0; i < 6; i++){
                                Pixel[desloca+centro+1][raio+desX+20+i+2] = 200;
                                Pixel[desloca+centro-5][raio+desX+20+i+2] = 200;
                        }
                }
        }
	if(melle_moore == 0){/*Saida em Melle*/ 
		desloca =-(9*aux)+18;/*Deslocamento para gerar a seta que separa a entrada da saida em melle*/
		for(j = 3; j >= 0; j--){
			Pixel[centro + desloca +j][raio+desX+20-2*j+7] = 230;
			Pixel[centro + desloca +j][raio+desX+20-2*j+7-1] = 230;
			Pixel[centro + desloca +j][raio+desX+20-2*j+7+1] = 230;
			Pixel[centro + desloca +j][raio+desX+20-2*j+7-2] = 230;
		}

		for(k = 0; k <= aux-1 ; k++){
			desloca =-(9*(aux-1-k))+18;/*Deslocamento para que a impressoa da saida saia de forma centralizada a cima da curva*/
			if(saida[k] == '1'){
				for(j = 0; j < 8; j++)
					Pixel[centro + desloca][raio+desX+20+j] = 200;

				for(j = 0; j < 4; j++){
					Pixel[centro + desloca+j][raio+desX+20] = 200;
					Pixel[centro + desloca-j][raio+desX+20] = 200;
				}
				for(j = 3; j >= 0; j--)
					Pixel[centro + desloca -j][raio+desX+20-j+8] = 200;
			}else if(saida[k] == '0'){
				for(i = 0; i < 2; i++){
					Pixel[desloca+centro-4-i][i+raio+desX+20] = 200;
					Pixel[desloca+centro+i][i+raio+desX+20] = 200;
				}
				for(i = 0; i < 4; i++){
					Pixel[desloca+centro-i][raio+desX+20] = 200;
					Pixel[desloca+centro-i][raio+desX+20+8] = 200;
				}
				for(i = 0; i < 6; i++){
					Pixel[desloca+centro+1][raio+desX+20+i+2] = 200;
					Pixel[desloca+centro-5][raio+desX+20+i+2] = 200;
				}
			}
		}
	}else{
		deslocamento  = 9;      
		for(k = 0; k <= aux-1 ; k++){
			if(saida[k] == '1'){
				for(j = 0; j < 3; j++){//base do 1
					Pixel[pos_estado + deslocamento][deslocamentoX + j-(7*(aux-1-k))-4 ] = 255;
					Pixel[pos_estado + deslocamento][deslocamentoX-j-(7*(aux-1-k))-4] = 255;
				}
				for(j = 0; j < 6; j++)// subida ate o topo do 1
					Pixel[pos_estado + deslocamento-j][deslocamentoX-((aux-1-k)*7)-4] = 255;
				for(j = 0; j < 3; j++)// linha inclinada do 1
					Pixel[pos_estado + deslocamento +j-6][deslocamentoX-j-(7*(aux-1-k))-4] = 255;
			}else if(saida[k] == '0'){
				for(i = 0; i < 2; i++){
					Pixel[pos_estado + deslocamento][deslocamentoX+i-(7*(aux-1-k))-4] = 255;
					Pixel[pos_estado + deslocamento][deslocamentoX-i-(7*(aux-1-k))-4] = 255;

					//curva do zero parte esquerda inferior
					Pixel[pos_estado + deslocamento-i][deslocamentoX-i-(7*(aux-1-k))-6] = 255;
					//curva do zero parte direta inferior
					Pixel[pos_estado + deslocamento-i][2+deslocamentoX+i-(7*(aux-1-k))-5 ] = 255;
				}
				for(i = 0; i < 4; i++){
					//deslocamento lado direito do 0
					Pixel[pos_estado + deslocamento-i-2][3+deslocamentoX-(7*(aux-1-k))-5] = 255;
					//deslocamento lado esquerdo do 0
					Pixel[pos_estado + deslocamento-i-2][deslocamentoX-(7*(aux-1-k))-7] = 255;				
				}
				for(i = 0; i < 3; i++){
					Pixel[pos_estado + deslocamento-6][deslocamentoX+i-(7*(aux-1-k))-5 ] = 255;
					Pixel[pos_estado + deslocamento-6][deslocamentoX-i-(7*(aux-1-k))-4 ] = 255;
				}
			}
		}
	}
}

void proximo_Estado_eh_Maior(double** Pixel, int estado_Atual, int prox, int DimenX, int DimenY, char* passagem, char* saida, int melle_moore){
        int j, k, x, y;
	int centro ;
	int raio;

	/*Centro entre o circulo a ser feito para montar a ligacao entre os estados*/
	centro = estado_Atual*50 + 24*(prox-estado_Atual);	
	/*Raio do Circulo a ser feito para montar a ligacao entre os estados*/
	raio = 25*(prox-estado_Atual);
	
	for(y = 0; y < DimenY; y++)/*Ligacao entre um estado e outro*/
		for(x = 0; x < DimenX; x++)
			if( x >= desX && (x - desX)*(x - desX) + (y - centro)*(y - centro) < (raio+2)*(raio+2) && 
				 (x - desX)*(x - desX) + (y - centro)*(y - centro) > (raio)*(raio) )
				Pixel[y][x+15] = 255;

	/*Escreve a passagem entre a ligacao feita*/
	escreve_passagem_maior(centro, raio, Pixel, passagem, saida, melle_moore, prox*50);

	for(k = 0; k < 10; k++)/*Seta para indicar a ligacao entre um estado menor para um maior*/
		for(j = 0; j <= k; j++){
			Pixel[(centro+raio+5) + j -5][15+desX+k] = 255;
			Pixel[(centro+raio+5) - j -5][15+desX+k] = 255;
		}
}

double** generate_picture(ESTADO** matriz,  int DimenX, int DimenY, int numCirculos, int melle_moore){
        int x, y, j, k, i;
        double** Pixel = NULL;
        int estado, prox_estado;

        Pixel=(double**)malloc( DimenY  * sizeof(double*));
       	for(y = 0, i = 0; y < DimenY; y++ ){
                Pixel[y] = (double*)malloc(sizeof(double)*DimenX);
                for(x = 0; x < DimenX; x++)
                        Pixel[y][x] = 10;/*Preenchendo a interface grafica de preto*/
        }

        for(k = 1; k <= numCirculos; k++)/*Gerando os circulos dos estados*/
                for( y = 0; y < DimenY; y++)
                        for(x = 0; x < DimenX; x++)
                                if( pow(x - desX, 2) + pow(y - 50*k , 2) < 300 && pow(x - desX, 2) + pow(y - 50*k , 2) > 200 )
                                        Pixel[y][x] = 255;

        for(i = 0; i < numCirculos; i++){
		estado = i + 1;/*Considerando numeros a cima de zero para relaciona os estados*/
		for(j = 0; j < numCirculos; j++){
			if(matriz[i][j].atual != 0){
				prox_estado = j + 1;/*Considerando numeros a cima de zero para relacionar os estados*/
				if (estado == prox_estado)
					seta_Para_si(Pixel,estado, DimenX, DimenY,matriz[i][j].passagem, matriz[i][j].out, melle_moore);
				else if(estado < prox_estado)
					/*A ligacao entre os estado eh feita 
					 *Na parte direita da interface grafica*/
					proximo_Estado_eh_Maior(Pixel, estado, prox_estado, DimenX, DimenY, matriz[i][j].passagem, matriz[i][j].out, melle_moore);
				else if(estado > prox_estado)
					/*A ligacao entre os estados eh feita 
					 *Na parte esquerda da interface grafica*/
					proximo_estado_eh_menor(Pixel, estado, prox_estado, DimenX, DimenY, matriz[i][j].passagem, matriz[i][j].out, melle_moore);
			}
		}
        }
        return Pixel;
}


double** create_picture(ESTADO** matriz, int numDeCirculo, int melle_moore ) {
        double** picture;
        picture = generate_picture(matriz , tamX, tamY, numDeCirculo, melle_moore );
        LiberaImagem(picture, tamX, tamY, 255);
	return picture;
}

void preenche_Estado(double** Pixel, int DimenX, int DimenY, int Estado){
	int y, x;
	
	for(y = 0; y < DimenY; y++ ){
                for(x = 0; x < DimenX ; x++)
                        if(Pixel[y][x] == 100)
				Pixel[y][x] = 10;
        }
	paint(Pixel, desX , 50*Estado, 100);
}

void retira_Linha_Do_Estado(double** Pixel,int estado){
	int i;
	for(i = 0; i < 15; i++){
		Pixel[estado*50][1+desX+i] = 0;	
		Pixel[estado*50][1+desX-i] = 0;	
		Pixel[estado*50+1][1+desX+i] = 0;	
		Pixel[estado*50+1][1+desX-i] = 0;	
	}
}

void simulacao_FSM(double** Pixel, ESTADO** matriz, int numEstados, int initial_Position){
	int i, j, prox_State = 0, condicao;
	int position = initial_Position-1;
	char* info ;
	preenche_Estado(Pixel, tamX, tamY, initial_Position/*Primeiro estado a aparecer*/);
	preenche_Palavra(Pixel, tamX, tamY, numEstados);
	LiberaImagem(Pixel, tamX, tamY, 255);
	printf("Digite a condicao para passar para o proximo estado\n");
	info = getInfo();
	while(strcmp_My(info, ",")!= 0){
		for(i = 0, condicao = 1; i < numEstados && condicao != 0; i++)
			if((matriz[position][i].passagem)!= NULL)
				condicao = strcmp_My(info,matriz[position][i].passagem);
		if(condicao == 0){
			printf("Passando de: Estado[%d] -> Estado[%d]\n", position + 1, i);
			retira_Linha_Do_Estado(Pixel, i);
			preenche_Estado(Pixel, tamX, tamY, i);
			paint(Pixel, desX-2 , 50*i-8, 100);/*Preenchendo o buraco em preto das letras P, A, R se forem selecionadas*/
			preenche_Palavra(Pixel, tamX, tamY, numEstados);
			LiberaImagem(Pixel, tamX, tamY, 255);
			position =  i - 1;
		}else	printf("Permanece no estado : [%d]\n", position + 1);
		condicao = 1;
		free(info);
		info = getInfo();
	}
	free(info);
}

void desaloca_Pixel(double** Pixel, int DimenX, int DimenY){
        int y;
        for(y = 0; y < DimenY; y++ )
                free(Pixel[y]);
        free(Pixel);
}

void desaloca_Matriz(ESTADO** matriz, int numCamera){
	int i, j;
	for(i = 0; i < numCamera; i++){
		for(j = 0; j < numCamera; j++){
			if(matriz[i][j].passagem != NULL)
				free(matriz[i][j].passagem);
			if(matriz[i][j].out != NULL)
				free(matriz[i][j].out);
		}
		free(matriz[i]);
	}
	free(matriz);
}
