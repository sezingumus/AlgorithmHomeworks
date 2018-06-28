#include <stdio.h>
#include <math.h>

int binarySearch(int arr[])
{
     int length = sizeof(arr)/ sizeof(arr[0]);
     int middle = ceil (length/2);

     int left_side = middle - 0;
     int right_side = length - middle - 1;
     int right_middle = 0 ;
     int left_middle = 0;

     if (left_side > right_side)
     {

       while ( middle < length )
       {
         right_middle = (length - middle) / 2;
         middle =middle + right_middle ;
          printf("Right : %d /n",middle);
       }
     }


     else if (left_side ==  right_side)
     {
      printf("No missing element\n");
      return -1;
     }

    else
    {

    printf("Left /n");
    while (middle >= left_middle)
    {
    left_middle = (middle -length) / 2;
        middle = middle - left_middle;
    }

    }
    // if we reach here, then element was
    // not present


}

int main()
{
    int arr[8] = {1,2,3,4,5,6,8,9};
    int missing = binarySearch(arr);
    printf("/n missing :%d",missing);

    return 0;
}
