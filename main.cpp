#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void getRGBinfo(vector <int>);
void isHexCode(vector <string> &);
void deleteRepeats(vector <string> &);
void convertToSix(vector <string> &);
vector <int> convertToInt(vector <string>);

int main()
{
  fstream reader;
  string line;
  char character;
  int number;
  string colorCode = "aaaaaa";
  vector <string> hexValues;
  vector <int> intHexValues;

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

  isHexCode(hexValues);
  deleteRepeats(hexValues);
  convertToSix(hexValues);
  intHexValues = convertToInt(hexValues);
  getRGBinfo(intHexValues);

  return 0;
}

void getRGBinfo(vector <int> colorCodes){

  int index = 0;
  int usersColor;
  int noRed;
  int noGreen;
  char yesNo;
  ofstream writeFile;
  
  
  do{
    usersColor = colorCodes[index];
    cout << hex << usersColor << endl;
    do{

      if(usersColor < 0 || usersColor > 0xFFFFFF)
      {
        cout << "Invalid hexadecimal value." << endl;
      }
    }while(usersColor < 0 || usersColor > 0xFFFFFF);


    if(usersColor >= 0x010000) //Checks for red in color
    {
      cout << "There is red in this color." << endl;
    }

    noRed = usersColor;
    if(usersColor >= 0x000100) //Checks for green in color
    {
      if(usersColor >= 0x010000) //Checks if color has red in it
      {
        do{ 
          noRed = noRed - 0x010000; //Subtracting all the red out of the color
        }while(noRed >= 0x010000);
      }
      if(noRed <= 0x00FFFF && noRed >= 0x000100) //Checks redless color for green
      {
      cout << "There is green in this color." << endl;
      }
    }

    if(noRed >= 0x000100) 
    {
      noGreen = noRed;
      do{
          noGreen = noGreen - 0x000100; //Subtracts all the green out of the color

      }while(noGreen >= 0x000100); 
    }
    else
    {
      noGreen = noRed;
    }
    if(noGreen > 0x000000) //Checks if there is blue in the green-less color
      {
        cout << "There is blue in this color." << endl;
      }
    
    
    cout << "Would you like to store this number? (y or n) ";
    cin >> yesNo;
    if(yesNo == 'y') 
    {
      writeFile.open("storedColors.txt", ios::app);
      writeFile << hex << usersColor << endl; //Stores colors in file storedColors.txt
      writeFile.close();
    }
    cout << "Do you want to go to the next color? (y or n) ";
    cin >> yesNo;
    index++;
  }while(yesNo == 'y' && index != colorCodes.size());

}

void isHexCode(vector <string> & colorCodes){ //Checks to see if color code is HEX 
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