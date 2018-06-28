/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// merge the vectors
void merge(int vec_left[], int vec_right[],
				int vec[], int size_vec_left, int size_vec_right, int size_vec)
{
	int i = 0, j = 0, k = 0;

	// makes the merge
	while(i < size_vec_left && j < size_vec_right)
	{
		if(vec_left[i] <= vec_right[j])
		{
			vec[k] = vec_left[i];
			i++;
		}
		else
		{
			vec[k] = vec_right[j];
			j++;
		}
		k++;
	}

	// fills with the rest of the elements
	while(i < size_vec_left)
	{
		vec[k] = vec_left[i];
		i++;
		k++;
	}

	while(j < size_vec_right)
	{
		vec[k] = vec_right[j];
		j++;
		k++;
	}
}


// merge sort algorithm
int mergeSort(int vec[], int size_vec , int k)
{
	int *vec_left, *vec_right;
	int i, middle;

	if(size_vec < 2) // base condition
		return;

	middle = size_vec / 2; // gets the middle of the vector

	// creates two vectors
	vec_left = (int*)malloc(middle * sizeof(int));
	vec_right = (int*)malloc((size_vec - middle) * sizeof(int));

	// fills the vectors
	for(i = 0; i < middle; i++)
		vec_left[i] = vec[i];
	for(i = middle; i < size_vec; i++)
		vec_right[i - middle] = vec[i];

	// recursive calls
	mergeSort(vec_left, middle , k);
	mergeSort(vec_right, size_vec - middle,k);
	merge(vec_left, vec_right, vec, middle, size_vec - middle, size_vec);

	free(vec_right);
	free(vec_left);

	return vec[k-1];
}

void printArray (int a [],int array_size)
 {
  int i;
  for (i=0;i<array_size;i++)
   printf("%d-",a[i]);
  printf("\n");
 }

int main()
{
   printf("Enter your input file :\n");
   char  file  [20];
   scanf("%s",file);

  /* int k_element ;
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
     int element = mergeSort(number,5000, 3);
     t2 = clock ();
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",3,element);
     printf("Time :%lf\n",sec);


     t1 = clock ();
     int element1 = mergeSort(number,5000, 2550);
     t2 = clock ();
     float sec1 = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",2550,element);
     printf("Time :%lf\n",sec1);

     t1 = clock ();
     int elemen2 = mergeSort(number,5000, 4900);
     t2 = clock ();
     float sec2 = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",4900,element);
     printf("Time :%lf\n",sec2);

    return 0;
}
