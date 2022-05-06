/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int start = 1;
        int end = z;
        int ans = 0;
        vector<vector<int>> data;
        while(start<=z && end>0){
         int temp = customfunction.f(start,end);
         if(temp == z){
             data.push_back({start,end});
             start++;
         }
         else if(temp < z)
             start++;
         else{
             end--;
         }
        }
        // int a = data.size()-1;
        // for(int i = a; i>=0; i--){
        //     if(data[i][1]!=data[i][0])
        //     data.push_back({data[i][1],data[i][0]});
        // }
        return data;
    }
};