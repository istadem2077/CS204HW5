#include <iostream>
#include "board.h"
#include "player.h"
using namespace std;

int mypower(int a, int b, int m)
{
    int res = 1;
    a = a % m;
    for (int i = 1; i <= b; ++i)
        res = (res * a) % m;
    return res;
}

int rand_CS(int seed) {
    static int recurseed = seed;
    int randnum = mypower(393, recurseed, 15307) % 6 + 1;
    recurseed = recurseed * 2 % 15307;
    return randnum;
}

int main() 
{
    int seed, boardSize;

    cout << "Please enter the size of the board:" << endl;
    cin >> boardSize;
    
    if (boardSize < 2)
    {
        cout << "Error: Board size must be at least 2. Program terminating." << endl;
        return 0; 
    }

    cout << "Please enter an integer for the seed of the random number generator:" << endl;
    cin >> seed;

    if (seed <= 0) 
    {
        cout << "Error: Seed must be greater than 0. Program terminating." << endl;
        return 0;
    }
    
    cout << endl;

    Board myBoard(boardSize);
    Player playerA(myBoard, 'A', 0);  
    Player playerB(myBoard, 'B', 1 % boardSize);
    Player playerC(myBoard, 'C', 2 % boardSize);


    char turn = 'A';  // Player A goes first
    int dice;
    int counter = 0;  // Turn counter
    bool gameContinue = true;

    // Main game loop
    while (gameContinue) 
    {
        dice = rand_CS(seed);

        // Player A's turn
        if (turn == 'A') {
            cout << "Player A rolled the dice: " << dice << endl;
            cout << "Player A moves from position " << playerA.get_position();
            playerA.move(dice);
            cout << " to position " << playerA.get_position() << endl;
            playerA.claim_ownership();
            turn = 'B';  // Next turn goes to Player B
        }
        // Player B's turn
        else if (turn == 'B') 
        {
            cout << "Player B rolled the dice: " << dice << endl;
            cout << "Player B moves from position " << playerB.get_position();
            playerB.move(dice);
            cout << " to position " << playerB.get_position() << endl;
            playerB.claim_ownership();
            turn = 'C';  // Next turn goes to Player C
        }
        // Player C's turn
        else if (turn == 'C') 
        {
            cout << "Player C rolled the dice: " << dice << endl;
            cout << "Player C moves from position " << playerC.get_position();
            playerC.move(dice);
            cout << " to position " << playerC.get_position() << endl;
            playerC.claim_ownership();
            turn = 'A';  // Next turn goes to Player A
        }

        // Display the current state of the board
        cout << "Current board state: ";
        myBoard.display_board();
        counter++;
        
        // Check if the game is over (i.e., board is full)
        if (myBoard.is_full()) {
            gameContinue = false;
            cout << "Board is full." << endl;
            cout << "Ending the Game." << endl;
        }
        cout << endl;
    }

    // Display numbers at the end
    cout << "Total number of turns: " << counter << endl;
    int cellsA = playerA.count_own_cells();
    int cellsB = playerB.count_own_cells();
    int cellsC = playerC.count_own_cells();

    cout << "Cells claimed by Player A: " << cellsA << endl;
    cout << "Cells claimed by Player B: " << cellsB << endl;
    cout << "Cells claimed by Player C: " << cellsC << endl;

    return 0;
}