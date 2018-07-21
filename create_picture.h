/*EWERTON PATRICK SILVA DO AMARAL n10346975 USP ICMC*/

#ifndef _CREATE_PICTURE_H_
#define _CREATE_PICTURE_H_

typedef struct estado{
	int atual;
	char* passagem;
	char* out;
} ESTADO;

#define tamX 700/*tamanho da imagem em X*/
#define tamY 500/*tamanho da imagem em Y*/
#define desX 300/*desloca toda a imagem em x*/

/* Relaciona as ligacoes entre os estados
 * Parametros:
 * 	int numEstados: Quantidade de estados na interface grafica
 * 	int melle_moore: Informa se a saida sera no formato melle ou moore
 *	int numSegmentos: Quantidade de ligacoes entre os estados
 * Retorno:
 *	ESTADO** matriz: matriz adjacente que relaciona as ligacoes entre os estados */
ESTADO** registraCaminhos(int numEstados, int melle_moore, int numSegmentos);

/* Compara duas palavras
 * Parametros:
 *	char* str1: primeira palavra
 *	char* str2: segunda palavra
 * Retorno:
 * 	-1: Se a primeira palavra vier antes seguindo a ordem alfabetica
 * 	1: Se a segunda palavra vier antes seguindo a ordem alfabetica
 * 	0: Se as duas palavras forem iguais */
int strcmp_My(char* str1, char* str2);

/* Preenche os estados com letras para identificacao e traça uma linha no meio do estado
 * Muitas dessas letras foram feitas Pixel a Pixel
 * Parametros: 
 *	int DimenX: Quantidade de Pixels em X
 *	int DimenY: Quantidade de Pixels em Y
 *	int numEstados: Quantidade de estados na interface grafica */
void preenche_Palavra(double** Pixel, int DimenX, int DimenY, int numEstados);
					
/* Libera a imagem para a visualizacao em formato .pgm 
 * Parametros:
 *	double** Pixel: matriz que contem os Pixels da interface grafica
 *	int DimenX: Quantidade de Pixels em X
 *	int DimenY: Quantidade de Pixels em Y
 * 	int MaiorPixel: O valor do maior Pixel gerado na imagem*/
void LiberaImagem(double** Pixel, int DimenX, int DimenY, int MaiorPixel);

/* Preenche uma area delimitada na interface grafica
 * Parametros:
 *	int x: coordenadas x dos Pixels
 *	int y: coordenadas y dos Pixels
 *	int tom: tonalidade a ser preenchidas 
 * Retorno:
 * 	Os retornos dessa funcao servem apenas para auxiliar
 * 	Na processo recursivo do preenchimento*/
int paint( double** PixelMat, int x, int y, int tom);

/* Escreve as passagens nas ligacoes feita para si
 * E escreve as saidas dos estados ou na ligacao feita(Se for melle)
 * Ou no proprio estado(Se for moore)
 * Parametros:
 *	double** Pixel: Pixels da imagem gerada
 *	int deslocamentoX: Posicao do centro em X do circulo feito que sinaliza o estado ligando para si
 *	int deslocamentoY: Posicao do centro em Y do circulo feito que sinaliza o estado ligando para si
 *	int raio: tamanho do raio do circulo
 *	char* passagem: Condicao para passar para o proximo estado
 *	char* saida: Saida quando vai para o proximo estado
 *	int melle_moore: Informa se a saida sera no formato melle ou moore
 *	int pos_estado: Se estiver no formato em moore a saida sera preenchida nesse estado */
void escreve_passagem_para_si(double** Pixel, int deslocamentoX, int deslocamentoY, int raio, char* passagem,
	char* saida, int melle_moore, int pos_estado);

/* Faz a ligacao para si e escreve a saida e a entrada
 * Parametros:
 * 	double** Pixel: Pixels da imagem gerada
 *	int pos_fsm: O estado a receber a ligacao para si mesmo
 *	int DimenX: Quantidade de Pixels em X
 *	int DimenY: Quantidade de Pixels em Y
 *	char* passagem: Condicao para passar para o proximo estado
 *	char* saida: Saida quando vai para o proximo estado
 *	int melle_moore: Informa se a saida sera no formato melle ou moore */
void seta_Para_si(double** Pixel, int pos_fsm, int DimenX, int DimenY, char* passagem, char* saida, int melle_moore);

/* Escreve as passagens nas ligacoes feita entre os estados 
 * As saidas dos estados sao escritas ou na ligacao feita entre os estados(Se for melle)
 * Ou no proprio estado(Se for moore)
 * Parametros:
 *	int centro: Centro do raio no qual foi feito a ligacao entre os estados
 *	int raio: Raio da ligacao feita entre os estados
 *	double** Pixel: Pixels da imagem gerada
 *	char* passagem: Condicao para passar para o proximo estado
 *	char* saida: Saida quando vai para o proximo estado
 *	int melle_moore: Informa se a saida sera no formato melle ou moore
 *	int pos_estado: Se estiver no formato em moore a saida sera preenchida nesse estado */
void escreve_passagem_menor(int centro, int raio, double** Pixel, char* passagem, char* saida, int melle_moore,int pos_estado);

