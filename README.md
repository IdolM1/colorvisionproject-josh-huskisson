# What's In Your Color?

## Description

This program will take in a hexadecimal color code and tell you whether there is red, green, or blue in it.

# v0.2 Updates

This program finds the hexadecimal color codes in an HTML file(currently only searches through csuchico.html). Then, it will cycle through each color code and tell the user whether there is red, green, or blue in it.

# v1.0 Updates

Functionality has been maintained from the last update. Redefined how the hex color codes are checked for red, green, and blue through the use of classes.

## Developer

Josh Huskisson

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Displaying colors from csuchico.html:
960000
There is red in this color.
Would you like to store this number? (y or n) y
Do you want to go to the next color? (y or n) y
882211
There is red in this color.
There is green in this color.
There is blue in this color.
Would you like to store this number? (y or n) n
Do you want to go to the next color? (y or n) y
fae88a
There is red in this color.
There is green in this color.
There is blue in this color.
Would you like to store this number? (y or n) y
Do you want to go to the next color? (y or n) n
```

## C++ Guide

### Variables and Data Types

```
int usersColor = 0x000000;
char yesNo;
```
The `int` variable type is used for storing numbers. In this program it will use the ```usersColor``` variable to store hexadecimal numbers. 
The ```char``` variable type is used for storing single characters. In this program it will get a 'y' or 'n' denoting whether the user is saying yes or no.

### Input and Output

```
cout << "Would you like to store this number? (y or n) ";
cin >> yesNo;
```
Using ```cout``` the program can ask questions from the user and get their input using ```cin```. The ```cout``` can output variables and strings into the terminal for the user to see. This ```cin``` is taking the user's input and storing it into ```yesNo``` which will affect program later on.

### Decisions

```
if(intRed > 0){
    cout << "This color has red in it." << endl;
  }
```
The ```if``` statement is used when wanting to do something if the given condition is true. In this example, it is checking if the color has red in it's hexadecimal value. It does this by checking if the integer value of the red portion of the color is greater than 0 which indicates that there is red in it.

```
if((line[j+i] >= 48 && line[j+i] <= 57) || (line[j+i] >= 65 && line[j+i] <=70) || (line[j+i] >= 97 && line[j+i] <= 102)){
  colorCode[j-1] = line[j+i];
}
//otherwise it will turn the character into a ' '
else{
  colorCode[j-1] = ' ';
}
```
Here I used an if-else statement. An if-else statement makes a decision where only one option can be done. If the initial ```if``` statement is true, it will skip the ```else``` statement. This was used because I needed to check if the character was part of the hex code and if it wasn't, I needed to get rid of it. 

### Iteration

```
//Puts each hex code into a vector of the color class
for (int i = 0; i < hexValues.size(); i++){
  color newColor{hexValues[i]};
  colorInfo.push_back(newColor);
}
```
A for loop allows the code inside the block to run until while the condition is met. In this case I needed it to run as many times as the number of values inside the vector `hexValues`. This will allow me to iterate through each item in the vector. 

### File Input and Output

```
cout << "Would you like to store this number? (y or n) ";
cin >> yesNo;
if(yesNo == 'y') //Stores colors in file storedColors.txt
{
writeFile.open("storedColors.txt", ios::app);
writeFile << hex << usersColor << endl;
writeFile.close();
}
```
In this portion of the program it will input the ```usersColor``` into the storedColors.txt file. This will allow the user to look back through the color codes they have saved.

### Arrays/Vectors

```
vector <string> hexValues;
```
Vectors are used to store values of a certain data type. Individual elements in the vector can be called by using square brackets. Vectors can be resized throughout the program. An array can not be resized and the size must instead be defined at the start of the program. 
In this part of the code, the vector ```hexValues``` is defined to hold ```string``` values. The hexadecimal color codes are added to this vector and changed throughout the program. 

### Functions

```
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
```
Functions are used to complete repeated actions without needing to type the code out again and again. This allows the main function to stay neat and remain easy to read. It can return a value or not. It can take in a value or not. 
In this function, it has a return type of ```void``` which means that nothing will be returned. For it's parameters it takes a ```vector``` of ```strings``` and uses pass-by reference as indicated by the '&' sign. This means that it is giving the function the ```vector``` and the ability to change that ```vector``` permanently. This is useful because in this function I need it to get rid of the repeats in the ```vector``` of hexadecimal color codes. If the function did not have the '&' sign it would be pass by value which gives the function a copy of the input to use, but doesn't have the ability to change the original. 

### Classes

```
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
```

Classes are a way to create your own data type that is a combination of other data types. They use a `.h` file, which acts as an interface for the class, and a `.cpp` file, which holds most of the functionality of the class. There are private variables of the class which hold the data for the class. This can only be accessed through member functions which are created in the public variables section of the `.h` file and then the functionality is defined in the `.cpp` file. Here is a function below.

```
//Checks to see if the green portion is greater than 0 indicating there is green in the color
void color::checkGreen(){
  int intGreen = stoi(green,0,16);
  if(intGreen > 0){
    cout << "This color has green in it." << endl;
  }
}
```

It must be defined with `color::` before the name of the function so that the program knows which variables it's using. Then it can use all the private variable from the `.h` file.

```
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
```

The example above shows a constructor. A constructor can set inital values for the private variables in the class when a new variable of the class is made. This one shows an overloaded constructor where depending on what value is given from the program, it will set the private variables as something else. 

For this program I created a class that gives all the information I needed for each of the color codes. It holds the complete hex value as well as how much red, green, and blue is in it. Through using member functions I'm able to get the specific information I need for the color value I'm working with.