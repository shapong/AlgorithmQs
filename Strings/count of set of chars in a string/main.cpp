#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        return count_if(begin(S), end(S), 
            [&J](char c) {
                return J.find(c)!=string::npos;
            }
        );
    }
};

int main() {
    string J,S;
    cout << "Enter a set of chars" << endl;
    cin >> J;

    cout << "Enter a string" << endl;
    cin >> S;
    
    int ret = Solution().numJewelsInStones(J, S);

    string out = to_string(ret);
    cout << out << endl;
    
    return 0;
}
