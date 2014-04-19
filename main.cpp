/*
 Project Euler by Wheat779
 projecteuler.net
*/

#include <iostream>
#include <vector>
#include <ctime>
#include "problems.h"

using namespace std;

void problemIncomplete();
void timeFunction();
void getProblemChoice();


int runProblem = -1;                            // Set to problem you want to run. -1 for user input. 0 to run all problems.
const int highestCompleted = 11;                // Set to number of highest completed Euler Problem for array length.
bool benchmark = true;                          // Set to true to time problems, set to false to disable.
void (* problems [highestCompleted+1])() = {};  // Create an array of function pointers for problem functions.


int main(int argc, const char * argv[])
{
    // Set all array indices to problemIncomplete to remove nulls.
    for (int i = 0; i < highestCompleted+1;i++) { problems[i] = problemIncomplete; }
    
    // Array index 8 = Euler Problem 8 etc.
    problems[3]  = euler3;
    problems[4]  = euler4;
    problems[5]  = euler5;
    problems[7]  = euler7;
    problems[8]  = euler8;
    problems[9]  = euler9;
    problems[10] = euler10;
    problems[11] = euler11;
    
    getProblemChoice();

    return 0;
}












// Benchmark given function.
void timeFunction(void (*func) (void)) {
    long int starttime = clock();
    func();
    double time = (clock() - starttime)/double(CLOCKS_PER_SEC/1000);
    string timetype = " ms";
    cout << "    Runtime: " << time << timetype << endl;
}

// When runProblem is set to a problem that hasn't been done yet tell the user.
void problemIncomplete() {
    cout << "Uh oh, haven't done that one yet!" << endl;
}

// Get user input or run the problem assigned to runProblem.
void getProblemChoice() {
    
    // If runProblem is set to -1, ask the user for input.
    if (runProblem < 0) {
        cout << "Which problem would you like to run? ";
        cin >> runProblem;
    }
    
    // If the user requests a value outside of the length of our array, respond with incomplete.
    if (runProblem > highestCompleted) {
        problemIncomplete();
        return;
    }
    
    // If runProblem is set to a number greater than 0 only run that problem.
    if (runProblem > 0) {
        if (benchmark == true) {
            cout << endl << runProblem << ": "; timeFunction(problems[runProblem]);
        }
        else {
            cout << runProblem << ": "; problems[runProblem]();
        }
        return;
    }
    
    // If runProblem is set to 0 run all problems.
    if (runProblem == 0) {
        for (int i=1;i<=highestCompleted;i++){
            if (problems[i] == problemIncomplete) {
                continue;
            }
            if (benchmark == true) {
                cout << endl << i << ": "; timeFunction(problems[i]);
            } else {
                cout << endl << i << ": "; problems[i]();
            }
        }
        return;
    }
}