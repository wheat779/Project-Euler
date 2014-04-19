/*
 4.19.2014
 Problem 5: Smallest number divisible by 1-20.
 projecteuler.net/problem=5
 */

#include <iostream>

using namespace std;

void euler5(){
    // Inspired by the wheel factorization optimizations to the sieve of atkin, I am using
    // the product of all of the primes under 20 (9699690) as a guiding divisor. Since the
    // Solution will have to be a multiple of this, I will iterate through each multiple and test
    // each one. Should this process need to be made more general, you could use the code from the
    // Sieve of Atkin to find all prime factors for a given number, and then find their
    // product to be used as the primeProduct is used here.
    
    int primeProduct = 9699690;
    long long unsigned int solution = 9699690;
    bool iterating = 1;
    
    // While loop terminates after finding a number which divides by 1-20.
    while(iterating){
        // For loop tries each number 4-20. Numbers 1-3 are already implied by iterating based
        // on multiples of primes.
        for(int i = 4; i <= 20; i++){
            // If current number isn't divisble, break out of for loop
            // (iterate to next prime multiple)
            if(solution % i  != 0){
                break;}
            // If we haven't broken out of the loop and we arrived at 20, 1-20 are divsors
            // for our number, so stop iterating through the while loop (we have solution).
            else if(i == 20){
                iterating = 0;
        }
        }
        // Iterate to next multiple of the primeProduct.
        if(iterating){
            solution += primeProduct;}
    }
    // After loops have terminates, output answer.
    cout << "Smallest number divisible by 1-20: " << solution << endl;
}