#include <iostream>
#include <vector>
using namespace std;

int main() {
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector<int>ans(n);
        for(auto &x : ans){
            cin >> x;
        }
        for(int i=0; i<n ;i++){
            cout << ans[n-i-1] << " ";
        }
        cout << endl;
    }
	//code
	return 0;
}