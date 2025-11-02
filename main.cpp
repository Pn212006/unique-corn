#include <iostream>
#include <string>
#include <set>
#include <stdexcept>
using namespace std;

class Unicorn {
private:
    string name;
    static set<string> takenNames;

public:
    Unicorn(const string& unicornName) {
        if (takenNames.count(unicornName)) {
            throw runtime_error("A unicorn with the name '" + unicornName + "' already exists!");
        }
        name = unicornName;
        takenNames.insert(unicornName);
        cout << "Unicorn " << name << " has been created." << endl;
    }

    ~Unicorn() {
        cout << "Unicorn " << name << " has vanished." << endl;
        takenNames.erase(name);
    }

    string getName() const {
        return name;
    }
};

set<string> Unicorn::takenNames;

int main() {
    try {
        Unicorn u1("Sparkle");
        Unicorn u2("Twinkle");
        Unicorn u3("Sparkle");
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nCreating a new Unicorn named Sparkle again..." << endl;
    Unicorn u4("Sparkle");

    return 0;
}
