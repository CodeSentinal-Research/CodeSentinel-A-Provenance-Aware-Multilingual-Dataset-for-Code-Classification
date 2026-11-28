#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution{
    vector<string> phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void bt(string& digits, int idx, string& curr, vector<string>& res){
        if(idx==(int)digits.size()){res.push_back(curr);return;}
        for(char c:phone[digits[idx]-'0']){curr.push_back(c);bt(digits,idx+1,curr,res);curr.pop_back();}
    }
public:
    vector<string> letterCombinations(string digits){
        if(digits.empty()) return {};
        vector<string> res; string curr;
        bt(digits,0,curr,res);
        return res;
    }
};
int main(){
    string digits;cin>>digits;
    auto res=Solution().letterCombinations(digits);
    for(auto& s:res) cout<<s<<"\n";
}
