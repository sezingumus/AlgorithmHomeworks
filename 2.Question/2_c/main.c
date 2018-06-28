#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//2. question part c

int main( void )
{

//Inputs and outputs
int numbers[15] = {0, 1, 0, 1, 0, 0, 0, 1, 0,1,0,1,0,1,1};
int length = sizeof(numbers)/sizeof(int);
printf("Longest alternating path for numbers: %d\n",longest_alternating_path(numbers,length));

int numbers2 [8] = {1, 1, 1, 0,1 ,0 , 1, 1};
int length2 = sizeof(numbers2)/sizeof(int);
printf("Longest alternating path for numbers2: %d\n",longest_alternating_path(numbers2,length2));

int numbers3 [15] = {0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1};
int length3 = sizeof(numbers3)/sizeof(int);
printf("Longest alternating path for numbers3: %d\n",longest_alternating_path(numbers3,length3));
return 0;
}

int longest_alternating_path (int number [] , int length)
{
int i; //For loop

/*middle  = middle element of index of the array
max_l = longest alternating path of left path
max_r = longest alternating path of right path
c_left = counter for alternating path in the left side of the array
c_right = counter for alternating path in the right side of the array
max_total = longest alternating path in this array*/


int middle = ceil(length/2);
int max_l = 0, max_r = 0,c_left=0,c_right=0 , max_total;

//Finds longest alternating path in left part , number [0 to middle]

for (i= 0;i<middle;i++)
{
 if (number[i] != number [i+1] )
 {
  c_left ++;
  if (c_left > max_l)
    max_l = c_left;  //If there is a corrupted alternating path , max_l will keep previous longest alternating path
 }
 else
  {
   c_left = 0; //If the current element is equal to the next element , counter will be set to 0.
  }
}

//Finds longest alternating path in right part , number [middle to length]

for (i= middle+1;i<length-2;i++)
{
 if (number[i] != number [i+1] )
 {
  c_right ++;
  if (c_right > max_r)
   max_r = c_right;  //If there is a corrupted alternating path , max_r will keep previous longest alternating path
 }

 else
  {
   c_right = 0; //If the current element is equal to the next element , counter will be set to 0.
  }
}


/*Middle element of the array is checked , if this element is not equal to the previous and next element ,
the longest alternating path may begin from left and end with right part . To see this  , if counter is not zero ,
we can say that this path begins from left and end with right part . */

/*If the longest path is in the left part , then max_l will be longest path*/
/*If the longest path is in the right part , then max_r will be longest path*/


if ( number[middle] != number[middle+1] && number[middle] != number [middle-1] )
 max_total = c_left + max_r + 2;
else
{
 if (max_l > max_r)
  max_total = max_l + 1;
 else if (max_l == 0 && max_r == 0)
  max_total = 0;
 else
  max_total = max_r + 1 ;
}

return max_total;
}




