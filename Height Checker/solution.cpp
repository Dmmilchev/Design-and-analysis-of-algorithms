class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int hash[101] = {0};

        for (int i=0; i<heights.size(); i++) 
            hash[heights[i]]++;

        int diffCount =0;
        int heightsIndex =0;

        for (int i=1; i<101; i++) {

            while (hash[i] > 0) {
                if (heights[heightsIndex] != i)
                    diffCount++;
                
                hash[i]--;
                heightsIndex++;
            }

        }

        return diffCount;
    }
};
