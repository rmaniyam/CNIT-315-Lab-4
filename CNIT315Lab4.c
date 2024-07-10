/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    char *firstName;
    char *lastName;
    char *major;
    double gpa;
    struct Node *next;
};
void menu(int input)
{
    printf("1. Print all students\n");
    printf("2. Insert a student to front\n");
    printf("3. Insert a student to middle\n");
    printf("4. Insert a student to the end\n");
    printf("5. Delete a student from the front\n");
    printf("6. Delete a student from the middle\n");
    printf("7. Delete a studentfrom the end\n");
    printf("8. Traversing to a student's gpa\n");
    printf("9. Looking up by index \n");
    printf("Please choose an action: \n");
}
struct Node *CreateListNoNodes() 
{
    struct Node *start;
    return start;
}

int FindLength(struct Node *head) 
{
    int len = 0;
    struct Node *temp = head;
    while (temp != NULL) 
    {
        temp = temp->next;
        len++;
    }
    return len;

}

struct Node *CreateListNode(char *firstName, char *lastName, char *major, double gpa) 
{
    struct Node *head = CreateListNoNodes();
    head = (struct Node *) malloc(sizeof(struct Node));
    head->firstName = firstName;
    head->lastName = lastName;
    head->major = major;
    head->gpa = gpa;
    head->next = NULL;
    return head;
}

// https://www.geeksforgeeks.org/insert-a-node-at-front-beginning-of-a-linked-list/ 
struct Node *InsertFront(struct Node *head, char *firstName, char *lastName, char *major, double gpa)
{
    struct Node *newNode = CreateListNode(firstName, lastName, major, gpa);
    newNode->firstName = firstName;
    newNode->lastName = lastName;
    newNode->major = major;
    newNode->gpa = gpa;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node *InsertMiddle(struct Node *head, char *firstName, char *lastName, char *major, double gpa)
{
    int listLength = FindLength(head);
    int insertIndx;
    if (listLength == 0)
    {
        insertIndx = 0;
    }
    else if(listLength % 2 == 1)
    {
        insertIndx = (listLength -1) / 2;
    }
    else
    {
        insertIndx = listLength / 2;
    }
    
    struct Node *temp = head;
    for (int i = 0; i < insertIndx - 1; i++)
    {
        temp = temp->next;
    }
    
    struct Node *newNode = CreateListNode(firstName, lastName, major, gpa);
    newNode->next = temp->next;
    temp->next = newNode;
    
    return head;
}

struct Node *InsertEnd(struct Node *head, char *firstName, char *lastName, char *major, double gpa) 
{
    int lengthNode = FindLength(head);

    struct Node *temp = head;
    for (int i = 0; i < lengthNode - 1; i++) 
    {
        temp = temp->next;
    }
    struct Node *newNode = CreateListNode(firstName, lastName, major, gpa);
    temp->next = newNode;
    return head;
}

struct Node *DeleteFront(struct Node *head)
{
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// https://www.geeksforgeeks.org/delete-middle-of-linked-list/
struct Node *DeleteMiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    
    struct Node *previous;
    
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        previous = slow;
        slow = slow->next;
    }
    previous->next = slow->next;
    slow = NULL;
    return head;
}

struct Node *DeleteEnd(struct Node *head)
{
    int delIndx = FindLength(head);
    struct Node *temp = head;
    for (int i = 0; i < delIndx - 2; i++)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(temp);
    return head;
}

int Traverse(struct Node *head, double gpaTrav)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        if(temp->gpa == gpaTrav)
        {
            return 0;
        }
        temp = temp->next;
    }
    return -1;
}

//Returns GPA of the specified index
int LookUpByIndex(struct Node *head, int index)
{
    struct Node *temp = head;
    if(FindLength(head) < index - 1)
    {
        return -1;
    }
    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->gpa;
}

