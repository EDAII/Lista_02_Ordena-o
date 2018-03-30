#include <iostream>
#include <time.h>

int partition(int array[], int start, int end){

  int pivo = array[end]; //Último elemento usado como pivo
  int i = start-1;

  for(int j = start; j < end; j++){
    if(array[j] <= pivo){
      i++;
      int aux = array[i];
      array[i] = array[j];
      array[j] = aux;
    }
  }

  int aux2 = array[i + 1];
  array[i + 1] = array[end];
  array[end] = aux2;

  return (i + 1);
}

void quick_sort(int array[], int start, int end){
  if(start < end){
    int index_atual = partition(array, start, end);
    quick_sort(array, start, index_atual - 1);
    quick_sort(array, index_atual + 1, end);
  }
}


int main(){
  printf("Digite o tamanho do array: \n");
  int tamanho;
  scanf("%d",&tamanho);
  int A[tamanho];
  int i,j,k;
  for(i=0; i < tamanho; i++){
      int valor = rand() % 100 + 1;
      A[i] = valor;
  }

  quick_sort(A, 0, tamanho);
  

  for(k=0; k<tamanho; k++){
    printf("%d ",A[k]);
  }
  printf("\n");

  return 0;
}


