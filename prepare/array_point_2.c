#include <stdio.h>
void showArray(int arr[], int length);
void showArray_2(int *p);


void showArray(int arr[], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("arr[%d]=%d||", i, arr[i]);
	}
}

void showArray_2(int *p, int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("arr[%d]=%d||", i, *(p+i));
	}
}

int main()
{
	int arr[6] = {2,3,4,5,6,7};
	showArray(arr, 6);
	showArray_2(arr, 6);

	return 0;
}