class KthLargest {
public:
    vector<int> input;
    int cap;

    KthLargest(int k, vector<int>& nums) {
        cap = k;

        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        input.push_back(val);

        push_heap(input.begin(), input.end(), greater<int>());

        if (input.size() > cap) {
            pop_heap(input.begin(), input.end(), greater<int>());
            input.pop_back();
        }

        return input.front();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */