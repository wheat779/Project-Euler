/*
4.21.14
 
 
 Solution to project Euler problem 2:
 
 ------------------------------------
 Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum. I.e. (1^2,2^2,3^2...) - (1,2,3,...)^2.
 ------------------------------------

 
*/

#include <iostream>


using namespace std;

void euler6(){
    int sumSquares = 0, squaredSum = 0, solution = 0;
    
    // Iterate from 1-100
    for(int i = 1; i <= 100; i++){
        squaredSum += i; // Add 1-100 to squaredSum
        sumSquares += i*i; // Add each squared number to sumSquares
    }
    // Square the contents of 1-100 for squaredSum
    squaredSum *= squaredSum;
    
    // Solution get
    solution = squaredSum - sumSquares;
    
    // From your lips to god's screen
    cout << "Difference between sum of squares and square of the sum for 1-100: " << solution << endl;
    
    
}