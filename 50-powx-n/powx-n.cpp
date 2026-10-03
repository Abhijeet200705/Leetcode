class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        long double X = x;

        if (N < 0) {
            X = 1.0L / X;
            N = -N;
        }

        long double result = 1.0L;

        while (N > 0) {
            if (N % 2 == 1) {
                result *= X;
            }

            X *= X;
            N /= 2;
        }

        return (double)result;
    }
};