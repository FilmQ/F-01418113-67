#include <iostream>
#include <vector>

using namespace std;

class Material {
private:
    string name;
    int quality;
    vector<string> compatibleTypes;

public:
    Material(string name, int quality);
    string getName();
    int getQuality();
    void addCompatibleType(string type);
    bool isCompatibleWith(string weaponType);
    int getUpgradeValue();
};

int main() 
{
    Material Iron("Iron", 3);
    std::cout << Iron.getName() << " " << Iron.getQuality();
}

Material::Material(std::string name, int quality) 
{
    this->name = name;

    if(quality > 5)      { this->quality = 5; }
    else if(quality < 1) { this->quality = 1; }
    else                 { this->quality = quality; }
}

std::string Material::getName()
{
    return this->name;
}

int Material::getQuality() 
{
    return this->quality;
}

void Material::addCompatibleType(std::string type)
{
    this->compatibleTypes.push_back(type);
}

bool Material::isCompatibleWith(std::string weaponType) 
{
    for(std::string compatibleWith : compatibleTypes) {
        if(compatibleWith == weaponType)
            return true;
    }
    return false;
}

int Material::getUpgradeValue()
{
    return 5 * this->quality;
}