class Solution {
public:
    string getHint(string secret, string guess) {
    int bulls = 0;
  int cows = 0;
  int size = guess.size();
  map<int, int> hint;
  for (int i = 0; i < size; i++) {
    if (secret[i] == guess[i]) {
      bulls++;
    } else
      hint[secret[i]]++;
  }
  for (int i = 0; i < size; i++) {
    if (secret[i]!=guess[i] && hint[guess[i]] > 0) {
      cows++;
      hint[guess[i]]--;
    }
  }

  return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};