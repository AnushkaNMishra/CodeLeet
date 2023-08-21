class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      string temp = s + s;
      string check = temp.substr(1, temp.size()-2);
      if(check.find(s)!=-1){
          return true;
      }
      return false;
    }
};