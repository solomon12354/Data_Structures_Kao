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

void preorder(node root){
    if(root == NULL){
        return;
    }else{
        printf("%d ",root->value);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(node root){
    if(root == NULL){
        return;
    }else{
        inorder(root->left);
        inorder(root->right);
        printf("%d ",root->value);
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
//1 30 1 40 1 50 1 20 1 10 2 30
/*
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
                node run = deleteIt->right;
                node previous = deleteIt->right;
                int j = 0;
                while(run->left != NULL){
                    if(j != 0){
                        previous = previous->left;
                    }
                    run = run->left;
                    j++;
                }
                printf("run = %d, previous = %d, j = %d\n",run->value,previous->value,j);
                previous->right = NULL;
                tempPtr->value = run->value;
                if(run->left == NULL && run->right == NULL && j == 0){
                    deleteIt->right = NULL;
                }else{
                    run = deletePtr(run,run->value);

                }

                if(run != NULL && j == 1){
                    run->right = NULL;
                }else if(run == NULL || (run->left == NULL && run->right == NULL)){
                    previous->left = NULL;
                }
                //free(run);
                return root;
            }else if(deleteIt->left != NULL){
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
                printf("run = %d, previous = %d, j = %d\n",run->value,previous->value,j);
                previous->right = NULL;
                tempPtr->value = run->value;
                if(run->left == NULL && run->right == NULL && j == 0){
                    deleteIt->left = NULL;
                }else{
                    run = deletePtr(run,run->value);

                }

                if(run != NULL && j == 1){
                    run->left = NULL;
                }else if(run == NULL || (run->left == NULL && run->right == NULL)){
                    previous->right = NULL;
                }
                //free(run);
                return root;
            }else if(deleteIt->left == NULL && root->right == NULL){
                return NULL;
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
*/

node minValueNode(node Node)
{
    node current = Node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
node deleteNode(node root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->value)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->value)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            node temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        node temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->value = temp->value;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->value);
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
            rootPtr = deleteNode(rootPtr,value);
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
        printf("inorder:");
        inorder(rootPtr);
        printf("\n");
        printf("preorder:");
        preorder(rootPtr);
        printf("\n");
        printf("postorder:");
        postorder(rootPtr);
        printf("\n");
        printf("\n");

    }
    return 0;
}
