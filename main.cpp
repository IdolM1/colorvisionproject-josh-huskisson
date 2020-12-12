#include <iostream>
#include <fstream>
#include <vector>
#include "color.h"

using namespace std;

void isHexCode(vector <string> &);
void deleteRepeats(vector <string> &);
void convertToSix(vector <string> &);
vector <int> convertToInt(vector <string>);

int main()
{
  fstream reader;
  int index = 0;
  char yesNo;
  ofstream writeFile;
  string line;
  char character;
  int number;
  string colorCode = "aaaaaa";
  vector <string> hexValues;
  vector <int> intHexValues;
  vector <color> colorInfo;

  reader.open("csuchico.html", ios::in);
  if(reader.is_open() == true){
    while(reader.eof() == false){
      reader >> line;
      for(int i=0; i < line.length(); i++){
        char current = line[i];
        //going through each character in the line looking for '#'
        if(current == '#'){
          //grabbing the whole 6 digit hex code
          for(int j=1; j <= 7; j++){
            //checking if each character is a character that could be in a hex code
              //I'm using ASCII values here in place of actual letters
              //Link to ASCII table of values: http://www.asciitable.com/
            if((line[j+i] >= 48 && line[j+i] <= 57) || (line[j+i] >= 65 && line[j+i] <=70) || (line[j+i] >= 97 && line[j+i] <= 102)){
              colorCode[j-1] = line[j+i];
            }
            //otherwise it will turn the character into a ' '
            else{
              colorCode[j-1] = ' ';
            }
          }
          //if a hex code has a space in it, turn the remaining characters after the space 
          //into spaces
          for(int counter = 0; counter < colorCode.length(); counter++){
            if(colorCode[counter] == ' '){
              colorCode[counter+1] = ' ';
            }
          } 
          hexValues.push_back(colorCode);
        }
      }
    }
  }
  else{
    cout << "Error in Opening File.";
  }
  reader.close();

  isHexCode(hexValues); //Checks to see if color code is hex
  convertToSix(hexValues); //Converts color codes to 6 characters
  deleteRepeats(hexValues); //Deletes repeated codes
  //Puts each hex code into a vector of the color class
  for (int i = 0; i < hexValues.size(); i++){
    color newColor{hexValues[i]};
    colorInfo.push_back(newColor);
  }
  cout << "Displaying colors from csuchico.html:" << endl;
  do{
    color currentColor = colorInfo[index];
    colorInfo[index].printColor();
    colorInfo[index].checkRed();
    colorInfo[index].checkGreen();
    colorInfo[index].checkBlue();

    do{
      cout << "Would you like to store this number? (y or n) ";
      cin >> yesNo;
    }while(yesNo != 'y' && yesNo != 'n');

    if(yesNo == 'y') 
    {
      writeFile.open("storedColors.txt", ios::app);
      writeFile << colorInfo[index].giveHex() << endl; //Stores colors in file storedColors.txt
      writeFile.close();
    }
    do{
    cout << "Do you want to go to the next color? (y or n) ";
    cin >> yesNo;
    }while(yesNo != 'y' && yesNo != 'n');
    index++;
  }while(yesNo == 'y' && index != colorInfo.size());

  return 0;
}

//Functions start here

//Checks to see if color code is HEX
void isHexCode(vector <string> & colorCodes){  
  string currentCode;
  char currentCharacter;
  
  
  //starting from the back, go through each element in the vector
  for(int i = colorCodes.size() - 1; i >= 0 ; i--){
    currentCode = colorCodes[i];
    int counter = 0;
    for(int j = 0; j < currentCode.length(); j++){
      currentCharacter = currentCode[j];
      if(currentCharacter == ' '){  //checking to see how many spaces are in the element
        counter++;
      }
    }
    if(counter > 3){ //Deletes element in vector if the spaces are more than 3
      colorCodes.erase(colorCodes.begin()+i);
    }
  }
}

void deleteRepeats(vector <string> & list){
  string element;
  string checkElement;
  

  //cycle through vector
  for(int i = 0; i < list.size(); i++){
    element = list[i];
    //cycle through vector from the bottom and check if each element matches the element 
    //from the loop above
    for(int j = list.size() - 1; j >= i + 1; j--){
      checkElement = list[j];
      if(checkElement == element){
        list.erase(list.begin() + j);
      }
    }

  }
}

//Converting the three and four digit hex codes to six digit hex codes
void convertToSix(vector <string> & list){
  string element;
  char currentCharacter;
  char firstCharacter;
  char secondCharacter;
  char thirdCharacter;
  int counter;

  for(int i = 0; i < list.size(); i++){
    element = list[i];
    counter = 0;
    for(int j = 0; j < element.length(); j++){
      currentCharacter = element[j];
      if(currentCharacter == ' '){
        counter++;
        
      }
      //checking if the hex code is 3 or 4 by counting how many spaces it has
      if(counter >= 2){
        firstCharacter = element[0];
        secondCharacter = element[1];
        thirdCharacter = element[2];
        element[0] = firstCharacter;
        element[1] = firstCharacter;
        element[2] = secondCharacter;
        element[3] = secondCharacter;
        element[4] = thirdCharacter;
        element[5] = thirdCharacter;
        list[i] = element;
        j = element.length(); //makes sure that the hex code doesn't go through twice
      }
    }
  }
  
}

vector <int> convertToInt(vector <string> list){
  string currentString; 
  vector <int> newVector;
  int counter = 0;

  for(int i = 0; i < list.size(); i++){
    newVector.push_back(1);
  }
  for(int i = 0; i < list.size(); i++){
    currentString = list[i];
    newVector[i] = stoi(currentString, 0, 16);
  }
  return newVector;
}