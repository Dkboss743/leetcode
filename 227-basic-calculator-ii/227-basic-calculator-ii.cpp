class Solution {
public:
    bool static isdigit(char a){
        return a>='0' && a<='9';
    }
    
    int calculate(string s) {
        istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' or op == '-') {
            total += term;
            in >> term;
            term *= 44 - op;
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
    }
    
};