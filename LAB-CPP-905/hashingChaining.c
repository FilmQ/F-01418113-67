#include <stdio.h>
#include <stdlib.h>

#define SIZE  97

typedef struct nodeType {
    int item;
    struct nodeType* next;
} Node;

int main()
{
    // woah an array of pointers
    Node* hashTableLinker[SIZE];
    Node* strayNode = NULL;
    int value = 0;

    char BUFFER[32];

    // init all to NULL
    for(int i = 0; i < SIZE; i++)
        hashTableLinker[i] = NULL;

    while(1) {
        printf("input> ");
        fgets(BUFFER, 31, stdin);

        switch(BUFFER[0]) {
            case 'a': {
                BUFFER[0] = ' ';
                value = atoi(BUFFER);
                strayNode = (Node*) malloc(sizeof(Node));

                if(hashTableLinker[value % SIZE] == NULL) {
                    strayNode->item = value;
                    strayNode->next = NULL;
                    hashTableLinker[value % SIZE] = strayNode;
                }
                else {
                    strayNode->item = value;
                    strayNode->next = hashTableLinker[value % SIZE];
                    hashTableLinker[value % SIZE] = strayNode;
                }
                break;
            }

            case 'p': { 

                for(int i = 0; i < SIZE; i++) {
                    Node* temp = hashTableLinker[i];

                    printf("KEY %2d:", i);
                    while(temp != NULL) {
                        printf(" %d", temp->item);
                        temp=temp->next;
                    }
                    printf("\n");
                }
                
            break;
            }

            case 'q': {
                exit(0);
            break;
            }

            default:
                continue;
        }
    }
}
