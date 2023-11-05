#include <stdlib.h>
#include <stdio.h>

struct node
{
    int height;
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->height = 1;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void displayPreorder(struct node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);    // root
    displayPreorder(node->left);  // subtree kiri
    displayPreorder(node->right); // subtree kanan
}

void displayInorder(struct node *node)
{
    if (node == NULL)
        return;
    displayInorder(node->left);  // subtree kiri
    printf("%d ", node->data);   // root
    displayInorder(node->right); // subtree kanan
}

void displayPostorder(struct node *node)
{
    if (node == NULL)
        return;
    displayPostorder(node->left);  // subtree kiri
    displayPostorder(node->right); // subtree kanan
    printf("%d ", node->data);     // root
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int getHeight(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// Hitung Balance factor untuk node N
int getBalanceFactor(struct node *N)
{
    if (N == NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

struct node *rightRotate(struct node *T)
{
    struct node *new_root = T->left;
    struct node *orphan = new_root->right;
    // Lakukan rotasi
    new_root->right = T;
    T->left = orphan;
    // Update height
    T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
    new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) + 1;
    // Return root baru
    return new_root;
}

struct node *leftRotate(struct node *T)
{
    struct node *new_root = T->right;
    struct node *orphan = new_root->left;
    // Lakukan rotasi
    new_root->left = T;
    T->right = orphan;
    // Update height
    T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
    new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) + 1;
    // Return root baru
    return new_root;
}

struct node *insert(struct node *root, int new_data)
{
    // 1. Lakukan BST insert biasa
    if (root == NULL)
        return (newNode(new_data));

    // asumsi tidak boleh ada nilai yang sama dalam BST
    if (new_data < root->data)
        root->left = insert(root->left, new_data);
    else if (new_data > root->data)
        root->right = insert(root->right, new_data);

    // 2. Update height dari node baru sampai root
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Hitung balance factor untuk menentukan apakah node unbalanced
    int balance = getBalanceFactor(root);

    // Jika tidak balanced, return hasil rotation
    // Kasus 1: Left Left
    if (balance > 1 && new_data < root->left->data)
        return rightRotate(root);

    // Kasus 2: Right Right
    if (balance < -1 && new_data > root->right->data)
        return leftRotate(root);

    // Kasus 3: Right Left
    if (balance < -1 && new_data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Kasus 4: Left Right
    if (balance > 1 && new_data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // return node jika balanced
    return root;
}

void search_node(struct node *root, int data)
{
    struct node *cursor = root;
    while (cursor->data != data)
    {
        if (cursor != NULL)
        {
            if (data > cursor->data)
            {
                cursor = cursor->right;
            }
            else
            {
                cursor = cursor->left;
            }
            if (cursor == NULL)
            {
                printf("\nNode %d tidak ditemukan", data);
            }
        }
    }
    printf("\nNode %d ditemukan", data);
    return;
}

struct node *delete_node(struct node *root, int deletedData)
{
    if (root == NULL)
        return;

    struct node *cursor;
    if (deletedData > root->data)
        root->right = delete_node(root->right, deletedData);
    else if (deletedData < root->data)
        root->left = delete_node(root->left, deletedData);
    else
    {
        // 1 CHILD
        if (root->left == NULL)
        {
            cursor = root->right;
            free(root);
            root = cursor;
        }
        else if (root->right == NULL)
        {
            cursor = root->left;
            free(root);
            root = cursor;
        }
        // 2 CHILDS NODE
        else
        {
            cursor = root->right;
            while (cursor->left != NULL)
            {
                cursor = cursor->left;
            }
            root->data = cursor->data;
            root->right = delete_node(root->right, cursor->data);
        }
    }

    // Jika setelah dilakukan delete, tree kosong maka return root
    if (root == NULL)
        return root;

    // 2. Update height dari node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Hitung balance factor untuk menentukan apakahroot unbalanced
    int balance = getBalanceFactor(root);

    // Jika tidak balanced, return hasil rotation
    // Kasus 1: Left Left
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Kasus 2: Right Right
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Kasus 3: Right Left
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Kasus 4: Left Right
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    return root;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    printf("Root sebelum dihapus:\n");
    displayPreorder(root);
    printf("\n");
    displayInorder(root);
    printf("\n");
    displayPostorder(root);
    printf("\n");

    root = delete_node(root, 10);

    printf("Root setelah dihapus:\n");
    displayPreorder(root);
    printf("\n");
    displayInorder(root);
    printf("\n");
    displayPostorder(root);
    printf("\n");
    return 0;
}
