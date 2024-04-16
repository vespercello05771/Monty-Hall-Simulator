#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime> 
using namespace std;

int debug = 0;
// Function to simulate the Monty Hall problem 
// Function returns two boolean values, first one is whether the user won by sticking and second is if user won by switching
vector<bool> simulateMontyHall(int num_doors, int num_doors_opened_by_host) {
    // Place the prize behind a random door
    int prize_door = 1 + rand() % num_doors;
    if(debug)
        cout << "prize door:" << prize_door <<endl;

    // Contestant makes an initial choice
    int initial_choice = 1 + rand() % num_doors;

    if(debug)
        cout << "intial choice: " << initial_choice << endl;    

    if(prize_door == initial_choice) return {true, false};

    // Host opens doors that don't have the prize and weren't chosen by the contestant
    vector<int> doors(num_doors);
    for (int i = 0; i < num_doors; i++)
        doors[i] = i + 1;

    doors.erase(remove(doors.begin(), doors.end(), prize_door), doors.end());
    doors.erase(remove(doors.begin(), doors.end(), initial_choice), doors.end());
    shuffle(doors.begin(), doors.end(), mt19937(time(NULL)));
    if(debug){
        cout<<"shuffle:"<<endl;
        for(int door: doors)
            cout<<door<<" ";
        cout<<endl;
    }
    vector<int> doors_opened_by_host;
    for (int i = 0; i < min(num_doors_opened_by_host, num_doors - 2); i++)
    {
        doors_opened_by_host.push_back(doors[i]);
    }
    

    // Contestant chooses whether to switch or stick
    int switched_choice = initial_choice;
    if (num_doors_opened_by_host < num_doors - 1) {
        vector<int> available_doors(num_doors);
        for(int i =0;i<num_doors;i++)
            available_doors[i] = i+1;

        available_doors.erase(remove(available_doors.begin(), available_doors.end(), initial_choice), available_doors.end());
        for (int door : doors_opened_by_host) {
            available_doors.erase(remove(available_doors.begin(), available_doors.end(), door), available_doors.end());
        }
        int rand_idx = rand() % available_doors.size();
        switched_choice = available_doors[rand_idx]; // since all of them have equal chance of picking
        if(debug){
            cout<<"available doors:"<<endl;
            for(int door: available_doors)
                cout<<door<<" ";
            cout<<endl;
        }
    }
    
    if(debug)
        cout<<"switched_choice:"<<switched_choice<<endl;
    // Determine if the contestant wins
    bool win_stick = initial_choice == prize_door;
    bool win_switch = switched_choice == prize_door;

    return {win_stick, win_switch};
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <num_doors> <num_doors_opened_by_host> <num_simulations>\n";
        return 1;
    }
    
    // Parse command-line arguments
    int num_doors = stoi(argv[1]);
    int num_doors_opened_by_host = stoi(argv[2]);
    int num_simulations = stoi(argv[3]);
    
    int wins_stick = 0;
    int wins_switch = 0;
    
    srand((unsigned) time(NULL));
    for (int i = 0; i < num_simulations; i++) {
        vector<bool> win_stick_switch = simulateMontyHall(num_doors, num_doors_opened_by_host);
        bool win_stick = win_stick_switch[0];
        bool win_switch = win_stick_switch[1];
        if (win_stick) 
            wins_stick++;
        if (win_switch) 
            wins_switch++;
    }
    
    double win_percentage_stick = (static_cast<double>(wins_stick) / num_simulations) * 100;
    double win_percentage_switch = (static_cast<double>(wins_switch) / num_simulations) * 100;
    
    cout << "win percentage for sticking with initial choice: " << win_percentage_stick << "%\n";
    cout << "win percentage for switching doors: " << win_percentage_switch << "%\n";
    
    return 0;
}