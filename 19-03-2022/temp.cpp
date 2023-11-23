#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int left = 1, right = N;
    int maxPos = 1; // Assume the maximum element is initially at the first position

    while (left < right) {
        int mid = (left + right) / 2;

        cout << "? " << maxPos << " " << mid << endl;
        string response;
        cin >> response;

        if (response == "First") {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    cout << "! " << left << endl;

    return 0;
}
