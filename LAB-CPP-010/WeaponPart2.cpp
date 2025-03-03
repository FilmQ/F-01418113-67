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

class Weapon {
    private:
        int durability;
        int damage;
        string weaponType;

    public:
        Weapon(int durability, int damage, string weaponType);
        int getDurability();
        int getDamage();
        string getWeaponType();
        int attack();
        bool upgrade(Material material);
        void repair();
        void showStatus();
};

int main() 
{
    // insert test cases here
}

// BEGIN MATERIAL_IMPLEMENTATION:
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
// END MATERIAL_IMPLEMENTATION.

// BEGIN WEAPON_IMPLEMENTATION:

Weapon::Weapon(int durability, int damage, std::string weaponType) {

    if       (durability <   0)  { this->durability =   0;        }
    else if  (durability > 100)  { this->durability = 100;        }
    else                         { this->durability = durability; }

    if       (damage < 0) { this->damage = 0; }
    else                  { this->damage = damage; }

    this->weaponType = weaponType;
}

int Weapon::getDurability() 
{
    return durability;
}

int Weapon::getDamage()
{
    return damage;
}

std::string Weapon::getWeaponType() 
{
    return weaponType;
}

int Weapon::attack()
{
    int lowerLimit = durability - 2;

    if(durability <= 0)
        return 0;

    else if(lowerLimit < 0) 
        durability = 0;

    else
        durability -= 2;

    return damage; 
}

bool Weapon::upgrade(Material material)
{
    if(material.isCompatibleWith(weaponType)) {
        damage += material.getUpgradeValue();
        return 1;
    }
    else {
        return 0;
    }
}

void Weapon::repair()
{
    durability = 100;
}

void Weapon::showStatus()
{
    std::cout << this->durability << " " << this->damage << " " << this->weaponType << std::endl;
}

// END WEAPON_IMPLEMENTATION.