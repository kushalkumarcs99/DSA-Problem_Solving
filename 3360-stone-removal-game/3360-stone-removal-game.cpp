class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;
        bool isAlice = true;
        int currentNoStones = 10;
        while(true)
        {
            if(isAlice && n >= currentNoStones)
            {
                n = n - currentNoStones;
                isAlice = false;
                currentNoStones--;
            }
            else if(isAlice && n < currentNoStones)
            {
                return false;
            }
            else if(!isAlice && n < currentNoStones)
            {
                return true;
            }
            else if(!isAlice && n >= currentNoStones)
            {
                n = n - currentNoStones;
                isAlice = true;
                currentNoStones--;
            }
        }

        return true;
    }
};