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
  villagerData["Raymond"] = make_tuple(7, "Wolf", "Hubba hubba!");
  //   villagerData.insert({"Marshal", {"Blue", "White", "Black"}});

  // access the map using a range-based for loop
  cout << "Villager details (range based for loop):" << endl;
  for (auto pair : villagerData) {
    cout << pair.first << " [" << get<0>(pair.second) << ", "
         << get<1>(pair.second) << ", " << get<2>(pair.second) << "]\n";
    cout << endl;
  }

  // access the map using iterators
  cout << "\nVillager details (iterators):" << endl;
  for (map<string, tuple<int, string, string>>::iterator it =
           villagerData.begin();
       it != villagerData.end(); ++it) {
    cout << it->first << " [" << get<0>(it->second) << ", "
         << get<1>(it->second) << ", " << get<2>(it->second) << "]\n"
         << endl;
  }
  // delete an element
  villagerData.erase("Raymond");

  // search for an element using .find() to avoid errors
  string searchKey = "Audie";
  auto it = villagerData.find(searchKey);
  if (it != villagerData.end()) {  // the iterator points to beyond the end of
                                   // the map if searchKey is not found
    cout << "\nFound " << searchKey << "[" << it->first << " ["
         << get<0>(it->second) << ", " << get<1>(it->second) << ", "
         << get<2>(it->second) << "]\n"
         << endl;
  } else
    cout << endl << searchKey << " not found." << endl;

  // report size, clear, report size again to confirm map operations
  cout << "\nSize before clear: " << villagerData.size() << endl;
  villagerData.clear();
  cout << "Size after clear: " << villagerData.size() << endl;

  return 0;
}