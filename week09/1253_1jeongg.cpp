#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int num_size;
vector<int> numbers;

bool isGoodNumber(int index, int target){
    int start_index=0, end_index = numbers.size()-1;
    while (start_index < end_index){
        int num_sum = numbers[start_index] + numbers[end_index];
        if (num_sum == target){
            if (start_index != index && end_index != index)
                return true;
            else if (start_index == index) start_index++;
            else if (end_index == index) end_index--;

        }
        else if (num_sum < target) start_index++;
        else end_index--;
    }
    return false;
}

int getGoodCount(){
    int cnt = 0;
    sort(numbers.begin(), numbers.end());
    int answer=0;
    for (int i=0; i<numbers.size(); i++){
        if (isGoodNumber(i, numbers[i]))
            answer++;
    }
    return answer;
}
void getInput(){
    int inp;
    cin >> num_size;
    for (int i=0; i<num_size; i++){
        cin >> inp;
        numbers.push_back(inp);
    }
}

int main() {
    getInput();
    cout << getGoodCount();
    return 0;
}
