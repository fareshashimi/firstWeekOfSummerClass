#include <stdio.h>
#include <stdlib.h>
int f(int n){
    if(n<=0){
        return 0;
    }
    else{
        return 2 + f(n - 1);
    }
}

int main(){
    int n;
    printf("Insert a number: ");
    scanf("%d", &n);

    int result = f(n);
    printf("\n The result is %d\n", result);

    return 0;
}
