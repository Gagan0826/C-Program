#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;

int flag = 0;

node* insert(int value, node* tree) {
    node* newnode = malloc(sizeof(node));
    newnode->value = value;
    newnode->left = newnode->right = NULL;
    if (tree == NULL)
        return newnode;
    else if (tree->value > value)
        tree->left = insert(value, tree->left);
    else
        tree->right = insert(value, tree->right);
    return tree;
}

void inorder(node* tree) {
    if (tree == NULL) {
        return;
    }
    inorder(tree->left);
    printf("%d ", tree->value);
    inorder(tree->right);
}

void preorder(node* tree) {
    if (tree == NULL) {
        return;
    }
    printf("%d ", tree->value);
    preorder(tree->left);
    preorder(tree->right);
}

void postorder(node* tree) {
    if (tree == NULL) {
        return;
    }
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ", tree->value);
}

void search(int key, node* tree) {
    flag = 0;
    node *temp=tree;
    while(temp!=NULL && temp->value!=key)
    {
        if(key < temp->value)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if (temp != NULL && temp->value==key)
        printf("Key is found");
    else
        printf("Key is not found");
}

void delete_element(int element,node* tree)
{
    node *current,*previous;
    current=tree;
    previous=NULL;
    while (current!=NULL && current->value!=element)
    {
        previous=current;
        if(element<current->value)
            current=current->left;
        else
            current=current->right;
    }
    if(current==NULL){
        printf("key not found");
        return;
    }
    //node with no children
    if (current->left==NULL && current->right==NULL)
    {
        if(previous==NULL)
        {
            free(current);
            tree=NULL;
        }
        else if(current==previous->left)
        {
            free(current);
            previous->left=NULL;
        }
        else if(current==previous->right)
        {
            free(current);
            previous->right=NULL;
        }
    }

    else if (current->left == NULL || current->right == NULL)
        {
        node *child;
        if (current->left == NULL) {
            child = current->right;
        } else {
            child = current->left;
        }
        if (previous == NULL) {
            free(current);
            tree = child;
        } else if (current == previous->left) {
            free(current);
            previous->left = child;
        } else {
            free(current);
            previous->right = child;
        }
    }
     else {
        node *successor = current->right;
        previous = NULL;
        while (successor->left != NULL) {
            previous = successor;
            successor = successor->left;
        }
        current->value = successor->value;
        if (previous != NULL) {
            previous->left = successor->right;
        } else {
            current->right = successor->right;
        }
        free(successor);
    }

}
void main() {
    node* root = NULL;
    int choice, value, key,del_ele;
    while (1) {
        printf("\n1.insert\n2.inorder traversal\n3.preorder traversal\n4.postorder traversal\n5.search\n6.delete\n7.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &value);
            root = insert(value, root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("Enter the item to be searched: ");
            scanf("%d", &key);
            search(key, root);
            break;
        case 6:{  printf("enter the element to be deleted");
                scanf("%d",&del_ele);
                delete_element(del_ele,root);
                break;
                }
        case 7:
            exit(0);
        }
    }
}



