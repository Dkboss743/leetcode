class Solution {
public:
    bool static comp(vector<int>&a , vector<int> &b){
        return a[1]<b[1];
    }
  
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        priority_queue<int>data;
        int tot_time = 0;
        for(auto course : courses){
            if(tot_time + course[0] <= course[1]){
                data.push(course[0]);
                tot_time += course[0];
            }
            else if(!data.empty() && data.top()>=course[0] ){
                    tot_time =tot_time - data.top() + course[0];
                     data.pop();
                    data.push(course[0]);
                }
        }
        return (int)data.size();
        
    }
};