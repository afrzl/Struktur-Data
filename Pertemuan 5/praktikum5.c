#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node *ptrnode;

ptrnode createNode(int nilai)
{
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    p->prev = NULL;
    return (p);
}

void printNode(ptrnode head)
{
    ptrnode temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Nodes of doubly linked list: \n");

    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

ptrnode insert_head(ptrnode head, int nilai)
{
    ptrnode new_node = createNode(nilai);
    new_node->next = head;
    head->prev = new_node;
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

ptrnode insert_after(ptrnode head, int nilai, int nilai_dicari)
{
    /* cari node sebelumnya, starting from the first
   node*/
    ptrnode cursor = head;
    while (cursor->value != nilai_dicari)
        cursor = cursor->next;
    ptrnode new_node = createNode(nilai);
    new_node->next = cursor->next;
    cursor->next->prev = new_node;
    new_node->prev = cursor;
    cursor->next = new_node;
    return (head);
}

ptrnode insert_before(ptrnode head, int nilai, int next_nilai)
{
    if (head->value == next_nilai)
        head = insert_head(head, nilai);
    else
    {

        // pencarian nilai sama seperti insert after, tidak perlu 2 cursor
        ptrnode cursor = head;
        while (cursor->value != next_nilai)
            cursor = cursor->next;

        ptrnode new_node = createNode(nilai);
        new_node->prev = cursor->prev;
        cursor->prev->next = new_node;
        new_node->next = cursor;
        cursor->prev = new_node;
    }
    return (head);
}

ptrnode remove_first(ptrnode head)
{
    if (head == NULL)
        return;
    ptrnode first = head;
    head = head->next;
    head->prev = NULL;
    first->next = NULL;
    free(first);
    return (head);
}

ptrnode remove_last(ptrnode head)
{
    if (head == NULL)
        return;
    // cursor bantuan satu lagi (prev_tail) tidak dibutuhkan
    ptrnode tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->prev = NULL;
    tail->prev->next = NULL;
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
        tmp->next->prev = cursor;
        tmp->next = NULL;
        tmp->prev = NULL;
        free(tmp);
    }
    return (head);
}

int main(int argc, char const *argv[])
{
    ptrnode head = NULL;
    ptrnode tail = NULL;
    head = (ptrnode)malloc(sizeof(struct node));
    tail = head;
    head->value = 10;
    head->next = NULL;
    head->prev = NULL;

    struct node node_dua;
    ptrnode dua = &node_dua;
    dua->value = 20;
    dua->next = NULL;
    dua->prev = NULL;

    head->next = dua;
    dua->prev = head;

    ptrnode tiga = NULL;
    ptrnode empat = NULL;
    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));
    dua->next = tiga;
    tiga->value = 30;
    tiga->next = empat;
    tiga->prev = dua;
    empat->value = 40;
    empat->next = NULL;
    empat->prev = tiga;

    ptrnode lima = createNode(50);
    empat->next = lima;
    lima->prev = empat;

    /* Tambahkan node baru dengan value = 99 sebagai head */
    head = insert_head(head, 99);
    printNode(head);

    /* Tambahkan node baru dengan value = 99 sebagai head */
    head = insert_head(head, 99);
    printNode(head);

    /* Tambahkan node baru dengan value = 11 sebagai tail */
    head = insert_tail(head, 11);
    printNode(head);

    /* Tambahkan node baru dengan value = 60 setelah node dengan value 50 */
    head = insert_after(head, 60, 50);
    printNode(head);

    /* Tambahkan node baru dengan value = 35 sebelum node dengan value 40 */
    head = insert_before(head, 35, 40);
    printNode(head);

    /* Hapus node head */
    head = remove_first(head);
    printNode(head);

    /* Hapus node tail */
    head = remove_last(head);
    printf("ahdbajsdnkasnd");
    printNode(head);

    /* Hapus node di tengah */
    head = remove_middle(head, 30);
    printNode(head);
    printf("ahdbajsdnkasnd");
    printNode(tail);

    return 0;
}
