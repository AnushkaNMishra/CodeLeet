class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()<=1)return chars.size();
        int k=0;
        for(int i=0;i<chars.size();){
            int j=i;
            while(i<chars.size() && chars[j]==chars[i])i++;
            if(i-j-1<1){
                chars[k]=chars[j];
                k++;
            }
            else {
                int num=i-j;
                chars[k]=chars[j];
                k++;
                string str;
                str+=(to_string(num));
                for(int n=0;n<str.length();n++){
                    chars[k++]=str[n];
                }
            }
        }
        return k;
    }
};