#include <iostream>
#include <string>

#include "helpers.h"
#include "alert.h"

using namespace std;

int handleMessage() {
  string m;

  cout << "> ";

  cin >> m;
}

int main() {
  bool quit = false;

  // Clear out the console
  clear();

  cout << "Welcome to uChat! I hope you enjoy your stay." << endl << endl;;
  cout << boxify("You are currently in a room by yourself. Use /help for information.", "Alert") << endl;

  while(!quit) {
    handleMessage();
  }
}