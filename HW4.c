#include <stdio.h>
#include <stdlib.h>

static int arr[8] = {1000,500,200,100,50,10,5,1};

int numberOfCoin(int value){



    if(value == 0){
        return 0;
    }

    int c;

    for(c=0;c<8;c++){
        if(value == arr[c]){
            return 1;
        }
    }

    for(c=0;c<8;c++){
        if(value > arr[c]){
            return 1 + numberOfCoin(value - arr[c]);
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
