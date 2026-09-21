const int N_MAX = 100'000;

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        int starts[N_MAX + 1] = { 0 };
        int ends[N_MAX + 1] = { 0 };
        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        sort(starts, starts + n);
        sort(ends, ends + n);

        long long count = 0;
        int end_i = 0;
        for (int start_i = 0; start_i < n; ++start_i) {
            while (end_i < n && ends[end_i] < starts[start_i]) {
                ++end_i;
            }
            count += end_i;
        }
        return (long long)(n - 1) * n / 2 - count;
    }
};