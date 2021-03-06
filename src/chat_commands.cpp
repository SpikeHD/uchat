#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "config.h"

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

void exit() {
  cout << "See you next time!" << endl;
  terminate();
}

void help() {
  cout << "Nobody can help you now..." << endl;
}

void setname(string name = "") {
  if (name.empty()) {
    cout << "Provide a name to set!" << endl;
    return;
  }

  cout << "Setting name to \"" << name << "\"..." << endl;

  cnfSet("name", name);
}

void handle(string command) {
  vector<string> args = getArgs(command);
  string c = args.front().substr(1, args.front().length());

  // Arg check!
  int totalArgs = args.size();

  // Ugly ifs ahead. Sorry.
  if (c == "exit") exit();  
  if (c == "help") help();

  if (totalArgs == 2) {
    if (c == "setname") setname(args[1]);
  }
}