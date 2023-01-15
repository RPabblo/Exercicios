#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void swap(int *a, int *b);
void imprimir(int *array, int n);

void selectionSort(int *array, int n);
void insertion(int *array, int n);
void bubbleSort(int *array, int n);

void subir(int *array,int i);
void descer(int *array,int i, int tam);
void heapify(int *array, int n);
void heapSort(int *array, int n);

void merge(int *array, int inicio, int meio, int fim);
void mergeSort(int *array, int inicio, int fim); 

int particiona(int *array, int inicio, int final);
void quickSort(int *array, int inicio, int final);


int main()
{
    int n = 12;
    int array[12] =  {7, 50, 18, 25, 3, 64, 35, 20, 45, 10, 30, 0};

    quickSort(array, 0, n - 1);
    imprimir(array, n);

    return 0;
}

// ------------------------------------------------------

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void imprimir(int *array, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d, ", array[i]);

    printf("\n");
}

// ------------------------------------------------------

void insertion(int *array, int n)
{
    int i, j;

    for(i = 1; i < n; i++) {
        j = i;

        while(j > 0 && array[j - 1] > array[j]) {
            swap(&array[j], &array[j - 1]);
            j -= 1;
        }
    }
}

void selectionSort(int *array, int n)
{
    int i, j, menor;

    for(i = 0; i < n - 1; i++) {
        menor = i;
        for(j = i + 1; j < n; j++) {
            if(array[j] < array[menor]) {
                menor = j;
            }
        }
        swap(&array[i], &array[menor]);
    }

}

void bubbleSort(int *array, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(array[i] > array[j]) {
                swap(&array[j], &array[i]);
            }
        }
    }
}

// ------------------------------------------------------

void subir(int *array,int i) 
{
    double x = (double) i / 2.0;
    double j = ceil(x) - 1.0; // Nó pai

    if(j >= 0.0) {
        if(array[i] > array[(int)j]) {
            swap(&array[i], &array[(int)j]);
            subir(array, (int)j);
        }
    }
}

void descer(int *array,int i, int tam)
{
    int j = 2 * i + 1; // Filho esquerdo

    if(j <= tam - 1) {
        if(j < tam - 1) {
            if(array[j + 1] > array[j]) {
                j += 1;
            }
        }

        if(array[i] < array[j]) {
            swap(&array[i], &array[j]);
            descer(array, j, tam);
        }
    }
}

void heapify(int *array, int n)
{ 
    int i;
    for(i = n / 2; i >= 0; i--) {
        descer(array, i, n);
    }
}

void heapSort(int *array, int n)
{
    heapify(array, n);

    int i = n;
    while(i > 0) {
        swap(&array[0], &array[i - 1]);
        i -= 1;
        descer(array, 0, i);
    }
}

// ------------------------------------------------------

void merge(int *array, int inicio, int meio, int fim)
{
    int i, j, k;
    // Cria dois arrays auxiliares que quardarao as duas metades do array inicial
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int temp1[n1];
    int temp2[n2];

    // Copia as metades do array nos dois arrays temporários
    for(i = 0; i < n1; i++) {
        temp1[i] = array[inicio + i];
    }

    for(i = 0; i < n2; i++) {
        temp2[i] = array[meio + i + 1];
    }

    i = 0; j = 0; k = inicio;

    while(i < n1 && j < n2) 
    {
        if(temp1[i] <= temp2[j]) {
            array[k] = temp1[i];
            i++;
        }
        else {
            array[k] = temp2[j];
            j++;
        }
        k++;
    }

    // Elementos restantes dos arrays auxiliares serao copiados para o array principal
    while(i < n1) {
        array[k] = temp1[i];
        i++; k++;
    }

    while(j < n2) {
        array[k] = temp2[j];
        j++; k++;
    }
}

void mergeSort(int *array, int inicio, int fim) 
{
    int meio;
    if(inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }
}

// ------------------------------------------------------

/* Pivo: ultimo elemento do array
int esq: elemento mais a esquerda maior que o pivo; 
int dir: elemento mais a direita menor que o pivo;

Troca dir e esq e repete o processo ate que esq > dir;
depois, troca esq com o pivo e chama o quicksort nas particoes   */
int particiona(int *array, int inicio, int final)
{
    if(final <= inicio) return - 200;
    int esq = inicio, dir = final - 1, pivo = final;

    for(;;)
    {
        while(array[dir] > array[pivo]) {
            dir -= 1;
        }

        while(array[esq] < array[pivo]) {
            esq += 1;
        }

        if(esq > dir) break;

        swap(&array[esq], &array[dir]);        
    }

    swap(&array[pivo], &array[esq]);
    pivo = esq;
    return pivo;
}

void quickSort(int *array, int inicio, int final)
{
    int pivo;
    if(inicio < final) {
        pivo = particiona(array, inicio, final);
        quickSort(array, inicio, pivo - 1);
        quickSort(array, pivo + 1, final);
    }
}
