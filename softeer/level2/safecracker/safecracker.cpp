#include<iostream>
#include<vector>
#include<cstring>


using namespace std;
#define WEIGHT 0
#define PRICE  1

int main(int argc, char** argv)
{
	unsigned int W; // 배낭무게
	unsigned int N; // 귀금속의 종류
	unsigned int M; // 금속무게
	unsigned int P; // 가격
	unsigned result = 0; // 최대 가격
	
	//input 받기
	cin >> W >> N ;

	vector<vector<int>> M_P; //무게, 가격
	vector<int> v;
	
	for(int d=0; d < N ;d++)
	{
		cin >> M >> P;
		M_P.push_back(v);
		M_P[d].push_back(M);
		M_P[d].push_back(P);		
	}
	
	//가격은 배열의 index, 무게는 해당 배열의 값
	int data[10001]; 
	memset(data, 0x00, sizeof(data));
	
	for(int i=0 ; i < N ; i++) {
		data[M_P[i][PRICE]] += M_P[i][WEIGHT];
	}


	//가격은 배열의 index, 무게는 해당 배열의 값
	int remain_Kg = W;

	for(int k=10000; 0 <= k; k--) {
		if(data[k] == 0)
			continue ;
		if((remain_Kg - data[k]) >= 0){
			result += (k * data[k]);
			remain_Kg -= data[k];
		} else {
			result = result + (remain_Kg * k);
			break;
		}
	}

	cout << result;
	return 0;
}