#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_M 2u
#define SIZE_N 2u

int mArray_wrd[SIZE_M] = {2,5}; 
int nArray_wrd[SIZE_N] = {2,6};

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main() 
{

   printf("The median is %f", findMedianSortedArrays(&mArray_wrd[0], SIZE_M, &nArray_wrd[0], SIZE_N));

   return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    double medianLocal_db = 0.0;
    
    int totalSize_wrd = (nums1Size+nums2Size); 

    int minorNumber_wrd = 0;
    int indexM = 0;
    int indexN = 0;
    int indexStop = totalSize_wrd/2;
    
    unsigned char isOdd = 0u;

    /* Define the array to hold the complete sorted values */
    int *mergedArray;
    mergedArray = (int *) malloc(totalSize_wrd*sizeof(int)); 

    if((totalSize_wrd)&((int)1))
    {
        isOdd = 1u;
    }
    else
    {

    }

    for(int index = 0; index < totalSize_wrd; index++)
    {
        if(indexStop >= index)
        {
            if(indexM >= nums1Size)
            {
                memcpy(&mergedArray[index], &nums2[indexN], (totalSize_wrd-index)*sizeof(int));
                break;
            }
            else if(indexN >= nums2Size)
            {
                memcpy(&mergedArray[index], &nums1[indexM], (totalSize_wrd-index)*sizeof(int));
                break;
            }
            else
            {
                
            }

            if(nums1[indexM] < nums2[indexN])
            {
                minorNumber_wrd = nums1[indexM];
                indexM++;
            }
            else
            {
                minorNumber_wrd = nums2[indexN];
                indexN++;
            }
            
            mergedArray[index] = minorNumber_wrd;
        }
        else
        {
            break;
        }
    }

    if(isOdd)
    {
        medianLocal_db = (double)mergedArray[indexStop];
    }
    else
    {
        medianLocal_db = ((double)mergedArray[indexStop]+(double)mergedArray[indexStop-1]);
        medianLocal_db /= (double)2.0;
    }
    
    free(mergedArray);

    return medianLocal_db;
}