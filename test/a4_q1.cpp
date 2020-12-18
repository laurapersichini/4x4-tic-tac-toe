//
//  main.cpp
//  a4_q1.cpp
//
//  Created by Laura Persichini on 2020-11-03.
//  Copyright © 2020 Laura Persichini. All rights reserved.
/*

 Project: 4x4 tic-tac-toe simulation
 Purpose:  Allow two usersto play 4x4 Tic-Tac-Toe..
 Due date: November 25th, 2020

Testing: To test the program, we first verified the validity of the input. For example, we entered values of 1 through 16 to ensure the program accepted them. We also entered values of zero and numbers of 17 or greater to make sure the program rejected those values. Furthermore, we tested the program to ensure it would not allow the user to enter a value into an already occupied box. We did so through entering in values repeatedly into the same cell to test the program. We also tested the spacing of the matrix through running multiple iterations of the program and altering the format after each time. Verification of the win conditions involved going through each case (win for x, win for o, tie) and ensuring that the program would correctly recognize and tally each case to output at the end of the session.
 
Limitations : One limitation of the program would be the range of inputs. For example, if anthing other than an integer is entered when the user is asked to enter a number from 1 to 16, the program will not run correctly.
 */

//include directive
#include <iostream>
#include <string>
#include <stdlib.h>

//using directive
using namespace std;

// Function declartion
void fourxfour(string boxes[4][4]);
//Input: An array of strings of [4][4] size.
//This function has void output.
//The task of this function is to print the array in a 4*4 square matrix form.

void play(string boxes[4][4], int x, int o, int tie);
//Input: An array of strings of [4][4] size, x, o, and tie
//input x,o, and tie to maintain tally of x score, o score, and tie score across all games.
//This function has void output.

void print_func(string boxes[4][4]);
//Input: An array of strings of [4][4] size.
//This function has void output.
//The task of this function is to print the new matix in which play function has replaced
//an element with "X" or "O". Need for a different print funcion other than fourxfour arises
//due to formatting difference.

void switcheroo (string& xor_knot);
//Input: A string variable with either the value "X" or "O".
//This function has void output.
//The task of this function is to switch between players (switched between "X" and "O".

void invoke_game(int x, int o, int tie);
// Input: x, o, tie.
//pass in x, o, and tie to maintain tally of score in previous games.
//The task of the function is to start the game.

void one_more(int x_score, int o_score, int tie_score);
//This function has no input and has void output.
//The task of the function is to ask the user if they want to play one more game.

void input_check(string boxes[4][4],int& play_input);
//Input: An array of string of [4][4] size and an integer recieved from players (the spot they want to play on).
//The function has void output.
//The function checks if the spot the player wants to move on is legal or not.
//It checks if number is between 1 and 16 and checks if the spot has already not been used.

string winner_check(string boxes[4][4]);
//Input: An array of strings of [4][4] size.
//Output: string that corresponds to the status of the game (x player win, O player win, a tie or no winner yet(i.e. continue the game)).
// The function checks all columns, rows, and diagonals for 4 Xs or Os in a row. It also checks for a tie at the end of the game if there has not been a win.

void score_output(int x_score, int o_score, int tie_score);
//Input: integer value for player X's score, player O's score, and integer value for the number of ties
//Output: print out the final number of victories for each player and the number of ties
//This function prints out the statistics for all the games played within the session when the user decides they would no longer like to play.
    
int main()
{
    invoke_game(0,0,0); // start off x score, o score, and the number of ties to 0
    
    return 0;
}

void fourxfour(string boxes[4][4])
{
//A nested for loop to print the first two rows.
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << boxes[i][j] <<"    ";
        }
        cout << endl;
    }
    //A nested for loop to print the last two rows. This is to address the different spacing
    //requirements of 2 digit numbers.
    for (int i = 2; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           //An exceptional condition for the number 9 in third row which is single digit.
           if (i == 2 && j == 0)
           {
                cout << boxes[i][j] <<"    ";
           } else
           {
                cout << boxes[i][j] <<"   ";
           }
        }
        cout << endl;
    }
}

void print_func(string boxes[4][4])
{
    //A nested for loop to print the first two rows.
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << boxes[i][j] << "    ";
        }
        cout << endl;
    }
    
    // A nested for loop to print the last two rows.
    for (int i = 2; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           //exceptional condition for the number 9 and when a 2 digit number is replaced
           //with a single characted "X" or "O".
            
            if(boxes[i][j] == "X" || (i == 2 && j == 0) || boxes[i][j] == "O")
            {
                {cout << boxes[i][j] << "    ";}
            } else  {
                cout << boxes[i][j] << "   ";
            }
        }
        cout << endl;
    }
}

