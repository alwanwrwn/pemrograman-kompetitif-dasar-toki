#include <iostream>

using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  char map[21][9];

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> map[i][j];
    }
  }

  int flag = 0;

  while (flag == 0) {
    int count = 0;
    int lastRow = -1;

    for (int i = 1; i <= r; i++) {
      bool allBlack = true;

      for (int j = 1; j <= c; j++) {
        if (map[i][j] == '0') {
          allBlack = false;
          break;
        }
      }

      if (allBlack == true) {
        lastRow = i;
        for (int j = 1; j <= c; j++) {
          map[i][j] = '0';
        }
      } else {
        count++;
      }
    }

    if (lastRow != -1) {
      for (int j = 1; j <= c; j++) {
        int blackCount = 0;

        for (int k = 1; k <= lastRow; k++) {
          if (map[k][j] == '1') {
            blackCount++;
          }
        }

        if (blackCount > 0) {
          int destination;

          for (int k = lastRow; k <= r; k++) {
            if (map[k][j] == '1') {
              destination = k - 1;
              break;
            }
          }

          for (int k = destination; k >= destination - blackCount; k--) {
            map[k][j] = '1';
          }

          for (int k = destination - blackCount; k >= 0; k--) {
            map[k][j] = '0';
          }
        }
      }
    }

    if (count == r) {
      flag = 1;
    }
  }

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cout << map[i][j];
    }
    cout << endl;
  }

  return 0;
}
