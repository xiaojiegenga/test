#include <stdio.h>
#include <stdlib.h>

int tailRecur(int n, int res) 
// "尾递归求n个数的和"
{
    if(n == 0){
        return res;
    }
    return tailRecur(n-1,res+n);
}

int main() 
{
    int n = 10;
    int res = tailRecur(n,0);
    printf("The sum of first %d numbers is %d\n",n,res);
    printf("I clone it in ubuntu!\n");
    return 0;
}
