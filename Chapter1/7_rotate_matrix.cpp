#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector< vector<int> >&, int);
void printMatrix(vector< vector<int> >&, int);

int main() {
  const int N = 3;

  vector< vector<int> > matrix(N, vector<int>(N));
  const int values[N][N] = {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
  };

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      matrix[i][j] = values[i][j];

  printMatrix(matrix, N);
  rotateMatrix(matrix, N);
  printMatrix(matrix, N);

  return 0;
}


void rotateMatrix(vector< vector<int> > &matrix, int N) {
  vector< vector<int> > rotated(N, vector<int>(N));

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      rotated[i][(N-1) - j] = matrix[j][i];

  matrix = rotated;
}

void printMatrix(vector< vector<int> > &matrix, int N) {

  for (int i = 0; i < N; ++i) {
    cout << "\n" << endl;
    for (int j = 0; j < N; ++j) {
      cout << matrix[i][j] << "\t";
      if (i == N-1 && j == N-1)
        cout << "\n" << endl;
    }
  }

}
