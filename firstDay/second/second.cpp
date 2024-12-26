#include <bits/stdc++.h>

using namespace std;

int main(){
  ifstream f("input.txt");

  if(!f.is_open()){
    cerr<<"Error opening the file!";
    return 1;
  }
  string s;
  vector<string> input;
  vector<vector<int>> trimmed;
  while(getline(f,s)){
    input.push_back(s);
  }
  // for(auto str:input){
  //   cout<<str.size()<<endl;
  // }
  // string first_f = input[0];
  // cout<<first_f<<endl;
  input.pop_back();
  for(auto str:input){
    string l,r;
    for(int i = 0;i<str.size();i++){
      if(i<5){
        l+=str[i];
      }
      else if(i>7){
        r+=str[i];
      }
      else continue;
    }
    vector<int> temp;
    temp.push_back(stoi(l));
    temp.push_back(stoi(r));
    // cout<<"left: "<<temp[0]<<" right: "<<temp[1]<<endl;
    trimmed.push_back(temp);
    l.clear();
    r.clear();
  }
  vector<int> left,right;
  for(auto v:trimmed){
    left.push_back(v[0]);
    right.push_back(v[1]);
  }
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());
  // for(auto l:left){
  //   cout<<l<<endl;
  // }
  int n = left.size();
  int sum = 0;
  map<int,int> mp;
  for(auto r:right){
    mp[r]++;
  }
  for(auto m: mp){
    cout<<m.first<<": "<<m.second<<endl;
  }
  for(auto l:left){
    sum += mp[l] * l; 
  }
  cout<<sum;
  // int sum = 0;
  // for(int i = 0;i<n;i++){
  //   sum+= abs(left[i] - right[i]);
  // }
  // cout<<"sum : "<<sum<<endl;
  f.close();
  return 0;
}

