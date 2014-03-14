#include <iostream>

using namespace std;


 //Brute force method for finding prime factors of a number
//int main(){
//    
//    long int bigNum = 13195;
//    bool prime = 1;
//    
//    //Iterate through and find numbers evenly divisble (factors)
//    for(long int i = 2; i < bigNum; i++){
//        if(bigNum % i == 0){
//            // Check if the factor has any factors.
//            for(int k = 2; k < i; k++){
//                // If the factor is divisble by a number, it isn't prime
//                if(i%k == 0){
//                    prime = 0;
//                }
//                }
//            // If it is prime, output dat thaaang
//            if(prime){
//                cout << i << endl;
//            }
//        }
//        prime = 1;
//    }
//    
//    cout << bigNum;
//    return 0;
//}


// Elegant method for finding prime factors
int main(){

    long int bigNum = 600851475143, factor = 0;
    
    // Iterate through, find smallest factor
    for(long int i = 2; i < bigNum; i++){
        if(bigNum % i == 0){
            // Once you find the smallest factor, divide your number by it,
            // then find the smallest factor for the new number
            bigNum /= i;
        }
    }
    // Once you have factored out each of the smallest factors of the number,
    // what you have remaing is the largest prime factor for the number
    cout << bigNum;
}
