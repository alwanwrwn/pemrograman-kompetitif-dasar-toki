#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(){
  string a, b; 
  cin >> a;
  cin >> b;

  if (a.size()-1 != b.size()) {
    cout << "Wah, tidak bisa :(";
    return 0;
  } else {
    for (int i = 0; i<a.size(); i++) {
      string temp = a;
      string curr = temp.erase(i,1);
      if (curr == b) {
        cout << "Tentu saja bisa!";
        return 0;
      }
    }
  }

  cout << "Wah, tidak bisa :(";

  return 0;
}
