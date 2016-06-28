#includes <iostream>
using namespace std;

void SelectionSort(int* arr, int size)
{
	int smallest, index;

	//two loops
	for(int i = 0; i < size; i++)
	{
		//set the smallest to the first element
		smallest = arr[i];
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < smallest)
			{
				//if the number compared to is smaller, keep track of the index
				index = j;
				smallest = arr[j];
			}
		}
		//after this loop, all the numbers would have been compared and the smallest would have been found
		if(arr[i] != smallest)
		{
			arr[index] = arr[i];
			arr[i] = smallest;
			
		}
		show(arr, size);
	}
};

int BinarySearch(int* arr, int size, int target)
{
	int first, mid, last;

	first = 0;
	last = size;
	mid = (first+last)/2;

	cout << "Mid = " << mid << endl;

	while (first <= last)
	{
		if (target > arr[mid])
		{
			first = mid + 1;
		}

		else if (target < arr[mid])
		{
			last = mid - 1;
		}

		else
			return mid;

		mid = (first + last)/2;
	}
};

void BubbleSort(int* arr, int size)
{
	//first loop will make sure i go through all the numbers
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i+1])
			{
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	cout << "Array = [";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i < size-1)
			cout << ',';
	}
	cout << "]" << endl;
}
