/*
 Problem 4: Largest Palindrome Product
 projecteuler.net/problem=4
 2/6/14
*/

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void euler4(){
    long t1 = 0;
    vector<int> primes;
    
    t1 = clock();
    primes.push_back(5);
    
    for(int i = 2; i < 200000; i++){
        i++;
        primes.push_back(i);
    }
    
    
    for(int i = 0; i < primes.size(); i++){
        
        for(int j = 1; j < primes.size(); j++){
            //cout << "is " << primes[j] << " divisible by " << primes[i] << "?" << endl;
            if(primes[j] % primes[i] == 0 && primes[j] != primes[i]){
              //  cout << "yes. Delete " << primes[j] << endl << endl;
                primes.erase(primes.begin()+j);
                j--;
            }
            else{
                //cout << "no." << endl << endl;
            }
            
        
        }
    }
    cout << endl << "the size of the vector is " << primes.size() << endl;
    
    for(int l = 0; l < primes.size(); l++){
        //cout << primes[l] << endl;
    }
    
    cout << "The 10,001st prime is: " << primes[10000];
    cout << endl << "the size of the vector is " << primes.size() << endl;
    cout << "runtime: " << ((double)(clock() - t1)/CLOCKS_PER_SEC);
}