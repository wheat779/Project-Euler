/*
 Project Euler by Wheat779
 projecteuler.net
*/

#include <iostream>
#include <vector>
#include "problems.h"

using namespace std;

// When runProblem is set to a problem that hasn't been done yet tell the user.
void problemIncomplete() {
    cout << "Uh oh, haven't done that one yet!" << endl;
}

int main(int argc, const char * argv[])
{
    // Set to -1 to run the problem entered by the users.
    // Set to  0 to run all problems.
    int runProblem = -1;
    
    // Set to the same number as the highest Euler problem completed.
    const int highestCompleted = 11;
    
    // Create an array of function pointers, set default value to return that the problem hasnt been done.
    void (* arr [highestCompleted+1])() = {problemIncomplete};
    
    // Array index 8 = Euler Problem 8 etc.
    arr[3]  = euler3;
    arr[7]  = euler7;
    arr[8]  = euler8;
    arr[9]  = euler9;
    arr[10] = euler10;
    arr[11] = euler11;
    
    // If runProblem is set to -1, ask the user for input.
    if (runProblem == -1) {
        cout << "Which problem would you like to run? ";
        cin >> runProblem;
    }
    
    // If the user requests a value outside of the length of our array, respond with incomplete.
    if (runProblem > highestCompleted) {
        problemIncomplete();
        return 1;
    }
    
    // If runProblem is set to a number greater than 0 only run that problem.
    if (runProblem > 0) {
        cout << runProblem << ": "; arr[runProblem]();
    }
    
    // If runProblem is set to 0 run all problems.
    if (runProblem == 0) {
        for (int i=1;i<=highestCompleted;i++){
            if (arr[i] != 0) {
                cout << endl << i << ": "; arr[i]();
            }
        }
    }

    return 0;
}