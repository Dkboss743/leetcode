class Trie{
    public:
    unordered_map<char , Trie*> mp;
    bool isEnd;
    void insert(Trie *root , string str){
        if(root == nullptr){
            root = new Trie();
            root->isEnd = false;
        }
        Trie *temp  = root;
        for(int i=0 ; i<str.size() ; i++){
            char x = str[i];
            if(temp->mp.find(x) == temp->mp.end()){
                temp->mp[x] = new Trie();
                temp->mp[x]->isEnd = false;
            }
            temp = temp->mp[x];
        }
        temp->isEnd = true;
    }
    bool dfs(Trie *root , int ind ,string str , int k){
        if(ind >= str.size()){
            return k>=2;
        }
        Trie *temp = root;
        for(int i = ind ; i<=str.size() ; i++){
            char x = str[i];
            if(temp->mp.find(x)  == temp->mp.end()){
                return false;
            }
            if(temp->mp[x]->isEnd == true){
                // cout << str  << " " << ind << endl;
                bool check = dfs(root , i+1 , str , k+1);
                if(check){
                    return check;
                }
            }
            temp = temp->mp[x];
        }
        return false;
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie *root = new Trie();
        root->isEnd = false;
        for(auto x : words){
            root->insert(root,x);
        }
        vector<string> ans;
        for(auto x : words){
            if(root->dfs(root , 0 , x , 0)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};