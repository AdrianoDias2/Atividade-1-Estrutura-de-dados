#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de ordenação por seleção
void Selection_Sort(int vet[], int n)
{
    int min;
    int aux;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vet[min] > vet[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            aux = vet[min];
            vet[min] = vet[i];
            vet[i] = aux;
        }
    }
}

// Função de ordenação por inserção
void Insertion_Sort(int vet[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = vet[i];
        int j = i - 1;

        while (j >= 0 && vet[j] > key)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = key;
    }
}

// Função para contar o número de elementos no arquivo
int countNumbersInFile(const char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Não foi possível abrir o arquivo %s\n", fileName);
        exit(1);
    }

    int count = 0;
    int temp;
    while (fscanf(file, "%d", &temp) == 1)
    {
        count++;
    }

    fclose(file);
    return count;
}

// Função para ler números do arquivo e armazená-los em um vetor
int* readNumbersFromFile(const char *fileName, int *size)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Não foi possível abrir o arquivo %s\n", fileName);
        exit(1);
    }

    int count = countNumbersInFile(fileName);
    int *numbers = (int*)malloc(count * sizeof(int));
    if (numbers == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(1);
    }

    for (int i = 0; i < count; i++)
    {
        fscanf(file, "%d", &numbers[i]);
    }

    fclose(file);
    *size = count;
    return numbers;
}

// Função que imprime o conteúdo de um vetor
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    int size;
    int *numbers = readNumbersFromFile(argv[1], &size);

    // printf("Vetor antes da ordenação:\n");
    // printArray(numbers, size);

    // Medir o tempo de execucao do Selection_Sort
    int *copy1 = (int*)malloc(size * sizeof(int));
    if (copy1 == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1;
    }
    for (int i = 0; i < size; i++) copy1[i] = numbers[i];

    clock_t start = clock();
    Selection_Sort(copy1, size);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // printf("Vetor após Selection Sort:\n");
    // printArray(copy1, size);

    printf("Tempo de execucao do Selection Sort: %f segundos\n", time_spent);

    free(copy1);

    // Medir o tempo de execucao do Insertion_Sort
    int *copy2 = (int*)malloc(size * sizeof(int));
    if (copy2 == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1;
    }
    for (int i = 0; i < size; i++) copy2[i] = numbers[i];

    start = clock();
    Insertion_Sort(copy2, size);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    //printf("Vetor após Insertion Sort:\n");
    // printArray(copy2, size);
    printf("Tempo de execucao do Insertion Sort: %f segundos\n", time_spent);

    free(copy2);
    free(numbers);

    return 0;
}
