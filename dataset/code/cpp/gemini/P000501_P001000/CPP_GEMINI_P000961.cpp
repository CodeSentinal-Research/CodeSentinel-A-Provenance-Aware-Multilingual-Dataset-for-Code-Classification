#include <iostream>

int main() {
    long long a, b, c;
    long long minx, maxx, miny, maxy;
    if (std::cin >> a >> b >> c >> minx >> maxx >> miny >> maxy) {
        long long count = 0;
        for (long long x = minx; x <= maxx; x++) {
            long long rem = c - a * x;
            if (rem % b == 0) {
                long long y = rem / b;
                if (y >= miny && y <= maxy) count++;
            }
        }
        std::cout << count << "\n";
    }
    return 0;
}