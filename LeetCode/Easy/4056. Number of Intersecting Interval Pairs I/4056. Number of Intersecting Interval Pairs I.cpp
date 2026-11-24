class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        for (int i = 0; i < intervals.size() - 1; i++) {
            for (int j = i + 1; j < intervals.size(); j++) {
                if (intervals[i][1] >= intervals[j][0] && intervals[j][1] >= intervals[i][0]) {
                    ++count;
                }
            }
        }
        return count;
    }
};