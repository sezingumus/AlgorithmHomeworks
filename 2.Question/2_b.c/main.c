#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Second question part b



int main( void )
{
//Inputs and outputs
int numbers [10] = {2,5,0,3,5,0,10,2,1,2};
int length = sizeof(numbers)/sizeof(int);
printf("Length of longest negative path for numbers is :%d \n",longest_negative_path(numbers,length));

int numbers1 [10] = {2,5,0,-3,-5,0,-1,-2,-1,2};
int length1 = sizeof(numbers1)/sizeof(int);
printf("Length of longest negative path for numbers1 is :%d \n",longest_negative_path(numbers1,length1));

int numbers2 [10] = {2,5,0,-3,-5,-3,-1,-2,-1,2};
int length2 = sizeof(numbers2)/sizeof(int);
printf("Length of longest negative path for numbers2 is :%d \n",longest_negative_path(numbers2,length1));

return 0;
}

/*middle  = middle element of index of the array
max_l = longest negative path of left path
max_r = longest negative path of right path
c_left = counter for negative path in the left side of the array
c_right = counter for negative path in the right side of the array
max_total = longest negative path in this array*/

int longest_negative_path (int number [] , int length)
{
int i;
int middle = ceil(length/2);
int max_l = 0, max_r = 0,c_left=0,c_right=0 , max_total;

//Finds longest negative path in left part , number [0 to middle]

for (i= 0;i<middle;i++)
{
 if (number[i] < 0 && number [i+1] <0)
 {
  c_left ++;
  if (c_left > max_l)
    max_l = c_left;
 }
 else
  {
   c_left = 0;   //If a positive number comes next element , counter will be set to 0.
  }
}

//Finds longest negative path in left part , number [middle to length]

for (i= middle+1;i<length;i++)
{
 if (number[i] < 0 && number [i+1] <0)
 {
  c_right ++;
  if (c_right > max_r)
   max_r = c_right; //If there is a corrupted alternating path , max_l will keep previous longest alternating path
 }

 else
  {
   c_right = 0;  //If a positive number comes next element , counter will be set to 0.
  }
}

/*Middle element of the array is checked , if it is a negative number
next and previous of the elements will be chechked to see whether
they are negative or not .If the condition is provided , then negative path
begins from left part and ends in right path*/

/*If the longest path is in the left part , then max_l will be longest path*/
/*If the longest path is in the right part , then max_r will be longest path*/
if (number[middle] < 0 && number[middle-1] < 0 && number[middle+1] <0)
 max_total = max_l + max_r + 2;
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




