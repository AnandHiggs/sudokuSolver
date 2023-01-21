/*

2nd Oct 2021
Sudoku Solver
Angad Singh

*/

#include <iostream>

using namespace std;

/*class Sudo{
  public:
  
};*/

void input(int sudo[9][9]);

bool blank(int sudo[9][9], int& r, int& c); //find coordinates of empty cells

bool check(int sudo[9][9], int sol, int r, int c); //check if num exists in row col or box

bool final(int sudo[9][9]); 

void output(int sudo[9][9]);

int main()
{
    cout << "Welcome to Sudoku Solver.\n";
    
    int sudo[9][9] = {  { 3, 0, 5, 4, 0, 2, 0, 6, 0 },
					    { 4, 9, 0, 7, 6, 0, 1, 0, 8 },
					    { 6, 0, 0, 1, 0, 3, 2, 4, 5 },
					    { 0, 0, 3, 9, 0, 0, 5, 8, 0 },
					    { 9, 6, 0, 0, 5, 8, 7, 0, 3 },
					    { 0, 8, 1, 3, 0, 4, 0, 9, 2 },
				    	{ 0, 5, 0, 6, 0, 1, 4, 0, 0 },
				    	{ 2, 0, 0, 5, 4, 9, 0, 7, 0 },
					    { 1, 4, 9, 0, 0, 7, 3, 0, 6 }  };
    
    //input();

    if (final(sudo) == true)
        output(sudo);
    else
        cout << "No solution exists";
 
    return 0;
}

/*void input(int sudo[9][9])
{
    cout << "Please Enter the Numbers Row-wise and use 0 to indicate blanks....\n";
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> sudo[i][j];
        }
    }
    
    cout << endl;
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << sudo[i][j] << " ";
        }
        cout << endl;
    }
    
    int bleh = 0;
    
    cout << "\n This is what you entered. Enter 1 to confirm OR 0 to re-enter: ";
    cin >> bleh;
    if(bleh != 1)
        input(sudo);
}*/

bool blank(int sudo[9][9], int& r, int& c)
{
    for(r = 0; r < 9; r++)
    {
        for(c = 0; c < 9; c++)
        {
            if(sudo[r][c] == 0)
                return true;
        }
    }
    return false;
}

bool check(int sudo[9][9], int sol, int r, int c)
{
    //checking for col first
    for(int i = 0; i < 9; i++)
    {
        if(sudo[i][c] == sol)
            return false;
    }
    
    
    //checking for row
    for(int j = 0; j < 9; j++)
    {
        if(sudo[r][j] == sol)
            return false;
    }
    
    //checking in box
    int x = r - r%3, y = c - c%3;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(sudo[i + x][j + y] == sol)
                return false;
        }
    }
    
    return true;
}

bool final(int sudo[9][9])
{
    int row, col;
    
    if (!blank(sudo, row, col))
        return true;
        
    for (int num = 1; num <= 9; num++)
    {

        if (check(sudo, num, row, col))
        {
            sudo[row][col] = num;
            
            if (final(sudo))
                return true;
            
            sudo[row][col] = 0;
        }
    }
    
    return false;
}

void output(int sudo[9][9])
{
     
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << sudo[i][j] <<" ";
        }
        cout << endl;
    }
}