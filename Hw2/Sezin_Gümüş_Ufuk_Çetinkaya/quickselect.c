
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Finding k th smallest number by using QuickSelect Algorithm
/*
Sezin Gümüş 150113841
Ufuk Çetinkaya 150113824
*/

//It replaces the elements.

void swap(int *x, int *y)
{
    int  temp = *x;
    *x = *y;
    *y = temp;
}

//Partitions subarray by Lomuto’s algorithm using first element as pivot
//to quickSelect method

//Input: A subarray A[l..r] of array A[0..n − 1], defined by its left and right
//indices l and r (l ≤ r)
//Output: Partition of A[l..r] and the new position of the pivot

int lomutoPartition (int a [] ,int l,int r)
{
 int p = a[l];
 int s = l;
 int i;

 for (i=l+1;i<r;i++)
 {
    if (a[i] < p)
    {
     s = s + 1 ;
     swap (&a[s],&a[i]);
    }
  swap( &a[l],&a[s]);
 }
 return s;
}


//This function finds k th smallest element in a given array by using quickselect algorithm
//uses Lomuto Partioning Algorithm

//Solves the selection problem by recursive partition-based algorithm
//Input: Subarray A[l..r] of array A[0..n − 1] of orderable elements and
//integer k (1 ≤ k ≤ r − l + 1)
//Output: The value of the kth smallest element in A[l..r]

int quickSelect (int a [] ,int l , int r , int k)
{
 if (l<=r)
 {
 int s = lomutoPartition(a,l,r);
 if (s == k-1)
  return a[s];
 else if (s >  k )
  quickSelect(a ,l, s-1 ,k);
 else
  quickSelect(a , s+1 , r , k );
 }

}


int main()
{

  // input file in where to be searched k th smallest element

   printf("Enter your input file :\n");
   char  file  [20];
   scanf("%s",file);

   //k th smallest number we would like to find

   int k_element ;
   printf("Enter the smallest element you would like to :\n");
   scanf("%d",&k_element);

   //Numbers in a entered file as an input are transferred to numbers array whose size is 5000.
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


     t1 = clock (); //Begin to measure time
     int element = quickSelect(number, 0, 5000 , k_element);
     t2 = clock ();  //Finish to measure time
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",k_element,element);//Finds the execution time of Quickselect with Lomuto Partitioning Algorithm
     printf("Time :%lf \n",sec);


    return 0;
}
