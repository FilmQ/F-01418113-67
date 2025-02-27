#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* i_insertNode(struct Node* head, int value_toInsert);
void p_printNode(struct Node* head);
struct Node* d_deleteNode(struct Node* head, int value_toDelete);

int main()
{
    char char_operator = ' ';
    char BUFFER[32];
    int value = 0;

    struct Node* head = NULL;

    for(;;)
    {
        printf("input> ");
        fgets(BUFFER, 31, stdin);

        for(int i = 0; i < 32; i++)
            if(BUFFER[i] == '\n') {
                BUFFER[i] = '\0';
                break;
            }

        char_operator = BUFFER[0];
        BUFFER[0] = ' ';

        switch (char_operator) {
            case 'd':
                value = atoi(BUFFER);
                head = d_deleteNode(head, value);
            break;

            case 'p':
                p_printNode(head);
            break;

            case 'i':
                value = atoi(BUFFER);
                head = i_insertNode(head,  value);
            break;

            case 'q':
                exit(0);
            break;

            default:
                continue;
            break;
        
        }
    }

    
}


struct Node* i_insertNode(struct Node* head, int value_ToInsert)
{

    struct Node* strayNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* temp = head;
    struct Node* prev = NULL;

    strayNode->data = value_ToInsert;
    strayNode->next = NULL;

    // empty list
    if(head == NULL) {
        head = strayNode;
        return head;
    }

    // insert at head
    if(value_ToInsert <= head->data) {
        strayNode->next = head;
        head = strayNode;
        return head;
    }

    // case where the value added isnt at the head

    for(;temp != NULL; temp=temp->next) {
        if(temp->data >= value_ToInsert) {
            prev->next = strayNode;
            strayNode->next = temp;
            return head;
        }
        else if(temp->data < value_ToInsert && temp->next == NULL) {
            temp->next = strayNode;
            return head;
        }
        prev = temp;
    }

    return head;
    
}


void p_printNode(struct Node* head)
{
    struct Node* temp_Node = head;

    printf("[ ");

    while(temp_Node != NULL) {
        printf("%d ", temp_Node->data);
        temp_Node = temp_Node->next;
    }

    printf("]\n");
    
}


struct Node* d_deleteNode(struct Node* head, int value_toDelete)
{
    int flag_foundValue = 0;
    struct Node* temp = head;

    for(; temp != NULL; temp=temp->next) {
        if(temp->data == value_toDelete) {
            flag_foundValue = 1;
            break;
        }
    }

    if(flag_foundValue == 0 || head == NULL)
        return head;
 
    temp = head;
    struct Node* prev = NULL;

    for(; temp != NULL ; temp=temp->next)
    {
        // case where there is only a single node
        if(temp == head && temp->data == value_toDelete && head->next == NULL)
            return NULL;

        // case removal at head;
        if(temp == head && temp->data == value_toDelete && head->next != NULL) {
            head = head->next;
            free(temp);
            temp = head;
        }

        // case removal at body
        else if(temp != head && temp->data == value_toDelete && temp->next != NULL) {
            prev->next = temp->next;
            free(temp);
            temp = prev;
        }

        // case: removal at tail, theoretically this can be commented out but lets not risk it
        else if(temp != head && temp->data == value_toDelete && temp->next == NULL) {
            prev->next = NULL;
            free(temp);
            temp = prev;
        }
        prev = temp;
    }

    // super ultra ultra edge case:
    if(temp == NULL && head->next == NULL && head->data == value_toDelete) {
        return NULL;
    }

    return head;
}