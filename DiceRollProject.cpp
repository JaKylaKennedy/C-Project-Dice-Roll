include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

using namespace std;
//Corrected, Std removed as namespace std is listed above and endl used.
int main() {
    // Seed for the randomizer
    unsigned seed;
    seed = time(0);
    srand(seed);

    //Color
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    // Variables
    int rollOne, rollTwo, input_option;
    string playername_One, playername_Two;

    // Roll Calculation for both players
    rollOne = rand() % 20 + 1;
    rollTwo = rand() % 20 + 1;

    cout << "Welcome to the Dice Game!" << endl;
    cout << "This game, as of now, only allows two players" << endl;
    cout << "Please select 1 to continue or any key to exit" << endl;
    cin >> input_option; 

    // IF/ELSE statements for game options, the user can choose to start the game or exit using any key

    // Game Starts
    if (input_option == 1) { // Corrected the comparison operator from '=' to '=='
        cout << "Please Enter Player One Name" << endl;
        cin >> playername_One;
        cout << "Please Enter Player Two Name" << endl;
        cin >> playername_Two;
        cout << "Good Luck Players" << endl;

        // Nested Statements for the critical rolls
        if (rollOne == 1) {
            SetConsoleTextAttribute(screen, 12);
            cout << "Critical Failure" << endl; // Red color
            SetConsoleTextAttribute(screen, 7);
        } else if (rollOne == 20) {
            SetConsoleTextAttribute(screen, 10);
            cout << "Critical Success" << endl; // Green color
            SetConsoleTextAttribute(screen, 7);
        }

        if (rollTwo == 1) {
            SetConsoleTextAttribute(screen, 12);
            cout << "Critical Failure" << endl; // Red color
            SetConsoleTextAttribute(screen, 7);
        } else if (rollTwo == 20) {
            SetConsoleTextAttribute(screen, 10);
            cout << "Critical Success" << endl; // Green color
            SetConsoleTextAttribute(screen, 7);
        }

        // Results
        cout << playername_One << "'s score is " << rollOne << endl; 
        cout << playername_Two << "'s score is " << rollTwo << endl; 

        if (rollOne > rollTwo) {
            cout << playername_One << " is the Winner!" << endl;
        } else if (rollTwo > rollOne) {
            cout << playername_Two << " is the Winner!" << endl;
        } else {
            cout << "The players are Evenly Matched!" << endl;
        }
    } else {
        cout << "See you later, alligator!" << endl;
    }

    return 0;
}
