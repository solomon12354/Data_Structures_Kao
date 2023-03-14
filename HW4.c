#include <stdio.h>
#include <stdlib.h>

int numberOfCoin(int value){
    if(value == 0){
        return 0;
    }
    if(value == 1 || value == 5 || value == 10 || value == 50 || value == 100 || value == 200 || value == 500 || value == 1000){
        return 1;
    }else{

        if(value > 1000){
            return 1 + numberOfCoin(value - 1000);
        }
        if(value > 500){
            return 1 + numberOfCoin(value - 500);
        }
        if(value > 200){
            return 1 + numberOfCoin(value - 200);
        }
        if(value > 100){
            return 1 + numberOfCoin(value - 100);
        }
        if(value > 50){
            return 1 + numberOfCoin(value - 50);
        }
        if(value > 10){
            return 1 + numberOfCoin(value - 10);
        }
        if(value > 5){
            return 1 + numberOfCoin(value - 5);
        }
        if(value > 1){
            return 1 + numberOfCoin(value - 1);
        }
    }
    return 0;
}

int main()
{
    int money = 1380;
    printf("%d\n",numberOfCoin(money));
    return 0;
}
