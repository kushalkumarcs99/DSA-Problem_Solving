class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int result = 0;
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        if (windowSum / k >= threshold) {
            result++;
        }
        int j = 0;
        for (int i = k; i < n; i++) {
            windowSum -= arr[j];
            windowSum += arr[i];
            if (windowSum / k >= threshold) {
                result++;
            }
            j++;
        }
        return result;
    }
};