#include <stdio.h>
#include <stdlib.h>


void Selection_Sort(int vet[], int n ){

    int min;
    int aux;

        for(int i = 0; i<n-1; i++){
            min = i;
            for(int j = i+1; j<n; j++){
                
                if(vet[min] > vet[j]){
                    min = j;
                }

            }
                if(min != i){
                    aux = vet[min];
                    vet[min] = vet [i];
                    vet[i] = aux;
                }
            
        }
}


int main(){


    int n = 10;
    int vetor[10] = {2, 2, 3, 3, 6, 51, 9, 8 , 9, 8};

    Selection_Sort(vetor, n);

    printf(" \n\n ");

    for(int i=0; i<n; i++){
        printf("%d , " ,vetor [i]);

    }
    
    printf(" \n\n ");

    return 0;
}