#include <iostream>
#include <vector>
	using namespace std;

bool isSafe(int row,int col,int val,int n,vector<vector<char>>& board){
    for(int i=0;i<n;i++){
        //row check 
        if(board[row][i]==val+'0') return false;
        // col check
        if(board[i][col]==val+'0') return false;
        // 3*3 check
        if(board[3*(row/3) +i/3][ 3*(col/3)+ i%3]==val+'0') return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board, int n)
{
    for(int row=0;row<n;row++)
		{
        for(int col=0;col<n;col++)
			{
            if(board[row][col]=='.')
				{
                for(int val=1;val<=9;val++)
					{
                    if(isSafe(row,col,val,n,board))
						{
                        board[row][col]=val+'0';
                        if(solve(board, n)) 
                        	return true;
                        else 
                        	board[row][col]='.';
                        }
                	}
                return false;
            }
        }
    }
    return true;
} 

int main()
{
	vector<vector<char>> board{
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	int n=9;

	if(solve(board, n))
	{
		cout<<"Solution exists!!"<<endl;
		for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					cout<<board[i][j]<<"   ";
				cout<<endl;
			}
	}
	else
	{
		cout<<"Solution doesnot exist";
	}

	return 0;
}