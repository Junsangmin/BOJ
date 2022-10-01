#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N,A,B,num1,num2,num3;
vector<pair<int,pair<int,int>>> vec;

bool compare(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
	return abs(a.second.first-a.second.second) > abs(b.second.first-b.second.second);
}

int main(int argc, char* argv[]) {

	while(true){
		vec.clear();
		cin>>N>>A>>B;
		if(N==A && A==B && B==0){
			break;
		}
		long long answer=0;
		for(int i=0;i<N;i++){
			cin>>num1>>num2>>num3;
			
			vec.push_back(make_pair(num1,make_pair(num2,num3)));

			//둘 간의 차이가 큰 거부터 정렬해서 하나씩 넣어주면 되는거 아닌감?
		}
		
		sort(vec.begin(),vec.end(),compare);
		for(int i=0;i<vec.size();i++){
			int cnt=vec[i].first;
			int Da=vec[i].second.first;
			int Db=vec[i].second.second;
			if(Da==Db){
				answer+=cnt*Da;

			}
			else{
				if(Da<Db){
					if(A>=cnt){
						A-=cnt;
						answer+=cnt*Da;

					}
					else{
						cnt-=A;
						A=0;
						answer+=cnt*Da;
						B-=cnt;
						answer+=cnt*Db;

					}
				}
				else{
					if(B>=cnt){
						B-=cnt;
						answer+=cnt*Db;

					}
					else{
						cnt-=B;
						B=0;
						answer+=cnt*Db;
						A-=cnt;
						answer+=cnt*Da;

					}
				}
			}
		}
		cout<<answer<<endl;
	}
	
}
/*
	거리 같으면 AB중 더 적게 남은 거에서 뺌
	거리 다를 때 뺄 수 있으면 그냥 빼고 안되면 일부 빼고 일부는 나머지로 뺌
	
*/
