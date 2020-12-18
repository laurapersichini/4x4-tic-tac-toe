#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
void fourxfour(string boxes[4][4]);
//^^ makes the initial matrix of 4*4
void play(string boxes[4][4]);
//^^ Replaces matrix elements with X or O.
void print_func(string boxes[4][4]);
//^^ Prints new matrix with X or O (Printed after each player moves).
//^^ Need for a different matrix production function due to formatting issues.
void switcheroo (string& xor_knot);
//^^ Switches between players.
void invoke_game();
//^^starts the game.
void one_more();
//^^ asks players if they want to play one more.
void input_check(string boxes[4][4],int& play_input);
//^^ checks if a spot is already taken on the matrix.
string winner_check(string boxes[4][4]);
// ^^ checks if there is a vertical, diagonal, or horizontal combination of 4 Xs or 4Os

int main()
{
    invoke_game();
    
    return 0;
}

// cout the initial matrix
void fourxfour(string boxes[4][4])
{
    // go from 0 to 2 then form 2 to 4 because of 1 digit or 2 digit numbers
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0;j < 4; j++)
        {
            cout << boxes[i][j] << "    ";
        }
        cout << endl;
        
    }
    for (int i = 2; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           if (i == 2 && j == 0)
               cout << boxes[i][j]<< "    ";
            else
                cout << boxes[i][j]<< "   ";
        }
        cout << endl;
    }
}

void print_func(string boxes[4][4])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << boxes[i][j] << "    ";
        }
        cout<<endl;
        
    }
    for (int i = 2; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (boxes[i][j] == "X" || (i == 2 && j == 0) || boxes[i][j] == "O")
            {cout << boxes[i][j] << "    ";}
            else {cout << boxes[i][j] << "   ";}
        }
        cout<<endl;
    }
}

void play(string boxes[4][4])
{
    string xor_knot = "X";
    cout << "Please input the square number you want to play in: \n";
    int play_input;
    
    for (int j = 0; j < 16; j++)
    {
        input_check(boxes, play_input);
        
        for (int i = 1; i < 17; i++)
        {
            if (play_input == i && i < 5)
            {
                boxes[0][i-1] = xor_knot;
                print_func(boxes);
            }
            else if (play_input == i && i < 9 && i> 4)
            {
                boxes[1][i-5] = xor_knot;
               print_func(boxes);
            }
            else if (play_input == i && i < 13 && i> 8)
            {
                boxes[2][i-9] = xor_knot;
                print_func(boxes);
            }
            else if (play_input == i && i < 17 && i> 12)
            {
                boxes[3][i-13] = xor_knot;
                print_func(boxes);
            }
            if (play_input == i)
                break;
            
            // call winner check
            string win_status = winner_check(boxes);
            if (win_status == "x_win")
            {
                cout << " X is the winner! Congratulations! " << endl;
                cout << " Would you like to play again? " << endl;

            } else if (win_status == "o_win")
            {
                cout << "X is the winner! Congratulations! " << endl;
                cout << " Would you like to play again? " << endl;
            } else if (win_status == "tie")
            {
                cout << " It's a tie! No winner this time. Would you like to play again? " << endl;
            }
            
            
            if (j!= 15)
            {
                cout<<"Next turn! \n";
            }
            switcheroo(xor_knot);
        }
    }
    
    one_more();
        
        
        
    
}

void switcheroo(string& xor_knot)
{
    if (xor_knot == "X")
    {
        xor_knot = "O";
    } else
    {
        xor_knot = "X";
    }
}

void invoke_game()
{
    string boxes[4][4] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"};
      fourxfour(boxes);
      play(boxes);
}

void one_more()
{
    char y_n;
    cout << "Do you want to play one more game? Type 'y' to convey Yes or 'n' for No. \n";
    
    do {
    cin >> y_n;
    if (y_n == 'Y' || y_n == 'y')
    {
        invoke_game();
    }
    else if (y_n == 'N' || y_n == 'n')
    {exit(0);}
    else
    {
        cout<<"Please type either y or n to indicate your preference. \n";
    }
    } while (y_n != 'N' || y_n != 'n' || y_n != 'Y' || y_n != 'y');
}

void input_check(string boxes[4][4], int& play_input)
{do {cin >> play_input;
        if (play_input > 16 || play_input < 1)
        {cout << "Please input a number between 1 to 16. \n";}
    }while(play_input > 16 || play_input < 1);
    
    for (int i = 1; i < 17; i++)
    {
        if (play_input == i && i < 5)
        {
            while (boxes[0][play_input-1] == "X" || boxes[0][play_input-1] == "O")
            {cout << "This spot has already been claimed don't try and cheat, input again! \n";
                cin >> play_input;}
            break;
        }
        else if (play_input == i && i < 9 && i > 4)
        {
         while (boxes[1][play_input-5] == "X" || boxes[1][play_input-5] == "O")
                    {cout << "This spot has already been claimed don't try and cheat, input again! \n";
                        cin >> play_input;}
            break;
        }
        else if (play_input == i && i < 13 && i> 8)
        {
            while (boxes[2][play_input-9] == "X" || boxes[2][play_input-9] == "O")
            {cout<<"This spot has already been claimed don't try and cheat, input again! \n";
                cin >> play_input;}
            break;
        }
        else if (play_input == i && i < 17 && i > 12)
        {
            while (boxes[3][play_input-13] == "X" || boxes[3][play_input-13] == "O")
            {cout<<"This spot has already been claimed don't try and cheat, input again! \n";
                cin >> play_input;}
            break;
        }
}
}

string winner_check(string boxes[4][4]) {
    string win_status = "continue";
    //check if there is a vertical combo of Xs and Os (columns of the matrix)
    for (int i = 0; i < 4; i++)
    {
        if (boxes[0][i] == boxes[1][i] &&
            boxes[1][i] == boxes[2][i] &&
            boxes[2][i] == boxes[3][i])
        {
          if (boxes[0][i] == "X")
          {
              win_status = "x_win";
          } else {
              win_status = "o_win";
          }
        }
    }
    //check horizontal (rows of the matrix)
    for (int i = 0; i < 4; i++)
    {
       if (boxes[i][0] == boxes[i][1] &&
           boxes[i][1] == boxes[i][2] &&
           boxes[i][2] == boxes[i][3])
        {
          if (boxes[i][0] == "X")
          {
              win_status = "x_win";
          } else {
              win_status = "o_win";
          }
        }
    }
    //check diagonal
    if (boxes[0][0] == boxes[1][1]&&
        boxes[1][1] == boxes[2][2]&&
        boxes[2][2] == boxes[3][3])
    {
        if (boxes[0][0] == "X")
        {
            win_status = "x_win";
        } else {
            win_status = "o_win";
        }
    }
    // check second diagonal
    if (boxes[3][0] == boxes[2][1]&&
        boxes[2][1] == boxes[1][2]&&
        boxes[1][2] == boxes[0][3])
    {
        if (boxes[3][0] == "X")
        {
            win_status = "x_win";
        } else {
            win_status = "o_win";
        }
    }
    
    //check tie
    bool tie = true;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (boxes[i][j] == "X" || boxes[i][j] == "O" )
            {
                tie = false;
            }
        }
    }
    
    if (tie == true)
    {
        win_status = "tie";
    }
    
    return win_status;
}
