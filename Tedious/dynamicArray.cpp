#include <cstdio>
#include <iostream>
using namespace std;

int main() {

    /*
  int rows;
  cout << "Enter rows:";
  cin >> rows;

  int colums;
  cout << "Enter columns:";
  cin >> colums;

  int **arr = new int *[rows];

  for (int i = 0; i < rows; i++) {
      arr[i] = new int[colums];
  }

  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < colums; j++) {
          cout << "arr[" << i << "][" << j << "]:";
          cin >> arr[i][j];
      }
  }

  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < colums; j++) {
          cout << arr[i][j] << " ";
      }
      cout << endl;
  }
  */

    int rows;
    cout << "Enter rows:";
    cin >> rows;

    char **ptr = new char *[rows];
    int *count = new int[rows];

    for (int i = 0; i < rows; i++) {
        int columns = 0;
        cout << "Enter columns:";
        cin >> columns;
        ptr[i] = new char[columns];
        count[i] = columns;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < count[i]; j++) {
            cout << "ptr[" << i << "][" << j << "]=";
            cin >> ptr[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < count[i]; j++) {
            cout << ptr[i][j];
        }
        cout << endl;
    }
}
