#include <iostream>
#include <vector>
	using namespace std;

bool is_safe(int row, int col, vector<vector<int>> &board, int n)
{
	for(int i=0;i<col;i++)
	{
		if(board[row][i])
			return false;
	}

	// check for upper diagonal
	for(int i=row, j=col;i>=0 &&j>=0;i--, j--)
	{
		if(board[i][j])
			return false;
	}


	//check for lower diagonal
	for(int i=row, j=col;i<n &&j>=0;i++, j--)
	{
		if(board[i][j])
			return false;
	}

	return true;
}

bool N_Queen(int col, int n, vector<vector<int>> &board)
{
	if(col>=n)
		return true;

	for(int row=0;row<n;row++)
	{
		if(is_safe(row, col, board, n))
		{
			board[row][col]=1;
			if(N_Queen(col+1, n, board))
				return true;

			//Backtrack
			board[row][col]=0;
		}
	}
	return false;
}

int main()
{
	int n;
	cin>>n;

	vector<vector<int>> board(n, vector<int>(n, 0));

	if(N_Queen(0, n, board))
		cout<<"Solution exists!!"<<endl;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			if(board[i][j])
			cout<<'Q'<<"   ";
			else
				cout<<0<<"   ";
		cout<<endl;
	}

	return 0;
}