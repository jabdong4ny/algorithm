#include <string>
#include <vector>

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

int solution(vector<int> numbers, int target) {
    answer = 0;
    gNumbers = numbers;
    g_target = target;
    numbers_size = numbers.size();

    DFS(0,0);
    
    return answer;
}