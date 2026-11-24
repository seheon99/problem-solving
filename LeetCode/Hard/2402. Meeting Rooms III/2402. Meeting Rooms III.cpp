const int N_MAX = 100;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        long long end_times[N_MAX] = { 0 };
        int count[N_MAX] = { 0 };

        sort(
            meetings.begin(),
            meetings.end(),
            [](const auto& a, const auto& b) {
                return a[0] < b[0];
            }
        );

        for (const auto& meeting : meetings) {
            int start_time = meeting[0];
            int end_time = meeting[1];
            bool founded = false;

            for (int i = 0; i < n; i++) {
                if (end_times[i] <= start_time) {
                    founded = true;
                    end_times[i] = end_time;
                    ++count[i];
                    break;
                }
            }
            if (!founded) {
                auto it = min_element(end_times, end_times + n);
                *it += end_time - start_time;
                ++count[it - end_times];
            }
        }

        auto it = max_element(count, count + n);
        return it - count;
    }
};