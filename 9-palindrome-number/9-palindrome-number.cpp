class Solution {
public:
    bool isPalindrome(int x) {
      if(x < 0)
          return false;
      else{
          long long int a = x;
          long long int b = 0;
          while(a>0){
              b = b*10 + a%10;
              a = a/10;
          }
          if(b == x)
              return true;
          else return false;
      }
        
    }
};