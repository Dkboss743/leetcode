class Solution {
public:
    int minNumberOfHours(int i, int e, vector<int>& ener, vector<int>& exp) {
        int cnt=0, diff;
         int ans = accumulate(ener.begin(),ener.end(),0) + 1 - i;
        if(ans < 0){
            ans = 0;
        }
        for(int k=0; k<ener.size(); k++)
        {
            // if(i<=ener[k])
            // {
            //     diff = (ener[k]-i+1);
            //     i += diff;
            //     cnt += diff;
            // }
            if(e<=exp[k])
            {
                diff = (exp[k]-e+1);
                cout << diff << endl;
                e += diff;
                cnt += diff;
            }
            
            // i -= ener[k];
            e += exp[k];
                
        }
        return cnt+ans;
    }
   
        // if(ener < 0){
        //     ener = 0;
        // }
        // int temp = 0;
        // int sum = initialExperience;
        // for(auto x : experience){
        //     if(sum <= x){
        //         temp+= x-sum+1;
        //     }
        //     else{
        //         sum+=x;
        //     }
        // }
        // return ener+temp;
};

