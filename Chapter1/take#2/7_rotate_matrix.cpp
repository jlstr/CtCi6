#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(std::vector< std::vector<int> >&, const int);
void printMatrix(std::vector< std::vector<int> >&);

int main() {

  // std::vector< std::vector<int> > matrix(3, std::vector<int>(3, 0)); // 3 x 3
  std::vector< std::vector<int> > matrix(3, std::vector<int>(3)); // 3 x 3
  static const int r1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  matrix[0].assign(r1, r1 + 3);
  matrix[1].assign(r1 + 3, r1 + 6);
  matrix[2].assign(r1 + 6, r1 + 9);

  printMatrix(matrix);
  cout << endl;

  rotateMatrix(matrix, 3);
  rotateMatrix(matrix, 3);
  rotateMatrix(matrix, 3);
  rotateMatrix(matrix, 3);

  printMatrix(matrix);
  cout << endl;

  return 0;
}

void rotateMatrix(std::vector< std::vector<int> > &matrix, const int N) {
  std::vector< std::vector<int> > newMatrix(N, std::vector<int>(N));

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      newMatrix[i][(N-1) - j] = matrix[j][i];

  matrix = newMatrix;
}

void printMatrix(std::vector< std::vector<int> > &matrix) {
  for (std::vector< std::vector<int> >::iterator i = matrix.begin(); i != matrix.end(); ++i) {
    for (std::vector<int>::iterator j = i->begin(); j != i->end(); ++j) {
      cout << *j << "\t";
    }
    cout << endl;
  }
}
