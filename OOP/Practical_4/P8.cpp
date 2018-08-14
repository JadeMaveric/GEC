/* Tic Tac Toe
 * Julius Alphonso '171105004'
 * 03-02-2018
 * */
#include <iostream>
#define UNDERLINE "\e[4m"
#define RESET     "\e[0m"

using namespace std;

char grid[3][3];
bool playerOneTurn;
enum {NONE, PLAYER_ONE, PLAYER_TWO} winner;

void init_game()
{
    // Initialise Game
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            grid[i][j] = ' ';
    
    // Set flags
    playerOneTurn = true;
    winner = NONE;
}

void print_grid()
{
    cout << UNDERLINE
         << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << "\n"
         << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << "\n" << RESET
         << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << endl;
}

void get_move()
{
    char input, symbol;
    symbol = playerOneTurn?'X':'O';

    cin.get(input);
    cin.ignore(); // For trailing newline char
    input ^= 32;
    
    switch (input)
    {
        case 'Q':
        grid[0][0] = symbol;
        break;
        case 'W':
        grid[0][1] = symbol;
        break;
        case 'E':
        grid[0][2] = symbol;
        break;
        case 'A':
        grid[1][0] = symbol;
        break;
        case 'S':
        grid[1][1] = symbol;
        break;
        case 'D':
        grid[1][2] = symbol;
        break;
        case 'Z':
        grid[2][0] = symbol;
        break;
        case 'X':
        grid[2][1] = symbol;
        break;
        case 'C':
        grid[2][2] = symbol;
        break;
    }
}

void update_game()
{
    // Check rows for winner
    if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] && grid[0][0] != ' ')
        winner = playerOneTurn?PLAYER_ONE:PLAYER_TWO;
    else if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2] && grid[1][0] != ' ')
        winner = playerOneTurn?PLAYER_ONE:PLAYER_TWO;
    else if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] && grid[2][0] != ' ')
        winner = playerOneTurn?PLAYER_ONE:PLAYER_TWO;
    
    // Check columns for winner
    if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] && grid[0][0] != ' ')
        winner = playerOneTurn?PLAYER_ONE:PLAYER_TWO;
    else if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[0][1] != ' ')
        winner = playerOneTurn?PLAYER_ONE:PLAYER_TWO;
    else if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[0][2] != ' ')
        winner = playerOneTurn?PLAYER_ONE:PLAYER_TWO;

    // Check diagonals for winner
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ')
        winner = playerOneTurn?PLAYER_ONE:PLAYER_TWO;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ')
        winner = playerOneTurn?PLAYER_ONE:PLAYER_TWO;

    // Toggle Player Turn flag
    playerOneTurn = !playerOneTurn;
}

int main()
{
    init_game();

    for (int i=0; i<9; i++)
    {
        print_grid();
        get_move();
        update_game();
        if (winner != NONE)
            break;
    }

    if (winner == NONE)
        cout << "DRAW";
    else if (winner == PLAYER_ONE)
        cout << "Player 1 wins!";
    else if (winner == PLAYER_TWO)
        cout << "Player 2 wins!";

    cout << endl;
    return 0;
}