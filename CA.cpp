#include <iostream>
#include <stdlib.h>
#include "CA.h"
using namespace std;
  
int main(int argc, char** argv) 
{

    // Input error checking
    if(argc != 5){ cout << "Incorrect number of input values"; return -1; }
    if(strtol(argv[1], NULL, 10) < 0 || strtol(argv[1], NULL, 10) > 256){ cout << "Seed must be between 0 and 255"; return -1; }
    if(strtol(argv[2], NULL, 10) < 0 || strtol(argv[2], NULL, 10) > 256){ cout << "Key must be between 0 and 255"; return -1; }
    if(strtol(argv[3], NULL, 10) < 1){ cout << "There must be at least one repetition"; return -1; }
    if(strtol(argv[4], NULL, 10) < 0 || strtol(argv[4], NULL, 10) > 1){ cout << "The display bit must be of value 1 or 0"; return -1; }

    // Repetitions of the algorithm
    int repetitions = strtol(argv[3], NULL, 10);
    // Output 1 for output of each round, 0 otherwise
    int output = strtol(argv[4], NULL, 10);

    // Setup current (seed) array 
    int currentInt = strtol(argv[1], NULL, 10);
    int current [8];
    int remainder = 1;
    for(int i = 0; i < 8; i++){
        remainder = currentInt%2;
        currentInt /= 2;
        current [7-i] = remainder;
    }

    // Setup key array
    int keyInt = strtol(argv[2], NULL, 10);
    int key [8];
    remainder = 1;
    for(int i = 0; i < 8; i++){
        remainder = keyInt%2;
        keyInt /= 2;
        key [7-i] = remainder;
    }

    // Next array used as a temporary array for keeping track of rounds 
    int next [8] = {0, 0, 0, 0, 0, 0, 0, 0};
    
    // Calculation for a number of repetitions specified in input
    for(int j = 0; j < repetitions; j++){
        for(int i = 0; i < 8; i++){

            // Calculate left, middle and right values
            int leftIndex = i - 1;
            if(leftIndex == -1){ leftIndex = 7; }
            int middleIndex = i;
            int rightIndex = i + 1;
            if(rightIndex == 8){ rightIndex = 0; }

            // Retrieve values from current
            int left = current[leftIndex];
            int middle = current[middleIndex];
            int right = current[rightIndex];

            // Convert to a digit and retrieve the corresponding index in the key
            int index = binaryCombineThree(left, middle, right);
            next [i] = key [index];

        }

        // Copy next array to current array
        for(int i = 0; i < 8; i++){
            current[i] = next[i];
        }

        // Output for demonstration purposes
        if(output){
            cout << "Output for iteration " << j + 1 << endl;
            for(int i = 0; i < 8; i++){
                cout << next[i];
            }
            cout << " = " << binaryArrayToDecimal(next) << endl << endl;
        }        

    }

    // Convert array of ints to an integer and return
    return binaryArrayToDecimal(current); 
    
}