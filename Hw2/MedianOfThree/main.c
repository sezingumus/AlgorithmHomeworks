#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


/*
l : first index of the array number
r : last index of the array number
*/


/*Median of three algorithm ,
Selects a median from the leftmost , middle and rightmost elements
*/
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int * median3(int a[], int left, int right)//Uses median of three partitioning technique
{

if ((right - left) < 2 )
     {
       if (a[right]< a[left])
         return a[right];
        else
          return a[left];
     }

    else
    {
    int center = (left + right)/2;
    if (a[center] < a[left])
        swap(&a[left],&a[center]);
    if (a[right] < a[left])
        swap(&a[left],&a[right]);
    if (a[right]< a[center])
        swap(&a[center],&a[right]);
    return a;//&a[center];
    }

}


/* Quickselect algorithm to find  k th smallest element,
To find a pivot element , this function uses median of three algorithm*/

int quickSelect (int a [] ,int l , int r , int k)
{

if ( l == r)
  return a[l];

 else
 {
 if (l<r)
 {
 if (0<k && k <= r-l+1)
 {
 int s = median3(a,l,r); //pivot element
 if (s == k -1 ) //if pivot elemnt equals to k , we find the k th smallest elemnt
  return a[s];
 else if (s > l + k - 1 /*k*/ )  //if pivot elemnet is greater than  k-1
  quickSelect(a ,l, s-1  ,k); //Checks the left part
 else  //if pivot elemnet is less than  k-1
  quickSelect(a , s+1 , r , k - 1 - s); //Checks the right part
 }

 }
 }
}



int main()
{
 /*
   User enters a file and k th smallest element of
   an orderable array
   Numbers are transferred to an array number from the entered
   input file and  k th smallest element is found by using quick-
   select algorithm with median of three algorithm
   max size of number array is 5000.
 */
 printf("Enter your input file :\n");
   char  file  [20];
   scanf("%s",file);

   int k_element ;
   printf("Enter the smallest element you would like to :\n");
   scanf("%d",&k_element);

   FILE *fptr =  fopen(file,"r");
    int number [5000],i=0;
    clock_t t1,t2;

   if (fptr == NULL) //If the entered input file does not exist.
     printf("File does not exists \n");

    fscanf (fptr, "%ld\n",&number[0]);
    while (!feof (fptr)) //
     {
       i++;
       fscanf (fptr, "%ld\n",&number[i]);
     }
      fclose(fptr);


      int d [] = {1,2,6,3,5,9,8};
      int * e  = median3(d,0,7);
    /*  for (i=0;i<7;i++)
       printf("%d\n",A[i]);*/
        printf("%d\n",d[0]);
    //  printf("%d",quickSelect(A,0,7,3,7));
    /* t1 = clock (); //Begin to measure time
     int element = quickSelect(number,0, 5000,k_element,5000);
     t2 = clock (); //Finish to measure time
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC; //Finds the execution time of quickselect
     printf("%d th smallest element is : %d \n",k_element,element);
     printf("Time :%lf \n",sec);*/

    return 0;

}
