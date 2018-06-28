#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int  median3(int a[], int left, int right)//Uses median of three partitioning technique
{
int index;
if (abs(right - left) < 2 )
     {
       if (a[right]< a[left])
         return a[right];
        else
          return a[left];
     }

    else
    {
    int center = (left + right)/2;
    index = center;
    if (a[center] < a[left])
    { swap(&a[left],&a[center]);
     index=left;}
       
    if (a[right-1] < a[center])
     { swap(&a[right-1],&a[center]);
      index=right-1;}
       
    if (a[center] < a[left])
        {swap(&a[center],&a[left]);
         index=left;}
   
      
     return index;
    }
         
}

int quickSelect (int a [] ,int l , int r , int k)
{
 if (l<=r)
 {
 int s = median3(a,l,r);
 if (s == k-1)
  return a[s];
 else if (s >  k )
  quickSelect(a ,l, s-1 ,k);
 else
  quickSelect(a , s+1 , r , k - 1 - s );
 }

}



int main()
{
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


     /* int d [] = {1,2,6,3,5,9,8};
      int * e  = median3(d,0,7);*/
    /*  for (i=0;i<7;i++)
       printf("%d\n",A[i]);*/
      //  printf("%d\n",d[0]);
    //  printf("%d",quickSelect(A,0,7,3,7));
     t1 = clock (); //Begin to measure time
     int element = quickSelect(number,0, 5000,k_element);
     t2 = clock (); //Finish to measure time
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC; //Finds the execution time of quickselect
     printf("%d th smallest element is : %d \n",k_element,element);
     printf("Time :%lf \n",sec);

     /*t1 = clock (); //Begin to measure time
     int element1 = quickSelect(number,0, 5000,2550);
     t2 = clock (); //Finish to measure time
     float sec1 = (float)(t2-t1)/CLOCKS_PER_SEC; //Finds the execution time of quickselect
     printf("%d th smallest element is : %d \n",2550,element1);
     printf("Time :%lf \n",sec);

     t1 = clock (); //Begin to measure time
     int element2 = quickSelect(number,0, 5000,4900);
     t2 = clock (); //Finish to measure time
     float sec2 = (float)(t2-t1)/CLOCKS_PER_SEC; //Finds the execution time of quickselect
     printf("%d th smallest element is : %d \n",4900,element2);
     printf("Time :%lf \n",sec2);*/



    return 0;

}