void play(string boxes[4][4], int x, int o, int tie)
{
    //Variable declaration the string which will hold "X" or "O" values.
    string xor_knot = "X";
    //User input prompt
    cout << "Please input the square number you want to play in: \n";
    //Variable declaration for incoming player input
    // Initialize the x score and o score to 0
    int play_input;
    int x_score = x;
    int o_score = o;
    int tie_score = tie;
    
    //A nested for loop to go through all matrix elements in 16 possible turns.
    //int j represents the possible player turns.
    for (int j = 0; j < 16; j++)
    {
        //Gets player input and makes sure it is legal.
        input_check(boxes, play_input);
        //int i represents all possible matrix elements.
        for (int i = 1; i < 17; i++)
        {
            //If the player input is in 1st row the element chosen in 1st row is changed
            if (play_input == i && i < 5)
            {
                boxes[0][i-1] = xor_knot;
                print_func(boxes);
            }
            //If the player input is in 2nd row the element chosen in 2nd row is changed
            else if (play_input == i && i < 9 && i > 4)
            {
                boxes[1][i-5] = xor_knot;
                print_func(boxes);
            }
            //If the player input is in 3rd row the element chosen in 3rd row is changed
            else if (play_input == i && i < 13 && i > 8)
            {
                boxes[2][i-9] = xor_knot;
                print_func(boxes);
            }
             //If the player input is in 4th row the element chosen in 4th row is changed
            else if (play_input == i && i < 17 && i > 12)
            {
                boxes[3][i-13] = xor_knot;
                print_func(boxes);
            }
            
            if (play_input == i)
            {
                break;
            }
        }
        
        // call winner check
        // assign the win status to the return of winner_check function
        string win_status = winner_check(boxes);
        if (win_status == "x_win")
        {
            cout << " X is the winner! Congratulations! " << endl;
            x_score++; // increment player x score by 1
            break;

        } else if (win_status == "o_win")
        {
            cout << "O is the winner! Congratulations! " << endl;
            o_score++; // increment player o score by 1
            break;
            
        } else if (win_status == "tie")
        {
            cout << "It's a tie! No winner this time. " << endl;
            tie_score++; // increment the number of ties by one
            break;
        }
        
        //Condition to check whether or not to print next turn!
        if (j!=15)
        {
            cout << "Next turn! \n";
        }
        switcheroo(xor_knot);
    }
    one_more(x_score, o_score, tie_score);
}

void switcheroo(string& xor_knot)
{
    //will switch between X and O each new turn.
    if (xor_knot == "X")
    {
        xor_knot = "O";
    }
    else
    {
        xor_knot = "X";
    }
}

void invoke_game(int x, int o, int tie)
{
    //declares the matrix 4*4 array.
    string boxes[4][4] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"};
    fourxfour(boxes);
    play(boxes, x, o, tie);
}

void one_more(int x_score, int o_score, int tie_score)
{
    //user input prompt.
    char y_n;
    cout << "Do you want to play one more game? " << endl;
    cout << "Enter 'y' for Yes or 'n' for No." << endl;
    
    //checks if user input is correct and if it is does corresponding action.
    do
    {
    cin >> y_n;
        if (y_n == 'Y' || y_n == 'y')// ensuring that both uppercase and lowercase are valid
        {
            invoke_game(x_score, o_score, tie_score);
        }
        else if (y_n == 'N' || y_n == 'n')// ensuring that both uppercase and lowercase are valid
        {
            score_output(x_score, o_score, tie_score);
            exit(0);
        }
        else
        {
            cout << "Please type either y or n to indicate your preference. \n";
        }
    } while (y_n != 'N' || y_n != 'n' || y_n != 'Y' || y_n != 'y');
}

