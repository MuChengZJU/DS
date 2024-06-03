#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Function to delete the entire subtree rooted at the given node
void deleteSubtree(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteSubtree(root->left);
    deleteSubtree(root->right);
    free(root);
}

// Function to remove nodes with a specific value from the binary tree
Node* removeNodes(Node* root, int targetValue) {
    if (root == NULL) {
        return NULL;
    }
    root->left = removeNodes(root->left, targetValue);
    root->right = removeNodes(root->right, targetValue);
    if (root->value == targetValue) {
        deleteSubtree(root);
        return NULL;
    }
    return root;
}

// Function to create a new node with the given value
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree from user input
Node* buildTree() {
    int value;
    scanf("%d", &value);
    if (value == 0) {
        return NULL;
    }
    Node* root = createNode(value);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Function to perform an in-order traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->value);
    inorderTraversal(root->right);
}

int main() {
    printf("输入二叉树：\n");
    Node* root = buildTree();
    
    printf("输入删除数字: ");
    int targetValue;
    scanf("%d", &targetValue);
    
    printf("原二叉树(中序遍历): \n");
    inorderTraversal(root);
    printf("\n");
    
    root = removeNodes(root, targetValue);
    
    printf("删除后树: \n");
    inorderTraversal(root);
    printf("\n");
    
    deleteSubtree(root);
    return 0;
}