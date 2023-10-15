#include<iostream>
#include <vector>

using namespace std;

int main() {
  int r, c; cin >> r >> c;

  vector<vector<int> > map;

  for (int i = 0; i<r; i++) {
    int n; cin >> n;
    // vector<int> temp = static_cast<vector<int> >(n);
    vector<int> temp(n);
    map.push_back(temp);
  }

  for (int i = 0; i<r; i++) {
    for (int j = 0; j<c; j++) {
      cout << map[i][j];   
    }
    cout << "\n";
  }

  return 0;
}