void input_check(string boxes[4][4], int& play_input)
{
    //asks user for input. Keeps asking until a value between 1 to 16 is given.
    cout << "Please input a number between 1 to 16. \n";
    cin >> play_input;
        
    while (!(play_input < 17 && play_input > 0))
    {
        cout << "Please input a number between 1 to 16. \n";
        cin >> play_input;
    }
    
    //This for loop checks if the spot the players wants to fill is occupied.
    for (int i = 1; i < 17; i++)
    {
        //checks legality in first row.
        if (play_input == i && i < 5)
        {
            while (boxes[0][play_input-1] == "X" || boxes[0][play_input-1] == "O")
            {
                cout << "This spot has already been claimed don't try and cheat," << endl;
                cout << "input again!" << endl;
                cin >> play_input;
            }
            break;
        }
        //checks legality in second row.
        else if (play_input == i && i < 9 && i > 4)
        {
             while (boxes[1][play_input-5] == "X" || boxes[1][play_input-5] == "O")
             {
                cout << "This spot has already been claimed don't try and cheat," << endl;
                 cout << "input again!" << endl;
                 cin >> play_input;
             }
             break;
        }
        //checks legality in third row.
        else if (play_input == i && i < 13 && i > 8)
        {
            while (boxes[2][play_input-9] == "X" || boxes[2][play_input-9] == "O")
            {
                cout << "This spot has already been claimed don't try and cheat,"<< endl;;
                cout << "input again!" << endl;
                cin >> play_input;
            }
            break;
        }
        //checks legality in fourth row.
        else if (play_input == i && i < 17 && i > 12)
        {
            while (boxes[3][play_input-13] == "X" || boxes[3][play_input-13] == "O")
            {
                cout << "This spot has already been claimed don't try and cheat," << endl;
                cout << "input again!" << endl;
                cin >> play_input;
            }
            break;
        }
    }
}

string winner_check(string boxes[4][4]) {
    string win_status = "continue"; // assuming the win status will be to continue
    //check if there is a vertical combo of Xs and Os (columns of the matrix)
    for (int i = 0; i < 4; i++) // starting at the 0th index, loops until third index
    {
        if (boxes[0][i] == boxes[1][i] && // first and second cells of the column
            boxes[1][i] == boxes[2][i] && // second and third cells of the column
            boxes[2][i] == boxes[3][i]) // third and fourth cells of the column
        {
         // check if value in the cell ([0][i] is an arbitrary cell) is equal to X
          if (boxes[0][i] == "X")
          {
              win_status = "x_win"; // X is the winner
          } else {
              win_status = "o_win"; // O is the winner
          }
        }
    }
    //check horizontal (rows of the matrix)
    for (int i = 0; i < 4; i++) // starting at the 0th index, loops until third index
    {
       if (boxes[i][0] == boxes[i][1] && // first and second cells of the row
           boxes[i][1] == boxes[i][2] && // second and third cells of the row
           boxes[i][2] == boxes[i][3]) // third and fourth cells of the row
        {
         // check if value in the cell ([i][0] is an arbitrary cell) is equal to X
          if (boxes[i][0] == "X")
          {
              win_status = "x_win";
          } else {
              win_status = "o_win";
          }
        }
    }
    
    //check diagonal
    if (boxes[0][0] == boxes[1][1]&& // first cell of diagonal and second cell
        boxes[1][1] == boxes[2][2]&& // second cell of diagonal and third cell
        boxes[2][2] == boxes[3][3]) // third cell of diagonal and fourth cell
    {
        if (boxes[0][0] == "X")
        {
            win_status = "x_win";
        } else {
            win_status = "o_win";
        }
    }
    
    // check second diagonal (there are only two possible 4-cell diagonals in a 4x4 matrix)
    if (boxes[3][0] == boxes[2][1]&& // first and second cells of the diagonal
        boxes[2][1] == boxes[1][2]&& // second and third cells of the diagonal
        boxes[1][2] == boxes[0][3]) // third and fourth cells of the diagonal
    {
        if (boxes[3][0] == "X")
        {
            win_status = "x_win";
        } else {
            win_status = "o_win";
        }
    }
    
    //check tie
    bool tie = true; // assume that there is a tie
    for (int i = 0; i < 4; i++) // row index
    {
        for (int j = 0; j < 4; j++) // column index
        {
            // check if there is a cell without an X or an O
            if (boxes[i][j] != "X" && boxes[i][j] != "O")
            {
                tie = false; // tie is now false
            }
        }
    }
    
    if (tie == true)
    {
        win_status = "tie";
    }
    
    return win_status;
}

//when the player decides they do not want to play anymore, output stats
void score_output(int x_score,int o_score,int tie_score)
{
    cout << " --------------------------------------------" << endl;
    cout << "End of game session stats" << endl;
    cout << " Player X wins: " << x_score << endl;
    cout << " Player O wins: " << o_score << endl;
    cout << " Number of ties: " << tie_score << endl;
    cout << " --------------------------------------------" << endl;
}

