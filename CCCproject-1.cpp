#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> backStack, forwardStack;
    string current = "Home", url;
    int choice;

    cout << "        SIMPLE BROWSER NAVIGATION\n";
    cout << "Navigate through pages using Back & Forward.\n";
    cin.ignore();

    while (true) {
        cout << "\n-----------------------------------------\n";
        cout << "Current Page: " << current << "\n";
        cout << "-----------------------------------------\n";
        cout << "1) Open a New Page\n";
        cout << "2) Back\n";
        cout << "3) Forward\n";
        cout << "4) Show History Count\n";
        cout << "5) Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter numbers only.\n";
            continue;
        }

        cin.ignore();

        if (choice == 1) {
            backStack.push(current);
            cout << "Enter URL: ";
            getline(cin, url);
            current = url;
            while (!forwardStack.empty()) forwardStack.pop();
        }
        else if (choice == 2) {
            if (!backStack.empty()) {
                forwardStack.push(current);
                current = backStack.top();
                backStack.pop();
            } else {
                cout << "No pages to go back.\n";
            }
        }
        else if (choice == 3) {
            if (!forwardStack.empty()) {
                backStack.push(current);
                current = forwardStack.top();
                forwardStack.pop();
            } else {
                cout << "No pages to go forward.\n";
            }
        }
        else if (choice == 4) {
            cout << "Back Stack Size : " << backStack.size() << "\n";
            cout << "Forward Stack Size : " << forwardStack.size() << "\n";
        }
        else if (choice == 5) {
            cout << "\nClosing Browser...\n";
            break;
        }
        else {
            cout << "Invalid Entry! Please try again.\n";
        }
    }

    return 0;
}

