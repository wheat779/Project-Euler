/*
 4.15.14
 Problem 4: Largest palindrome product of two 3-digit numbers
 projecteuler.net/problem=4
 */


# include <iostream>

using namespace std;

void euler4(){

    // Create var to store palindrome numbers
    int num;
    int largestPalindrome = 0;
    
    // Using a nested for loop iterate backward through the highest three digit numbers,
    // multiply the two numbers together trying each combination once.
    // You should hit the highest quickly.
    for(int i = 999; i > 99; i--){
        for(int j = 999; j > i-1; j--){
            num = j * i;
            
            // convert product to string
            string numString = to_string(num);
            
            // check to see if it's the same string if reversed (using recursive functions)
            if(numString == string(numString.rbegin(), numString.rend())){
                
                // Check if it's the largest palindrome number so far
                if(num > largestPalindrome){
                    largestPalindrome = num;
                }
            }
        }
    }
    // output answer
    cout << "Largest palindrome product of two 3-digit numbers: " << largestPalindrome << endl;
}