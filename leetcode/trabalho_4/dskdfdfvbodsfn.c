/*18. 4Sum
Medium
Topics
premium lock icon
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

 void quicksort( int* nums, int inicio, int fim ) {
    
	int i, j, meio, temp;
	int numAleatorio = inicio + rand() % (fim-inicio+1);
	i = inicio;
	j = fim;
	meio = nums[numAleatorio];

	do{
		while ( nums[i] < meio ) {
			i++;
		}
		while ( nums[j] > meio ) {
			j--;
		}

		if ( i <= j ) {
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++;
			j--;
		}
	} while ( i <= j );
	
	if ( i < fim ) {
		quicksort( nums, i, fim );
	}
	if( j > inicio ) {
		quicksort( nums, inicio, j );
	}
}

 int main(){
    int v[] =  {6,5,4,3,2,1};
    srand(time(NULL));
int i=0;
    do
    {
        printf("%d", v[i]);
        i++;
    } while ( i < 6);
    

    quicksort(v, 0, 5);
i=0;
      do
    {
        printf("%d", v[i]);
        i++;
    } while ( i < 6);
 }