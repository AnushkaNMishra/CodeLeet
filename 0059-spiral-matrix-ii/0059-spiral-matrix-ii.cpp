class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //microsoft paypal amazon
        int m=n;
        int dir=0;
        if(n==0){
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
        int c=1;
        vector<vector<int>> matrix(m,vector<int>(n));
        while(top<=down && left<=right){
            if(dir==0){
                //left to right
                //const:row
                for(int i=left;i<=right;i++){
                    //res.push_back(matrix[top][i]);
                    matrix[top][i]=c++;
                }
                top++;
            }
            if(dir==1){
                //top to down
                //const:col
                for(int i=top;i<=down;i++){
                    
                    matrix[i][right]=c++;
                }
                right--;
            }
            if(dir==2){
                //right to left
                //const:row(down)
                for(int i=right;i>=left;i--){              
                    matrix[down][i]=c++;
                }
                down--;
            }
            if(dir==3){
                //down to top
                //const:col(left)
                for(int i=down;i>=top;i--){
                    matrix[i][left]=c++;
                }
                left++;
            }
            dir=(dir+1)%4;
            
        }
        return matrix;
    }
};