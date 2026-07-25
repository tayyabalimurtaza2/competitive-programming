#include <iostream>
using namespace std;

int main() {
    double d;
    cin >> d;

    double t = 0;
    double s = 2;
    int step = 0;

    while (t < d) {
        t += s;
        s *= 0.98;
        step++;
    }

    cout << step;
}