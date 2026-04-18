class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            string temp = to_string(nums[i]);
            int stringLen = temp.length();

            for(int i=0;i<stringLen;i++)
            {
                if(temp[i] == (digit + '0'))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};