/* Faz a ligacao para um estado menor e escreve a saida e a entrada
 * Parametros:
 * 	double** Pixel: Pixels da imagem gerada
 *	int estado_Atual: O estado no qual sai a ligacao
 *	int prox: O estado no qual recebe a ligacao
 *	int DimenX: Quantidade de Pixels em X
 *	int DimenY: Quantidade de Pixels em Y
 *	char* passagem: Condicao para passar para o proximo estado
 *	char* saida: Saida quando vai para o proximo estado
 *	int melle_moore: Informa se a saida sera no formato melle ou moore */
void proximo_estado_eh_menor(double** Pixel, int estado_Atual, int prox, int DimenX, int DimenY, char* passagem, char* saida, int melle_moore);

/* Escreve as passagens nas ligacoes feita entre os estados 
 * As saidas dos estados sao escritas ou na ligacao feita entre os estados(Se for melle)
 * Ou no proprio estado(Se for moore)
 * Parametros:
 *	int centro: Centro do raio no qual foi feito a ligacao entre os estados
 *	int raio: Raio da ligacao feita entre os estados
 *	double** Pixel: Pixels da imagem gerada
 *	char* passagem: Condicao para passar para o proximo estado
 *	char* saida: Saida quando vai para o proximo estado
 *	int melle_moore: Informa se a saida sera no formato melle ou moore
 *	int pos_estado: Se estiver no formato em moore a saida sera preenchida nesse estado */
void escreve_passagem_maior(int centro, int raio, double** Pixel, char* passagem, char* saida, int melle_moore, int pos_estado);

/*Faz a ligacao para um estado maior e escreve a saida e a entrada
 *Parametros:
 * 	double** Pixel: Pixels da imagem gerada
 *	int estado_Atual: O estado no qual sai a ligacao
 *	int prox: O estado no qual recebe a ligacao
 *	int DimenX: Quantidade de Pixels em X
 *	int DimenY: Quantidade de Pixels em Y
 *	char* passagem: Condicao para passar para o proximo estado
 *	char* saida: Saida quando vai para o proximo estado
 *	int melle_moore: Informa se a saida sera no formato melle ou moore */
void proximo_Estado_eh_Maior(double** Pixel, int estado_Atual, int prox, int DimenX, int DimenY, char* passagem, char* saida, int melle_moore);

/* Gera ligacao entre os estados de acordo com as informacoes
 * Estabelecidas pela matriz adjacente
 * Parametros:
 *	ESTADO** matriz: Qatriz de adjacencia que contem as conexoes entre os estados
 *	int DimenX: Quantidade de Pixels em X
 *	int DimenY: Quantidade de Pixels em Y
 *	int numDeCirculo: Quantidade de Estados da interface grafica
 *	int melle_moore: Informa se sera registrado em melle ou moore a interface grafica 
 * Retorno:
 *	double** Pixel: Pixels da imagem gerada */
double** generate_picture(ESTADO** matriz,  int DimenX, int DimenY, int numCirculos, int melle_moore);

/* Gera a imagem e libera para a visualizacao
 * Parametros:
 *	ESTADO** matriz: Qatriz de adjacencia que contem as conexoes entre os estados
 *	int numDeCirculo: Quantidade de Estados da interface grafica
 *	int melle_moore: Informa se sera registrado em melle ou moore a interface grafica 
 * Retorno:
 * 	picture: Pixels da imagem gerada*/
double** create_picture(ESTADO** matriz, int numDeCirculo, int melle_moore );

/* Verifica se tem outro estado preenchido, retira o preenchimento do estado
 * E inclui o preenchimento no estado seguinte
 * Parametros:
 *	double** Pixel: matriz que contem os Pixels da interface grafica
 *	int DimenX: Quantidade de Pixels em X
 *	int DimenY: Quantidade de Pixels em Y
 *	int Estado: O proximo estado a ser preenchido de tonalidade cinza */
void preenche_Estado(double** Pixel, int DimenX, int DimenY, int Estado);

/*Retira a Linha do estado, isso auxiliara' no preenchimento de todo o circulo
 *Da interface grafica
 *Parametros:
 *	double** Pixel: matriz que contem os Pixels da interface grafica
 *	int estado: O estado que devera ser retirado a linha */
void retira_Linha_Do_Estado(double** Pixel,int estado);

/*Apos gerar a imagem essa funcao recebera os dados digitados	
 *No terminal e atualizara a imagem de acordo com as sequencias
 *Estabelecidas para o funcionamento da Maquina de Estado Finita
 *Parametros:
 *	double** Pixel: matriz que contem os Pixel da interface grafica
 *	int numEstados: Quantidade de estados a serem incluidos na interface grafica 
 *	int initial_Position: Posicao inicial a ser preenchido o estado */
void simulacao_FSM(double** Pixel, ESTADO** matriz, int numEstados, int initial_Position);

/* Desaloca os pixels da interface grafica
 * Parametros:
 * 	double** Pixel: Os pixels da imagem
 *	int DimenX: Quantidade de Pixels em X
 *	int DimenY: Quantidade de Pixels em Y */
void desaloca_Pixel(double** Pixel, int DimenX, int DimenY);

/* Desaloca a matriz de adjacencia utilizada para relacionar as ligacoes entre os estados
 * Parametros:
 *	ESTADO** matriz: matriz de adjacencia
 *	int numEstados: Quantidade de estados */
void desaloca_Matriz(ESTADO** matriz, int numEstados);

#endif
