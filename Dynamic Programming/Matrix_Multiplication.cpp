#include <bits/stdc++.h>
    using namespace std;

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for(int diff=1; diff<N-1; diff++)
    {
        for(int i=1; i<N-diff; i++)
        {
            int j=i+diff;
            int mini = INT_MAX;

            for(int k=i; k<j; k++)
            {
                int p = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[j]*arr[k];
                if(mini>p)
                {
                    mini=p;
                }
            }
            dp[i][j]=mini;
        }
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
                cout<<dp[i][j]<<"   ";
            cout<<endl<<endl;
        }
        cout<<endl<<endl;
    }
    return dp[1][N-1];
}

int main()
{
    vector<int> arr = {5, 4, 6, 2, 7};
    int N = 5;

    cout<<matrixMultiplication(arr, N);
}
