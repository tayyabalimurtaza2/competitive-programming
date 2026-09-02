#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;

inline double f(double x) {
    // Horner's method
    return ((a * x + b) * x + c) * x + d;
}

int main() {
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    const double EPS = 1e-9;
    int cnt = 0;

    for (int i = -100; i <= 100; ++i) {
        double x = i;

        // Check integer endpoint root
        if (fabs(f(x)) < EPS) {
            if (cnt) putchar(' ');
            printf("%.2f", x);
            ++cnt;
            if (cnt == 3) return 0;
        }

        // Check interval [i, i+1]
        if (i < 100) {
            double l = i;
            double r = i + 1.0;
            double fl = f(l);
            double fr = f(r);

            // If an endpoint is already a root, we already handled it
            if (fabs(fl) < EPS || fabs(fr) < EPS) continue;

            if (fl * fr < 0.0) {
                for (int it = 0; it < 100; ++it) {
                    double mid = (l + r) * 0.5;
                    if (f(l) * f(mid) <= 0.0) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }

                if (cnt) putchar(' ');
                printf("%.2f", r);
                ++cnt;
                if (cnt == 3) return 0;
            }
        }
    }

    return 0;
}
