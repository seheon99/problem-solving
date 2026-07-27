#include <iterator>
#include <limits>
#include <set>
#include <utility>

class MyCalendar {
public:
    bool book(int start_time, int end_time) {
        auto next = ranges.lower_bound({
            start_time,
            std::numeric_limits<int>::lowest()
        });

        if (next != ranges.end() && next->first < end_time) {
            return false;
        }

        if (next != ranges.begin()) {
            auto prev = std::prev(next);
            if (prev->second > start_time) {
                return false;
            }
        }

        ranges.emplace(start_time, end_time);
        return true;
    }

private:
    std::set<std::pair<int, int>> ranges;
};