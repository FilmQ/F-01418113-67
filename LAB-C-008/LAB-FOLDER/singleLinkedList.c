#include <stdio.h>
#include <stdlib.h>

typedef struct __node 
{
  int value;
  struct __node *next;
} node;

void printList(node *pList)
{
    node* temp = pList;

    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

node* insertNode(node *pList, int add)
{
    // totally memory safe
    node* head = pList;
    node* temp = head;
    node* prev = NULL;
    node* strayNode = NULL;

    // Case: EMPTY LIST:
    if(pList == NULL) {
        pList = (node*) malloc(sizeof(node));
        pList->value = add;
        pList->next = NULL;
    }

    // Case: Insert at HEAD:
    else if(add <= head->value) {
        head = (node*) malloc(sizeof(node));
        head->value = add;
        head->next = pList;
        pList = head;
    }

    // Case: Insert at BODY OR TAIL:
    else if(add > head->value) {
        for(; temp != NULL; temp=temp->next) {
            if(add < temp->value) {
                strayNode = (node*) malloc(sizeof(node));
                strayNode->value = add;
                strayNode->next = temp;
                prev->next = strayNode;
                break;
            }
            else if(temp->next == NULL) {
                strayNode = (node*) malloc(sizeof(node));
                strayNode->value = add;
                strayNode->next = NULL;
                temp->next = strayNode;
                break;
            }
            else {
                prev = temp;
                continue;
            }
            prev = temp;
        }
    }
    return pList;
}

int main() {
    int i, value;
    node *pList=NULL;
  
    for (i = 0; i < 10; i++) {
      scanf(" %d", &value);
      pList = insertNode(pList, value);
    }
  
    printList(pList);
  }
  