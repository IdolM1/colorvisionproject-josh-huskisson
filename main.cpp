#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  int usersColor = 0x000000;
  int noRed;
  int noGreen;
  char yesNo;
  ofstream writeFile;
  
  do{
    do{
      cout << "What color are you using (in hexadecimal)? ";
      cin >> hex >> usersColor;
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
    cout << "Do you want to input another color? (y or n) ";
    cin >> yesNo;

  }while(yesNo == 'y');
  
  
  return 0;
}
