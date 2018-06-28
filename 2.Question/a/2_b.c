
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//2.soru a şıkkı
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

int i; /* counter to loop from 1-10 */
int item; /* variable to hold random values */
TreeNodePtr rootPtr = NULL; /* tree initially empty */

/* insert random values between 0 and 14 in the tree */
int  numbers [8] = {-2,-5,6,-2,-3,1,5,-6};
int lenghth = sizeof(numbers)/sizeof(int);
int pivot = ceil(lenghth/2);


insertNode(&rootPtr,numbers[pivot]);

for ( i = 0; i < lenghth; i++ ){
if (i != pivot)
insertNode( &rootPtr, numbers[i] );
}


find_max_sum(rootPtr);
 /* end for */
/* traverse the tree preOrder */

return 0; /* indicates successful termination */
} /* end main */
/* insert node into tree */

void find_max_sum (TreeNodePtr treeptr)
{
if (treeptr != NULL)
{
int sum = 0;
while (treeptr != NULL)
{
 sum += treeptr->data;

 if(treeptr->rightPtr == NULL && treeptr->leftPtr != NULL)
 {
   treeptr = treeptr->leftPtr;
   sum += treeptr->data;
 }
 treeptr = treeptr->rightPtr;
}
 printf("Sumx :%d \n",sum);
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
/* begin inorder traversal of tree */
void inOrder( TreeNodePtr treePtr )
{
/* if tree is not empty then traverse */
if ( treePtr != NULL ) {
inOrder( treePtr->leftPtr );
printf( "%3d", treePtr->data );
inOrder( treePtr->rightPtr );
} /* end if */
} /* end function inOrder */

