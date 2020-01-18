#include "libmx.h"

int mx_sqrt(int x) {
    if(x == 0) return 0;
    int min = 1;
    int max = x/2 + 1;
    int res = 0;

    while (min <= max) {
        int mid = min + ((max - min)/2);
        if(mid <= x / mid) {
            min = mid + 1;
                if(mid * mid == x) {
                    res = mid;
                    return res;
                }
        }
        else {
            max = mid - 1;
        }
    }
    return res;
}
