#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int _main() {
    return 0;
}

void processLine(const string& line) {
    cout << line << endl;
}

int __main() {
    int n;
    cin >> n;
    string line;
    while (cin >> line) {
        processLine(line);
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    string line;
    for (int i = 0; i < n; ++i) {
        // process case
        cout << "Case #" << i + 1 << ": " << "Y" << endl;
    }
    return 0;
}

