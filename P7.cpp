#include <iostream>
#include <string>
#include <limits>
using namespace std;
class Player {
private:
    string playerName;
    int age;
    char ch;
    int matchplayed;
    int runsScored;      
    float batavg;        
    int notouts;         
    int halfCenturies;   
    int centuries;       
    int wickets;         
    int fifertaken;      
    float bowlavg;       
    int over;
public:
    Player() {}
    Player(string name, int playerAge, char choice)
        : playerName(name), age(playerAge), ch(choice) {
        matchplayed = 0;
        runsScored = 0;
        batavg = 0.0;
        notouts = 0;
        halfCenturies = 0;
        centuries = 0;
        wickets = 0;
        fifertaken = 0;
        bowlavg = 0.0;
    }
    void inputData() {
        cout << "Enter match played: ";
        cin >> matchplayed;
        if (ch == 'b' || ch == 'B') { 
            cout << "Enter runs scored: ";
            cin >> runsScored;
            cout << "Enter not outs: ";
            cin >> notouts;
            cout << "Enter half centuries: ";
            cin >> halfCenturies;
            cout << "Enter centuries: ";
            cin >> centuries;
        } else if (ch == 'w' || ch == 'W') { 
            cout << "Enter wickets taken: ";
            cin >> wickets;
            cout << "Overs Bowled: ";
            cin >> over;
            cout << "Enter five-wicket hauls: ";
            cin >> fifertaken;
        }
    }
    void displayData() {
        cout << "Player Name:" << playerName << endl;
        cout << "Age: " << age << endl;
        cout << "Choice: " << ch << endl;
        cout << "Matches Played: " << matchplayed << endl;
        if (ch == 'b' || ch == 'B') { 
            cout << "Runs Scored: " << runsScored << endl;
            batavg = (float)runsScored / (matchplayed - notouts);
            cout << "Batting Average: " << batavg << endl;
            cout << "Not Outs: " << notouts << endl;
            cout << "Half Centuries: " << halfCenturies << endl;
            cout << "Centuries: " << centuries << endl;
        } else if (ch == 'w' || ch == 'W') {
            cout << "Wickets Taken: " << wickets << endl;
            cout << "Five-Wicket Hauls: " << fifertaken << endl;
            bowlavg = (float)over * 6 / (wickets);
            cout << "Bowling Average: " << bowlavg << endl;
        }
        cout << "----------------------" << endl;
    }
    void searchByName(string searchName) {
        if (playerName == searchName) {
            cout << "Player found:\n";
            displayData();
        }
    }
};
int main() {
    int choice;
    Player players[5];
    do {
        cout << "Choose an option:\n";
        cout << "1. Insert Player Data\n";
        cout << "2. Display Player Data\n";
        cout << "3. Search Player by Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                for (int i = 0; i < 5; ++i){
                    string name;
                    int age;
                    char playerChoice;
                    cout << "Enter player name for Player " << i + 1 << ": ";
                    cin.ignore(); 
                    getline(cin, name);
                    cout << "Enter player age: ";
                    cin >> age;
                    cout << "Enter choice (b/B for batsman, w/Wfor bowler): ";
                    cin >> playerChoice;

                    players[i] = Player(name, age, playerChoice);
                    players[i].inputData();
                }
                break;
            case 2:
                for (int i = 0; i < 5; ++i) {
                    cout << "Player " << i + 1 << ":\n";
                    players[i].displayData();}
                break;
            case 3:{
                    string searchName;
                    cout << "Enter the name to search: ";
                    cin.ignore();
                    getline(cin, searchName);
                    for (int i = 0; i < 5; ++i) {
                        players[i].searchByName(searchName);
                    }
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);
    return 0;
}
