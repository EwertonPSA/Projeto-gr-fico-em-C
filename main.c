/*EWERTON PATRICK SILVA DO AMARAL n10346975 USP-ICMC*/

#include<stdio.h>
#include<stdlib.h>
#include<create_picture.h>

int main( int argc, char* argv [] ) {
	int i, j;
	int numEstado;
	int numSegmentos;
	int numSaidas;
	ESTADO** matriz;/*Associa todas as informacoes de entrada, saida*/
	float** armazemPontos;
	double** picture;
	int melle_moore;
	int initial_Position = 1;

	printf("Os estados estarao no formato melle(0) ou moore(1)?\n");
	scanf("%d",&melle_moore);//0: melle, 1:moore
	if(melle_moore == 1)
		printf("ATENCAO: No formato moore cada estado deve ter apenas uma saida\n");
	printf("Digite a quantidade de estados\n");
	scanf("%d",&numEstado);
	while(numEstado <= 0 || numEstado >= 9){
		printf("A quantidade de estados vai de 1 a 8, digite novamente!\n");
		scanf("%d", &numEstado);
	}
	printf("Digite a quantidade total de conexoes entre os estados\n");
	scanf("%d",&numSegmentos);
	while(numSegmentos <= 0){
		printf("Deve ter pelo menos uma conexao, digite novamente!\n");
		scanf("%d", &numSegmentos);
	}
	matriz = registraCaminhos(numEstado, melle_moore, numSegmentos );
	picture = create_picture(matriz, numEstado, melle_moore);
	simulacao_FSM(picture, matriz, numEstado, initial_Position);
	desaloca_Matriz(matriz, numEstado);
	desaloca_Pixel(picture, tamX, tamY);
}
