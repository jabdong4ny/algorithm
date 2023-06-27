#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> gNumbers;
int numbers_size;
int g_target;
int answer;

void DFS(int index, int sum)
{
    if(index == numbers_size)
    {   
        if(g_target == sum) answer++;
        return ;
    }
    
    DFS(index+1, sum + gNumbers[index]);
    DFS(index+1, sum - gNumbers[index]);
}

void BFS() {
    vector<int> temp_sum, sum;
    int sum_counter = 0;
    double sum_result_size = pow(2, numbers_size);
    temp_sum.resize(sum_result_size, 0);
    sum.resize(sum_result_size, 0);

    //idx 0
    sum[sum_counter++] = + gNumbers[0];
    sum[sum_counter++] = - gNumbers[0];


    //idx 1~ numbers size
    for (int numInx = 1; numInx < numbers_size; numInx++) {
        temp_sum = sum;
        sum_counter = 0;
        double recurse = pow(2, numInx);
        for (int i = 0; i < recurse ; i++) {
            sum[sum_counter++] = temp_sum[i] + gNumbers[numInx];
            sum[sum_counter++] = temp_sum[i] - gNumbers[numInx];
        }
        cout << "sum_counter : " << sum_counter << " numInx : " << numInx << endl;
    }

    for (int numInx = 0; numInx < sum_result_size; numInx++) {
        if (g_target == sum[numInx]) {
            answer++;
        }
    }
    return;
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    gNumbers = numbers;
    g_target = target;
    numbers_size = numbers.size();
    //DFS(0,0);
    BFS();
    
    return answer;
}

int main()
{
    vector<int> numbers = {1, 1, 1, 1, 1};
    cout << solution(numbers,3);
}