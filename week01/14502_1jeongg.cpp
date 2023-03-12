#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int col_size, row_size;
vector<vector<int>> visited;


bool isInBound(int x, int y) {
    return x >= 0 && x < col_size && y >= 0 && y < row_size;
}
int bfs(vector<vector<int>> virus_map){
    queue<pair<int, int>> virus;
    virus.push({0,0});
    while (!virus.empty()){
        int x = virus.front().first, y = virus.front().second;
        virus.pop();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        for (int i=0; i<4; i++){
            int temp_x = x + dx[i], temp_y = y + dy[i];
            if (!isInBound(temp_x, temp_y)) continue;
            if (visited[temp_x][temp_y] == 0) {
                visited[temp_x][temp_y] += 1;
                virus.push({temp_x, temp_y});
            }
            if (virus_map[temp_x][temp_y] == 0
                && virus_map[x][y] == 2) {
                virus_map[temp_x][temp_y] = 2;
                virus.push({temp_x, temp_y});
            }
        }
    }
    int answer = 0;
    for (int i=0; i<col_size; i++){
        for (int j=0; j<row_size; j++){
            if (virus_map[i][j] == 0)
                answer++;
        }
    }
    return answer;
}
void clearVisit(){
    for (int i=0; i<col_size; i++){
        for (int j=0; j<row_size; j++){
            visited[i][j] = 0;
        }
    }
}
void getLargestSize(vector<vector<int>> virus_map) {
    int answer = 0;
    for (int a=0; a<col_size; a++){
        for (int b=0; b<row_size; b++){
            for (int c=0; c<col_size; c++){
                for (int d=0; d<row_size; d++){
                    for (int e=0; e<col_size; e++){
                        for (int f=0; f<row_size; f++){
                            // 미친 6중 포문
                            vector<vector<int>> virus_new;
                            virus_new.resize(virus_map.size());
                            copy(virus_map.begin(), virus_map.end(), virus_new.begin());
                            if (virus_new[a][b] != 0) continue;
                            if (virus_new[c][d] != 0) continue;
                            if (virus_new[e][f] != 0) continue;
                            if (a==c && b==d) continue;
                            if (a==e && b==f) continue;
                            if (c==e && d==f) continue;

                            virus_new[a][b] = 1;
                            virus_new[c][d] = 1;
                            virus_new[e][f] = 1;

                            answer = max(answer, bfs(virus_new));
                            clearVisit();
                        }
                    }
                }
            }
        }
    }
    cout << answer;
}
void getInput(){
    vector<vector<int>> virus_map;
    int inp;
    cin >> col_size >>row_size;
    for (int i=0; i<col_size; i++){
        vector<int> inp_vec, visit_vec;
        for (int j=0; j<row_size; j++){
            cin >> inp;
            inp_vec.push_back(inp);
            visit_vec.push_back(0);
        }
        virus_map.push_back(inp_vec);
        visited.push_back(visit_vec);
    }
    getLargestSize(virus_map);
}

int main() {
    getInput();

    return 0;
}
