#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef vector< pair<int, int> > pairVector;

void printMatrix(vector< vector<int> >&, int, int);
pairVector findZeros(vector< vector<int> >&, int, int);
void nullifyRow(vector< vector<int> >&, int, int);
void nullifyCol(vector< vector<int> >&, int, int);

int main() {
  const int M = 5; // ROWS
  const int N = 4; // COLUMNS

  vector< vector<int> > matrix(M, vector<int>(N));
  const int values[M][N] = {
    { 0, 2, 3, 0 },
    { 5, 6, 0, 8 },
    { 7, 3, 1, 6 },
    { 5, 3, 9, 4 },
    { 8, 4, 1, 8 }
  };

  for (int i = 0; i < M; ++i)
    for (int j = 0; j < N; ++j)
      matrix[i][j] = values[i][j];

  printMatrix(matrix, M, N);
  //
  pairVector zeros = findZeros(matrix, M, N);

  vector<int> nullRows;
  vector<int> nullCols;

  for (pairVector::iterator i = zeros.begin(); i != zeros.end(); ++i) {
    vector<int>::iterator it;

    it = find(nullRows.begin(), nullRows.end(), i->first);
    if (it == nullRows.end())
      nullRows.push_back(i->first);

    it = find(nullCols.begin(), nullCols.end(), i->second);
    if (it == nullCols.end())
      nullCols.push_back(i->second);
  }

  for (vector<int>::iterator i = nullRows.begin(); i != nullRows.end(); ++i)
    nullifyRow(matrix, *i, N);

  for (vector<int>::iterator i = nullCols.begin(); i != nullCols.end(); ++i)
    nullifyCol(matrix, *i, M);

  printMatrix(matrix, M, N);

  return 0;
}


pairVector findZeros(vector< vector<int> > &matrix, int M, int N) {
  pairVector zeros;

  for (int i = 0; i < M; ++i)
    for (int j = 0; j < N; ++j)
      if (matrix[i][j] == 0)
        zeros.push_back(std::make_pair(i, j));

  return zeros;
}

void nullifyRow(vector< vector<int> > &matrix, int rowNumber, int colSize) {
  for (int i = 0; i < colSize; ++i)
    matrix[rowNumber][i] = 0;
}

void nullifyCol(vector< vector<int> > &matrix, int colNumber, int rowSize) {
  for (int i = 0; i < rowSize; ++i)
    matrix[i][colNumber] = 0;
}


void printMatrix(vector< vector<int> > &matrix, int M, int N) {

  for (int i = 0; i < M; ++i) {
    cout << "\n" << endl;

    for (int j = 0; j < N; ++j) {
      cout << matrix[i][j] << "\t";
      if (i == M-1 && j == N-1)
        cout << "\n" << endl;
    }
  }

}
