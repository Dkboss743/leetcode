  bool compare(int a,int b){
    int count1 = 0;
    int count2= 0;
    int val1 = a;
    int val2 = b;
    while(true){
        if(a>0){
        a = (a&(a-1));
        count1++;
        }
        if(b>0){
        b = (b&(b-1));
        count2++;
        }
        else
            break;
    }
    if(count1 == count2)
    return val1<val2;
    else
    return count1<count2;
 
}
class Solution {
public:

vector<int> sortByBits(vector<int> &arr) {
    sort(arr.begin(),arr.end(),compare);
    return arr;      
}
};