class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to positive long long values
        long long a = dividend;
        long long b = divisor;

        if (a < 0) a = -a;
        if (b < 0) b = -b;

        long long quotient = 0;

        // Subtract largest possible powers of 2
        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        // Apply sign
        if (negative)
            quotient = -quotient;

        // Clamp to 32-bit range
        if (quotient > INT_MAX)
            return INT_MAX;

        if (quotient < INT_MIN)
            return INT_MIN;

        return (int)quotient;
    }
};