class Solution {
public:
    int total_songs;
    long mod = 1e9+7;
    vector<vector<int>>dp{105,vector<int>(105,-1)};
    int helper(int goal,int n,int &k) // n is count of remaining unique songs // goal is the remaining goal
    {
        if(goal == 0)// if we meet out goal
        {
            if(n == 0) return 1; // if we are able to play all the unique songs then we can make a set otherwise not
            return 0;
        }
        if(dp[goal][n] != -1) return dp[goal][n];
        long long ans = 0;

        //we can play a unique song and we have n number of unique   songs so we can play any of this 
//if we have any remaining unique songs then we can only play it otherwise not so it is checked by if condition.
        if(n > 0) ans += 1ll* n * helper(goal-1,n-1,k);

//we can replay a song and for this in between two same songs atleast k number of songs should be played
//(total_songs-n) is value of unique songs which are already played 
//(total_songs-n-k) songs which can be replayed when in between atleast k number of songs already played
//we can only replay that songs that are already played so we are taking (total_songs-n).
//if we are not played any songs and we want to replay that is not going to happen so we are checking that in if condition.
        if(total_songs-n-k > 0) ans += 1ll*(total_songs-n-k)*helper(goal-1,n,k); 

        return dp[goal][n] = ans % mod;

    }
    int numMusicPlaylists(int n, int goal, int k)
    {
        total_songs = n;
        return helper(goal,n,k); //count_songs,count_unique
    }
};