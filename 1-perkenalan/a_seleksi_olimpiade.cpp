#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[3] > b[3]) {
          return true;
        } else if ((a[3] == b[3]) && (a[2] > b[2])) {
          return true;
        } else if ((a[2] == b[2]) && (a[1] > b[1])) {
          return true;
        } else {
          return false;
        }
};

int main(){
  int t; cin >> t;

  while (t--) {
    int n, m; cin >> n >> m;

    string p; cin >> p;
    int peserta = stoi(p.erase(0,1));

    vector<vector<int> > score;

    while (n--) {
      vector<int> curr;

      string x; cin >> x;

      int a,b,c,d; cin >> b >> c >> d;

      a = stoi(x.erase(0,1));
      
      curr.push_back(a);
      curr.push_back(b);
      curr.push_back(c);
      curr.push_back(d);

      score.push_back(curr);    
    }

    // Sort the vector
    sort(score.begin(), score.end(), comp);

    int flag = 0;
    // Result
    for (int i = 0; i<m; i++) {
      if (score[i][0] == peserta) {
        cout << "YA" << "\n";
        flag = 1;
        break;
      }
    }
    
    if (flag == 0) {
      cout << "TIDAK" << "\n";
    }
  }


  return 0;
}
