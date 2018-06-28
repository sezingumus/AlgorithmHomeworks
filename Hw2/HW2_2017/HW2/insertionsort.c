#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void quickSort (int  list [] ,int s, int e)
{
if (s<e)
{
 if (e-s >100)
   {
     insertionSort (list,s,e+1);
   }
   else
   {
    int part = partition(list,s,e);
    quickSort(list,s,part-1);
    quickSort(list,part+1,e);
   }
}
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

int partition (int list [] ,int l ,int r)

{
int left = l;
int right = r;
int pivot = list[l];
while (l<r)
  {
   if  (list[left]<pivot)
      left++;
    else if (list[right]<pivot)
        right--;

    int tmp = list[left];
    list[left] = list[right];
    list [right] = tmp;
    left++;
   }
return left;

}


int main()
{
   /*printf("Enter your input file :\n");
   char  file  [20];
   scanf("%s",file);

   int element ;
   printf("Enter the smallest element you would like to :\n");
   scanf("%d",&element);*/

   FILE *fptr =  fopen("mixdata.txt","r");
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
    quickSort(number, 0, 5000 );
     t2 = clock ();
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("Time :%lf",sec);



}
