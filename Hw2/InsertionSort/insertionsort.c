#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
   printf("Enter your input file :\n");
   char  file  [20];
   scanf("%s",file);

  /* int k_element ;
   printf("Enter the smallest element you would like to :\n");
   scanf("%d",&k_element); */

   FILE *fptr =  fopen(file,"r");
    int number [1000],i=0;
    clock_t t1,t2;

   if (fptr == NULL)
     printf("File does not exists \n");

    fscanf (fptr, "%ld\n",&number[0]);
    while (!feof (fptr)) //
     {
       i++;
       fscanf (fptr, "%ld\n",&number[i]);
       if (i==1000)
         break;
     }
      fclose(fptr);
      i=0;
      for (i=0;i<1000;i++)
       printf("%d\n",number[i]);

     t1 = clock ();
     int element = insertionSort(number, 0, 1000 , 3);
     t2 = clock ();
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",3,element);
     printf("Time :%lf\n",sec);

     t1 = clock ();
     int element1 = insertionSort(number, 0, 1000 ,255);
     t2 = clock ();
     float sec1 = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",255,element1);
     printf("Time :%lf\n",sec1);

     t1 = clock ();
     int element2 = insertionSort(number, 0, 1000 , 990);
     t2 = clock ();
     float sec2 = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",990,element2);
     printf("Time :%lf",sec2);


return 0;

}
