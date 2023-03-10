class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>s;
        for(auto it:sentence){
            s.insert(it);
        }
        if(s.size()==26){
        return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool checkIfPangram(string sentence) {
//         unordered_map<char,int>mp;
//         vector<int>v(26);
//         for(auto it:sentence){
//             v[it-'a']++;
//         }
//         for(auto it:v){
//             if(it==0){
//                 return false;
//             }
//         }
//         return true;
//     }
// };