#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    Date() {
        day = 1;
        month = 1;
        year = 1900;
    }

    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
};

class Address {
public:
    string country;
    string region;
    string city;
    string street;
    int houseNumber;
    char buildingSection;

    Address() {
        country = "Not specified";
        region = "Not specified";
        city = "Not specified";
        street = "Not specified";
        houseNumber = 0;
        buildingSection = 'A';
    }

    Address(string cn, string rg, string ct, string st, int hn, char bs) {
        country = cn;
        region = rg;
        city = ct;
        street = st;
        houseNumber = hn;
        buildingSection = bs;
    }
};

class PersonalDetails {
public:
    string firstName;
    string lastName;
    Date* birthDate;
    Address* homeAddress;

    PersonalDetails() {
        firstName = "";
        lastName = "";
        birthDate = new Date();
        homeAddress = new Address();
    }

    void setDetails(const string& fn, const string& ln, Date* bd, Address* ha) {
        firstName = fn;
        lastName = ln;
        birthDate = bd;
        homeAddress = ha;
    }

    virtual void displayDetails() const {
        cout << "Student Name: " << firstName << " " << lastName << endl;
        cout << "Birth Date: " << birthDate->day << "/" << birthDate->month << "/" << birthDate->year << endl;
        cout << "Address: " << homeAddress->street << ", " << homeAddress->city << ", " << homeAddress->country << endl;
    }
};

class EducationDetails {
public:
    Date startDate;
    int currentCourse;
    string groupName;
    string specialization;

    EducationDetails() {
        startDate = Date();
        currentCourse = 1;
        groupName = "None";
        specialization = "None";
    }

    void setEducationDetails(const Date& sd, int cc, const string& gn, const string& sp) {
        startDate = sd;
        currentCourse = cc;
        groupName = gn;
        specialization = sp;
    }

    void displayEducation() const {
        cout << "Start Date: " << startDate.day << "/" << startDate.month << "/" << startDate.year << endl;
        cout << "Course: " << currentCourse << endl;
        cout << "Group: " << groupName << endl;
        cout << "Specialization: " << specialization << endl;
    }
};

class Automobile {
private:
    string make;
    string model;
    string color;
    int manufactureYear;

public:
    Automobile() {
        make = "Unknown";
        model = "Model";
        color = "Color";
        manufactureYear = 1990;
    }

    Automobile(string mk, string mdl, string clr, int yr) {
        make = mk;
        model = mdl;
        color = clr;
        manufactureYear = yr;
    }

    bool updateMake(const string& mk) {
        if (!mk.empty()) {
            make = mk;
            return true;
        } else {
            cerr << "Invalid make. The make must not be empty." << endl;
            return false;
        }
    }

    bool updateModel(const string& mdl) {
        if (!mdl.empty()) {
            model = mdl;
            return true;
        } else {
            cerr << "Invalid model. The model must not be empty." << endl;
            return false;
        }
    }

    bool updateColor(const string& clr) {
        if (!clr.empty()) {
            color = clr;
            return true;
        } else {
            cerr << "Invalid color. The color must not be empty." << endl;
            return false;
        }
    }

    bool updateYear(int yr) {
        if (yr > 1885) {
            manufactureYear = yr;
            return true;
        } else {
            cerr << "Invalid year. The year must be later than 1885." << endl;
            return false;
        }
    }

    string fetchMake() const { return make; }
    string fetchModel() const { return model; }
    string fetchColor() const { return color; }
    int fetchYear() const { return manufactureYear; }
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
        if (!automobile->updateMake(mk)) {
            cout << "Using default make." << endl;
        }

        cout << "Enter Model: ";
        getline(cin, mdl);
        if (!automobile->updateModel(mdl)) {
            cout << "Using default model." << endl;
        }

        cout << "Enter Color: ";
        getline(cin, clr);
        if (!automobile->updateColor(clr)) {
            cout << "Using default color." << endl;
        }

        cout << "Enter Year: ";
        if (!(cin >> yr) || !automobile->updateYear(yr)) {
            cout << "Using default year." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

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
