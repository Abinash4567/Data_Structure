#include <iostream>
#include <climits>
	using namespace std;

class heap
{
public:
	int arr[100];
	int size = -1;

	void insert(int val)
	{
		size++;
		arr[size] = val;
		int index = size;

		while(index > 0)
		{
			int parent = (index-1)/2;
			if(arr[parent] < arr[index]){
				swap(arr[parent], arr[index]);
				index = parent;
			}
			else{
				return;
			}
		}
	}

	void delete_heap()
	{
		if(size ==-1)
		{
			cout<<"Heap is empty";
			return;
		}

		arr[0]=arr[size];
		size--;

		int index = 0;

		while(index < n/2)
		{
			int largest = index;
			int left = 2*index+1;
			int right = 2*index+2;

			if (left <= size and arr[index] < arr[left])
				largest = left;

			if (right <= size and arr[index] < arr[right])
				largest = right;
			else
				return;

			if (largest!=index)
				swap(arr[largest], arr[index]);
			index = largest;
		}
	}

	void print_heap()
	{
		for(int i=0;i<size;i++)
			cout<<arr[i]<<"   ";
	}

};

int main()
{
	heap h1;
	h1.insert(11);
	h1.insert(12);
	h1.insert(18);
	h1.insert(12);
	h1.insert(10);
	h1.insert(15);

	h1.print_heap();

	
	return 0;
}
