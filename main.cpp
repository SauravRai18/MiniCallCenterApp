#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Call {
public:
    int id;
    string name;
    string issue;
    bool resolved;

    Call(int i, string n, string is) {
        id = i;
        name = n;
        issue = is;
        resolved = false;
    }
};

class CallCenter {
    vector<Call> calls;
    int counter = 1;

public:
    void addCall() {
        string name, issue;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Issue: ";
        getline(cin, issue);

        calls.push_back(Call(counter++, name, issue));
        cout << "Call added successfully!\n";
    }

    void showCalls() {
        if (calls.empty()) {
            cout << "No calls available.\n";
            return;
        }

        for (auto &c : calls) {
            cout << "\nID: " << c.id
                 << " | Name: " << c.name
                 << " | Issue: " << c.issue
                 << " | Status: " << (c.resolved ? "Resolved" : "Pending");
        }
        cout << "\n";
    }

    void resolveCall() {
        int id;

        cout << "Enter Call ID to resolve: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            return;
        }

        for (auto &c : calls) {
            if (c.id == id) {
                c.resolved = true;
                cout << "Marked as resolved!\n";
                return;
            }
        }

        cout << "Call not found!\n";
    }
};

int main() {
    CallCenter cc;
    int choice;

    while (true) {
        cout << "\n--- Call Center Menu ---\n";
        cout << "1. Add Call\n2. Show Calls\n3. Resolve Call\n4. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice!\n";
            continue;
        }

        switch (choice) {
            case 1: cc.addCall(); break;
            case 2: cc.showCalls(); break;
            case 3: cc.resolveCall(); break;
            case 4: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}