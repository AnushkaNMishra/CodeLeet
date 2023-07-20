// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
        
//     }
// };

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n = asteroids.size();

        for(int i=0;i<n;i++)
        {
            if(st.empty()==true)//if stack empty then push elements to compare
            st.push(asteroids[i]); 
            
            else if(asteroids[i]<0 && st.top()>0)// opp direction
            {
                if(st.top()>abs(asteroids[i]))
                continue;//opp asteroid value is lower

                else if(st.top()<abs(asteroids[i]))
                {
                    while(st.size()>0 && st.top()<abs(asteroids[i]) && st.top()>0)
                    st.pop();

                    
                    if(st.size()> 0 && st.top()>abs(asteroids[i]))
                    continue;
                    else if(st.size()>0 && st.top()==abs(asteroids[i]))
                    {
                        st.pop();
                        continue;
                    }
                    else st.push(asteroids[i]);
                    
                }
                
                if(st.size()>0 && st.top()==abs(asteroids[i]))
                {
                    st.pop();
                    continue;
                }
            
            }
            else if(st.size()>0 && asteroids[i]>0 && st.top()<0)//already in opp directions
                st.push(asteroids[i]);
            else if(st.size()>0 && (st.top()>0 && asteroids[i]>0) ||(st.top()<0 && asteroids[i]<0) )st.push(asteroids[i]);//same directions

            


        }
        vector<int>ans;
            while(st.empty()==false)
            {
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};