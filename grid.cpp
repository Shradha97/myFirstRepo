#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int m,n;
bool moves( int m, int n, int i, int j, int** grid)
{
	int k, l;
	cout << "i is " << i << " j is " <<  j << endl; 
	cout << "grid value is " << grid[i][j] << endl;
	if (grid[i][j] == 0 || ((j+1) <= n-1 && (i+1) <= m-1 && grid[i][j+1] == 0 && grid[i+1][j] == 0))
	{
		cout << "I am here" << endl;
		return 0;
	}
	else if (i == m-1 && j == n-1 && grid[i][j] == 1)
	{
		cout << "yes" << endl;
		return 1;
	}
	else if (i == m-1)
	{
		if ((j+1) <= n-1 && grid[i][j+1] == 1)
		{
			cout << "a" << endl;
			return moves(m, n, i, j+1, grid);
		}
		else if ((j+1) <= n-1 && grid[i][j+1] == 0)
		{
			cout << "b" << endl;
			return 0;
		}
	}
	else if (j == n-1)
	{
		if ((i+1) <= m-1 && grid[i+1][j] == 1)
		{
			cout << "c" << endl;
			return moves(m, n, i+1, j, grid);
		}
		else if ((i+1) <= m-1 && grid[i+1][j] == 0)
		{
			cout << "d" << endl;
			return 0;
		}
	}
	else if (grid[i][j+1] == 0 && grid[i+1][j] == 1 && (i+1) <= m-1 && (j+1) <= n-1)
	{
		cout << "e" << endl;
		return moves(m, n, i+1, j, grid);
	}
	else if (grid[i][j+1] == 1 && grid[i+1][j] == 0 && (i+1) <= m-1 && (j+1) <= n-1)
	{
		cout << "f" << endl;
		return moves(m, n, i, j+1, grid);
	}
	else if (grid[i][j+1] == 1 && grid[i+1][j] == 1 && (i+1) <= m-1 && (j+1) <= n-1)
	{
		cout << "g" << endl;
		k = moves(m, n, i, j+1, grid);
		cout << "h" << endl;
		l = moves(m, n, i+1, j, grid);
		if (k == 0 && l == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
int main()
{
	int k = 0 ;
	cout << "Enter the no. of rows and columns " << endl;
	cin >> m >> n;
	int** grid = (int**) malloc(m * sizeof(int *));
	for(int i = 0; i < m; i++)	
		grid[i] = (int*) malloc(n * sizeof(int));

	cout << "Enter the values in the grid" << endl;
	for (int i = 0; i < m; ++i)
	{
			for (int j = 0; j < n; ++j)
			{
				cin >> grid[i][j];
			}
	}
	k = moves(m, n, 0, 0, grid);
	cout << k << endl;
	return 0;
}