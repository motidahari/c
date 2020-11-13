#include <stdio.h>  
#include "myMath.h"
/**
 * created by yochai modechai dahari
 * ID: 308212570
*/


/**
 * name function: Exp
 * @param: x typy int
 * @return: result
*/
double Exponent(int x) {
    double e = 2.71828;
    double result = e;
    for (int i = 0; i < x-1; i++){
        result = result *  e;
    }
    return result;
}
/**
 * name function: Pow
 * @param: x typy double, y type int
 * @return: result
*/
double Power(double x , int y) {
    double result = 1;
    for (int i = 0; i < y; i++){
        result *= x;
    } 
    return result;
}
