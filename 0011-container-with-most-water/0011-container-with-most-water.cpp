class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int ans = 0;
        while(i < j){
           int water = (j - i)*(min(height[j],height[i]));
           ans = max(ans , water);
           if(height[j] < height[i]){
               j--;
           }
           else if(height[j] > height[i]){
               i++;
           }
          else{
              i++;
              j--;
          }
        }
        return ans;
    }
};