class Solution {
public:
    string predictPartyVictory(string senate) {
        string temp=senate;
        for(int i=0;i<temp.length()-1;i++)
        {
            char x=temp[i];
            //temp.erase(temp.begin());
            bool flag=true;
            for(int j=i+1;j<temp.length();j++)
            {
                if(x!=temp[j])
                {
                    //cout<<j<<" ";
                    temp.erase(temp.begin()+j);
                    flag=false;
                    break;
                }
            }
            if(flag==true)break;
            temp.push_back(x);
           // cout<<temp<<" ";
        }
        if(temp.length())
        {
            if(temp[temp.length()-1]=='R')return "Radiant";
            else return "Dire";
        }
        return "";
        

    }
};