class Solution {
public:
    int smallestNumber(int n, int t) {

        while (true) {
            int a = n;
            int product = 1;

            while (a > 0) {
                int d = a % 10;
                product *= d;
                a /= 10;
            }

            if (product % t == 0) {
                return n;
            } else {
                n++;
            }
        }
    }
};