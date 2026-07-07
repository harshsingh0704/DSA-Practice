class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);
        string s = "";

        int m = str.size();
        long long sum = 0;

        for (int i = 0; i < m; i++) {
            if (str[i] != '0') {
                s += str[i];
                sum += str[i] - '0';
            }
        }

        long long x = 0;
        if (!s.empty())
            x = stoll(s);

        return x * sum;
    }
};