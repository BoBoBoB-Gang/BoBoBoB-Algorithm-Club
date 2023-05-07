 #include <bits/stdc++.h>

using namespace std;
deque<int> gear[4];

void rotateGear(int n, int d){
    if (d == 1){ // clock
        int x = gear[n].back();
        gear[n].pop_back();
        gear[n].push_front(x);
    }
    else if (d == -1) {
        int x = gear[n].front();
        gear[n].pop_front();
        gear[n].push_back(x);
    }
}

void changeGear(int n, int d){
    int direct[4] = {0,0,0,0};
    direct[n] = d;
    for (int i=n+1; i<4; i++){
        if (gear[i-1][2] == gear[i][6])
            break;
        direct[i] = -direct[i-1];
    }
    for (int i=n-1; i>=0; i--){
        if (gear[i][2] == gear[i+1][6])
            break;
        direct[i] = -direct[i+1];
    }
    for (int i=0; i<4; i++)
        rotateGear(i, direct[i]);

}


void getInput(){
    char inp;
    for (int i=0; i<4; i++){
        for (int j=0; j<8; j++){
            cin >> inp;
            gear[i].push_back(inp-'0');
        }
    }
    int n, gear_num, direction;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> gear_num >> direction;
        changeGear(gear_num-1, direction);
    }
    int ans=0, two =1;
    for (int i=0; i<4; i++){
        ans += (gear[i][0]==0) ? 0 : two;
        two *= 2;
    }
    cout << ans;
}

int main() {
    getInput();
   // changeGear();
    return 0;
}
