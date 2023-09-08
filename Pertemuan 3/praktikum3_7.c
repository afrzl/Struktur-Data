#include <stdio.h>

struct student
{
    char name[50];
    int age;
};

// membuat fungsi dengan struct sebagai parameter
void display(struct student s)
{
    printf("\nDisplaying information\n");
    printf("Name: %s", s.name);
    printf("\nRoll: %d", s.age);
}

void main()
{
    struct student s1;
    printf("Enter name: ");
    gets(s1.name);
    printf("Enter age: ");
    scanf("%d", &s1.age);
    display(s1); // passing structure as an argument
}