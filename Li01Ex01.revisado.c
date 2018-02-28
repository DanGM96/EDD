#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PAUSAR printf("\n\n") & system("pause") //pula duas linhas e espera o usuario para continuar.

int i, j, linha, coluna;
int matrix[10][10]; //e possivel mudar o tamanho da matriz aqui e manter quase todos os calculos em perfeito funcionamento.

void matriz(){ //mostra uma matriz com numeros aleatorios.
	printf("\n\tMatriz[%d][%d]\n", linha, coluna);
	
	for(i = 0; i < linha; i++){
		
		printf("\n");	
		for(j= 0; j < coluna; j++){
			
			matrix[i][j] = rand() % 10; //cria um numero aleatorio de 0 a 9 para a posicao atual, isso foi escolhido para manter a parte astetica da matriz.
			printf("[%d]", matrix[i][j]); //Imprime a posicao atual ate completar a matriz.
		}
	}
}

void principal(){ //mostra a diagonal principal.
	printf("\n\n\tDiagonal Principal\n");
	
	for(i = 0; i < linha; i++){
		printf("\n");
		
		for(j= 0; j < coluna; j++){
			
			if(i == j)
				printf("[%d]", matrix[i][j]); //Imprime a posicao atual se for da diagonal principal.
			else
				printf("[ ]"); //Imprime "*" cosmeticamente caso a posicao nao faca parte da diagonal principal.
		}
	}
}

void secundaria(){ //mostra a diagonal secundaria.
	printf("\n\n\tDiagonal Secundaria\n");
	
		for(i = 0; i < linha; i++){
		printf("\n");
		
		for(j= 0; j < coluna; j++){
			
			if(i + j == linha - 1)
				printf("[%d]", matrix[i][j]); //Imprime a posicao atual se for da diagonal secundaria.
			else
				printf("[ ]"); //Imprime "*" cosmeticamente caso a posicao nao faca parte da diagonal secundaria.
		}
	}
}

void superior(){ //mostra o triangulo superior
	printf("\n\n\tTriangulo Superior\n");
	
		for(i = 0; i < linha; i++){
		printf("\n");
		
		for(j= 0; j < coluna; j++){
			
			if(i < j)
				printf("[%d]", matrix[i][j]); //Imprime a posicao atual se for do triangulo superior.
			else
				printf("[ ]"); //Imprime "[ ]" cosmeticamente caso a posicao nao faca parte da triangulo superior.
		}
	}
}

void inferior(){ //mostra o triangulo inferior
	printf("\n\n\tTriangulo Inferior\n");
	
	for(i = 0; i < linha; i++){
	printf("\n");
		
		for(j= 0; j < coluna; j++){
			
			if(i > j)
				printf("[%d]", matrix[i][j]); //Imprime a posicao atual se for do triangulo inferior.
			else
				printf("[ ]"); //Imprime "*" cosmeticamente caso a posicao nao faca parte da triangulo inferior.
		}
	}
}

void multiplicar(){ //cria mais uma matriz 10x10 aleatória, mostra as duas na tela, e mostra o produto delas.
	int matrixMulti[linha][coluna], matrixResult[linha][coluna];
	int k, multi = 0;
	printf("\n\nMultiplicar duas Matrizes:");
		
	printf("\n\n\tMatrizUM[%d][%d]\n", linha, coluna);
	for(i = 0; i < linha; i++){
		printf("\n");	
		for(j= 0; j < coluna; j++)
			printf("[%d]", matrix[i][j]); //Imprime a posicao atual ate completar a matriz.
	}
	
	printf("\n\n\tMatrizDOIS[%d][%d]\n", linha, coluna); 
	for(i = 0; i < linha; i++){ //Cria e imprime a segunda matriz.
		printf("\n");	
		for(j= 0; j < coluna; j++){
			matrixMulti[i][j] = rand() % 10;
			printf("[%d]", (matrixMulti[i][j] )); 
		}
	}
	
	printf("\n\n\tNova Matriz[%d][%d]\n", linha, coluna);
	for(i = 0; i < linha; i++){
		printf("\n");
		for(j= 0; j < coluna; j++){
			matrixResult[i][j] = 0; //Inicializar Matriz.
			for(k = 0; k < coluna; k++)
				matrixResult[i][j] += matrix[i][k] * matrixMulti[k][j]; //Calcular novos valores das posicoes na matriz.
			printf("[%d]", matrixResult[i][j]); //Imprime Nova Matriz.
		}
	}
}

void menu(){ //menu para gerenciar todas as acoes do usuario.
	int entrada;
	system("cls");
	
	printf("\n\tSeja bem vindo ao Matriz Show 10/10 - IGN.\n");
	printf("\nEscolha uma das opcoes abaixo:\n");
	printf("\n1 - Criar Matriz (auto)");
	printf("\n2 - Diagonal Principal");
	printf("\n3 - Diagonal Secundaria");
	printf("\n4 - Triangulo Superior");
	printf("\n5 - Triangulo Inferior");
	printf("\n6 - Multiplicar duas Matrizes (quebra a formatacao)");
	printf("\n7 - Todas as opcoes acima");
	printf("\n0 - Sair\n\t");
	
	scanf("%d", &entrada);
	
	switch(entrada){
		case 1:
			matriz();
			PAUSAR;
			menu();
			break;
		case 2:
			principal();
			PAUSAR;
			menu();
			break;
		case 3:
			secundaria();
			PAUSAR;
			menu();
			break;
		case 4:
			superior();
			PAUSAR;
			menu();
			break;
		case 5:
			inferior();
			PAUSAR;
			menu();
			break;
		case 6:
			multiplicar();
			PAUSAR;
			menu();
			break;
		case 7:
			matriz();
			principal();
			secundaria();
			superior();
			inferior();
			multiplicar();			
			PAUSAR;
			menu();
			break;
		case 0:
			break;
		default:
			printf("\nPor favor, insira uma opcao valida.");
			PAUSAR;
			menu();
			break;
	}
}

int main(int argc, char *argv[]) { //so pega linha e coluna, dai chama o menu.

	srand(time(NULL)); 

	linha = sizeof (matrix)/sizeof(matrix[0]); //calcula o tamanho da linha.
	coluna = sizeof (matrix[0])/sizeof(matrix[0][0]); //calcula o tamanho da coluna.

	menu();	

	return 0;
}

