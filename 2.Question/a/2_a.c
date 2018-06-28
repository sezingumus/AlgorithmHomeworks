#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//2.Question part a
struct treeNode {
struct treeNode *leftPtr; /* pointer to left subtree */
int data; /* node value */
struct treeNode *rightPtr; /* pointer to right subtree */
}; /* end structure treeNode */
typedef struct treeNode TreeNode; /* synonym for struct treeNode */
typedef TreeNode *TreeNodePtr; /* synonym for TreeNode* */
/* prototypes */
void insertNode( TreeNodePtr *treePtr, int value );
void inOrder( TreeNodePtr treePtr );
void preOrder( TreeNodePtr treePtr );
void postOrder( TreeNodePtr treePtr );


int main( void )
{

int i; /* counter to loop for construct binary tree */
TreeNodePtr rootPtr = NULL; /* tree initially empty */
TreeNodePtr root2Ptr = NULL; /* tree initially empty */
TreeNodePtr root3Ptr = NULL; /* tree initially empty */


//Middle element of the arrays
int  numbers [8] = {-2,-5,6,-2,-3,1,5,-6};
int length = sizeof(numbers)/sizeof(int);
int pivot = ceil(length/2);

int  numbers2 [9] = {-2,-5,6,-2,-3,1,5,5,-8};
int length2 = sizeof(numbers2)/sizeof(int);
int pivot2 = ceil(length2/2);

int  numbers3 [6] = {-2,-2,-3,1,5,4};
int length3 = sizeof(numbers3)/sizeof(int);
int pivot3 = ceil(length3/2);

//middle element is put to the root of the binary search tree

insertNode(&rootPtr,numbers[pivot]);
insertNode(&root2Ptr,numbers2[pivot2]);
insertNode(&root3Ptr,numbers3[pivot3]);

//Adding elements of the arrays in a binary Search Tree
for ( i = 0; i < length; i++ ){
if (i != pivot)
insertNode( &rootPtr, numbers[i] );
}

for ( i = 0; i < length2; i++ ){
if (i != pivot2)
insertNode( &root2Ptr, numbers2[i] );
}

for ( i = 0; i < length3; i++ ){
if (i != pivot2)
insertNode( &root3Ptr, numbers3[i] );
}

printf("sum for numbers:\n");
find_max_sum(rootPtr);

printf("sum for numbers2:\n");
find_max_sum(root2Ptr);

printf("sum for numbers3:\n");
find_max_sum(root3Ptr);


return 0;
}

//This method finds the sum of the subsequence that has largest sum

void find_max_sum (TreeNodePtr treeptr)
{
if (treeptr != NULL)  //The tree is not empty
{
int sum = 0;
while (treeptr != NULL)
{
 sum += treeptr->data;
  //If the right child of the node is empty but still has a left child , this element will be
  //added to sum.
 if(treeptr->rightPtr == NULL && treeptr->leftPtr != NULL)
 {
   treeptr = treeptr->leftPtr;
   sum += treeptr->data;
 }
 treeptr = treeptr->rightPtr;
}
 printf("Sum :%d \n",sum);
}
else //If the tree is empty
{
  printf("Tree is empty \n");
  return -1;
}



}


void insertNode( TreeNodePtr *treePtr, int value )
{
/* if tree is empty */
if ( *treePtr == NULL ) {
*treePtr = malloc( sizeof( TreeNode ) );
/* if memory was allocated then assign data */
if ( *treePtr != NULL ) {
( *treePtr )->data = value;
( *treePtr )->leftPtr = NULL;
( *treePtr )->rightPtr = NULL;
} /* end if */
else {
printf( "%d not inserted. No memory available.\n", value );
} /* end else */
} /* end if */
else { /* tree is not empty */
/* data to insert is less than data in current node */
if ( value <= ( *treePtr )->data ) {
insertNode( &( ( *treePtr )->leftPtr ), value );
} /* end if *
/* data to insert is greater than data in current node */
else  {
insertNode( &( ( *treePtr )->rightPtr ), value );
} /* end else if */
/* end else */
} /* end else */
} /* end function insertNode */



