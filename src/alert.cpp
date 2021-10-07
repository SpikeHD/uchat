#include <string>

using namespace std;

string boxify(string content, string title = "") {
  int len = content.length();
  string output = "";
  
  if (title.length() == 0) {
    output += "+" + string(len-4, '=') + "+\n";
  } else {
    output += "+= " + title + " " + string(len-1-title.length(), '=') + "+\n";
  }

  output += "| " + content + " |\n";
  output += "+" + string(len+2, '=') + "+\n";

  return output;
}