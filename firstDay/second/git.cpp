#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
  std::string word;
  std::ifstream stream;
  stream.open("input.txt");

  std::vector<int> first, second;

  unsigned int total{ 0 };
  unsigned int totalTwo{ 0 };
  int count{ 0 };

  while (stream >> word) {
    int num{ stoi(word) };

    if (count % 2 == 0)
      first.push_back(num);
    else
      second.push_back(num);

    count++;
  }

  std::sort(first.begin(), first.end());
  std::sort(second.begin(), second.end());

  for (int i{ 0 }; i < first.size(); i++) {
    total += abs(first[i] - second[i]);
  }

  // Second puzzle - two solutions
  // Less efficiet
  std::for_each(first.begin(), first.end(), [&](auto elem) {
    totalTwo += elem * std::count(second.begin(), second.end(), elem);
  });

  // More efficient
  std::unordered_map<int, int> counts;

  for (int num : second) {
    counts[num]++;
  }
  for(auto c: counts){
    cout<<c.first<<" "<<c.second<<endl;
  }

  for (int num : first) {
    totalTwo += num * counts[num];
  }
  std::cout<<totalTwo;
  return 0;
}
