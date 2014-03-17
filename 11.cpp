/*
 Problem 11: Largest Product in a Grid
 projecteuler.net/problem=11
 3/8/2014
 Reads from a text file, transfers its numeric contents to an array matrix then finds the largest 4 number multiple in any direction across the matrix (up/across/diagonal).
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void euler11(){
    
    // Var for reading in and holding the contents of the text document
    stringstream ss;
    char buffer[10]; // Buffer for holding chars delimited by spaces
    string line; // Object for holding each line of the text document

    
    // Matrix for holding read-in numbers, and row/column var for sizing matrix
    int row = 20;
    int col = 20;
    int matrix[row][col];
    
    // Int for holding the largest product. This goan be the answer.
    unsigned long int largestProduct = 0, testNum = 0;
    
    
    //read in the text file into a string stream
    string file = getenv("HOME");
    file += "/Code/Project-Euler/11.txt";
    ifstream numFile (file);
    if(numFile.is_open()){
        while (getline (numFile, line)){
            
            ss << line << " ";
            // cout << line << endl;
        }
        
        numFile.close();
    }
    else{
        cout << "Unable to open file." << endl;
        return;
    
    }
    
    // Once we have the contents of the text file in the stream, parse it into the matrix
    // converting the chars into ints using stringstream + atoi
    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            ss.getline(buffer, 80, ' ');
            matrix[x][y] = (atoi(buffer));
        }
    }
    
    // Test code: printing the matrix
    // cout << endl;
    
    //    for(int i = 0; i < row; i++){
    //        for(int j = 0; j < col; j++){
    //            cout << matrix[i][j] << " ";
    //        }
    //        cout  << endl;
    //    }
    
    // The search for the largest four number multiple will be accomplished in four sweeps
    // (1) horizontally through each row, (2) vertically through each column,
    // (3) diagonally from top left down to the right, (4) diagonally from top right down to left
    

        // 1. horizontal search
        for(int y = 0; y < col; y++){
            for(int x = 0; x < row-3; x++){
                // Set test num
                testNum = (matrix[y][x] * matrix[y][x+1] * matrix[y][x+2] * matrix[y][x+3]);
                
                if(testNum > largestProduct){
                    largestProduct = testNum;
                }
            }
        }
    
    // 2. vertical search
    for(int x = 0; x < row; x++){
        for(int y = 0; y < col-3; y++){
            testNum = (matrix[y][x] * matrix[y+1][x] * matrix[y+2][x] * matrix[y+3][x]);
            if(testNum > largestProduct){
                largestProduct = testNum;
            }
        }
    }
    
    // 3. diagonal from top left to bottom right.
    for(int y = 0; y < col-3; y++){
        for(int x = 0; x < row-3; x++){
            testNum = (matrix[x][y] * matrix[x+1][y+1] * matrix[x+2][y+2] * matrix[x+3][y+3]);
            if(testNum > largestProduct){
                largestProduct = testNum;
            };
        }
    }
    // 4. diagonal from top right to bottom left.
    for(int x = 19; x > 2; x--){
        for(int y = 0; y < col-3; y++){
            testNum = (matrix[y][x] * matrix[y+1][x-1] * matrix[y+2][x-2] * matrix[y+3][x-3]);
            if( testNum > largestProduct){
                largestProduct = testNum;
            }
        }
    }
    // Output answer
    cout << "Largest product in grid: " << largestProduct << endl;
}