#include <string>
#include <math.h>
using namespace std;

////////////////////////
// Conversion Methods //
////////////////////////

int decimalToBinary(int n){
    int binaryNumber = 0;
    int remainder = 1;
    int i = 1;

    while (n!=0){
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }

    return binaryNumber;
}

int binaryToDecimal(int n) { 
    int decimalNumber = 0;
    int base = 1;       
    int temp = n; 

    while (temp){ 
        int last_digit = temp % 10; 
        temp = temp/10;          
        decimalNumber += last_digit*base;          
        base = base*2; 
    }

    return decimalNumber; 
} 

int binaryArrayToDecimal(int* binaryArray){
    int r = 0;
    for(int i = 0; i < 8; i++){
        r = r << 1 | binaryArray[i];
    }
    return r;
}

int binaryCombineThree(int left, int middle, int right){
    return left * 4 + middle * 2 + right;
}