#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max;

/* to every key, it will generate a corresponding index */
int hashcode(int key)
{
    return (key % max);
}

int size = 0; // size dari hashtable

int size_of_hashtable()
{
    return size;
}

void insert(int array[][3], int key, int value)
{
    int index = hashcode(key);
    int i = index;
    int count = 1;

    /* probing through the array until we reach an empty space - QUADRATIC PROBING*/
    while (array[i][0] == 1 || array[i][0] == 2)
    {
        i = index;
        if (array[i][1] == key)
        {
            /* case where already existing key matches the given key */
            printf("\n Key already exists, hence updating its value \n");
            array[i][2] = value;

            return;
        }
        i = (count * count) % max; // maju satu langkah
        count++;
        if (i == index) // jika sudah mengecek satu - satu index sampai balik lagi ke index penuh
        {
            printf("\n Hash table is full, cannot insert any more item \n");

            return;
        }
    }
    array[i][0] = 1;
    array[i][1] = key;
    array[i][2] = value;
    size++;
    printf("\n Key (%d) has been inserted \n", key);
}

void remove_element(int array[][3], int key)
{
    int index = hashcode(key);
    int i = index;
    /* probing through array until we reach an empty space where not even once an element had been present */
    while (array[i][0] != 0)
    {
        if (array[i][0] == 1 && array[i][1] == key)
        {
            // case when data key matches the given key
            array[i][0] = 2;
            size--;
            printf("\n Key (%d) has been removed \n", key);

            return;
        }
        i = (i + 1) % max;
        if (i == index)
        {
            break;
        }
    }
    printf("\n This key does not exist \n");
}

/* to display all the elements of hash table */
void display(int array[][3])
{
    int i;
    for (i = 0; i < max; i++)
    {
        if (array[i][0] != 1)
        {
            printf("\n Array[%d] has no elements \n", i);
        }
        else
        {
            printf("\n Array[%d] has elements -: \n % d(key) and % d(value) ", i, array[i][1], array[i][2]);
        }
    }
}

int main()
{
    int choice, key, value, n, c;

    printf("Insert size of hash table: ");
    scanf("%d", &max);

    int array[max][3];
    /* array[][0] = flag
    array[][1] = key
    array[][2] = value */

    do
    {
        printf("Implementation of Hash Table in C with Linear Probing \n\n");
        printf("MENU-: \n1.Inserting item in the Hashtable"
               "\n2.Removing item from the Hashtable "
               "\n3.Check the size of Hashtable "
               "\n4.Display Hashtable"
               "\n\n Please enter your choice-:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Inserting element in Hashtable\n");
            printf("Enter key-:\t");
            scanf("%d", &key);
            printf("Enter value-:\t");
            scanf("%d", &value);
            insert(array, key, value);
            break;
        case 2:
            printf("Deleting in Hashtable \n Enter the key to delete-:");
            scanf("%d", &key);
            remove_element(array, key);
            break;
        case 3:
            n = size_of_hashtable();
            printf("Size of Hashtable is-:%d\n", n);
            break;
        case 4:
            display(array);
            break;
        default:
            printf("Wrong Input\n");
        }
        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
    } while (c == 1);

    getchar();
    return 0;
}
