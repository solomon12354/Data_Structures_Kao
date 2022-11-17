#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int n){
    int out = 1;
    for(int i=1;i<=n;i++){
        out = out * i;
    }
    return out;
}

void train(int start[], int sizeStart, int stack[], int sizeStack, int n,int order,int all[]){
    if(order >= pow(10,n-1) || (sizeStart == 0 && sizeStack == 0)){
        //printf("%d\n",order);
        int isExist = 0;
        int count = 0;
        for(int i=0;i<factorial(n);i++){
            if(order == all[i]){
                isExist = 1;
                break;
            }
        }
        for(int i=0;i<factorial(n);i++){
            if(all[i] == 0){
                count = i;
                break;
            }
        }
        if(!isExist){
            all[count] = order;
        }
        return;
    }else{
        int a = start[0];
        int b = stack[sizeStack-1];
        int newStart[n];
        int newPushStack[n];
        int newPopStack[n];
        int oldStart[n];
        int oldStack[n];
        for(int i=1;i<n;i++){
            newStart[i-1] = start[i];
        }
        newStart[n-1] = 0;
        for(int i=0;i<sizeStack-1;i++){
            newPopStack[i] = stack[i];

        }
        newPopStack[sizeStack-1] = 0;
        for(int i=0;i<sizeStack;i++){
            newPushStack[i] = stack[i];
        }
        newPushStack[sizeStack] = a;
        for(int i=0;i<n;i++){
            oldStart[i] = start[i];
            oldStack[i] = stack[i];
        }
        if(sizeStart>0){
            train(newStart,sizeStart-1,oldStack,sizeStack,n,(order * 10 + a),all);
        }
        if(sizeStack>0){
            train(oldStart,sizeStart,newPopStack,sizeStack-1,n,(order * 10 + b),all);
        }
        if(sizeStart>0){
            train(newStart,sizeStart-1,newPushStack,sizeStack+1,n,order,all);
        }
    }
}

int main()
{
    int amount = 4;
    int array[amount];
    int stack[amount];
    int all[factorial(amount)];
    for(int i=0;i<amount;i++){
        array[i] = i+1;
        stack[i] = 0;
    }
    for(int i=0;i<factorial(amount);i++){
        all[i] = 0;
    }
    train(array,amount,stack,0,amount,0,all);
    for(int i=0;i<factorial(amount);i++){
        if(all[i]!=0){
            printf("%d ",all[i]);
        }else{
            printf("\n");
            break;
        }
    }
    return 0;
}
