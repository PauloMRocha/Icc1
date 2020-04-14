#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int numero_coment, numero_perg;
	int *contador_palavras=NULL, *contador_positivo=NULL, *contador_negativo=NULL;
	char** lista_de_produtos = NULL;
	char*** lista_de_descricoes = NULL;

	//aloca os contadores de palavras totais, positivas e negativas
	contador_palavras = calloc(20, sizeof(int));
	contador_negativo = calloc(20, sizeof(int));
	contador_positivo = calloc(20, sizeof(int));

	//le a quantidade de comentarios
	scanf("%d %d", &numero_coment, &numero_perg);

	//aloca a lista de produtos e descricoes
	lista_de_descricoes = realloc(lista_de_descricoes, numero_coment*sizeof(char**));
	lista_de_produtos = realloc(lista_de_produtos, numero_coment*sizeof(char*));

	//para cada comentario, aloca um array de char para os produtos e uma lista de array de char para ler 
	//as palavras da descricao separadamente
	for (int i = 0; i < numero_coment; i++)
	{
		lista_de_produtos[i] = realloc(lista_de_produtos[i], 40*sizeof(char));
		scanf(" %[^;];", lista_de_produtos[i]);
		lista_de_descricoes[i] = realloc(lista_de_descricoes[i], 20*sizeof(char*));

		//aloca e le um array de char para cada palavra do comentario depois do ';'e antes do 'Ø'
		for (int j = 0; j < 20; j++)
		{
			lista_de_descricoes[i][j] = realloc(lista_de_descricoes[i][j], 20*sizeof(char));
			scanf(" %s", lista_de_descricoes[i][j]);
			//interrompe quando ler o caractere especial
			if (strcmp(lista_de_descricoes[i][j], "Ø") == 0)
			{
				break;
			}
			//alocando array de polaridade
			char *positivas[12], *negativas[12];
			//array de palavras positivas
			positivas[0] = "bom";
			positivas[1] = "maravilhoso";
			positivas[2] = "otimo";
			positivas[3] = "sensacional";
			positivas[4] = "excelente";
			positivas[5] = "adorei";
			positivas[6] = "gostei";
			positivas[7] = "amei";
			positivas[8] = "eficiente";
			positivas[9] = "boa";
			positivas[10] = "maravilhosa";
			positivas[11] = "otima";
			//array de palavras negativas
			negativas[0] = "detestei";
			negativas[1] = "odiei";
			negativas[2] = "ruim";
			negativas[3] = "pessimo";
			negativas[4] = "terrivel";
			negativas[5] = "raiva";
			negativas[6] = "odio";
			negativas[7] = "pessima";
			negativas[8] = "lento";
			negativas[9] = "lenta";
			negativas[10] = "fragil";
			negativas[11] = "desisti";
			//conta as palavras positivas em um comentario
			for (int k = 0; k < 12; k++)
			{
				if (strcmp(lista_de_descricoes[i][j], positivas[k]) == 0)
					contador_positivo[i]++;
			}
			//conta as palavras positivas em um comentario
			for (int k = 0; k < 12; k++)
			{
				if (strcmp(lista_de_descricoes[i][j], negativas[k]) == 0)
					contador_negativo[i]++;
			}
			//conta o total de palavras
			contador_palavras[i]++;
		}
	}

	//teste
	printf("\n");
	printf("LISTA DE PRODUTOS\n");
	printf("\n");
	for (int i = 0; i < numero_coment; i++)
	{
		printf("%s\n", lista_de_produtos[i]);
	}
	printf("\n");
	printf("LISTA DE PALAVRAS\n");
	printf("\n");
	for (int i = 0; i < numero_coment ; i++)
	{
		for (int j = 0; j < contador_palavras[i]; j++)
		{
			printf("%s\n",lista_de_descricoes[i][j]);
		}
	}
	printf("\n");
	printf("CONTADOR DE POLARIDADE\n");
	printf("\n");
	for (int i = 0; i < numero_coment; ++i)
	{
		printf("COMENTARIO %d \n", i+1);
		printf("PORCENTAGEM DE POSITIVAS: %f %% \n", (float)contador_positivo[i]/(float)(contador_negativo[i]+contador_positivo[i])*100);
		printf("PORCENTAGEM DE NEGATIVAS: %f %% \n", (float)contador_negativo[i]/(float)(contador_negativo[i]+contador_positivo[i])*100);
	}

	

	return 0;
}