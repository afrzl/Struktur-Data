#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node *ptrnode;

ptrnode createNode(int nilai)
{
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    return (p);
}

void printNode(struct node *head)
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Node is empty.\n");
        return;
    }

    temp = head;
    printf("List of node:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

ptrnode insert_head(ptrnode head, int nilai)
{
    ptrnode new_node = createNode(nilai);
    new_node->next = head;
    head = new_node;
    return (head);
}

ptrnode insert_tail(ptrnode head, int nilai)
{
    /* iterasi mencari node terakhir*/
    ptrnode tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    /* buat node baru */
    ptrnode new_node = createNode(nilai);
    tail->next = new_node;
    return (head);
}

ptrnode insert_after(ptrnode head, int nilai, int prev_nilai)
{
    /* cari node sebelumnya, starting from the first node*/
    ptrnode cursor = head;
    while (cursor->value != prev_nilai)
        cursor = cursor->next;
    ptrnode new_node = createNode(nilai);
    new_node->next = cursor->next;
    cursor->next = new_node;
    return (head);
}

ptrnode insert_before(ptrnode head, int nilai, int next_nilai)
{
    if (head->value == next_nilai)
        head = insert_head(head, nilai);
    else
    {
        ptrnode cursor, prevcursor;
        cursor = head;
        do
        {
            prevcursor = cursor;
            cursor = cursor->next;
        } while (cursor->value != next_nilai);

        ptrnode new_node = createNode(nilai);
        new_node->next = cursor;
        prevcursor->next = new_node;
    }
    return (head);
}

ptrnode remove_first(ptrnode head)
{
    if (head == NULL)
        return;
    ptrnode first = head;
    head = head->next;
    first->next = NULL;
    free(first);
    return (head);
}

ptrnode remove_last(ptrnode head)
{
    if (head == NULL)
        return;
    ptrnode tail = head;
    ptrnode prevtail = NULL;
    while (tail->next != NULL)
    {
        prevtail = tail;
        tail = tail->next;
    }
    prevtail->next = NULL;
    free(tail);
    return (head);
}

ptrnode remove_middle(ptrnode head, int nilai)
{
    ptrnode cursor = head;
    while (cursor != NULL)
    {
        if (cursor->next->value == nilai)
            break; // keluar dari iterasi
        cursor = cursor->next;
    }
    if (cursor != NULL)
    {
        ptrnode tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    return (head);
}

ptrnode dispose(ptrnode head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        ptrnode tmp = head;
        head = head->next;
        tmp->next = NULL;
        free(tmp);
    }
    printf("semua node telah dihapus\n");
    return (head);
}

int main(int argc, char const *argv[])
{
    ptrnode head = NULL;
    head = (ptrnode)malloc(sizeof(struct node));
    head->value = 10;
    head->next = NULL;

    struct node node_dua;
    ptrnode dua = &node_dua;
    dua->value = 20;
    dua->next = NULL;

    head->next = dua;

    ptrnode tiga = NULL;
    ptrnode empat = NULL;

    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));
    dua->next = tiga;
    tiga->value = 30;
    tiga->next = empat;
    empat->value = 40;
    empat->next = NULL;

    ptrnode lima = createNode(50);
    empat->next = lima;

    printNode(head);
    printf("\n\n");

    /* Tambahkan node baru dengan value = 99 sebagai head */
    head = insert_head(head, 99);
    printNode(head);
    printf("\n\n");

    /* Tambahkan node baru dengan value = 11 sebagai tail */
    head = insert_tail(head, 11);
    printNode(head);
    printf("\n\n");

    /* Tambahkan node baru dengan value = 60 setelah node dengan value 50 */
    head = insert_after(head, 60, 50);
    printNode(head);
    printf("\n\n");

    /* Tambahkan node baru dengan value = 35 sebelum nodedengan value 99 */
    head = insert_before(head, 35, 40);
    printNode(head);
    printf("\n\n");

    // DELETE
    /* Hapus node head */
    head = remove_first(head);
    printNode(head);
    printf("\n\n");

    /* Hapus node tail */
    head = remove_last(head);
    printNode(head);
    printf("\n\n");

    /* Hapus node di tengah */
    head = remove_middle(head, 30);
    printNode(head);
    printf("\n\n");

    /* Hapus/free linked list */
    head = dispose(&head);
    printNode(head);
    printf("\n\n");

    return 0;
}
