// An iterative implementation of quick sort
#include <stdio.h>
#include <time.h>
// A utility function to swap two elements
void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

int median3(int a[], int left, int right)//Uses median of three partitioning technique
{
    int center = (left + right)/2;
    if (a[center] < a[left])
        swap(&a[left],&a[center]);
    if (a[right] < a[left])
        swap(&a[left],&a[right]);
    if (a[right]< a[center])
        swap(&a[center],&a[right]);

    swap(&a[center], &a[right - 1]);//since the largest is already in the right.
    return a[right - 1];
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

/* A[] --> Array to be sorted,
   l  --> Starting index,
   h  --> Ending index */
void quickSortIterative (int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[ h - l + 1 ];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;



    if (h-l > 100)
     {
      insertionSort(arr,l,h+1);
     }
     else
      {
          // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];

        // Set pivot element at its correct position
        // in sorted array
        int p = median3( arr, l, h );

        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
      }

}

// A utility function to print contents of arr
void printArr( int arr[], int n )
{
    int i;
    for ( i = 0; i < n; ++i )
        printf( "%d \n", arr[i] );
}

// Driver program to test above functions
int main()
{
    FILE *fptr =  fopen("mixdata.txt","r");
    int number [5000],i=0;
    clock_t t1,t2;
   if (fptr == NULL)
     printf("File does not exists \n");


    //int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
    //int n = sizeof( arr ) / sizeof( *arr );

    fscanf (fptr, "%ld\n",&number[0]);
    while (!feof (fptr)) //
     {
       i++;
       fscanf (fptr, "%ld\n",&number[i]);
     }
      fclose(fptr);


    t1 = clock ();
    quickSortIterative( number, 0, 5000 );
     t2 = clock ();
     float sec = (float)(t2-t1)/CLOCKS_PER_SEC;
     printf("Time:%lf",sec);

    return 0;
}
