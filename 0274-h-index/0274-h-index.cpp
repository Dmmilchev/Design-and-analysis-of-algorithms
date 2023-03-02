class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;

        int citationsSize = citations.size();
        vector<int> hash (citationsSize + 1, 0);

        for (int i=0; i<citationsSize; ++i) {
            if (citations[i] >= citationsSize)
                hash[citationsSize]++;
            else
                hash[citations[i]]++;
        }

        int papersCount =0;
        for (int i = citationsSize; i>= 0; --i) {
            papersCount += hash[i];

            if (papersCount >= i)
                return i;
        }

        return 0;
    }
};