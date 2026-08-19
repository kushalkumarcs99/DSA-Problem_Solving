class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int n = nums.size();
        int left = 0;
        int result = 0;
        long long product = 1;

        for (int right = 0; right < n; right++) {

            product *= nums[right];

            while (product >= k) {
                product /= nums[left];
                left++;
            }

            result += right - left + 1;
        }

        return result;
    }
};