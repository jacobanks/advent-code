#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

int getSquareFeet(int length, int width, int height) {
  // find square feet of box
  int squareFeet = (2 * (length * width)) + (2 * (width * height)) + (2 * (height *length));

  // find the smallest side
  int side1 = length * width;
  int side2 = width * height;
  int side3 = height * length;

  int smallestSideArea = side1;

  if(side2 < smallestSideArea) {
    smallestSideArea = side2;
  }
  if(side3 < smallestSideArea) {
    smallestSideArea = side3;
  }

  return squareFeet + smallestSideArea;
}

int getRibbonLength(int length, int width, int height) {
  int totalRibbon = 0;
  int ribbonForBow;
  int ribbonToWrap;

  ribbonForBow = length * width * height;

  if (length > width) {
    swap(length, width);
  }
  if (length > height) {
    swap(length, height);
  }
  if (width > height) {
    swap(width, height);
  }

  ribbonToWrap = (2 * length) + (2 * width);
  totalRibbon = ribbonToWrap + ribbonForBow;

  return totalRibbon;
}

vector<string>& split(const string& s, char delim, vector<string>& elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
      elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string& s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main() {
  ifstream ifs("day2Dimensions.txt");
  string input;
  vector<string> parsedInput;
  int l, w, h, surfaceArea, ribbonLength;
  int totalWrappingPaper = 0;
  int totalRibbonLength = 0;

  while(getline(ifs, input)) {
    parsedInput = split(input, 'x');
    l = stoi(parsedInput.at(0));
    w = stoi(parsedInput.at(1));
    h = stoi(parsedInput.at(2));

    surfaceArea = getSquareFeet(l, w, h);
    totalWrappingPaper += surfaceArea;

    ribbonLength = getRibbonLength(l, w, h);
    totalRibbonLength += ribbonLength;
  }

  cout << "Total wrapping paper: " << totalWrappingPaper << " feet." << endl;
  cout << "Total ribbon length: " << totalRibbonLength << " feet." << endl;

}
