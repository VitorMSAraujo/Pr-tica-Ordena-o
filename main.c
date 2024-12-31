#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de ordenação Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função de ordenação Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Troca os valores
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Função para medir o tempo de execução
void testSortingAlgorithm(void (*sortFunction)(int[], int), int arr[], int n, const char *name) {
    int *copy = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        copy[i] = arr[i];
    }

    clock_t start = clock();
    sortFunction(copy, n);
    clock_t end = clock();

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s demorou %.6f segundos.\n", name, elapsed);

    free(copy);
}

// Função principal
int main() {
    FILE *file = fopen("num.1000.1.in", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n); // Lê o tamanho da lista
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Erro ao alocar memória!\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    printf("Testando algoritmos de ordenação com %d elementos.\n", n);

    testSortingAlgorithm(insertionSort, arr, n, "Insertion Sort");
    testSortingAlgorithm(selectionSort, arr, n, "Selection Sort");

    free(arr);
    return 0;
}
