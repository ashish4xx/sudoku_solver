#include <bits/stdc++.h>
using namespace std;

// Function to recursively solve the Sudoku puzzle
void helper(int r, int c, vector<vector<char>> &a, map<pair<int,int>,map<int,int>> &mp, vector<map<int,int>> &row, vector<map<int,int>> &col )
{
    // Base case: if the row index is 9, print the Sudoku and return
    if(r==9)
    {
        for(auto it:a)
        {
            for(auto i: it)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    
    // If column index reaches 9, move to the next row
    if(c==9)
    {
        helper(r+1,0,a,mp,row,col);
        return;
    }
    
    // If the current cell is not empty, move to the next column
    if(a[r][c]!='.')
    {
        helper(r,c+1,a,mp,row,col);
        return;
    }
    
    // Try placing numbers 1-9 in the empty cell and recursively proceed
    for(int i=1; i<=9; i++)
    {
        int rw=r/3, c1=c/3;
        
        // Check if the number can be placed in the current cell
        if(!mp[{rw,c1}][i] and !row[r][i] and !col[c][i])
        {
            mp[{rw,c1}][i]=1;  // Marking number i as used in the 3x3 subgrid
            row[r][i]=1;       // Marking number i as used in the current row
            col[c][i]=1;       // Marking number i as used in the current column
            a[r][c]=i+'0';     // Placing the number in the cell
            
            // Recurse to the next cell
            helper(r,c+1,a,mp,row,col);
            
            // Backtrack: reset the changes made to try the next possibility
            mp[{rw,c1}][i]=0;
            row[r][i]=0;
            col[c][i]=0;
            a[r][c]='.';
        }
    }
}

// Function to solve the Sudoku puzzle
void solvethissudoku(vector<vector<char>>&a)
{
    map<pair<int,int>,map<int,int>> mp;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);
    
    // Preprocessing: Marking filled cells in the Sudoku
    for(int i=0; i<9 ; i++)
    {
        for(int j=0; j<9;j++)
        {
            if(a[i][j]!='.')
            {
                mp[{i/3,j/3}][a[i][j]-'0']=1;  // Marking filled numbers in subgrids
                row[i][a[i][j]-'0']=1;        // Marking filled numbers in rows
                col[j][a[i][j]-'0']=1;        // Marking filled numbers in columns
            }
        }
    }
    
    // Start solving the Sudoku puzzle
    helper(0,0,a,mp,row,col);
}

int main()
{
    vector<vector<char>> sudoku(9, vector<char>(9));
    
    cout << "Enter the Sudoku puzzle (use '.' for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }

    // Solve the given Sudoku puzzle
    solvethissudoku(sudoku);
    
    return 0;
}
