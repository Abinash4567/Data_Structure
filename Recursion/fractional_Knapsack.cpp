#include <bits/stdc++.h>
    using namespace std;

double fractional_knapsack(int p[], int wt[], int n, int W)
{
    for(int i=1;i<n;i++)
    {
        double val=p[i]/wt[i];
        int j=i-1;
        int key1=p[i];
        int key2=wt[i];

        while(j>=0 and (p[j]/(double)wt[j])>val)
        {
            p[j+1]=p[j];
            wt[j+1]=wt[j];
            j--;
        }
        p[j+1]=key1;
        wt[j+1]=key2;
    }


    for(int i=0;i<3;i++)
    {
        cout<<p[i]<<"  "<<wt[i]<<endl;
    }


    double value=0.00;
    for(int i=n-1;i>=0;i--)
    {
        if(wt[i]<=W)
        {
            value+=p[i];
            W-=wt[i];
        }
        else
        {
            value+=((double)W/(double)wt[i])*p[i];
            break;
        }
    }
    return value;
}


int main()
{
    int n = 3;
    int p[3] = {60, 100, 120};
    int w[3] = {10, 20, 30};
    int W = 50;

    cout<<fractional_knapsack(p, w, n, W);
    return 0;
}
#include <bits/stdc++.h>
    using namespace std;

void printS(int index, vector<int> ds, int s, int sum, int arr[], int n)
{
    if(index==n)
    {
        if(sum==s)
        {
            for(auto i:ds)
                cout<<i<<"  ";
            cout<<endl<<endl;
        }
    }

    printS(index+1, ds, s, sum, arr, n);

    s+=arr[index];
    ds.push_back(arr[index]);

    printS(index+1, ds, s, sum, arr, n);
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr, n);

    return 0;
}

