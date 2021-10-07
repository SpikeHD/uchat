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

  // Split the string from the key=value format
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

  // Check if the value exists
  if (kvPairs.find(key) == kvPairs.end()) return "null";

  return kvPairs.find(key)->second;
}

void cnfSet(string key, string value) {
  fstream cnf(confDir, std::ofstream::out | std::ofstream::trunc);
  map<string, string>::iterator it;

  string content((istreambuf_iterator<char>(cnf)), istreambuf_iterator<char>());
  map<string, string> kvPairs = cnfParse(content);

  cout << "content: " << content << endl;
  cout << "key: " << key << endl;
  cout << "value: " << value << endl;

  // Set the new value
  kvPairs.insert({ key, value });

  cout << "made it this far" << endl;

  for (it = kvPairs.begin(); it != kvPairs.end(); it++) {
    cnf << it->first << "=" << it->second << endl;
  }

  cnf.close();
}