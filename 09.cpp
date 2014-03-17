/*
 Problem 9: Special Pythagorean Triplet
 projecteuler.net/problem=9
*/

#include <iostream>
#include <cmath>

using namespace std;

void euler9(){
    double c = 0, sum = 1000;
    for(double i = 1; i < sum/3; i++){
        for(double k = i+1; k < sum/2; k++){
            c = sum - i - k;
            if( ((i*i) + (k*k)) == (c*c)){
//                cout << "c = " << c << endl;
//                cout << i << " + " << k << " + " << c  << " = " << i+k+c << endl << endl;
                cout << "a + b + c = 1000, a*b*c = " << int(i*k*c) << endl;
            }
        }
    }
}

//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main(){
//    double a = 0, b = 0, c = 0, product = 0;
//    for(double i = 1; i < 1000; i++){
//        for(double k = i; k < 1000; k++){
//            a = i*i;
//            b = k*k;
//            c = a+b;
//            cout << " a = " << a << endl;
//            cout << " b = " << b << endl;
//            cout << " c = " << c << endl;
//            if(sqrt(c) == int(sqrt(c))){
//                cout << "c has a integer square root!" << endl;
//                cout << "a+b+c = " << (i + k + sqrt(c));
//                if((i + k + sqrt(c)) == 1000){
//                    cout << "found it!!";
//                    a = i;
//                    b = k;
//                    c = sqrt(a+b);
//                    cout << a << " + " << b << " + " << c << " = " << a+b+c;
//                    break;
//                }
//            }
//        }
//    }
//}