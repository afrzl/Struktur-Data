#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct node
{
    int height;
    char nama[30];
    struct node *left;
    struct node *right;
};

struct node *newNode(char *nama)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    strcpy(node->nama, nama);
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void displayPreorder(struct node *node)
{
    if (node == NULL)
        return;
    printf("%s ", node->nama);    // root
    displayPreorder(node->left);  // subtree kiri
    displayPreorder(node->right); // subtree kanan
}

void displayInorder(struct node *node)
{
    if (node == NULL)
        return;
    displayInorder(node->left);  // subtree kiri
    printf("%s ", node->nama);   // root
    displayInorder(node->right); // subtree kanan
}

void displayPostorder(struct node *node)
{
    if (node == NULL)
        return;
    displayPostorder(node->left);  // subtree kiri
    displayPostorder(node->right); // subtree kanan
    printf("%s ", node->nama);     // root
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

struct node *insert(struct node *root, char *newData)
{
    // 1. Lakukan BST insert biasa
    if (root == NULL)
        return (newNode(newData));

    // asumsi tidak boleh ada nilai yang sama dalam BST
    int cmp = strcasecmp(root->nama, newData);

    if (cmp == 0)
    {
        printf("\nNama sudah ada");
        return root;
    }
    else if (cmp > 0)
        root->left = insert(root->left, newData);
    else
        root->right = insert(root->right, newData);

    // 2. Update height dari node baru sampai root
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Hitung balance factor untuk menentukan apakah node unbalanced
    int balance = getBalanceFactor(root);

    // Jika tidak balanced, return hasil rotation
    // Kasus 1: Left Left
    if (balance > 1 && (strcasecmp(newData, root->left->nama) < 0))
        return rightRotate(root);

    // Kasus 2: Right Right
    if (balance < -1 && (strcasecmp(newData, root->right->nama) > 0))
        return leftRotate(root);

    // Kasus 3: Right Left
    if (balance < -1 && (strcasecmp(newData, root->right->nama) < 0))
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Kasus 4: Left Right
    if (balance > 1 && (strcasecmp(newData, root->left->nama) > 0))
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    return root;
}

void search_node(struct node *root, char *nama)
{
    struct node *cursor = root;

    while (cursor != NULL)
    {
        int cmp = strcasecmp(cursor->nama, nama);

        if (cmp == 0)
        {
            printf("\nNode %s ditemukan", nama);
            return;
        }
        else if (cmp > 0)
        {
            cursor = cursor->left;
        }
        else
        {
            cursor = cursor->right;
        }
    }

    printf("\nNode %s tidak ditemukan", nama);
    return;
}

struct node *delete_node(struct node *root, char *deletedData)
{
    if (root == NULL)
        return root;

    struct node *cursor;

    int cmp = strcasecmp(root->nama, deletedData);

    if (cmp > 0)
    {
        root->left = delete_node(root->left, deletedData);
    }
    else if (cmp < 0)
    {
        root->right = delete_node(root->right, deletedData);
    }
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
            strcpy(root->nama, cursor->nama);
            root->right = delete_node(root->right, cursor->nama);
        }
    }

    return root;
}

/* Print nodes at a given level */
void printGivenLevel(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%s ", root->nama);
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrder(struct node *root)
{
    int i;
    for (i = 1; i <= root->height; i++)
    {
        printGivenLevel(root, i);
        printf("\n");
    }
}

int main()
{
    struct node *root = NULL;
    char question, string[30];

    printf(">> FITUR INSERT DATA <<");
    do
    {
        printf("\n> Masukkan nama: ");
        scanf("%s", string);
        root = insert(root, string);
        printf("Apakah anda akan memasukkan nama lagi? (y/n): ");
        scanf(" %c", &question);
    } while (tolower(question) != 'n');

    // root = insert(root, "abc");
    // root = insert(root, "cde");
    // root = insert(root, "bcd");
    // root = insert(root, "adf");
    // root = insert(root, "bfe");

    system("@cls||clear");

    printf("\n\n>> DAFTAR NAMA MAHASISWA <<");
    printf("\nPreorder: ");
    displayPreorder(root);
    printf("\nInorder: ");
    displayInorder(root);
    printf("\nPostorder: ");
    displayPostorder(root);
    printf("\nPrint per level node: ");
    printLevelOrder(root);

    printf("\n\n>> FITUR PENCARIAN <<");
    question = 'y';
    do
    {
        printf("\n> Masukkan nama: ");
        scanf("%s", string);
        search_node(root, string);
        printf("\nApakah anda akan mencari nama lagi? (y/n): ");
        scanf(" %c", &question);
    } while (tolower(question) != 'n');

    printf("\n\n>> FITUR DELETE MAHASISWA <<");
    question = 'y';
    do
    {
        printf("\n> Masukkan nama: ");
        scanf("%s", string);
        root = delete_node(root, string);
        printf("\nApakah anda akan menghapus nama lagi? (y/n): ");
        scanf(" %c", &question);
    } while (tolower(question) != 'n');

    printf("\n\n>> DAFTAR NAMA MAHASISWA <<");
    printf("\nPreorder: ");
    displayPreorder(root);
    printf("\nInorder: ");
    displayInorder(root);
    printf("\nPostorder: ");
    displayPostorder(root);

    return 0;
}
