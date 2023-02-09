class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        std::map<char, std::set<std::string>> mp;

        for(auto& idea : ideas) mp[idea[0]].insert(idea.substr(1));

        long long result = 0;
        for(const auto& [first_letter1, remainder1]: mp){
            for(const auto& [first_letter2, remainder2] : mp){
                if(first_letter1 == first_letter2) continue;
                std::vector<std::string> intersection;
                std::set_intersection(remainder1.begin(), remainder1.end(), remainder2.begin(), remainder2.end(),
                          std::back_inserter(intersection));

                result += (remainder1.size() - intersection.size()) * (remainder2.size() - intersection.size());
            }
        }
        
        return result;
    }
};