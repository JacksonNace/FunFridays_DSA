#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> decryptBombCode(vector<int>& code, int k) {
  int n = code.size();
  vector<int> decryptedCode(n, 0);

  if (k == 0) {
    return decryptedCode;
  }

  for (int i = 0; i < n; ++i) {
    int currentSum = 0;
    if (k > 0) {
      for (int j = 0; j < k; ++j) {
        currentSum += code[(i + 1 + j) % n];
      }
    } else {
      for (int j = 0; j < abs(k); ++j) {
        currentSum += code[(i - 1 - j + n) % n];
      }
    }
    decryptedCode[i] = currentSum;
  }

  return decryptedCode;
}


void printVector(const vector<int>& vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
    cout << vec[i] << " ";
  }
}

int main() {
  vector<int> code1 = {5, 7, 1, 4};
  int k1 = 3; 
  vector<int> result1 = decryptBombCode(code1, k1); 
  printVector(result1); 
  cout << endl;

  vector<int> code2 = {1, 2, 3, 4};
  int k2 = 0;
  vector<int> result2 = decryptBombCode(code2, k2);
  printVector(result2); 
  cout << endl;


  vector<int> code3 = {2, 4, 9, 3};
  int k3 = -2;
  vector<int> result3 = decryptBombCode(code3, k3);
  printVector(result3);
  cout << endl;

  return 0;
}