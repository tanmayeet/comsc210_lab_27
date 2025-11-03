// COMSC210 | Lab 27 | Tanmayee Chalamalasetti
// IDE Used: VS Code

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  // declarations
  map<string, tuple<int, string, string>> villagerData;

  // insert elements into the map
  // note how the right-hand side of the assignment are the vector elements
  villagerData["Audie"] = make_tuple(7, "Wolf", "Snap to It!");
  villagerData["Raymond"] = make_tuple(10, "Alligator", "Hubba hubba!");
  villagerData["Drago"] = make_tuple(8, "Cat", "Nice fit!");

  int choice;
  string name;

  while (true) {
    cout << "Menu: \n";
    cout << "1. Increase Friendship \n";
    cout << "2. Decrease Friendship \n";
    cout << "3. Search for villager \n";
    cout << "4. Exit \n";
    cout << "Enter choice: \n";
    cin >> choice;

    if (choice == 4) {
      break;
    }

    cout << "Enter villager name: ";
    cin.ignore();
    getline(cin, name);

    auto it = villagerData.find(name);

    switch (choice) {
      case 1: {
        // access the map using a range-based for loop
        if (it != villagerData.end()) {
          get<0>(it->second) = min(10, get<0>(it->second) + 1);
          cout << name << "'s friendship increased.\n";
        } else {
          cout << name << " not found.\n";
        }
        break;
      }

      case 2: {
        // access the map using a range-based for loop
        if (it != villagerData.end()) {
          get<0>(it->second) = min(10, get<0>(it->second) - 1);
          cout << name << "'s friendship decreased.\n";
        } else {
          cout << name << " not found.\n";
        }
        break;
      }

      case 3: {
        // access the map using a range-based for loop
        if (it != villagerData.end()) {
          cout << name << " [" << get<0>(it->second) << ", "
               << get<1>(it->second) << ", " << get<2>(it->second) << "]\n";
        } else {
          cout << name << " not found.\n";
        }
        break;
      }
    }
    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;
  }
  return 0;
}