#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
void quickSort (int  list [] ,int s, int e)
{
if (s<e)
{
 if (e-s > 100)
   {
     insertionSort (list,s,e+1);
   }
   else
   {
    int part =median3(list,s,e);
    quickSort(list,s,part-1);
    quickSort(list,part+1,e);
   }
}
}


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return ;
}


int median3(int a[], int left, int right)//Uses median of three partitioning technique
{
    int center = (left + right)/2;
    if (a[center] < a[left])
        swap(&a[left],&a[center]);
    if (a[right] < a[left])
        swap(&a[left],&a[right]);
    if (a[right]< a[center])
        swap(&a[center],&a[right]);

    swap(&a[center], &a[right - 1]);//since the largest is already in the right.
    return a[right - 1];
}

void insertionSort (int  list [],int s, int e)
{
int i =0;
  for (i=s+1;i<e;i++)
   {
      int val = list [i];
      int j = i-1;
      while (j>= 0 && val < list[j])
      {
        list [j+1] = list[j];
        j--;
      }
      list[j+1]= val;
   }
}

int main()
{
   FILE *fptr =  fopen("mixdata.txt","r");
    int number [5000],i=0;
    clock_t t1,t2;
   if (fptr == NULL)
     printf("File does not exists \n");


    //int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
    //int n = sizeof( arr ) / sizeof( *arr );

    fscanf (fptr, "%ld\n",&number[0]);
    while (!feof (fptr)) //
     {
       i++;
       fscanf (fptr, "%ld\n",&number[i]);
     }
      fclose(fptr);


     t1 = clock ();
    quickSort(number, 0, 5000 );
     t2 = clock ();
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("Time---:%lf",sec);
       return 0;


}
