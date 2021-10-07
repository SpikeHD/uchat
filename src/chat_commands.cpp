#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> getArgs(string c) {
  vector<string> arr;
  stringstream ss (c);
  string item;

  // https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
  while (getline(ss, item, ' ')) {
    arr.push_back (item);
  }

  return arr;
}


void help() {
  cout << "Nobody can help you now..." << endl;
}

void handle(string command) {
  vector<string> args = getArgs(command);
  string c = args.front().substr(1, args.front().length());

  // Ugly ifs ahead. Sorry.
  if (c == "help") help();
}