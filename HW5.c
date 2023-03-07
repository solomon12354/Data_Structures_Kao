#include <stdio.h>
#include <stdlib.h>


int check(int n,int arr[n],int i,int j,int k){
    if(i >= n){
        return 0;
    }else{
        if(j >= n){
            return check(n,arr,i+1,0,0);
        }
        else if(k >= n){
            return check(n,arr,i,j+1,0);
        }
        else if(i != j && j != k && i != k){
            if(arr[i] + arr[j] == arr[k]){
                printf("%d %d %d\n",arr[i],arr[j],arr[k]);
                return 1;
            }
        }

        return check(n,arr,i,j,k+1);
    }

}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d\n",check(10,arr,0,0,0));
    return 0;
}
