using number = long long;

const number MODULO_NUMBER = 1'000'000'000 + 7;

class Solution {
public:
    int sumDecoded(vector<number>& nums) {
        number sum = 0;
        for (auto& num : nums) {
            number w = num % 10;
            number d = floor(num / 10);
            
            int n_digits_of_d = floor(log10(d)) + 1;
            number crit = pow(10, n_digits_of_d - w);
            number x = d / crit;
            number y = d % crit;

            number n = 1;
            number base = x;
            number exp = y;
            while (exp > 0) {
                if (exp & 1) {
                    n *= base % MODULO_NUMBER;
                    n %= MODULO_NUMBER;
                }
                base *= base % MODULO_NUMBER;
                base %= MODULO_NUMBER;
                exp >>= 1;
            }
            sum += n;
            sum %= MODULO_NUMBER;
        }
        return sum;
    }
};