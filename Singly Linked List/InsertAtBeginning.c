#include <stdio.h>
#include <stdlib.h>

//Structure of a node
struct node {
    int data;
    struct node *next;
}*head;


void createList(int n);
void insertNodeAtBeginning(int data);
void displayList();

int main()
{

    int n, data

       /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    /*
     * Insert data at the beginning of the singly linked list
     */
    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insertNodeAtBeginning(data);

    printf("\nData in the list \n");
    displayList();

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of data node 1: ");
        scanf("%d",&data);

        head->data = data;
        head->next = NULL;

        temp = head;

        // Crete n nodes and adds to linked list
        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            if(newNode == NULL)
            {
                printf("Unable to allocate memory");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d",&data);

                newNode->data = data;
                newNode->next = NULL;

                temp->next = newNode;
                temp = temp->next;
            }
        }
         printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory");
    }
    else
    {
        newNode->data = data;
        newNode->next = head;

        head = newNode;

        printf("Data inserted successfully")
    }
}

void displayList()
{
    struct node *temp;

    head = (struct node*)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;

        while(temp != NULL)
        {
            printf("Data %d\n",temp->data);
            temp = temp->next;
        }
    }
}
