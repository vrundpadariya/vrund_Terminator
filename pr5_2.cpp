#include <iostream>
using namespace std;

class Animal {
public:
    Animal(const string& animalType) : type(animalType) {}

    void showType() const {
        cout << "Type: " << type << endl;
    }

private:
    string type;
};

class Mammal : virtual public Animal {
public:
    Mammal(const string& animalType, const string& mammalType)
        : Animal(animalType), mammalType(mammalType) {}

    void showMammalType() const {
        cout << "Mammal Type: " << mammalType << endl;
    }

public:
    string mammalType;
};

class Bird : virtual public Animal {
public:
    Bird(const string& animalType, const string& birdType)
        : Animal(animalType), birdType(birdType) {}

    void showBirdType() const {
        cout << "Bird Type: " << birdType << endl;
    }

public:
    string birdType;
};

class Bat : public Mammal, public Bird {
public:
    Bat(const string& animalType, const string& mammalType, const string& birdType)
        : Animal(animalType), Mammal(animalType, mammalType), Bird(animalType, birdType) {}

    void showBatType() const {
        cout << "Bat Type: Hybrid of " << Mammal::mammalType << " and " << Bird::birdType << endl;
    }
};

int main() {
    Bat bat("Animal", "Mammal", "Bird");

    cout << "Animal Information:\n";
    bat.showType();
    cout << endl;

    cout << "Mammal Information:\n";
    bat.showMammalType();
    cout << endl;

    cout << "Bird Information:\n";
    bat.showBirdType();
    cout << endl;

    cout << "Bat Information:\n";
    bat.showBatType();

    return 0;
}

