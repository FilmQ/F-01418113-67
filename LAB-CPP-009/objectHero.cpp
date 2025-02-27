#include <iostream>
#include <string>


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
    std::string heroName;
    unsigned int heroLevel;

    std::cin >> heroName >> heroLevel;
    Hero* heroObject = new Hero(heroName, heroLevel);

    std::cout << heroObject->getName() << " " << heroObject->getLevel();
    delete heroObject;
}