#include <stdio.h>
#include <stdlib.h>

void imprime_matriz(int matriz[][4]);
void operacion_linea(int matriz[][4],int l,int m, int indice);

int main(int argc, char *argv[]){
	int sistema[3][4]={0};
	int i,j;
	float x,y,z;
	printf("Introduce cada una de las ecuaciones  siguiendo el orden que se indica:");
	printf("\n a1,a2,a3 y a4 donde a1.x+a2.y+a3.z=a4\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("Introduce el valor a%d de la ecuacion %d:",j,i);
			scanf("%i",&sistema[i][j]); //rellena la matriz de coeficientes
		}
	}
	imprime_matriz(sistema);
	operacion_linea(sistema,0,1,0); //transforma en 0 el coeficiente (2,1)
	imprime_matriz(sistema);
	operacion_linea(sistema,0,2,0);// transforma en 0 el coeficiente (3,1)
	imprime_matriz(sistema);
	operacion_linea(sistema,1,2,1);// transforma en 0 el coeficiente (3,2)
	imprime_matriz(sistema);
	z=sistema[2][3]/sistema[2][2]; //calcula el valor de z
	y=(sistema[1][3]-sistema[1][2]*z)/sistema[1][1];//calcula el valor de y
	x=(sistema[0][3]-sistema[0][2]*z-sistema[0][1]*y)/sistema[0][0]; //calcula el valor de x
	printf("El valor de z es: %5.2f\nEl valor de y es: %5.2f\nEl valor de x es: % 5.2f",z,y,x);
	return 0;
}
void operacion_linea(int matriz[][4],int l1,int l2, int c){ //función que elimina las incognitas de la ecuación
	int i;
	for(i=3;i>=0;i--){
		matriz[l2][i]= matriz[l1][c]*matriz[l2][i]-matriz[l2][c]*matriz[l1][i];
	}
}
void imprime_matriz(int matriz[][4]){ //función que imprime una matriz
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf(" %i",matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
}

