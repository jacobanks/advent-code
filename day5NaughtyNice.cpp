#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

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

    if (inputs[i].find("ab") != string::npos ||
        inputs[i].find("cd") != string::npos||
        inputs[i].find("pq") != string::npos ||
        inputs[i].find("xy") != string::npos) {
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
  vector<string> input;
  ifstream in("day5Input.txt");
  string line;

  while(getline(in, line)) {
    input.push_back(line);
  }

  cout << "There are " << naughtyOrNice(input) << " nice strings" << endl;


  return 0;
}
