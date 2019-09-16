/* Primer programa del curso
	
*/
#include <stdio.h> //directivas del preprocesador

int main(int argc, char *argv[]){

	char s[20]; //cadena de 20 caracteres
	printf("Buenos días ¿cómo te llamas?:");
	scanf("%s",s);
	printf("Es un placer saludarte %s \n",s);
	return 0;
}
