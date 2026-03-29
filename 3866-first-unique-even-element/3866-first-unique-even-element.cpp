class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Step 1: Count only even numbers
        for (int num : nums) {
            if (num % 2 == 0) {
                freq[num]++;
            }
        }

        // Step 2: Traverse original array (to maintain order)
        for (int num : nums) {
            if (num % 2 == 0 && freq[num] == 1) {
                return num;
            }
        }

        return -1;
    }
};