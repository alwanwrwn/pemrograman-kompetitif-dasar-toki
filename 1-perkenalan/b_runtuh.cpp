#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int r, c; cin >> r >> c;

  vector<vector<int> > map;

  // Input
  for (int i = 0; i<r; i++) {
    int n; cin >> n;
    vector<int> temp;
    
    for (int j = 0; j<c; j++) {
      temp.insert(temp.begin(), n%10);
      n /= 10;
    }

    map.push_back(temp);
  }

  int flag = 0;

  while (flag == 0) {
    int last = 0;
    // Check and remove complete row
    for (int i = 0; i<r; i++) {
      int sum = accumulate(map[i].begin(), map[i].end(), 0);

      if (sum == c) {
        fill(map[i].begin(), map[i].end(), 0);
        last = i;
      }
    }

    // Falling logic (greedy)
  
    // -> 5 ACC, 5 WA
    for (int i = last; i>= 0; i--) {
      for (int j = 0; j<c; j++) {
        if (map[i][j] == 1) {
  
          int index = -1;
          for (int x = i+1; x < r; x++) {
            if (map[x][j] == 1) {
              index = x;
              break;
            }
          }

          if (index>-1) {
            map[i][j] = 0;
            map[index-1][j] = 1;
          }
        }
      }
    }

    // Check
    flag = 1;
    for (int i = 0; i<r; i++) {
      int sum = accumulate(map[i].begin(), map[i].end(), 0);

      if (sum == c) {
        flag = 0;
        break;
      }
    }
  }
    
  for (int i = 0; i<r; i++) {
    for (int j = 0; j<c; j++) {
      cout << map[i][j];   
    }
    cout << "\n";
  }

  return 0;
}
