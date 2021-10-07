#include <iostream>
#include <string>

using namespace std;

void help() {
  cout << "Nobody can help you now..." << endl;
}

void handle(string command) {
  string c = command.substr(1, command.length());

  // Ugly ifs ahead. Sorry.
  if (c == "help") help();
}