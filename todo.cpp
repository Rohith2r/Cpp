#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> pullFile(string fileName) {
    vector<string> tasks;
    ifstream file(fileName);
    string task;
    while (getline(file, task)) {
        tasks.push_back(task);
    }
    return tasks;
}

void pushFile(vector<string> totalList, string fileName) {
    ofstream file(fileName);
    for (const string& task : totalList) {
        file << task << endl;
    }
}

bool ifExists(string fileName) {
    ifstream file(fileName);
    return file.good();
}

void printList(const vector<string>& totalList, const string& fileName) {
    cout << "Tasks in " << fileName << ":\n";
    for (size_t i = 0; i < totalList.size(); ++i) {
        cout << i + 1 << ". " << totalList[i] << endl;
    }
}

int main() {
    string fileName;
    vector<string> totalList;

    cout << "Enter the name of your to-do list: ";
    cin >> fileName;
    fileName += ".txt";

    if (ifExists(fileName)) {
        totalList = pullFile(fileName);
    }

    bool cont = true;
    while (cont) {
        printList(totalList, fileName);
        cout << "\nWhat would you like to do?\n";
        cout << "1. Add item\n";
        cout << "2. Remove item\n";
        cout << "3. Quit\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string newItem;
                cout << "Enter new item: ";
                cin >> newItem;
                totalList.push_back(newItem);
                break;
            }
            case 2: {
                int itemNumber;
                cout << "Enter item number to delete: ";
                cin >> itemNumber;
                if (itemNumber >= 1 && itemNumber <= totalList.size()) {
                    totalList.erase(totalList.begin() + (itemNumber - 1));
                } else {
                    cout << "Invalid item number.\n";
                }
                break;
            }
            case 3:
                cont = false;
                pushFile(totalList, fileName);
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
