class Solution {
public:
    //  int n ;
    // int t[100000];

    // int solve(int i,vector<int>& prefixsum)
    // {
    //     if(i==n-1){
    //         return prefixsum[n-1];
    //     }

    //     if(t[i]!= -1)
    //     {
    //         return t[i];
    //     }
    // //     //    int take = prefixsum[i] - solve(i + 1, prefixsum);
    // //     // int skip = solve(i + 1, prefixsum);

    // //    int  take = prefixsum[i] - solve(i+1);
    // // int skip = solve(i+1);

    //  int take = prefixsum[i] - solve(i + 1, prefixsum);
    //     int skip = solve(i + 1, prefixsum);

    //     return t[i] =max(take,skip);
    // }
    int stoneGameVIII(vector<int>& stones) {
        //Alice's goal is to maximize
        //Bob's goal is the m9inimize
        int n = stones.size();
        // memset(t,-1,sizeof(t));

        vector<int> prefixsum(n,0);
        prefixsum[0] = stones[0];

        // int Alicescore = 0;
        // int Bobscore = 0;
        for(int i =1;i<n;i++){
           prefixsum[i] = prefixsum[i-1] + stones[i];
        }

        vector<int> t(n);
        t[n-1] = prefixsum[n - 1];
        //base : if(i == n-1) return prefixsum[n-1]
       for(int i = n-2; i>= 1; i--){
        int take = prefixsum[i]- t[i+1];
        int skip = t[i+1];

        t[i] = max(take,skip);
       }
       return t[1];
    }
};