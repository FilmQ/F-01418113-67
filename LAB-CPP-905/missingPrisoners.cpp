#include <iostream>
#include <algorithm>
#include <vector>

void findMissingPrisoners()
{
    int num_prisoners = 0, n_prisonerTag = 0;
    std::vector<int> prisonerContainer;
    std::cin >> num_prisoners;

    for(int i = 0; i < num_prisoners; i++) {
        std::cin >> n_prisonerTag;
        prisonerContainer.push_back(n_prisonerTag);
        //std::cout << i << " " << num_prisoners << std::endl;
    }

    std::sort(prisonerContainer.begin(), prisonerContainer.end());

    std::vector<int> missingPrisonerOdd;
    std::vector<int> missingPrisonerEven;
    
    for(int i = 0, j = 0, k = 1; i < prisonerContainer.back(); i++, k++) {
        if(prisonerContainer[j] != k && i % 2 == 0) {
            missingPrisonerOdd.push_back(k);
        }
        else if(prisonerContainer[j] != k && i % 2) {
            missingPrisonerEven.push_back(k);
        }
        else {
            j++;
        }

    }

    // print the results
    for(int i = 0; i < missingPrisonerOdd.size(); i++)
        std::cout << missingPrisonerOdd[i] << " ";

    std::cout << "\n";

    for(int i = 0; i < missingPrisonerEven.size(); i++)
        std::cout << missingPrisonerEven[i] << " ";

}

int main()
{
    findMissingPrisoners();
}