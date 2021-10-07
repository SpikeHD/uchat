#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

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

map<string, string> cnfParse(string cnf) {
  map<string, string> kvPairs;
  string line;
  istringstream ss(cnf);

  while (getline(ss, line)) {
    kvPairs[line.substr(0, line.find("="))] = line.substr(line.find("=")+1, line.length());
  }

  // Parse cnf into key-value pairs
  return kvPairs;
}

string cnfGet(string key) {
  ifstream cnf(confDir);
  string content((istreambuf_iterator<char>(cnf)), istreambuf_iterator<char>());

  map<string, string> kvPairs = cnfParse(content);

  if (kvPairs.find(key) == kvPairs.end()) return "null";

  return kvPairs.find(key)->second;
}

string cnfSet(string key, string value) {

}