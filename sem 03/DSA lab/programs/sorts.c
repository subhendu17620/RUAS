// sorts
#include <stdio.h>
#include <time.h>

#define max 10

// for bubble sort
void bubbleSort(int array[], int size)
{
  for (int step = 0; step < size - 1; ++step)
  {
    for (int i = 0; i < size - step - 1; ++i)
    {
      if (array[i] > array[i + 1])
      {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
// for selection sort
void selectionSort(int array[], int size)
{
  for (int step = 0; step < size - 1; step++)
  {
    int min_idx = step;
    for (int i = step + 1; i < size; i++)
    {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}
// for quick sort
int partition(int array[], int low, int high)
{
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
// for printing
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main()
{

  int data[max];
  // we are getting time for worst-case
  // for (size_t i = max; i < -1; i--)
  // {
  //   data[i] = i;
  // }
  printf("Enter array: ");
  for (size_t i = 0; i < max; i++)
  {
    scanf("%d",&data[i]);
  }
  
  int size = sizeof(data) / sizeof(data[0]);
  clock_t start_t, end_t;
  
  start_t = clock();
  bubbleSort(data, max);
  end_t = clock();
  printf("Bubble Sort: ");
  printArray(data, max);
  printf("\nExecution time for Bubble-sort : %f seconds", (double)(end_t - start_t) / CLOCKS_PER_SEC);

  start_t = clock();
  selectionSort(data, max);
  end_t = clock();
  printf("\nSelection Sort: ");
  printArray(data, max);
  printf("\nExecution time for Selection-sort : %f seconds", (double)(end_t - start_t) / CLOCKS_PER_SEC);
  
  start_t = clock();
  quickSort(data, 0, max - 1);
  end_t = clock();
  printf("\nQuick Sort: ");
  printArray(data, max);
  printf("\nExecution time for Quick-sort : %f seconds", (double)(end_t - start_t) / CLOCKS_PER_SEC);
}