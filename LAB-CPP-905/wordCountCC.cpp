#include <iostream>
#include <string>

typedef struct Word_ {
    std::string uniqueWord;
    int wordCount;
} Word;

int main()
{
    std::string input;
    int i, last_word = 0, find = 0;
    Word data[20];

    while(true) {
        std::cin >> input;
        if(input == "exit")
            break;

        for(int i = 0; i < 20; i++) {
            if(data[i].uniqueWord == input && i < last_word) {
                data[i].wordCount++;
                break;
            }
            else if(i == last_word){
                data[last_word].uniqueWord = input;
                data[last_word].wordCount = 1;
                last_word++;
                break;
            }
            else {
                continue;
            }
        }
    }

    std::cout << "Output:\n";

    for(int i = 0; i < last_word; i++) 
        std::cout << data[i].uniqueWord << " = " << data[i].wordCount << std::endl;
}