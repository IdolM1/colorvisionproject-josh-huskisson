#ifndef COLOR_H //Pre-processor directives
#define COLOR_H
#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;


class color{
  private:
    string hexCode;
    string red;
    string green;
    string blue;

  public:

  color();

  
  color(string code):hexCode{code}{
  red = "00";
  green = "00";
  blue = "00";
  //Setting the first two characters of the hex color string to the "red" variable
  red[0] = hexCode[0];
  red[1] = hexCode[1];
  //Setting the next two characters to the "green" variable
  green[0] = hexCode[2];
  green[1] = hexCode[3];
  //Setting the last two characters to the "blue" variable
  blue[0] = hexCode[4];
  blue[1] = hexCode[5];
  //This works because of how hex values show rgb values. 
  //For example if the hex color code is "abcdef"
    //the red portion will be "ab", the green portion will be "cd" and the blue portion will be "ef"
  }

  void printColor();

  void checkRed();
  void checkGreen();
  void checkBlue();
  string giveHex();

};

#endif