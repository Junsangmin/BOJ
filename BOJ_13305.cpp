#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;


int T,n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;

    for(int i=0;i<T;i++){
        int dp[100001][2];
        dp[0][0]=0;
        dp[0][1]=0;
        cin>>n;
        for(int j=0;j<2;j++){
            for(int k=1;k<=n;k++){
                cin>>dp[k][j];
            }
        }
        dp[2][0]+=dp[1][1];
        dp[2][1]+=dp[1][0];
        for(int i=3;i<=n;i++){
            dp[i][0]+=max(dp[i-2][1],dp[i-1][1]);
            dp[i][1]+=max(dp[i-2][0],dp[i-1][0]);
        }
        cout<<max(dp[n][0],dp[n][1])<<'\n';
        
    }
}

