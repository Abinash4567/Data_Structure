#include <iostream>
#include <vector>
	using namespace std;

bool is_safe(int x, int y, vector<vector<bool>> visited, vector<vector<int>> board, int n)
{
	if(x>=0 and y>=0 and x<n and y<n and visited[x][y]!=1 and board[x][y]==1)
		return true;
	return false;
}


void solve_maze(int x, int y, vector<vector<int>> board, int n, vector<vector<bool>> &visited, string path, vector<string> &ans)
{
	//base case
	if(x==n-1 and y==n-1)
	{
		ans.push_back(path);
	}

	//Down Movement
	if(is_safe(x+1, y, visited, board, n))
	{
		visited[x+1][y]=1;
		solve_maze(x+1, y, board, n, visited, path+'D', ans);
	}

	//Up Movement
	if(is_safe(x-1, y, visited, board, n))
	{
		visited[x-1][y]=1;
		solve_maze(x-1, y, board, n, visited, path+'U', ans);
	}

	//Left Movement
	if(is_safe(x, y-1, visited, board, n))
	{
		visited[x][y-1]=1;
		solve_maze(x, y-1, board, n, visited, path+'L', ans);
	}

	//Right Movement
	if(is_safe(x, y+1, visited, board, n))
	{
		visited[x][y+1]=1;
		solve_maze(x, y+1, board, n, visited, path+'R', ans);
	}
	visited[x][y]=0;       //backtracking
}


int main()
{
	vector<vector<int>> board {
		{1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1},
    };
    int n=4;

    vector<string> ans;
    vector<vector<bool>> visited(4, vector<bool>(n, 0));
    string path="";

    solve_maze(0, 0, board, n, visited, path, ans);

    for(int i=0;i<ans.size();i++)
    	cout<<ans[i]<<endl;

    return 0;
}