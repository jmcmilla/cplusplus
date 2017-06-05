#include <iostream>
#include <stdint.h>
using namespace std;

void printfArray(int *arr, int size)
{
  for(int i = 0; i < size; i++)
  {
  cout << arr[i] << ",";
  }
  cout << endl;
}

int first(int arr[], int size)
{
  int smallidx = 0;
  for( int i = 0; i < size; i++)
    {
    if( arr[smallidx] > arr[i])
        {
        smallidx = i;
        }
    }
  return smallidx;
}


int * sort(int *arr, int size)
{
  int *copy;
  copy = new int[size];
  for(int a = 0; a < size; a++)
    {
    copy[a] = arr[a];
    }
  int *sortedarr;
  sortedarr = new int[size];
  for( int i = 0; i < size; i++)
    {
    int j = first(copy, size);
    sortedarr[i] = copy[j];
    copy[j] = INT_MAX;
    }
  delete[] copy;
  return sortedarr;
}


int main()
  {
  int Arry[4]={8, 2, 9, 5};
  printfArray(Arry, 4);
  printfArray(sort(Arry, 4), 4);
  printfArray(Arry, 4);

  return 0;
  }
