#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

void quicksort(int a[], int left, int right)
{
  if (left < right) {

    if (left<right)
    {
      int pivot = median3(a,left,right);
      if (left == right-1) return;
      int i = left;
    int j = right - 1;
    for ( ; ;) {
        while(a[++i]<pivot) {}
        while(pivot<a[--j]) {}
        if ( i < j)
            swap(&a[i],&a[j]);
        else
            break ;
    }
    swap(&a[i],& a[right -1]);
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
  }
    }

    return ;
}

int main(int argc, char* argv[])
{

FILE *fptr =  fopen("decrease.txt","r");
    int number [2500],i=0;
    clock_t t1,t2;
   if (fptr == NULL)
     printf("File does not exists \n");


    //int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
    //int n = sizeof( arr ) / sizeof( *arr );

    fscanf (fptr, "%ld\n",&number[0]);
    while (i<2500) //!feof (fptr)
     {
       i++;
       fscanf (fptr, "%ld\n",&number[i]);
     }
      fclose(fptr);


     t1 = clock ();
    quicksort(number, 0, 2500 );
     t2 = clock ();
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("Time.... :%lf \n",sec);

     for (i=0;i<2500;i++)
       printf("%d \n",number[i]);


    return 0;
}


