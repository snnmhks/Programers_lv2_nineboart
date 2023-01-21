#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 아이디어는 오름차순으로 정렬하고 현재 가장 작은 값과 뒤에서 부터 합하고 비교한다.
// 만약 현재 최소값과 뒤에서 부터 비교하는 값의 합이 최대 무게보다 같거나 작다면
// 비교하는 값 이후에 있는 값들은 더 이상 비교할 의미가 없으므로 (즉 누군가와 같이 탈 수 없다.)
// 뒤에 있는 값의 수 + 1(현재 최소값과 페어를 이루는 값)
// 예로 40 45 50 70 80 80 90 이고 한도가 100이라면 40과 90 80 80 70 까지는 한도를 넘으므로 페어를 이룰수 없지만
// 40과 50은 페어를 이룰수 있으므로 제일 처음 40으로 비교한 값들은 4개에 40 50페어까지해서 5를 정답에 더한다.
// 이후 가장 작은 값으로 윗 과정을 반복한다. 예시에 따르면 이후 가장 작은 값은 45이고 이와 페어를 이룰수 있는
// 짝이 없으므로 1을 더해준다 최종적으로 6이 정답이 된다.

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int start = 0;
    int end = people.size();
    int index = end - 1;
    while (1)
    {
        if (people[start] + people[index] <= limit)
        {
            answer += end - index;
            end = index;
            start++;
            index = end;
            if (end == start + 1)
            {
                answer++;
                break;
            }
            else if (end == start)
            {
                break;
            }
        }
        else if (index == start + 1)
        {
            answer += end - start;
            break;
        }
        index--;
    }
    
    return answer;
}
