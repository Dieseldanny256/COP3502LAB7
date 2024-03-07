#include <stdio.h>
#include <stdlib.h>

void printArray(int*, int);
void printSwaps(int*, int*, int);
void swap(int*, int, int);
void copy(int*, int*, int);
int* countingBubbleSort(int*, int);
int* countingSelectionSort(int*, int);

#define ARRAY_SIZE 9

int main()
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int arraycpy[ARRAY_SIZE];
    int* swapsBubble = NULL;
    int* swapsSelection = NULL;

    
    printf("array1 bubble sort:\n");
    copy(arraycpy, array1, ARRAY_SIZE);
    swapsBubble = countingBubbleSort(arraycpy, ARRAY_SIZE);
    printSwaps(arraycpy, swapsBubble, ARRAY_SIZE);
    free(swapsBubble);
    printf("\n");

    printf("array2 bubble sort:\n");
    copy(arraycpy, array2, ARRAY_SIZE);
    swapsBubble = countingBubbleSort(arraycpy, ARRAY_SIZE);
    printSwaps(arraycpy, swapsBubble, ARRAY_SIZE);
    free(swapsBubble);
    printf("\n");

    printf("array1 selection sort:\n");
    copy(arraycpy, array1, ARRAY_SIZE);
    swapsSelection = countingSelectionSort(arraycpy, ARRAY_SIZE);
    printSwaps(arraycpy, swapsSelection, ARRAY_SIZE);
    free(swapsSelection);
    printf("\n");
    
    printf("array2 selection sort:\n");
    copy(arraycpy, array2, ARRAY_SIZE);
    swapsSelection = countingSelectionSort(arraycpy, ARRAY_SIZE);
    printSwaps(arraycpy, swapsSelection, ARRAY_SIZE);
    free(swapsSelection);
}

void copy(int* dest, int* src, int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }
}

void swap(int* array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void printArray(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void printSwaps(int* array, int* countingArray, int size)
{
    int total = 0;
    for(int i = 0; i < size; i++)
    {
        printf("%d: %d\n", array[i], countingArray[i]);
        total += countingArray[i];
    }
    printf("%d\n", total/2);
}

int* countingBubbleSort(int* array, int size)
{
    int* countsArray = (int*)calloc(ARRAY_SIZE, sizeof(int));

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (array[j] > array[j+1])
            {
                countsArray[j]++;
                countsArray[j+1]++;
                swap(array, j, j+1);
                swap(countsArray, j, j+1);
            }
        }
    }

    return countsArray;
}

int* countingSelectionSort(int* array, int size)
{
    int* countingArray = (int*)calloc(ARRAY_SIZE, sizeof(int));
    for (int i = 0; i < size-1; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }

        if (min == i)
        {
            continue;
        }

        countingArray[i]++;
        countingArray[min]++;
        swap(array, i, min);
        swap(countingArray, i, min);
    }

    return countingArray;
}