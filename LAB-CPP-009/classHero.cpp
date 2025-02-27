#include <iostream>
#include <string>
using namespace std;

class Hero
{
    private:
        std::string name;
        unsigned int level;

    public:
        Hero(std::string initName, unsigned int initLevel) {
            name = initName;
            level = initLevel;
        }

        std::string getName() {
            return this->name;
        }

        int getLevel() {
            return this->level;
        }
};

int main() 
{
    Hero A("Bruj", 123);
    std::cout << A.getName() << " " << A.getLevel();
}