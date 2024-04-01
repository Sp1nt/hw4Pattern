#include <iostream>
#include <cstring>
using namespace std;


class Continent {
public:
    virtual void Print() = 0;
};

class Herbivore {
public:
    virtual void eatGrass() = 0;
};

class Carnivore {
public:
    virtual void eatHerb(Herbivore* herbivore) = 0;
};


class Africa : public Continent {
public:
    void Print() override {
        cout << "Continent: Africa" << endl;
    }
};

class NorthAmerica : public Continent {
public:
    void Print() override {
        cout << "Continent: North America" << endl;
    }
};

class Eurasia : public Continent {
public:
    void Print() override {
        cout << "Continent: Eurasia" << endl;
    }
};

class Wildebeest : public Herbivore {
public:
    void eatGrass() override {
        cout << "Wildebeest is eating grass. Weight increased by 10." << endl;
    }
};

class Bison : public Herbivore {
public:
    void eatGrass() override {
        cout << "Bison is eating grass. Weight increased by 10." << endl;
    }
};

class Elk : public Herbivore {
public:
    void eatGrass() override {
        cout << "Elk is eating grass. Weight increased by 10." << endl;
    }
};

class Lion : public Carnivore {
public:
    void eatHerb(Herbivore* herbivore) override {
        cout << "Lion is eating herbivore." << endl;
    }
};

class Wolf : public Carnivore {
public:
    void eatHerb(Herbivore* herbivore) override {
        cout << "Wolf is eating herbivore." << endl;
    }
};

class Tiger : public Carnivore {
public:
    void eatHerb(Herbivore* herbivore) override {
        cout << "Tiger is eating herbivore." << endl;
    }
};


class AnimalFactory {
public:
    virtual Continent* CreateContinent() = 0;
    virtual Herbivore* CreateHerbivore() = 0;
    virtual Carnivore* CreateCarnivore() = 0;
};


class AfricaFactory : public AnimalFactory {
public:
    Continent* CreateContinent() override {
        return new Africa();
    }

    Herbivore* CreateHerbivore() override {
        return new Wildebeest();
    }

    Carnivore* CreateCarnivore() override {
        return new Lion();
    }
};

class NorthAmericaFactory : public AnimalFactory {
public:
    Continent* CreateContinent() override {
        return new NorthAmerica();
    }

    Herbivore* CreateHerbivore() override {
        return new Bison();
    }

    Carnivore* CreateCarnivore() override {
        return new Wolf();
    }
};

class EurasiaFactory : public AnimalFactory {
public:
    Continent* CreateContinent() override {
        return new Eurasia();
    }

    Herbivore* CreateHerbivore() override {
        return new Elk();
    }

    Carnivore* CreateCarnivore() override {
        return new Tiger();
    }
};


class AnimalWorld {
private:
    Continent* continent;
    Herbivore* herbivore;
    Carnivore* carnivore;

public:
    AnimalWorld(AnimalFactory* factory) {
        continent = factory->CreateContinent();
        herbivore = factory->CreateHerbivore();
        carnivore = factory->CreateCarnivore();
    }

    void SimulateLife() {
        continent->Print();
        herbivore->eatGrass();
        carnivore->eatHerb(herbivore);
    }
};

int main() {

    cout << "Creating animal world for Africa:" << endl;
    AnimalFactory* africaFactory = new AfricaFactory();
    AnimalWorld* africaWorld = new AnimalWorld(africaFactory);
    africaWorld->SimulateLife();
    cout << endl;


    cout << "Creating animal world for North America:" << endl;
    AnimalFactory* northAmericaFactory = new NorthAmericaFactory();
    AnimalWorld* northAmericaWorld = new AnimalWorld(northAmericaFactory);
    northAmericaWorld->SimulateLife();
    cout << endl;


    cout << "Creating animal world for Eurasia:" << endl;
    AnimalFactory* eurasiaFactory = new EurasiaFactory();
    AnimalWorld* eurasiaWorld = new AnimalWorld(eurasiaFactory);
    eurasiaWorld->SimulateLife();
    cout << endl;

    return 0;
}
