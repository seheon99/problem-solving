#include <vector>

class NumArray {
public:
    NumArray(std::vector<int>& nums) {
        _tree.resize(nums.size() * 4, 0);
        _size = nums.size();
        _initialize(nums, 1, 1, _size);
    }
    
    void update(int idx, int val) {
        _update(1, idx + 1, val, 1, _size);
    }
    
    int sumRange(int left, int right) {
        return _sumRange(1, left + 1, right + 1, 1, _size);
    }

private:
    std::vector<int> _tree;
    int _size;

    void _initialize(std::vector<int>& nums, int id, int start, int end) {
        if (start == end) {
            _tree[id] = nums[start - 1];
        } else {
            int mid = (start + end) / 2;
            _initialize(nums, 2 * id, start, mid);
            _initialize(nums, 2 * id + 1, mid + 1, end);
            _tree[id] = _tree[2 * id] + _tree[2 * id + 1];
        }
    }

    int _update(int id, int idx, int val, int start, int end) {
        if (idx < start || end < idx) {
            return 0;
        } else if (idx == start && end == idx) {
            int diff = val - _tree[id];
            _tree[id] = val;
            return diff;
        } else {
            int mid = (start + end) / 2;
            int ldiff = _update(2 * id, idx, val, start, mid);
            int rdiff = _update(2 * id + 1, idx, val, mid + 1, end);
            int diff = ldiff + rdiff;
            _tree[id] += diff;
            return diff;
        }
    }

    int _sumRange(int id, int left, int right, int start, int end) {
        if (end < left || right < start) {
            return 0;
        } else if (left <= start && end <= right) {
            return _tree[id];
        } else {
            int mid = (start + end) / 2;
            int lsum = _sumRange(2 * id, left, right, start, mid);
            int rsum = _sumRange(2 * id  + 1, left, right, mid + 1, end);
            return lsum + rsum;
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */