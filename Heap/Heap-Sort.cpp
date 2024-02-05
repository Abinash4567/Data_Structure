#include <iostream>
#include <climits>
	using namespace std;


void heapify(int arr[], int i, int n)
{
		int largest = i;
		int left = 2*i+1;
		int right = 2*i+2;

		if(left < n and arr[left]>arr[largest])
			largest = left;

		if(right < n and arr[right]>arr[largest])
			largest = right;

		if(largest!=i){
			swap(arr[largest], arr[i]);
			heapify(arr, largest, n);
		}	
}


void heap_sort(int arr[], int n)
{
	for(int i = n/2-1; i >= 0; i--)
		heapify(arr, i, n);

	for(int i = n-1; i>0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, 0, i);
	}
}

void print_heap(int arr[], int n)
{
	for(int i = 0; i<n; i++)
		cout<<arr[i]<<"  ";
}

int main()
{
	int arr[] = {4, 5, 23, 76, 89, 21};
	int n = sizeof(arr)/sizeof(arr[0]);

	heap_sort(arr, n);

	print_heap(arr, n);
	
	return 0;
}
