
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 23

void swap ( int *a, int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int partition(int *a, int high){ //high is the last index of this array
    int i,j,pivotValue;
    i = -1;
    j = 0;
    pivotValue = a[high];
    for ( j=0; j<high; j++){
        if ( a[j]> pivotValue){
            continue;
        }
        i++;
        swap(&a[i], &a[j]);
    }
    return i+1;
}
int quickSelect(int a[],int n, int k) { //n is the size of the array
    int pivotIndex;
    pivotIndex = partition(a, n-1);
    if ( pivotIndex >= k ){//left.size = pivotIndex
        printf("left\n");

        return quickSelect(a, pivotIndex, k);
    }
    else if ( (pivotIndex+1)==k ){
        printf("pivot\n");
        return a[n-1];
    }
    else{
        printf("right\n");
        return quickSelect(&a[pivotIndex], n-(pivotIndex+1), k-(pivotIndex+1));
    }
}


int main()
{
int a[] = {1612,1894,3018,4212,6046,12894,13379,14408,14615,16394,17982,23004,27588,31393,33195,39526,54326,54566,60000,60000,60000,60000,703908};

    int find,k;

    k = floor(N*0.9)+1;
    printf("k=%d\n",k);

    find = quickSelect(a, N, k);

    printf("the 90th number=%d\n",find);

    return 0;
}
