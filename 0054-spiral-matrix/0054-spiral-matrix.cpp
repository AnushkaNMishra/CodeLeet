class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(); //row
        int n=matrix[0].size(); //col
        int dir=0;
        if(matrix.size()==0){
            return {};
        }
        int top=0;
        int down=m-1;
        int right=n-1;
        int left=0;
        
        /*
            dir=0: left to right
            dir=1: top to down
            dir=2: right to left
            dir=3: down to top
        */
        
        vector<int>res;
        while(top<=down && left<=right){
            if(dir==0){
                //left to right
                //const:row
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir==1){
                //top to down
                //const:col
                for(int i=top;i<=down;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir==2){
                //right to left
                //const:row(down)
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[down][i]);
                }
                down--;
            }
            if(dir==3){
                //down to top
                //const:col(left)
                for(int i=down;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir==4){
                dir=0;
            }
            
        }
        return res;
    }
};