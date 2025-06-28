class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                // Return 1-based indices
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++; // Increase the smaller value
            } else {
                right--; // Decrease the larger value
            }
        }
        return {}; // Shouldn't reach here for valid inputs
    }
};