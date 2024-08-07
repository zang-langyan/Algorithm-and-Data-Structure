#include <iostream>
#include <vector>

using namespace std;

vector<int> kmp_table(string& pat){
  int m = pat.length();
  vector<int> lps(m);

  int i = 1, len = 0;
  while (i < m){
    if (pat[i] == pat[len]){
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len){
        len = lps[len-1];
      } else {
        i++;
      }
    }
  }
  return lps;
}

vector<int> kmp(string& pat, string& txt){
  int m = pat.length(), n = txt.length();
  int i = 0, j = 0;
  vector<int> ans;

  vector<int> kmpT = kmp_table(pat);
  while (i < n){
    if (txt[i] == pat[j]){
      i++;
      j++;
    }
    if (j == m){
      ans.push_back(i-j);
      j = kmpT[j-1];
    } else if (i < n && txt[i] != pat[j]) {
      if (j){
        j = kmpT[j-1];
      } else {
        i++;
      }
    }
  }
  return ans;
}


int main(){
  string pat = "ABC", txt = "ABCCABC";
  vector<int> idx = kmp(pat, txt);
  int m = pat.length();
  for (auto& i: idx){
    cout << "index: " << i << "->" << txt.substr(i, m) << endl;
  }
}
