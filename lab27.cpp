#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

//
void print(const string n, const tuple<int,string, string> d){
    int friendship = get<0>(d);
    string species = get<1>(d);
    string catchphrase = get<2>(d);
    cout << n << ": " << endl;
    cout << "\tF"
}

int main() {
    // declarations
    // change the data stored to be a tuple instead of a vector, (int(friendship) string(species) string(catchphrase))
    map<string, tuple<int,string,string>> villagers;

    //insert three elements into the map
    villagers["Audie"] = {10, "Human", "Zoo Wee Mama"}; // i j remembered this is friendship level 1-10 and not favorite number oops, let me change that
    villagers["Raymond"] = {7, "Beast", "Believe it!"};
    villagers.insert({"Marshal", {1, "Dwarf", "Ay caramba"}});

    // access the map using a range-based for loop
    cout << "Villagers and their data (range-based for loop):" << endl;
    for (auto pair : villagers) {
        // imma need to make a function to call to print these
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}