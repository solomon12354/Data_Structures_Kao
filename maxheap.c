#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* node;

void inorder(node root) {
    if (root == NULL) {
        return;
    }
    else {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void preorder(node root) {
    if (root == NULL) {
        return;
    }
    else {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node root) {
    if (root == NULL) {
        return;
    }
    else {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

struct myQueue {
    node Node;
    struct myQueue* next;
};

typedef struct myQueue* que;

void printTree(node root) {
    if (root == NULL) {
        return;
    }
    que arr = malloc(sizeof(que));
    arr->Node = root;
    arr->next = NULL;
    int count = 1;
    que tail = arr;
    que deletePtr = arr;
    while (count != 0 && arr != NULL) {
        printf("%d ", arr->Node->value);
        if (arr->Node->left != NULL) {
            que nodePtr = malloc(sizeof(que));
            nodePtr->next = NULL;
            tail->next = nodePtr;
            nodePtr->Node = arr->Node->left;
            tail = tail->next;

        }
        count++;
        if (arr->Node->right != NULL) {
            que nodePtrR = malloc(sizeof(que));
            nodePtrR->next = NULL;
            tail->next = nodePtrR;
            nodePtrR->Node = arr->Node->right;
            tail = tail->next;
        }
        count++;
        que nextPtr = arr->next;

        //free(arr);
        arr = nextPtr;

        count--;
    }
    /*
    while (deletePtr != NULL) {
        que* deleteNode = &deletePtr;
        //printf("%d ",*deleteNode.Node.value);
        deletePtr = deletePtr->next;
        free(*deleteNode);
    }*/
    return;
}

node maxheapsort(node root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        return root;
    }else{
        node left = maxheapsort(root->left);
        node right = maxheapsort(root->right);
        if(left != NULL && left->value > root->value){
            int temp = root->left->value;
            root->left->value = root->value;
            root->value = temp;
        }
        if(right != NULL && right->value > root->value){
            int temp = root->right->value;
            root->right->value = root->value;
            root->value = temp;
        }
        return root;
    }
    return root;
}

node insert(node root, int value) {
    node tempPtr = root;
    node nodePtr = malloc(sizeof(struct Node));
    nodePtr->left = NULL;
    nodePtr->right = NULL;
    nodePtr->value = value;

    if (root == NULL) {
        return nodePtr;
    }
    else
    {
        que arr = malloc(sizeof(que));
        arr->Node = root;
        arr->next = NULL;
        int count = 1;
        que tail = arr;
        que deletePtr = arr;
        while (1)
        {
            printf("%d ", arr->Node->value);
            if (arr->Node->left != NULL)
            {
                que nodePtr = malloc(sizeof(que));
                nodePtr->next = NULL;
                tail->next = nodePtr;
                nodePtr->Node = arr->Node->left;
                tail = tail->next;

            }
            count++;
            if (arr->Node->right != NULL)
            {
                que nodePtrR = malloc(sizeof(que));
                nodePtrR->next = NULL;
                tail->next = nodePtrR;
                nodePtrR->Node = arr->Node->right;
                tail = tail->next;
            }
            count++;
            if(arr->Node->left == NULL){
                arr->Node->left = nodePtr;
                break;
            }
            if(arr->Node->right == NULL){
                arr->Node->right = nodePtr;
                break;
            }
            que nextPtr = arr->next;

            //free(arr);
            arr = nextPtr;

            count--;
        }
        /*
        while (deletePtr != NULL) {
            que* deleteNode = &deletePtr;
            //printf("%d ",*deleteNode.Node.value);
            deletePtr = deletePtr->next;
            free(*deleteNode);
        }*/
        root = maxheapsort(root);
        return root;
    }
    return root;

}

int main()
{
    node rootPtr = NULL;

    while (1) {
        int n = 0;
        int value = 0;
        printf("Input ");

        printf("what value?");
        scanf("%d", &value);
        rootPtr = insert(rootPtr, value);

        printf("inorder:");
        inorder(rootPtr);
        printf("\n");
        printf("preorder:");
        preorder(rootPtr);
        printf("\n");
        printf("postorder:");
        postorder(rootPtr);
        printf("\n");
        printf("Tree:");
        printTree(rootPtr);
        printf("\n");

    }
    return 0;
}
