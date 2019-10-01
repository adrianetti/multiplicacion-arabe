#include<stdio.h>
#include<stdlib.h>

int solicitudCifra1();
int solicitudCifra2();
void matriz(int m[5][5], int matrizTransversa[5][5], int cifra1, int cifra2);
void imprimir(int m[5][5], int matrizTransversa[5][5], int cifra1, int cifra2);
void sumaDigitos(int m[5][5], int matrizTransversa[5][5], int cifra1, int cifra2, int resultado[30]);
void imprimirResultadofinal(int m[5][5], int matrizTransversa[5][5], int cifra1, int cifra2, int resultado[30]);

int main(){
	int cifra1,cifra2;
	int m[5][5], matrizTransversa[5][5], resultado[30];
    
    //solicitud de cifras
	cifra1=solicitudCifra1();
    cifra2=solicitudCifra2();
    
    system("cls");
    
    //impresion de resultados
    imprimir(m,matrizTransversa,cifra1,cifra2);
    imprimirResultadofinal(m,matrizTransversa, cifra1, cifra2, resultado);
    
    
	system("pause");

	return 0;
}




int solicitudCifra1(){
	int cifra1;
	printf("Introduzca una cifra con un maximo de 4 digitos: ");
	do{
	scanf("%d",&cifra1);
	if(cifra1<0||cifra1>9999)
	printf("La cifra que ha introducido no cumple con los parametros. Intente con otra: ");
}while(cifra1<0||cifra1>9999);
	return cifra1;
}

int solicitudCifra2(){
	int cifra2;
	printf("Introduzca otra cifra con un maximo de 4 digitos: ");
	do{
	scanf("%d",&cifra2);
	if(cifra2<0||cifra2>9999)
	printf("La cifra que ha introducido no cumple con los parametros. Intente con otra: ");
}while(cifra2<0||cifra2>9999);	
	return cifra2;
}

void matriz(int m[5][5], int matrizTransversa[5][5], int cifra1, int cifra2){
	int i,j;
    for(i=4;i>0;i--){
		m[0][i]=cifra2%10;
		cifra2/=10;
	}	

	for(i=1;i<5;i++){
		m[i][0]=cifra1%10;
		cifra1/=10;         
	}
		printf("\n");
	for(i=1;i<5;i++){
		for(j=1;j<5;j++){
			m[j][i]=m[0][i]*m[j][0];
			matrizTransversa[j][i]=m[j][i]%10;
			m[j][i]/=10;
		}
	}
}

void imprimir(int m[5][5], int matrizTransversa[5][5], int cifra1, int cifra2){
	int i,j;
	matriz(m,matrizTransversa,cifra1,cifra2);
	printf("  X    ");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(i>0||j>0)
			printf("%3d",m[i][j]);
			if(i>=1&&j>=1)
			printf("\\""%d ",matrizTransversa[i][j]);
		}
		printf("\n");
	}
	
//imprimiendo la matriz alterna generada	
/*	
	printf("\nMatriz transversa:\n");
	for(i=1;i<4;i++){
		for(j=1;j<4;j++){
			if(i>0||j>0)
			printf("%3d ",matrizTransversa[i][j]);
		}
		printf("\n");
	}
*/
}

void sumaDigitos(int m[5][5], int matrizTransversa[5][5], int cifra1, int cifra2, int resultado[30]){
	int suma=0, aux=1, acarreo=0;
    int i,j;
    
	matriz(m,matrizTransversa,cifra1,cifra2);
    
	i=4;
	
	do{
	suma=0;
	j=1;
	
	for(i;i<5;i++){
		if(j<4&&i<4)
		suma+=matrizTransversa[j][i]+m[j][i+1];
		else
		suma+=matrizTransversa[j][i];
		j++;
	}
	
	
	resultado[aux]=suma;
	
	if (acarreo>0){
		resultado[aux]+=1;
		acarreo--;
}
	
	if(resultado[aux]>=10){
	resultado[aux]%=10;
	acarreo++;
}

	i=4-aux;
	aux++;
	
    }while(aux<5);

	j=1;
	aux=1;
	
	do{
	i=1;	
	suma=0;
	for(i;i<5;i++){	
		if(j<4)
		suma+=m[j][i]+matrizTransversa[j+1][i];
		else
		suma+=m[j][i];
		j++;
		if(j>4){
			i=5;
		}
	}

	resultado[aux+4]=suma;
	
	if (acarreo>0){
		resultado[aux+4]+=1;
		acarreo--;
	}
	
	
	if(resultado[aux+4]>=10){
	resultado[aux+4]%=10;
	acarreo++;
}
    
	j=1+aux; 
	aux++;
}while(aux<5);

}

void imprimirResultadofinal(int m[5][5], int matrizTransversa[5][5], int cifra1, int cifra2, int resultado[30]){
	sumaDigitos(m,matrizTransversa, cifra1, cifra2, resultado);
	int i, aux=0;
	printf("\nResultado: ");
	for(i=8;i>0;i--){
		if(resultado[8]==0&&resultado[i]==0&&aux==0);
        else{
        printf("%d", resultado[i]);
        aux++;
    }
}
printf("\n\n");
}

