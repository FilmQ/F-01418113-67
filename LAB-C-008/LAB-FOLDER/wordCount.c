#include <stdio.h>
#include <string.h>

struct Word {
    int count;
    char word[20];
};

int main() {
        char input[21];
        int i, last_word = 0, find = 0;
        struct Word data[20] = {0};
        scanf("%20s", input);

        while(strcmp(input, "exit") != 0) {
            find = 0;

            if(last_word == 0) {
                strcpy(data[0].word, input);
                last_word++;
            }

            if(strcmp(input, "exit") == 0)
                break;
            else {
                for(i = 0; i < last_word; i++) {
                    if(strcmp(data[i].word, input) == 0) {
                        data[i].count++;
                        find = 1;
                    }
                }
                if(find == 0) {
                    strcpy(data[last_word].word, input);
                    ++data[last_word].count;
                    ++last_word;
                }
            }

            scanf("%20s", input);

        }

        printf("Output:\n");
        for(i=0; i<last_word; i++){
                printf("%s = %d\n", data[i].word, data[i].count);
        }
}
