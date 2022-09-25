#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int answer[301][301]={0,};
bool visited[301][301];
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int beginX,beginY,endX,endY;
int N;

int T;

void bfs(int a,int b){
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    visited[a][b] = true; 
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==endX && y==endY){
            cout<<answer[x][y]<<'\n';
            while(!q.empty()){
                q.pop();
            }
            break;
        }
        
        for(int i=0; i< 8; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(!visited[nx][ny] &&nx>=0 && nx<N && ny>=0 && ny<N){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true; 
                answer[nx][ny]=answer[x][y]+1;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        cin>>beginX>>beginY>>endX>>endY;
        bfs(beginX,beginY);
        memset(answer,0,sizeof(answer));
        memset(visited,false,sizeof(visited));
    }
    
    return 0;
} 
