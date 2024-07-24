#include <stdio.h>
#include <stdlib.h>

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


    Selection_Sort(numbers, size);

    printf("Vetor ordenado por selection sort:\n");
    printArray(numbers, size);

    free(numbers);

    return 0;
}
