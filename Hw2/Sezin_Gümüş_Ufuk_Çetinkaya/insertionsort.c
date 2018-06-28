#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Finding k th smallest number by using Insertion Sort Algorithm

/*
Sezin Gümüş 150113841
Ufuk Çetinkaya 150113824

*/

//This method finds k th smallest element by using insertion sort method.
//s:starting point
//e:ending point for sorting
int insertionSort  (int  list [],int s, int e ,int k)
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
return list [k-1];
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
    while (!feof (fptr))
     {
       i++;
       fscanf (fptr, "%ld\n",&number[i]);
     }
      fclose(fptr);
      i=0;
      for (i=0;i<5000;i++)
       printf("%d\n",number[i]);

     t1 = clock (); //Begin to measure time
     int element = insertionSort(number, 0, 5000 , k_element);
     t2 = clock (); //Finish to measure time
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC; //Finds the execution time of Insertionsort Algorithm
     printf("%d th smallest element is : %d \n",3,element);
     printf("Time :%lf\n",sec);


return 0;

}
