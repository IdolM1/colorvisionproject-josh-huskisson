#include "color.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

color::color(){
  string hexCode = "000000";
  string red = "00";
  string green = "00";
  string blue = "00";
  cout << hexCode << endl;
}

void color::printColor(){
  cout << hexCode << endl;
}
//Checks to see if the red portion is greater than 0 indicating there is red in the color
void color::checkRed(){
  int intRed = stoi(red,0,16);
  if(intRed > 0){
    cout << "This color has red in it." << endl;
  }
}
//Checks to see if the green portion is greater than 0 indicating there is green in the color
void color::checkGreen(){
  int intGreen = stoi(green,0,16);
  if(intGreen > 0){
    cout << "This color has green in it." << endl;
  }
}
//Checks to see if the blue portion is greater than 0 indicating there is blue in the color
void color::checkBlue(){
  int intBlue = stoi(blue,0,16);
  if(intBlue > 0){
    cout << "This color has blue in it." << endl;
  }
}

string color::giveHex(){
  return hexCode;
}