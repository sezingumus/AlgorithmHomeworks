
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//QuickSelect

void swap(int *x, int *y)
{
    int  temp = *x;
    *x = *y;
    *y = temp;
}



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


   printf("Enter your input file :\n");
   char  file  [20];
   scanf("%s",file);

   /*int k_element ;
   printf("Enter the smallest element you would like to :\n");
   scanf("%d",&k_element);*/

   FILE *fptr =  fopen(file,"r");
    int number [1000],i=0;
    clock_t t1,t2;

   if (fptr == NULL)
     printf("File does not exists \n");

    fscanf (fptr, "%ld\n",&number[0]);
    while (!feof (fptr)) //
     {
       if (i == 1000)
        break;
       i++;
      fscanf (fptr, "%ld\n",&number[i]);

     }
      fclose(fptr);


     t1 = clock ();
     int element = quickSelect(number, 0, 1000 , 3);
     t2 = clock ();
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",3,element);
     printf("Time :%lf \n",sec);

     t1 = clock ();
     int element1 = quickSelect(number, 0, 1000 , 255);
     t2 = clock ();
     float sec1 = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",255,element1);
     printf("Time :%lf \n",sec1);

     t1 = clock ();
     int element2 = quickSelect(number, 0, 1000 , 990);
     t2 = clock ();
     float sec2 = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",990,element2);
     printf("Time :%lf \n",sec2);

    return 0;
}
