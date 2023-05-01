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
	//cout << W << " " << N << endl;

	vector<vector<int>> M_P; //무게, 가격
	vector<int> v;
	
	for(int d=0; d < N ;d++)
	{
		cin >> M >> P;
		M_P.push_back(v);
		M_P[d].push_back(M);
		M_P[d].push_back(P);		
	}
	
	int data[N][2]; //0: 무게,  1:가격
	//int data[10000]; //가격은 배열의 index, 무게는 해당 배열의 값
	memset(data, 0x00, sizeof(data));
	//cout << data[N-1][0] << " " << data[N-1][1] << endl;

	int compare_p =0, compare_w=0, temp_price = 0, temp_weight=0;
/*	
	for(int i=0 ; i < N ; i++) {
		data[M_P[i][PRICE]] = M_P[i][WEIGHT];
	}
*/	
	for(int i=0 ; i < N ; i++){
		compare_p = M_P[i][PRICE];
		compare_w = M_P[i][WEIGHT];
		for(int j=0 ; j < 1000000 ; j++){
			if(data[j][PRICE] < compare_p)
			{
				//cout << "before data " << data[j][PRICE] << " compare_p " << compare_p << endl;
				temp_price = data[j][PRICE];
				temp_weight = data[j][WEIGHT];
				//cout << "before temp_price " << temp_price << " temp_weight " << temp_weight << endl;
				data[j][PRICE] = compare_p;
				data[j][WEIGHT] = compare_w;
				//cout << "before data[j][PRICE] " << data[j][PRICE] << " data[j][WEIGHT] " << data[j][WEIGHT] << endl;
				compare_p = temp_price;
				compare_w = temp_weight;
				//cout << "data[j][PRICE] = " << data[j][PRICE]  << endl;
			} 
			else if(data[j][PRICE] > compare_p){
				continue;
			}
			if(temp_price == 0) break; 
		}
	}
	
/*
	//가격은 배열의 index, 무게는 해당 배열의 값
	int remain_Kg = W;
	for(int k=9999; 0 <= k; k--) {
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
*/
	int remain_Kg = W;
	for(int k=0 ; k < N ; k++){
		//cout << "remain_KG = " << remain_Kg << endl;
		//cout << "data[k][WEIGHT] = " << data[k][WEIGHT] << endl;
		//cout << "remain_Kg - data[k][WEIGHT] = " << remain_Kg - data[k][WEIGHT] << endl ;
		
		if((remain_Kg - data[k][WEIGHT]) >= 0){
			//cout << "data[k][PRICE] = " << data[k][PRICE] << endl;
			result += (data[k][PRICE] * data[k][WEIGHT]);
			//cout << "result = " << result << endl;
			remain_Kg -= data[k][WEIGHT];
		} else {
			result = result + (remain_Kg * data[k][PRICE]);
			//cout << "result = " << result << endl;
			//cout << (unsigned)result;
			break;
		}
	}
	
	cout << result;
	return 0;
}