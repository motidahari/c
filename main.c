#include <stdio.h>  
#include "myMath.h"

/**
 * created by yochai modechai dahari
 * ID: 308212570
*/


/**
 * name function: solve
 * @param: x typy double
 * @return: none
*/
void solve(double x ) {
    double x1 = sub(add((Exp((x))),Pow(x,3)),2);
    double x2 = add(mul(x,3), mul(Pow(x,2),2));
    double x3 = sub(div(mul(Pow(x,3),4),5),mul(x,2));
    
    printf("\n The value of f(𝑥) = 𝑒^𝑥 + 𝑥^3 − 2 at the point %0.4f is: %0.4f" ,x , x1);
    printf("\n The value of f(𝑥) = 3x + 2x^2 at the point %0.4f is: %0.4f" ,x , x2);
    printf("\n The value of f(𝑥) = (4x^3)/5 - 2x at the point %0.4f is: %0.4f\n" ,x , x3);
}

int main(){
    double z;
    printf("Enter double x:");
    scanf("%lf", &z);
    solve(z);
    return 0;
}
