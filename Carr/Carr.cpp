#include <iostream>
#include <string>

using namespace std;

class Automobile {
private:
    string make;
    string model;
    string color;
    int manufactureYear;

public:
    Automobile(string mk = "Unknown", string mdl = "Model", string clr = "Color", int yr = 1990)
        : make(mk), model(mdl), color(clr), manufactureYear(yr) {}

    void updateMake(string mk) {
        make = mk;
    }

    string fetchMake() const {
        return make;
    }

    void updateModel(string mdl) {
        model = mdl;
    }

    string fetchModel() const {
        return model;
    }

    void updateColor(string clr) {
        color = clr;
    }

    string fetchColor() const {
        return color;
    }

    void updateYear(int yr) {
        manufactureYear = yr;
    }

    int fetchYear() const {
        return manufactureYear;
    }
};

class AutomobileDisplay {
private:
    const Automobile* automobile;

public:
    AutomobileDisplay(const Automobile* autoPtr) : automobile(autoPtr) {}

    void displayDetails() const {
        cout << "Make: " << automobile->fetchMake() << endl;
        cout << "Model: " << automobile->fetchModel() << endl;
        cout << "Color: " << automobile->fetchColor() << endl;
        cout << "Year: " << automobile->fetchYear() << endl << endl;
    }
};

class AutomobileConfigurator {
private:
    Automobile* automobile;

public:
    AutomobileConfigurator(Automobile* autoPtr) : automobile(autoPtr) {}

    void configure() {
        string mk, mdl, clr;
        int yr;

        cout << "Enter Make: ";
        getline(cin, mk);
        automobile->updateMake(mk);

        cout << "Enter Model: ";
        getline(cin, mdl);
        automobile->updateModel(mdl);

        cout << "Enter Color: ";
        getline(cin, clr);
        automobile->updateColor(clr);

        cout << "Enter Year: ";
        cin >> yr;
        cin.ignore();  // To consume the newline character left in the input stream
        automobile->updateYear(yr);
    }
};

int main() {
    Automobile myCar("Toyota", "Corolla", "Blue", 2020);

    AutomobileDisplay carDisplay(&myCar);
    carDisplay.displayDetails();

    AutomobileConfigurator carConfig(&myCar);
    carConfig.configure();

    carDisplay.displayDetails();

    return 0;
}
