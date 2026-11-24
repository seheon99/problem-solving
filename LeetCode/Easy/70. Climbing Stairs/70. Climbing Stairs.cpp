const int N_MAX = 45;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }

        static int cache[N_MAX + 1];
        static bool visited[N_MAX + 1] = {true};
        
        if (!visited[n]) {
            visited[n] = true;
            cache[n] = climbStairs(n - 1) + climbStairs(n - 2);
        }
        return cache[n];
    }
};