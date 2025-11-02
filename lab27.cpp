#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

// print() function to display the tuple data 
// arguments: string and tuple data of villager
// returns: nothing
void print(const string n, const tuple<int,string, string> d){
    int friendship = get<0>(d);
    string species = get<1>(d);
    string catchphrase = get<2>(d);
    // imma change the output to look like the sample, it just takes up too much space atm
    cout << n << ": " << "[" << friendship << ", " << species << ", " << catchphrase << "]" << endl;
}

// menu(): outputs the menu
// arguments: nothign
// returns nothing
void menu(){
    cout << endl;
    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
} 

// friendship(): changes the friendship level of chosen villager
// arguments: villager data, string for the name to search for, integer for wether or not to increase or decrease the friendship level
// returns nothing
// hold up im not changing anything i need to make this pass by reference
void friendship(map<string, tuple<int,string,string>>& villagers, const string n, int x){
    auto it = villagers.find(n);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        // get the friendship level 
        int& fLevel = get<0>(it->second);
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

// printAll(): print all the villagers
// arguments: map
// returns nothing
void printAll(const map<string, tuple<int,string,string>>& v) {
    cout << "Villager details: " << endl;
    for(auto i : v){
        print(i.first, i.second);
    }
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
    int choice = 0;
    string name;

    // my menu was running once then going infinite
    while(choice != 6){

        // put menu and chocie inside
        menu();
        cin >> choice;

        if(choice > 6 || choice < 0){
            cout << "Invalid choice try again: " << endl;
            cin >> choice;
        }
        if(choice == 1){
            // variables for new villager data
            string newN;
            int newF;
            string newS;
            string newC;      

            // prompt for the new data
            cout << "Villager name: ";
            cin >> newN;
            cout << "Friendship level: ";
            cin >> newF;
            cout << "Species: ";
            cin >> newS;
            cout << "Catchphrase: ";
            getline(cin, newC);

            // create new villager with given data
            villagers[newN] = {newF,newS,newC};
            cout << newN << " added." << endl;

            // display all villagers
            printAll(villagers);
        }
        else if(choice == 2){
            string eliminated;
            cout << "Villager to delete: ";
            cin >> eliminated;

            // erase given villager
            villagers.erase(eliminated);

            printAll(villagers);
        }
        else if(choice == 3){
            // are we meant to increase and decrease the level of everyones friendship or a chosen villager?
            // im going to go with the chosen villager option
            cout << "Villager to increase frienship:" << endl;
            cin >> name;
            // imma need to make a function to change the friendship levels
            friendship(villagers, name, 1);
            // imma need to make a print all function
            printAll(villagers);
        }
        else if(choice == 4){
            cout << "Villager to decrease frienship:" << endl;
            cin >> name;
            friendship(villagers, name, -1);
            printAll(villagers);
        }
        else if(choice == 5){
            cout << "Villager to search: ";
            cin >> name;
            auto it = villagers.find(name);
            if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
                cout << "\nFound " << name << "'s data: ";
                // use print function again
                print(it->first, it->second);
            } else
            cout << endl << name << " not found." << endl;
            printAll(villagers);
        }
    }

    return 0;
}