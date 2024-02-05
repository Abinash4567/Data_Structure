#include <bits/stdc++.h>
    using namespace std;

int signum(int a, int b)
{
    if(a==b)
        return 0;
    else if(a>b)
        return 1;
    return -1;
}

void call(int element, priority_queue<int> &max_heap, priority_queue<int, vector<int>, greater<int>> &min_heap, int &median)
{
    switch(signum(max_heap.size(), min_heap.size()))
    {
    case 0:  if(median < element)
                {
                    min_heap.push(element);
                    median = min_heap.top();
                }
                else
                {
                    max_heap.push(element);
                    median = max_heap.top();
                }

                break;

    case 1: if(median < element)
                {
                    min_heap.push(element);
                    median = (min_heap.top()+max_heap.top())/2;
                }
            else
                {
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                    max_heap.push(element);
                    median = (max_heap.top()+min_heap.top())/2;
                }
                break;

    case -1: if(element < median)
            {
                max_heap.push(element);
                median = (max_heap.top()+min_heap.top())/2;
            }
            else
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                median = (max_heap.top()+min_heap.top())/2;
            }
            break;

    }

}

vector<int> median_stream(vector<int> arr)
{
    vector<int> ans;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int median = 0;

    for(int i=0; i<arr.size(); i++)
    {
        call(arr[i], max_heap, min_heap, median);
        ans.push_back(median);
        cout<<median<<endl;
    }
    return ans;
}



int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ans;
    ans = median_stream(arr);
    return 0;
}