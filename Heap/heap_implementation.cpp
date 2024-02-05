#include <iostream>
#include <math.h>
#include <climits>
    using std::cin;
    using std::cout;
    using std::swap;

class max_heap{
private:
    int *arr;
    int capacity;
    int heap_size;

    max_heap(int s)
    {
        heap_size = -1;
        capacity = s;
        arr = new int[s];
    }

    int height()
    {
        return (ceil(log2(heap_size+1))-1);
    }

    int right_child(int a)
    {
        return arr[2*a+2];
    }

    int left_child(int a)
    {
        return arr[2*a+1];
    }

    int parent(int a)
    {
        return floor((a-1)/2);
    }

    int sizee()
    {
        return  heap_size+1;
    }

    void heapify_bottom_up(int index)
    {
        int pa = parent(index);

        while(pa>0 and arr[pa]<arr[index])
        {
                swap(arr[pa], arr[index]);
                pa = parent(pa);
        }
    }

    void insert(int a)
    {
        if(heap_size==capacity-1)
        {
            cout<<"Overflow: Heap full";
            return;
        }

        arr[++heap_size] = a;

        heapify_bottom_up(heap_size);
    }

    void heapify(int index)
    {
        int largest = index;
        int left = left_child(largest);
        int right = right_child(largest);
 
        if(left < heap_size+1 and arr[left]>arr[largest])
            largest = left;

        if(right < heap_size+1 and arr[right]>arr[largest])
            largest = right;

        if(largest!=index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    void heapify(int index, int n)
    {
        int largest = index;
        int left = left_child(largest);
        int right = right_child(largest);
 
        if(left < n and arr[left]>arr[largest])
            largest = left;

        if(right < n and arr[right]>arr[largest])
            largest = right;

        if(largest!=index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }


    void delete_heap()
    {
        swap(arr[0], arr[heap_size]);

        heap_size--;

        heapify(0);
    }

    void delete_node(int index)
    {
        increase_key(index, INT_MAX);
        extract_max();
    }

    int extract_max()
    {
       if(heap_size==-1)
        return -1;

        if(heap_size==0)
        {
            heap_size--;
            return arr[heap_size+1];
        } 

        int b = arr[0];
        delete_heap();
        return b;
    }

    void increase_key(int index, int val)
    {
        if(val<arr[parent(index)])
            {
                cout<<"Not valid operation";
                return;
            }

        arr[index] = val;
        heapify_bottom_up(index);
    }

    void decrease_key(int index, int val)
    {
        if(val>arr[left_child(index)] and val>arr[right_child(index)])
        {
            cout<<"Not valid operation";
            return;
        }

        arr[index] = val;
        heapify(index);
    }

    void print()
    {
        for(int i=0; i<heap_size; i++)
            cout<<arr[i]<<"  ";
    }

    void heap_sort()
    {
        int ss = heap_size+1;
        for(int i=ss/2-1; i>0; i--)
            heapify(i);
        

        for(int i=heap_size; i>=0; i--)
        {
            swap(arr[i], arr[0]);
            heapify(0, i);
        }
    }
};



int main()
{


    return 0;
}