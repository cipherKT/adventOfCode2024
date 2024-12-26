#include <bits/stdc++.h>
using namespace std;

bool is_increasing(const vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; i++) {
    if (v[i] > v[i + 1]) return false;
  }
  return true;
}

bool is_decreasing(const vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; i++) {
    if (v[i] < v[i + 1]) return false;
  }
  return true;
}

bool is_valid(const vector<int> &v) {
  int n = v.size();
  if (n < 2) return false; // No array is valid with fewer than 2 elements.

  bool is_inc = is_increasing(v);
  bool is_dec = is_decreasing(v);
  if (!is_inc && !is_dec) return false;

  for (int i = 0; i < n - 1; i++) {
    int diff = abs(v[i] - v[i + 1]);
    if (diff < 1 || diff > 3) return false;
  }
  return true;
}

int main() {
  ifstream f("input.txt");

  if (!f.is_open()) {
    cerr << "Error opening the file" << endl;
    return 1;
  }

  string s;
  vector<vector<int>> input;

  while (getline(f, s)) {
    stringstream ss(s);
    int num;
    vector<int> v;
    while (ss >> num) {
      v.push_back(num);
    }
    input.push_back(v);
  }

  if (input.empty()) {
    cout << "No data in the input file or incorrect format!" << endl;
    return 1;
  }

  // Print arrays
  for (const auto &temp : input) {
    for (auto i : temp) {
      cout << i << " ";
    }
    cout << endl;
  }

  // Answer to the first question
  int sum = 0;
  for (const auto &v : input) {
    if (is_valid(v)) sum++;
  }
  cout << "Answer to first question is: " << sum << endl;

  // Answer to the second question
  sum = 0;
  for (const auto &v : input) {
    if (is_valid(v)) {
      sum++;
    } else {
      for (int i = 0; i < v.size(); i++) {
        vector<int> temp = v;
        temp.erase(temp.begin() + i); // Remove one element
        if (is_valid(temp)) sum++;
      }
    }
  }
  cout << "Answer to second question is: " << sum << endl;

  return 0;
}

