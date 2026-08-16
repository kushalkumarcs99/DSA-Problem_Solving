class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;

        for(int stone : stones)
        {
            pq.push(stone);
        }

        while(pq.size() > 1)
        {
            int firstHeaviest = pq.top();
            pq.pop();
            int secondHeaviest = pq.top();
            pq.pop();

            if(firstHeaviest == secondHeaviest)
            {
                pq.push(0);
            }
            else
            {
                int diffWeight = abs(firstHeaviest - secondHeaviest);
                pq.push(diffWeight);
            }
        }
        return pq.top();
    }
};