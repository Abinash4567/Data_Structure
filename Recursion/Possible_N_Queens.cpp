#include <bits/stdc++.h>
	using namespace std;


bool is_safe(int row, int col, vector<vector<int>> &board, int n)
{
	int x=row;
    int y=col;
        
        // check for same row
        while(y>=0)
        {
            if(board[x][y]==1)
                return false;
            y--;
        }
        
        x=row;
        y=col;
        
        // check for upper diagonaal
        while(x>=0 && y>=0)
        {
            if(board[x][y]==1)
                return false;
            x--;
            y--;
        }
        
        x=row;
        y=col;
        
        // check for lower diagonaal
        while(x<n && y>=0)
        {
            if(board[x][y]==1)
                return false;
            x++;
            y--;
        }
        
        return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<vector<int>>> &ans, int n)
{

	if(col>=n)
	{
		ans.push_back(board);
 		return ;
	}

	for(int row=0; row<n; row++)
	{
		if(is_safe(row,col, board, n))
		{
			board[row][col]=1;

			solve(col+1, board, ans, n);

			board[row][col]=0;
		}

	}
}


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n=5;

    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<vector<vector<int>>> ans;
    solve(0, board, ans, n);

    for (auto it = ans.begin(); it != ans.end(); ++it)
	{
		for (auto it2 = it->begin(); it2 != it->end(); ++it2)
			{
				for (auto it3 = it2->begin(); it3 != it2->end(); ++it3)
				cout<<*it3<<"  ";

				cout<<endl;
			}
    		

    	cout<<endl<<endl<<endl;
    }
 	
	return 0;
}