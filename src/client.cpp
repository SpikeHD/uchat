#include <iostream>
#include <string>

#include "helpers.h"
#include "alert.h"
#include "chat_commands.h"
#include "config.h"

using namespace std;

int handleMessage() {
  string name = cnfGet("name");
  string m;

  cout << name << " > ";

  getline(cin, m);

  // If it starts with a slash, it's a command
  if (m.substr(0, 1) == "/") {
    handle(m);
  }
}

int main() {
  bool quit = false;
  string name = "NULL";

  // Clear out the console
  clear();

  // First-time setup
  if (!cnfExists()) {
    cout << "Performing first-time setup..." << endl;
    firstTime();
  }

  cout << "Welcome to uChat! I hope you enjoy your stay." << endl << endl;;
  cout << boxify("You are currently in a room by yourself. Use /help for information.", "Alert") << endl;

  while(!quit) {
    handleMessage();
  }

  return 0;
}