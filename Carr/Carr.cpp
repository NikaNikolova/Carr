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

    // Setters with data validation
    void updateMake(const string& mk) {
        if (!mk.empty()) {
            make = mk;
        } else {
            cout << "Invalid make. The make must not be empty." << endl;
        }
    }

    void updateModel(const string& mdl) {
        if (!mdl.empty()) {
            model = mdl;
        } else {
            cout << "Invalid model. The model must not be empty." << endl;
        }
    }

    void updateColor(const string& clr) {
        if (!clr.empty()) {
            color = clr;
        } else {
            cout << "Invalid color. The color must not be empty." << endl;
        }
    }

    void updateYear(int yr) {
        if (yr > 1885) {  // Validating the year of manufacture (first car was made in 1886)
            manufactureYear = yr;
        } else {
            cout << "Invalid year. The year must be later than 1885." << endl;
        }
    }

    // Getters
    string fetchMake() const {
        return make;
    }

    string fetchModel() const {
        return model;
    }

    string fetchColor() const {
        return color;
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
        automobile->updateYear(yr);
        
        cin.ignore(); // Consuming the leftover newline character
    }
};

int main() {
    // Initialize the Automobile object with default parameters
    Automobile myCar("Toyota", "Corolla", "Blue", 2020);

    // Create a display object for the automobile
    AutomobileDisplay carDisplay(&myCar);
    carDisplay.displayDetails();

    // Create a configurator object for the automobile
    AutomobileConfigurator carConfig(&myCar);
    carConfig.configure();

    // Display the updated automobile details
    carDisplay.displayDetails();

    return 0;
}