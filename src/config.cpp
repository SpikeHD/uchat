#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#if defined (__WIN32__)
#define confDir "\%appdata\%/uchat/uchat.conf"
#else
#define confDir (string)getenv("HOME") + "/uchat.conf"
#endif

void firstTime() {
  cout << confDir << endl;
  ofstream cnf(confDir);

  cnf << "name=NewUser" << endl;

  cnf.close();
}

bool cnfExists() {
  ifstream cnf(confDir);

  return cnf.is_open();
}

vector<string, string> cnfParse(string cnf) {
  vector<string, string> kvPairs;
  string line;
  istringstream s(cnf);

  while (getline(s, line)) {
    cout << line << endl;
  }

  // Parse cnf into key-value pairs
  return kvPairs;
}

string cnfGet(string key) {
  ifstream cnf(confDir);
  string content((istreambuf_iterator<char>(cnf)), istreambuf_iterator<char>());

  vector<string, string> kvPairs = cnfParse(content);
}

string cnfSet(string key, string value) {

}