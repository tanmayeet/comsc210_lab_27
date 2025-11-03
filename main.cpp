// COMSC210 | Lab 27 | Tanmayee Chalamalasetti
// IDE Used: VS Code

#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  // declarations
  map<string, tuple<int, string, string>> villagerData;

  // insert elements into the map
  // note how the right-hand side of the assignment are the vector elements

  // Each villager is stored as a tuple: (friendshipLevel, species, catchphrase)
  villagerData["Audie"] = make_tuple(7, "Wolf", "Snap to It!");
  villagerData["Drago"] = make_tuple(8, "Cat", "Nice fit!");
  villagerData["Raymond"] = make_tuple(10, "Alligator", "Hubba hubba!");

  int choice;
  string name;
  const int max_friendship = 10;
  const int min_friendship = 0;

  while (true) {
    cout << "Menu: \n";
    cout << "1. Add Villager \n";
    cout << "2. Delete Villager \n";
    cout << "3. Increase Friendship \n";
    cout << "4. Decrease Friendship \n";
    cout << "5. Search for villager \n";
    cout << "6. Exit \n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 6) {
      break;
    }

    cout << "Enter villager name: ";
    cin.ignore();
    getline(cin, name);

    auto it = villagerData.find(name);
    switch (choice) {
      case 1: {
        // Adds a villager
        int friendshipLevel;
        string species, catchphrase;
        cout << "Friendship level (0-10): ";
        cin >> friendshipLevel;
        while (friendshipLevel < min_friendship ||
               friendshipLevel > max_friendship) {
          cout << "Invalid. Please enter a value between 0 and 10.\n";
          cout << "Friendship level (0-10): ";
          cin >> friendshipLevel;
        }
        friendshipLevel =
            max(min_friendship, min(max_friendship, friendshipLevel));
        cin.ignore();
        cout << "Species: ";
        getline(cin, species);
        cout << "Catchphrase: ";
        getline(cin, catchphrase);
        villagerData[name] = make_tuple(friendshipLevel, species, catchphrase);
        cout << name << " added.\n";
        cout << endl;
        break;
      }
      case 2: {
        // Deletes a villager
        if (it != villagerData.end()) {
          villagerData.erase(name);
          cout << endl;
        } else {
          cout << name << " not found.\n";
          cout << endl;
        }
        break;
      }
      case 3: {
        // Increases friendship level of a villager
        if (it != villagerData.end()) {
          get<0>(it->second) = min(max_friendship, get<0>(it->second) + 1);
          cout << name << "'s friendship increased.\n";
          cout << endl;
        } else {
          cout << name << " not found.\n";
          cout << endl;
        }
        break;
      }

      case 4: {
        // Decreases friendship level of a villager
        if (it != villagerData.end()) {
          get<0>(it->second) = max(min_friendship, get<0>(it->second) - 1);
          cout << name << "'s friendship decreased.\n";
          cout << endl;
        } else {
          cout << name << " not found.\n";
          cout << endl;
        }
        break;
      }

      case 5: {
        // Allows user to search a villager and outputs villagers' details
        if (it != villagerData.end()) {
          cout << name << " [" << get<0>(it->second) << ", "
               << get<1>(it->second) << ", " << get<2>(it->second) << "]\n";
          cout << endl;
        } else {
          cout << name << " not found.\n";
          cout << endl;
        }
        break;
      }
      default:
        cout << "Invalid choice.\n";
    }

    // Print all villagers
    cout << "Villager details:\n";
    for (auto pair : villagerData) {
      cout << pair.first << " [" << get<0>(pair.second) << ", "
           << get<1>(pair.second) << ", " << get<2>(pair.second) << "]\n";
    }
    cout << endl;

    // report size, clear, report size again to confirm map operations
    // cout << "\nSize before clear: " << villagerData.size() << endl;
    // villagerData.clear();
    // cout << "Size after clear: " << villagerData.size() << endl;
  }
  return 0;
}