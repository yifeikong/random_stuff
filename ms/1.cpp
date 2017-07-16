#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;




int main() {
    int P, Q;
    cin >> P >> Q;
    vector<int> Q_divisors;
    Q_divisors.reserve(sqrt(Q));
    for (int q = 1; q <= Q; ++q) {
        if (Q % q == 0)
            Q_divisors.push_back(q);
    }

    for (int p = 1; p <= P; ++p) {
        if (P % p == 0)
            for (int i = 0; i < Q_divisors.size(); ++i) {
                cout << p << " " << Q_divisors[i] << endl;
            }
    }
    return 0;
}

