class Solution {
private:
    std::unordered_map<int, int> rank;
    std::vector<int> left;
    std::vector<int> right;
    int n;

    bool calc(
        std::vector<int>& arr,
        int rate,
        int idx,
        int l,
        int r,
        bool is_push
    ) {
        if (l == r) {
            if (rank[rate] != l) return false;

            arr[idx] += (is_push ? 1 : -1);
            return true;
        }

        int mid = (l + r) / 2;
        bool updated;

        if (rank[rate] <= mid) {
            updated = calc(
                arr, rate, idx * 2, l, mid, is_push
            );
        } else {
            updated = calc(
                arr, rate, idx * 2 + 1, mid + 1, r, is_push
            );
        }

        if (updated) {
            arr[idx] += (is_push ? 1 : -1);
        }

        return updated;
    }

    int query(
        std::vector<int>& arr,
        int rate,
        int idx,
        int l,
        int r
    ) {
        int target = rank[rate];

        if (target <= l) return 0;
        if (r < target) return arr[idx];

        int mid = (l + r) / 2;

        return query(arr, rate, idx * 2, l, mid)
             + query(arr, rate, idx * 2 + 1, mid + 1, r);
    }

public:
    void push(std::vector<int>& arr, int rate) {
        calc(arr, rate, 1, 0, n - 1, true);
    }

    void pop(std::vector<int>& arr, int rate) {
        calc(arr, rate, 1, 0, n - 1, false);
    }

    int numTeams(std::vector<int>& rating) {
        n = rating.size();

        rank.reserve(n);
        left.resize(n * 4);
        right.resize(n * 4);

        std::vector<int> sorted = rating;
        std::sort(sorted.begin(), sorted.end());

        for (int i = 0; i < n; i++) {
            rank[sorted[i]] = i;
        }

        for (int rate : rating) {
            push(right, rate);
        }

        int answer = 0;

        for (int i = 0; i < n; i++) {
            int rate = rating[i];

            pop(right, rate);

            int left_smaller = query(left, rate, 1, 0, n - 1);
            int right_smaller = query(right, rate, 1, 0, n - 1);

            int left_greater = i - left_smaller;
            int right_greater = n - i - 1 - right_smaller;

            answer += left_smaller * right_greater;
            answer += left_greater * right_smaller;

            push(left, rate);
        }

        return answer;
    }
};
