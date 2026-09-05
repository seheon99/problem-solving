enum Flag {
    NEVER_SEEN,
    TRACKING,
    SPECIAL,
    NOT_SPECIAL,
};

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        Flag flags[101] = { NEVER_SEEN, };
        int last_seen = -1;
        for (int num : nums) {
            if (last_seen >= 0 && num != last_seen && flags[last_seen] == TRACKING) {
                flags[last_seen] = SPECIAL;
            }
            if (flags[num] == NEVER_SEEN) {
                flags[num] = TRACKING;
            } else if (flags[num] == SPECIAL && num != last_seen) {
                flags[num] = NOT_SPECIAL;
            }
            last_seen = num;
        }

        int count = 0;
        for (auto flag : flags) {
            if (flag == SPECIAL || flag == TRACKING) {
                ++count;
            }
        }
        return count;
    }
};