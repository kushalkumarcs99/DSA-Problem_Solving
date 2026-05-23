/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
        auto dim = binaryMatrix.dimensions();
        int rows = dim[0], cols = dim[1];

        int i = 0, j = cols - 1;
        int ans = -1;
        while (i < rows && j >= 0) {
            if (binaryMatrix.get(i, j) == 1) {

                ans = j;
                j--; // move left

            } else {
                i++; // mpove down
            }
        }
        return ans;
    }
};