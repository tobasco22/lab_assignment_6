#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	//This checks if the array is empty and returns error code 1 if it is
		if (low >= high){
			return -1;
		}
		//to find the mid point you need to get the average of the array so low + high divided by 2 gets the mid point
		int mid = (low + high) / 2;

		//if the value you are searching for is the mid point then it returns that
		if(numbers[mid] == value){
			return mid;}

			//if the value you are searching for is greater than the mid point then the search is changed to 
			//only look in the right half of the array from the mid point. This makes the seach faster since it does not need to 
			//go through the entire array. The return recalls the search function but with the updated parameters.
			if(numbers[mid] < value){
				return search(numbers, mid + 1, high, value);}
				//if the value is not bigger than the mid point hen this else function will kick in. It updates the search
				//function to look on the left half of the array in relation to the mid point. The return recalls the 
				//search funtion with the updated parameters.
				else{
					return search(numbers, low, mid - 1, value);
		}
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}