class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int count=0;
        int n=s.size();
        
        if(n==1) return 0;
        
        while(true){
            bool flag=false;
            int i=1;
            while(i<n)
            {
            
            if(s[i-1]=='0' && s[i]=='1'){
                swap(s[i-1],s[i]);
                flag=true;
                i+=2;
            }
            else{
                i++;
                }
            }
            if(flag==false){
                break;
            }
            count++;
           // cout<<s<<" "<<count<<endl;
        }
        return count;
    }
};