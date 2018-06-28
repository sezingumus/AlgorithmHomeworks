#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//It replaces the elements.
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
//By using median of three partition , an index is selected as a pivot for an array that will be searched by quickselect
int median3(int a[], int left, int right)
{
//If the array has less than two elements
if (abs(right - left) < 2 )
     {
       if (a[right]< a[left])
         return a[right];

        else
          return a[left];

     }

    else
    {
    int center = (left + right)/2;  //Middle element of the array a
    int index = center; //index of pivot element
    //First , last and middle element of an array are choseen and
    // median of these three element is calculated ,
    //then we will find the index of median that we should use for quickselect
    if (a[center] < a[left])
    { swap(&a[left],&a[center]);
     index=left;}

    if (a[right-1] < a[center])
     { swap(&a[right-1],&a[center]);
      index=right-1;}

    if (a[center] < a[left])
        {swap(&a[center],&a[left]);
        index = center;}
     return index;
    }

}

//This function finds k th smallest element in a given array by using quickselect algorithm
int quickSelect (int a [] ,int l , int r , int k)
{
 if (l<=r)
 {
 int s =median3(a,l,r);
 if (s == k-1)
  return a[s];
 else if (s >  k - 1 )
  quickSelect(a ,l, s - 1 ,k);
 else
  quickSelect(a , s + 1 , r , k);
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
     int element = quickSelect(number,0, 5000,k_element);
     t2 = clock (); //Finish to measure time
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC; //Finds the execution time of quickselect
     printf("%d th smallest element is : %d \n",k_element,element);
     printf("Time :%lf \n",sec);


    return 0;

}
