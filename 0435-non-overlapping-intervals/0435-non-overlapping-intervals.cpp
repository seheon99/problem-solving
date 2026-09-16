class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b)
                                                 {
                                                    return a[1] < b[1];
                                                 });
        int final = -50'000;
        int count = 0;
        for (const auto& interval : intervals) {
            if (final <= interval[0]) {
                final = interval[1];
                ++count;
            }
        }
        return intervals.size() - count;
    }
};