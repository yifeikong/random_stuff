#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct Event {
    int a_excitement, b_excitement, c_last;
};

int main() {
    int n_events, m_time, k_limit;
    cin >> n_events >> m_time >> k_limit;

    int timeElapsed;
    vector<Event> events;

    int a, b, c;
    while (n_events--) {
        cin >> a >> b >> c;
        events.push_back(Event(a, b, c));
    }



    int maxExcitement;
    int timeLeft;
    return 0;
}

