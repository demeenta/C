#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Triangulos!
*/
#define N 6

int candidatos[N] = {0,0,0,0,0,0};
int usados[N] = {1,0,0,0,0,0};
int lados[N] = {0,0,0,0,0,0};

int candidato;


int seleccionar_candidato();
int permutaciones(int [], int);
int suma=0;
int mayor=0;
int M[6][3];
int main(){
	int i;
	char a;
	
	do{
		mayor=0;
		suma=0;
		for (i=0; i<6; i++){
			scanf("%d %d %d", &M[i][0], &M[i][1], &M[i][2]);
			/*printf("%d %d %d\n", M[i][0], M[i][1], M[i][2]);*/
		}
		scanf("%c", &a);
		scanf("%c", &a);
		
		for (i=0; i<3; i++){
		/*	printf("VUELTA: %d\n", i);		*/
			lados[0]=i;
			permutaciones(candidatos, 1);
		
		}
		/*printf("entro %d\n", M[0][0]);*/
		if (mayor==0)
			printf("none\n");
		else
			printf("%d\n", mayor);
		
	}while(a!='$');

	return 0;
}

int seleccionar_candidato(){
	int i;
	for (i=0; i<N; i++)
		if (usados[i]==0)
			return i;
	return -1;
}

int encuentra_lado(int x, int tri[3]){
	int i=0;
	for (i=0; i<3; i++)
		if(tri[i]==x)
			return i;
	return -1;	
}

int solu_completa(){
	int i=0, cont=0;
	for (i=0; i<N; i++)
		if (usados[i]==0)
			return -1;
	return 1;
}

/*Permutacion ciclica*/
int	 permutaciones(int candidatos[], int pos){
	int x, i;
	int selecc, lado;
	if (pos == N ){
		puts("Candidatos");
		for (x = 0; x != N; ++x){
			printf("%d ", candidatos[x]);
		}
		printf("\n ");
		getchar();
	}

	else {
		for (x=1; x!= N; ++x){

			if (usados[x]==0){ 
				lado = encuentra_lado(M[candidatos[pos-1]][lados[pos-1]], M[x]);
		
				if (lado!=-1){

					candidatos[pos]=x; /*Agrego numero a permutacion*/
					usados[x] = 1;  /*Marcar como usado*/

					lados[pos] = ((lado+2)%3); /*Guardo lado*/
					suma = suma + M[x][(lado+1)%3];
				
					if (solu_completa()==-1){
						
						permutaciones (candidatos,pos+1);/*Llamada recursiva a la siguiente posicion*/
					
					}
					else{
						if (M[candidatos[N-1]][lados[N-1]]==M[0][((lados[0]+1)%3)]){
							if (mayor<suma+ M[0][(lados[0]+2)%3])
								mayor = suma+ M[0][(lados[0]+2)%3];
							
						}
					}
					
				
	
					suma = suma - M[x][(lado+1)%3];

					usados[x] = 0;	/*Desmarcar*/		
				}
			}
		}
	}
}


