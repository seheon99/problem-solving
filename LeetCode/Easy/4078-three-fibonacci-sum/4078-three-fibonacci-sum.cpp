const int N_MAX = 100'000;

class Solution {
private:
    unsigned long long fibonacci[N_MAX] = {0, 1, 1, 2, 3, 5, 8, 13};
    unsigned long long consecutive_sum[N_MAX] = {0, 0, 2, 4, 6, 10, 16, 26};
public:
    bool threeFibonacciSum(int n) {
        for (int i = 1; i < N_MAX; i++) {
            if (fibonacci[i] == 0) {
                fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
                consecutive_sum[i] = fibonacci[i] + fibonacci[i - 1] + fibonacci[i - 2];
            }
            if (consecutive_sum[i] == n) {
                return true;
            }
            if (fibonacci[i] >= n) {
                break;
            } 
        }
        return false;
    }
};