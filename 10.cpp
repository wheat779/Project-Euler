/*
 Problem 10: Summation of Primes
 projecteuler.net/problem=10
*/

#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void euler10(){
    long int t1 = clock();
    // Create the limit of primes you want to generate to, and find its square root
    // square root is used to limit calculations within loops to ensure the loops
    // do not continue to generate quadratic answers above the limit
    int limit = 2000000;
    int root = ceil(sqrt(limit));
    
    // Sum of primes. This will contain our answer to the euler problem
    unsigned long long int primeSum = 0;

    // Create a sieve array filled with bools. Each entry is true if the entry number is prime
    // Note: if using a compilers where the default value for a bool isn't negative, primality will
    // be opposite
    vector<bool> primes;
    for(int i = 0; i < limit; i++){
        primes.push_back(false);
    }
    
    // Add special cases
    primes[2] = true;
    primes[3] = true;
    
    // Generates numbers based on quadratics, and flips them if they meet the wheeled mod 60 test
    for(int x = 1; x <= root; x++){
        for(int y = 1; y <= root; y++){
            
            int n = (4*x*x) + (y*y);
            if(n <= limit && (n%12 == 1 || n%12 == 5)) {primes[n] = !primes[n];}
            
            n = (3*x*x) + (y*y);
            if(n <= limit && (n%12 == 7)){primes[n] = !primes[n];}
            
            n = (3*x*x) - (y*y);
            if(x > y && n <= limit && (n%12 == 11)){primes[n] = !primes[n];}
        }
    }
    
    // Remove multiples of squares
    for(int r = 5; r <= root; r++){
        if(primes[r]){
            for(int i = r*r; i < limit; i += r*r){
            primes[i] = false;
            }
        }
    }
    
    for(int i = 0; i < limit; i++){
        if(primes[i]){
            //cout << i << endl;
            primeSum += i;
            //cout << "new sum = " << primeSum << endl;
        }
    }
    cout << "runtime: " << ((double)(clock() - t1)/CLOCKS_PER_SEC);
    cout << endl << primeSum << endl;
}