#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int elegirTamanio();
int generarAleatorio(int min, int max);
void cargarVectorAleatorio(int v[], int tam);
void mostarVector(int v[], int tam);
void mostrasPosicionesDivisibles3(int v[], int tam);
int encontrarMaximoImparesNeg(int v[],int tam);


int main(){
    srand(time(0));

    int tam=elegirTamanio();
    int v[tam];
    cargarVectorAleatorio(v,tam);
    mostarVector(v,tam);

    mostrasPosicionesDivisibles3(v,tam);

    encontrarMaximoImparesNeg(v,tam);


    return 0;
}

int elegirTamanio(){
    int tamanio;
    do {
    printf("Ingrese un tamanio de 2 cifras que no puede terminar en 7: ");
    scanf("%d", &tamanio);
    } while(tamanio<10 || tamanio>99 || tamanio%10==7);
    return tamanio;
};



void cargarVectorAleatorio(int v[], int tam){
    for (int i = 0; i < tam; i++) {
        v[i] = (rand() % 201) - 100;
    }

};


void mostarVector(int v[], int tam){
    printf("||");
    for(int i=0; i<tam; i++){
        printf(" %d ", v[i]);
    }
    printf("||");
};

void mostrasPosicionesDivisibles3(int v[], int tam){
    printf("\n");
    printf("||");
    for(int i=0; i<tam; i+=3){
        printf(" %d ", v[i]);
    }
    printf("||\n");
};

int encontrarMaximoImparesNeg(int v[],int tam){
    int mayor = -100;

    for ( int i = 0 ; i< tam; i++){
        if ( v[i] > mayor && v[i] < 0 && v[i]%2!=0){
                mayor = v[i];
        }

    }

    if (mayor != -100){
        printf("\nEl mayor de los impares negativos es: %d", mayor);
    }
    else{
    printf("\nNo hay impares negativos.");
    }

    return mayor;
}
