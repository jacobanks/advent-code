#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int naughtyOrNice(vector<string> inputs) {
  int totalNice = 0;
  int totalNaughty = 0;

  for(int i = 0; i < inputs.size(); i++) {
    int vowelCount = 0;
    char prevLetter;
    bool hasDoubleLetters = false;
    bool hasBadStrings = false;

    for (int j = 0; j < inputs[i].length(); j++) {
      char c = inputs[i][j];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        vowelCount++;
      }

      if (c == prevLetter) {
        hasDoubleLetters = true;
      }
      prevLetter = c;
    }

    if (inputs[i].find("ab") ||
        inputs[i].find("cd") ||
        inputs[i].find("pq") ||
        inputs[i].find("xy")) {
      hasBadStrings = true;
    }

    if (vowelCount >= 3 && hasDoubleLetters == true && hasBadStrings == false) {
      totalNice++;
    } else {
      totalNaughty++;
    }
  }

  return totalNice;
}

int main() {
  vector<string> v;
  v.push_back("jchzalrnumimnmhp");
  cout << naughtyOrNice(v) << endl;
  return 0;
}
