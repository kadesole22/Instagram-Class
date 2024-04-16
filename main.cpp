#include "instagram.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    instagram<std::string> myInstagram;
    std::ifstream inputFile("presidentsWstates.txt");

    if(!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return -1;
    }
    string president;
    while (getline(inputFile, president)) {
        myInstagram.addFollower(president);
    }
    cout << "\nFollowers: \n";
    myInstagram.printFollowers();

    cout << "\nLatest Follower: \n" << myInstagram.latestFollower() << endl;

    cout << "\nRemoving Follower: \n" << myInstagram.removeFollower() << endl;

    cout << "\nRemaining Followers: \n";
    myInstagram.printFollowers();

    cout << "\nResetting Followers...\n" << endl;
    myInstagram.resetFollowers();

    if (myInstagram.checklist()) {
        cout << "\nFollower list is empty.\n" << endl;
    } else {
        cout << "\nFollower list is not empty.\n" << endl;
    }

    return 0;
}

