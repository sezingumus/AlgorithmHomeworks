#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
//Finding k th smallest number by using MergeSort Algorithm
/*
Sezin Gümüş 150113841
Ufuk Çetinkaya 150113824
*/

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


// This method finds k th smallest element by using mergesort algorithm
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

   if (fptr == NULL)   //If the entered input file does not exist.
     printf("File does not exists \n");

    fscanf (fptr, "%ld\n",&number[0]);
    while (!feof (fptr))
       i++;
       fscanf (fptr, "%ld\n",&number[i]);
     }
      fclose(fptr);


     t1 = clock (); //Begin to measure time
     int element = mergeSort(number,5000, 3);
     t2 = clock ();  //Finish to measure time
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("%d th smallest element is : %d \n",k_element,element); //Finds the execution time of Mergesort Algorithm
     printf("Time :%lf\n",sec);


    return 0;
}
