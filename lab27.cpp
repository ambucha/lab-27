#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

// print() function to display the tuple data 
// arguments: string and tuple data of villager
// returns: nothing
void print(const string n, const tuple<int,string, string> d){
    int friendship = get<0>(d);
    string species = get<1>(d);
    string catchphrase = get<2>(d);
    cout << n << ": " << endl;
    cout << "\tFriendship Level: " << friendship << endl;
    cout << "\tSpecies: " << species << endl;
    cout << "\tCatchphrase: " << catchphrase << endl << endl;
}

// menu(): outputs the menu
// arguments: nothign
// returns nothing
void menu(){
    cout << "1. Increase Friendship" << endl;
    cout << "2. Decrease Friendship" << endl;
    cout << "3. Search for Villager" << endl;
    cout << "4. Exit" << endl;
} 

// friendship(): changes the friendship level of chosen villager
// arguments: villager data, string for the name to search for, integer for wether or not to increase or decrease the friendship level
void friendship(map<string, tuple<int,string,string>> villagers, const string n, int x){
    auto it = villagers.find(n);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        // get the friendship level 
        int fLevel = get<0>(it->second);
        // add the either positive or negative 1 to the friend level
        fLevel += x;
        // check if f is now at one of the extremes, to keep it going too high or low
        if (fLevel < 0){
            fLevel = 0;
        }
        if (fLevel > 10){
            fLevel = 10;
        }
    } else
        cout << endl << n << " not found." << endl;
}

int main() {
    // declarations
    // change the data stored to be a tuple instead of a vector, (int(friendship) string(species) string(catchphrase))
    map<string, tuple<int,string,string>> villagers;

    //insert three elements into the map
    villagers["Audie"] = {10, "Human", "Zoo Wee Mama"}; // i j remembered this is friendship level 1-10 and not favorite number oops, let me change that
    villagers["Raymond"] = {7, "Beast", "Believe it!"};
    villagers.insert({"Marshal", {1, "Dwarf", "Ay caramba"}});

    // imma make a menu function to output it, create an int for choice
    int choice;
    menu();
    cin >> choice;
    while(choice != 4){
        if(choice > 4 || choice < 0){
            cout << "Invalid choice try again: " << endl;
            cin >> choice;
        }
        if(choice == 1){
            // are we meant to increase and decrease the level of everyones friendship or a chosen villager?
            // im going to go with the chosen villager option
            cout << "Villager to increase frienship:" << endl;
            // imma need to make a function to change the friendship levels
        }
    }

    // access the map using a range-based for loop
    cout << "Villagers and their data (range-based for loop):" << endl;
    for (auto pair : villagers) {
        // imma need to make a function to call to print these
        print(pair.first, pair.second);
    }

    // access the map using iterators
    cout << "\nVillagers and their data (iterators):" << endl;
    // change it to tuple instead of vector
    for (map<string, tuple<int,string,string>>::iterator it = villagers.begin(); 
                                               it != villagers.end(); ++it) {
        cout << it->first << ": ";
        // use the print function created earlier but now using iterators
        print(it->first,it->second);
        cout << endl;
    }

    // delete an element, should be the same just change the name
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s data: ";
        // use print function again
        print(it->first, it->second);
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}