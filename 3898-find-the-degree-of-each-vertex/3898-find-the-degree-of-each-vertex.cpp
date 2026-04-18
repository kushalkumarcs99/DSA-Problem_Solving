class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> result;

        for(int i=0;i<n;i++)
        {
            int noOfEdges = 0;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] == 1)
                {
                    noOfEdges++;
                }
            }

            result.push_back(noOfEdges); 
        }

        return result;
    }
};