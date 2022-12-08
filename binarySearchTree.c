#include <stdio.h>
#include <stdlib.h>
struct Node{
    int value;
    struct Node* left;
    struct Node* right;
};
//1 30 1 40 1 50 1 20 1 25 1 10 1 5 1 8 1 7
typedef struct Node* node;

void inorder(node root){
    if(root == NULL){
        return;
    }else{
        inorder(root->left);
        printf("%d ",root->value);
        inorder(root->right);
    }
}

node insert(node root, int value){
    node tempPtr = root;
    if(root == NULL){
        root = malloc(sizeof(node));
        root->left = NULL;
        root->right = NULL;
        root->value = value;
        return root;
    }else{
        /*
        while(tempPtr->left != NULL && tempPtr->right != NULL){
            if(tempPtr->value > value){
                tempPtr = tempPtr->left;
            }else{
                tempPtr = tempPtr->right;
            }
        }*/
        while(1){
            if(tempPtr->left == NULL && tempPtr->value > value){
                node nodePtr = malloc(sizeof(node));
                nodePtr->left = NULL;
                nodePtr->right = NULL;
                nodePtr->value = value;
                tempPtr->left = nodePtr;
                return root;
            }else if(tempPtr->right == NULL && tempPtr->value <= value){
                node nodePtr = malloc(sizeof(node));
                nodePtr->left = NULL;
                nodePtr->right = NULL;
                nodePtr->value = value;
                tempPtr->right = nodePtr;
                return root;
            }else if(tempPtr->value > value){
                tempPtr = tempPtr->left;
            }else if(tempPtr->value <= value){
                tempPtr = tempPtr->right;
            }
        }
        return root;
    }
    return root;

}

node deletePtr(node root, int value){
    node tempPtr = root;
    node prev = root;

    int i = 0;
    if(root->left == NULL && root->right == NULL){
        return NULL;
    }
    while(1){
        if(tempPtr->value == value){
            node deleteIt = tempPtr;
            //printf("temp = %d\n",tempPtr->value);
            //printf("prev = %d\n",prev->value);
            if(deleteIt->left == NULL){
                if(i == 0){
                    root = root->right;
                }
                if(prev->value > deleteIt->value){
                    prev->left = deleteIt->right;
                }else if(prev->value <= deleteIt->value){
                    prev->right = deleteIt->right;
                }

                return root;
            }else{
                node run = deleteIt->left;
                node previous = deleteIt->left;
                int j = 0;
                while(run->right != NULL){
                    if(j != 0){
                        previous = previous->right;
                    }
                    run = run->right;
                    j++;
                }
                //printf("run = %d, previous = %d\n",run->value,previous->value);
                //previous->right = NULL;
                tempPtr->value = run->value;
                run = deletePtr(run,run->value);

                if(run != NULL && j == 1){
                    run->left = NULL;
                }else if(run == NULL || (run->left == NULL && run->right == NULL)){
                    previous->right = NULL;
                }
                //free(run);
                return root;
            }
            return root;
        }else{
            if(i != 0){
                prev = tempPtr;
            }
            if(tempPtr->left == NULL && tempPtr->value > value){
                return root;
            }else if(tempPtr->right == NULL && tempPtr->value <= value){
                return root;
            }else if(tempPtr->value > value){
                tempPtr = tempPtr->left;
            }else if(tempPtr->value < value){
                tempPtr = tempPtr->right;
            }

        }
        i++;
    }
    return root;
}

node itersearch(node root,int value){
    node run = root;
    if(run == NULL){
        return NULL;
    }else{
        while(run != NULL && run->value != value){
            if(run->value > value){
                run = run->left;
            }else if (run->value < value){
                run = run->right;
            }
        }

        return run;

    }
    return NULL;
}

node search(node root,int value){
    if(root == NULL){
        return NULL;
    }else{
        if(root->value > value){
            root = root->left;
        }else if (root->value < value){
            root = root->right;
        }else{
            return root;
        }
        return search(root,value);
    }
    return NULL;
}

int main()
{
    node rootPtr = NULL;

    while(1){
        int n = 0;
        int value = 0;
        printf("Input(1) or delete(2) or find(3)\n");
        scanf("%d",&n);
        if(n == 1){
            printf("What value?");
            scanf("%d",&value);
            rootPtr = insert(rootPtr,value);
        }else if(n == 2){
            printf("What value?");
            scanf("%d",&value);
            rootPtr = deletePtr(rootPtr,value);
        }else if(n == 3){
            printf("What value?");
            scanf("%d",&value);
            node iter = itersearch(rootPtr,value);
            if(iter){
                printf("iter = %d,",iter->value);
            }
            node recu = search(rootPtr,value);
            if(recu){
                printf(" recu = %d\n",recu->value);
            }
        }
        inorder(rootPtr);
        printf("\n");

    }
    return 0;
}
