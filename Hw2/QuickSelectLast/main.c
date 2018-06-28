#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int *A, int left, int right){
    int pivot = A[left], i = right, x;

    for (x = left; x < right; x++){
        if (A[x] <= pivot){
            swap(&A[i], &A[x]);
            i++;
        }
    }

    swap(&A[i], &A[right]);
    return i;
}


int quickSelect(int *A, int left, int right, int k){

    //p is position of pivot in the partitioned array
    int p = partition(A, left, right);

    //k equals pivot got lucky
    if (p == k-1){
        return A[p];
    }
    //k less than pivot
    else if (k - 1 < p){
        return quickSelect(A, left, p - 1, k);
    }
    //k greater than pivot
    else{
        return quickSelect(A, p + 1, right, k);
    }
}

int ksmallest(int *A, int n, int k){

    int left = 0;
    int right = n - 1;

    return quickSelect(A, left, right, k);
}


int main()
{
   printf("Enter your input file :\n");
   char  file  [20];
   scanf("%s",file);

 /*  int k_element ;
   printf("Enter the smallest element you would like to :\n");
   scanf("%d",&k_element);*/

   FILE *fptr =  fopen(file,"r");
    int number [5000],i=0;
    clock_t t1,t2;

   if (fptr == NULL)
     printf("File does not exists \n");

    fscanf (fptr, "%ld\n",&number[0]);
    while (!feof (fptr)) //
     {
       i++;
      fscanf (fptr, "%ld\n",&number[i]);

     }
      fclose(fptr);


     t1 = clock ();
     int element = ksmallest(number, 5000 , 3);
     t2 = clock ();
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",3,element);
     printf("Time :%lf \n",sec);


 /*   t1 = clock ();
     int element1 = quickSelect(number, 0, 5000 , 2550);
     t2 = clock ();
     float sec1 = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",2550,element1);
     printf("Time :%lf \n",sec1);

     t1 = clock ();
     int element2 = quickSelect(number, 0, 5000 , 4900);
     t2 = clock ();
     float sec2 = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",4900,element2);
     printf("Time :%lf \n",sec2);*/

    return 0;
}
