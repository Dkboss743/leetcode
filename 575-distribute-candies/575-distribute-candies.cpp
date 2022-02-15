class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
       int n = candyType.size();
       sort(candyType.begin(), candyType.end());
       auto itr =  unique(candyType.begin(), candyType.end());
        candyType.resize(distance(candyType.begin(),itr));
       if(candyType.size() <=n/2)
           return candyType.size();
        else
            return n/2;
    }
};