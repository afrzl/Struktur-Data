#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new linked list node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of a linked list
void append(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the binary representation of a linked list
void printBinary(Node *head)
{
    if (head == NULL)
    {
        printf("0");
        return;
    }
    printBinary(head->next);
    printf("%d", head->data);
}

// Function to convert a decimal number to binary using linked list
Node *decimalToBinary(int n)
{
    Node *binaryList = NULL;

    // Handle negative numbers with two's complement
    if (n < 0)
    {
        n = -n;
        int carry = 1;
        while (n > 0)
        {
            int bit = n % 2;
            int complement = 1 - bit;
            int sum = complement + carry;
            append(&binaryList, sum % 2);
            carry = sum / 2;
            n /= 2;
        }
    }
    else
    {
        while (n > 0)
        {
            append(&binaryList, n % 2);
            n /= 2;
        }
    }

    // Add a sign bit for negative numbers
    if (binaryList != NULL && binaryList->data == 1)
    {
        append(&binaryList, 1);
    }
    else
    {
        append(&binaryList, 0);
    }

    return binaryList;
}

int main()
{
    int decimalNumber = -10;
    Node *binaryList = decimalToBinary(decimalNumber);

    printf("Binary representation of %d in two's complement is: ", decimalNumber);
    printBinary(binaryList);
    printf("\n");

    return 0;
}
