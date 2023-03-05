
class Solution {
    unordered_map<int, vector<int>> myMap;
public:
    int minJumps(vector<int>& arr) {
        for(int i = 0; i < arr.size(); ++i)
        myMap[arr[i]].push_back(i);

        vector<bool> visited(arr.size(),false);

        queue<int> q;
        q.push(0);
        visited[0] = true;
        int level = -1;

        while(!q.empty()){
            ++level;
            int size = q.size();

            while(size--){
                int front = q.front();
                q.pop();

                if(front == arr.size() - 1)
                return level;

                if(front + 1 < arr.size() && !visited[front+1]){
                q.push(front+1);
                visited[front+1] = true;
                }

                if(front - 1 >= 0 && !visited[front-1]){
                q.push(front-1);
                visited[front-1] = true;
                }

                for(auto it : myMap[arr[front]]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }

                myMap[arr[front]].clear();
            }
        }
        return -1;
    }
};