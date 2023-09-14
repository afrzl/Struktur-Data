#include <stdio.h>
#include <stdlib.h>

struct myNode
{
    int data;
    struct myNode *next;
};

int main(int argc, char const *argv[])
{
    struct myNode *head = NULL;
    struct myNode *dua = NULL;

    head = (struct myNode *)malloc(sizeof(struct myNode));
    dua = (struct myNode *)malloc(sizeof(struct myNode));

    head->data = 1;
    head->next = dua;

    dua->data = 2;
    dua->next = NULL;

    printf("Isi dari linked list:\n");
    struct myNode *n = head;
    while (n != NULL)
    {
        printf("%d\n", n->data);
        n = n->next;
    }

    printf("Ukuran: %d\n", sizeof(struct myNode *));
    printf("Ukuran: %d\n", sizeof(head));

    return 0;
}
