//13305 주유소
#include <iostream>
#include <vector>

using namespace std;

int N;

long long answer=0;
vector<long long> len; // 길이 저장 벡터
vector<long long> oil; // 기름 가격 저장 벡터
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long min=1000000001;
    cin>>N;
    for(int i=0;i<N-1;i++){
        long long num;cin>>num;
        len.push_back(num);
    }

    for(int i=0;i<N;i++){
        long long num;cin>>num;
        oil.push_back(num);
    }

    for(int i=0;i<N-1;i++){

        if(oil[i]<min){
            min=oil[i];
        }

        answer+=min*len[i];
    }

    cout<<answer;
    
}

