#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node tree;

int BST(tree *ptr){
    int largest, smallest;
    tree *temp;
    if(!ptr){
        return 1;
    }
    if(!BST(ptr->left)){
        return 0;
    }
    if(!BST(ptr->right)){
        return 0;
    }
    if(!ptr->left && !ptr->right){
        return 1;
    }
    if(!ptr->left){
        temp = ptr->right;
        while(!temp){
            smallest = temp->data;
            temp = temp->left;
        }
        if(ptr->data < smallest){
            return 1;
        }else{
            return 0;
        }
    }
    if(!ptr->right){
        temp = ptr->left;
        while(!temp){
            largest = temp->data;
            temp = temp->right;
        }
        if(ptr->data > largest){
            return 1;
        }else{
            return 0;
        }
        temp = ptr->left;
        while(!temp){
            largest = temp->data;
            temp = temp->right;
        }
        temp = ptr->right;
        while(!temp){
            smallest = temp->data;
            temp = temp->left;
        }
        if(ptr->data < smallest && ptr->data > largest){
            return 1;
        }else{
            return 0;
        }
    }
}

int AVL(tree *ptr, int *height){
    int heightL, heightR, diff;
    if(!ptr){
        *height = 0;
        return 1;
    }
    if(!AVL(ptr->left,&heightL)){
        return 0;
    }
    if(!AVL(ptr->right,&heightR)){
        return 0;
    }
    diff = heightL - heightR;
    if(diff > 1 || diff < -1){
        return 0;
    }else{
        if(heightL >= heightR){
            *height = heightL + 1;
        }else{
            *height = heightR + 1;
        }
        return 1;
    }

}

tree* input(tree* t,int i){
    if(t == NULL){
        t = (tree*)malloc(sizeof(tree));
        t->data = i;
        t->left = NULL;
        t->right = NULL;
        return t;
    }else{
        tree* in = (tree*)malloc(sizeof(tree));
        in->data = i;
        in->left = NULL;
        in->right = NULL;
        tree *temp = t;
        while(1){
            if(temp->left == NULL && temp->data > i){
                temp->left = in;
                return t;
            }else if(temp->right == NULL && temp->data <= i){
                temp->right = in;
                return t;
            }else if(temp->data > i){
                temp = temp->left;
            }else if(temp->data <= i){
                temp = temp->right;
            }
        }
        return t;
    }
}

void inorder(tree* t){
    if(!t){
        return;
    }else{
        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);
        return;
    }
}

int main()
{
    tree *t = NULL;

    while(1){
        int a = 0;
        int height = 0;
        printf("Input a value:");
        scanf("%d",&a);
        t = input(t,a);
        inorder(t);
        printf("\n");
        printf("BST = %d , AVL = %d\n",BST(t),AVL(t,&height));
    }

    return 0;
}
