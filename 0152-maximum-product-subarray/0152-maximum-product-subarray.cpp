class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];

        int maxHere = nums[0];
        int minHere = nums[0];

        for(int i = 1; i < n; i++) {
            int x = nums[i];

            if(x < 0) swap(maxHere, minHere);

            maxHere = max(x, maxHere * x);
            minHere = min(x, minHere * x);

            ans = max(ans, maxHere);
        }
        return ans;
    }
};
