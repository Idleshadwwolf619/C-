#include <iostream>
#include <thread>

using namespace std;

bool raceInProgress = true; // Flag to track if the race is in progress

// Function to simulate a horse race
void HorseRace(const string& horseName) {
    cout << horseName << " (Thread ID: " << this_thread::get_id() << ") is ready!" << endl;

    // Wait for other horses to start
    this_thread::sleep_for(chrono::seconds(1));

    // Display passing event
    if (horseName == "Horse 1") {
        cout << horseName << " is passing Horse 2! "  << endl;
    }
    else if (horseName == "Horse 2") {
        cout << horseName << " is being passed by Horse 1! " << endl;
    }
    else if (horseName == "Horse 3") {
        cout << horseName << " is jumping over an obstacle! " << endl;
    }

    // Wait for other horses to finish
    this_thread::sleep_for(chrono::seconds(2));

    cout << horseName << " (Thread ID: " << this_thread::get_id() << ") has finished the race." << endl;

    // Check if all horses have finished
    static atomic<int> finishedHorses(0);
    if (++finishedHorses == 3) {
        raceInProgress = false;
    }
}

int main() {
    cout << "Race started with 3 horses!" << endl;

    thread horse1(HorseRace, "Horse 1");
    thread horse2(HorseRace, "Horse 2");
    thread horse3(HorseRace, "Horse 3");

    // Wait for all horse threads to finish
    horse1.join();
    horse2.join();
    horse3.join();

    cout << endl;
    cout << "Horse 2 wins the race!" << endl;
    cout << "Race finished!" << endl;

    return 0;
}