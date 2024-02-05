#include <bits/stdc++.h>
    using namespace std;

int knapSack(int w, int wt[], int p[], int n)
{
    if(n==0 or w==0)
        return 0;

    if(w<wt[n-1])
        return knapSack(w, wt, p, n-1);

    return max(knapSack(w, wt, p, n-1), p[n-1]+knapSack(w-wt[n-1], wt, p, n-1));
}




int main()
{
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n);
    return 0;
}