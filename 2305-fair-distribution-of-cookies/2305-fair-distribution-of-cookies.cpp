class Solution {
public:
    int result = INT_MAX;
    vector<int> child;

    void dfs(vector<int>& cookies, int k, int index){
        int temp = *max_element(begin(child), end(child));
        
        if(result < temp) return;

        if(index == cookies.size()){
            result = min(temp, result);
            return;
        }

        for(int i = 0 ; i < k ; ++i){
            child[i] += cookies[index];
            dfs(cookies, k , index+1 );
            child[i] -= cookies[index];
        }

    }


    int distributeCookies(vector<int>& cookies, int k) {
        sort(begin(cookies), end(cookies));
        child = vector<int>(k,0);
        dfs(cookies, k , 0);
        return result;
    }
};