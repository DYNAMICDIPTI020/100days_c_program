#include"stdio.h"
int fibonachi(int);

int fibonachi(int n){
    if (n ==1 || n ==2)
    {
        return n-1;
    }
    return fibonachi(n-1)+ fibonachi(n-2);
}
int main(){
    int n = 4;
    printf("the value of fibonachi series %d  is %d ", n , fibonachi(n));
}