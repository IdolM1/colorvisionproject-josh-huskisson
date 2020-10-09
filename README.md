# What's In Your Color?

## Description

This program will take in a hexadecimal color code and tell you whether there is red, green, or blue in it.

## Developer

Josh Huskisson

## Example

To run the program, give the following commands:

```
g++ --std=c++11 main.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
What color are you using (in hexadecimal)? A1F358
There is red in this color.
There is green in this color.
This color has blue in it.
Would you like to store this number? (y or n) y
Do you want to input another color? (y or n) y
What color are you using (in hexadecimal)? FFFF00
There is red in this color.
There is green in this color.
Would you like to store this number? (y or n) n
Do you want to input another color? (y or n) n
```

## C++ Guide

### Variables and Data Types

```
int usersColor = 0x000000;
char yesNo;
```
The ```int``` variable type is used for storing numbers. In this program it will use the ```usersColor``` variable to store hexadecimal numbers. 
The ```char``` variable type is used for storing single characters. In this program it will get a 'y' or 'n' denoting whether the user is saying yes or no.

### Input and Output

```
cout << "What color are you using (in hexadecimal)? ";
cin >> hex >> usersColor;
```
Using ```cout``` the program can ask questions from the user and get their input using ```cin```. The ```cout``` can output variables and strings into the terminal for the user to see. This ```cin``` is taking the user's input and storing it into ```usersColor``` as a hex value.

### Decisions

```
if(usersColor >= 0x010000) //Checks for red in color
    {
      cout << "There is red in this color." << endl;
    }
```
The ```if``` statement is used when wanting to do something if the given condition is true. In this example, it is checking if the ```usersColor``` has red in it's hexadecimal value. It does this by checking if ```usersColor``` is greater than or equal to 0x010000 which is the smallest hexadecimal value to have red in it. Anything greater than or equal to 0x010000 will have red in it since the first two digits of the 6 digit hexadecimal value denotes the red amount in the color. 

```
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
```
Here I used an if-else statement. An if-else statement makes a decision where only one option can be done. If the initial ```if``` statement is true, it will skip the ```else``` statement. This was used because what the variable ```noGreen``` was equal to depended on what the variable ```noRed``` was equal to. Both of these conditions could not be true at the same time. 

### Iteration

```
do{ 
  noRed = noRed - 0x010000; //Subtracting all the red out of the color
}while(noRed >= 0x010000);
```
A do-while loop is used when you want to run the code inside at least once. In this case, I already knew that I would need to subtract from the color so I had it run at least once. If after subtracting there was still red in it, it would subtract again. This would continue until the first two digits of the 6-digit hexadecimal color value equals 0. 

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