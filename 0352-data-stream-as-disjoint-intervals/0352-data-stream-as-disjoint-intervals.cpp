class SummaryRanges {
public:
    vector<vector<int>> interval;
    unordered_set<int> st;
    SummaryRanges() {
       
    }
    void combine(){
        vector<vector<int>> temp;
        int n = interval.size();
        if(n == 1){
            return;
        }
        for(int i = 0; i<n; i++){
            // cout << interval[i][1] << " " << interval[i+1][0] << endl;
            int st  = interval[i][0];
            while(i < n-1 && interval[i][1] + 1 == interval[i+1][0]){
                i++;
            }
            temp.push_back({st , interval[i][1]});
        }
        interval = temp;
    }
    void addNum(int value) {
        if(st.find(value) != st.end()){
            return;
        }
        st.insert(value);
        interval.push_back({value , value});
        sort(interval.begin() , interval.end());
        combine();
    }
    
    vector<vector<int>> getIntervals() {
        return interval;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */