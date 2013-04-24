#include "compat.h"
#include <math.h>

#ifdef WIN32

double erf(double x) {
    static const double _M_2_SQRTPI = 1.12837916709551257390;
    static const double eps = 1.0e-7;
    if (fabs(x) >= 3.75)
        return x > 0 ? 1.0 : -1.0;
    double r = _M_2_SQRTPI * x;
    double f = r;
    for (int i = 1;; ++i) {
        r *= -x * x / i;
        f += r / (2 * i + 1);
        if (fabs(r) < eps * (2 * i + 1))
            break;
    }
    return f;
}

#endif // WIN32