void PrintNode(struct Node *head) 
{

    struct Node *temp = head;
    while (temp != NULL) 
    {
        printf("[ %s, %s, %s, %f ]-->", temp->firstName, temp->lastName,
        temp->major, temp->gpa);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    printf("\nCreating a list and entering the first element\n");
    struct Node *mainNode = CreateListNode("Rishabh","Maniyambeth",
    "CIT", 100.0);
    PrintNode(mainNode);
    int start;
    char tempFirst;
    char tempLast;
    char tempMajor;
    double tempGPA;
    int menuChoice;
    int tempIndex;
    int repeat =1;
    while(repeat == 1)
    {
        menu(start);
        scanf("%i", menuChoice);
        if(menuChoice == 1)
        {
            printf("Printing list: \n");
            PrintNode(mainNode);
            printf("Would you like to do another action?(1= Yes, 0 = No): \n");
            scanf("%i", &repeat);
        }
        else if(menuChoice == 2)
        {
            printf("Please enter the first name: \n");
            scanf("%s", tempFirst);
            printf("Please enter the last name: \n");
            scanf("%s", tempLast);
            printf("Please enter the major: \n");
            scanf("%s", tempMajor);
            printf("Please enter the gpa: \n");
            scanf("%f", tempGPA);
            printf("\nInserting values to the front\n");
            mainNode = InsertFront(mainNode, tempFirst, tempLast, tempMajor, tempGPA);
            PrintNode(mainNode);
            printf("Would you like to do another action?(1= Yes, 0 = No): \n");
            scanf("%i", &repeat);
        }
        else if(menuChoice == 3)
        {
            printf("Please enter the first name: \n");
            scanf("%s", tempFirst);
            printf("Please enter the last name: \n");
            scanf("%s", tempLast);
            printf("Please enter the major: \n");
            scanf("%s", tempMajor);
            printf("Please enter the gpa: \n");
            scanf("%f", tempGPA);
            printf("\nInserting values to the middle\n");
            mainNode = InsertMiddle(mainNode, tempFirst, tempLast, tempMajor, tempGPA);
            PrintNode(mainNode);
            printf("Would you like to do another action?(1= Yes, 0 = No): \n");
            scanf("%i", &repeat);
        }
        else if(menuChoice == 4)
        {
            printf("Please enter the first name: \n");
            scanf("%s", tempFirst);
            printf("Please enter the last name: \n");
            scanf("%s", tempLast);
            printf("Please enter the major: \n");
            scanf("%s", tempMajor);
            printf("Please enter the gpa: \n");
            scanf("%f", tempGPA);
            printf("\nInserting values to the end\n");
            mainNode = InsertEnd(mainNode, tempFirst, tempLast, tempMajor, tempGPA);
            PrintNode(mainNode);
            printf("Would you like to do another action?(1= Yes, 0 = No): \n");
            scanf("%i", &repeat);
        }
        else if(menuChoice == 5)
        {
            printf("Deleting an element from the front\n");
            mainNode = DeleteFront(mainNode);
            PrintNode(mainNode);
            printf("Would you like to do another action?(1= Yes, 0 = No): \n");
            scanf("%i", &repeat);
        }
        else if(menuChoice == 6)
        {
            printf("Deleting an element from the middle\n");
            mainNode = DeleteMiddle(mainNode);
            PrintNode(mainNode);
            printf("Would you like to do another action?(1= Yes, 0 = No): \n");
            scanf("%i", &repeat);
        }
        else if(menuChoice == 7)
        {
            printf("Deleting an element from the end\n");
            mainNode = DeleteEnd(mainNode);
            PrintNode(mainNode);
            printf("Would you like to do another action?(1= Yes, 0 = No): \n");
            scanf("%i", &repeat);
        }
        else if(menuChoice == 8)
        {
            printf("Please enter a gpa: \n");
            scanf("%f", tempGPA);
            printf("Traversing to gpa %f (0 is successful): \n", tempGPA);
            printf("Result: %i\n", Traverse(mainNode, tempGPA));
            printf("Would you like to do another action?(1= Yes, 0 = No): \n");
            scanf("%i", &repeat);
        }
        else if(menuChoice == 9)
        {
            printf("Please enter an index: \n");
            scanf("%i", tempIndex);
            printf("The GPA of the #%i index is:%f\n", tempIndex, LookUpByIndex(mainNode, tempIndex));
            printf("Would you like to do another action?(1= Yes, 0 = No): \n");
            scanf("%i", &repeat);
        }
        else
        {
            printf("Please enter a valid number \n");
        }
    }
    return 0;

}
