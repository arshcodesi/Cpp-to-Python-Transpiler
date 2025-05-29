#include <iostream>
using namespace std;

int main() {
    int start, end;

    // Ask user for input
    cout << "Enter the starting number: ";
    cin >> start;
    
    cout << "Enter the ending number: ";
    cin >> end;

    // Check if start is less than or equal to end
    if (start > end) {
        cout << "Starting number must be less than or equal to the ending number." << endl;
    } else {
        int count = start;

        // Loop from start to end
        while (count <= end) {
            cout << "Count is: " << count;

            // Check even or odd
            if (count % 2 == 0) {
                cout << " (even)";
            } else {
                cout << " (odd)";
            }

            cout << endl;
            count++;
        }

        cout << "Final count: " << count << endl;
    }

    return 0;
}
