# IFRSLib
Didactic library in C for input/output processing and data structures handling. 
The library was designed with the need to facilitate the use of ANSI C language in simple systems and academic algorithms.

# ifrs_io.h
# Functions
## Reading functions
### - readTYPE function
The functions "readTYPE" changes the content of a variables by reference using pointers.
You can use a header text to guide the user and an error message if necessary.

```C
//   readTYPE(&VARIABLE_ADDRESS, OPTIONAL_HEADER_MESSAGE, OPTIONAL_ERROR_MESSAGE);
void readShort(short *variableAddress, char headerMessage[], char errorMessage[]);
void readInt(int *variableAddress, char headerMessage[], char errorMessage[]);
void readLong(long *variableAddress, char headerMessage[], char errorMessage[]);
void readFloat(float *variableAddress, char headerMessage[], char errorMessage[]);
void readDouble(double *variableAddress, char headerMessage[], char errorMessage[]);
//   readChar(&VARIABLE_ADDRESS, OPTIONAL_HEADER_MESSAGE);
void readChar(char *variableAddress, char headerMessage[]);
//   readString(&VARIABLE_ADDRESS, STRING_LENGTH, OPTIONAL_ERROR_MESSAGE);
void readString(char *variableAddress, int stringLength, char headerMessage[]);
```

## Example

```C
int value = 0;
readInt(&value);
```
- Input: 40 (Example)
```C
int value = 0;
readInt(&value, "Enter an integer:");
```
- Output: Enter an integer:
- Input: 40 (Example)
```C
int value = 0;
readInt(&value, "Enter an integer:", "Ops! Only integer values."); 
```
- Output: Enter an integer:
- Input: 40.3 (Example)
- Output: Ops! Only integer values.
- Output: Enter an integer:

### - readTYPERet function - DEPRECATED
The functions "readTYPERet" creates a variable with the inputted value and returns it.

## Writing functions
### - printTYPE function
The functions "print TYPE" prints the variable sent with a header.

```C
//   printInt(HEADER_MESSAGE, VARIABLE);
void printInt(char headerMessage[], int value);
void printLong(char headerMessage[], long value);
void printShort(char headerMessage[], short value);
void printDouble(char headerMessage[], double value);
void printFloat(char headerMessage[], float value);
void printChar(char headerMessage[], char value);
void printString(char headerMessage[], char value[]);
```

## Structures
### - Scanner 
Scanner is a data structure for data input like Scanner of the Java Language.
Available functions:
- nextInt (Returns int)
- nextLong (Returns long)
- nextFloat (Returns float)
- nextChar (Returns char)
- nextCharArray(size) (Returns char[])
 
## Example
```C
Scanner input = newScanner();
int value = input.nextInt();
```
- Input: 40 (Example)

### - String 
String implementation using struct.
C is a procedural language, although there is the possibility of object orientation in ANSI C, it was not built for this. The current implementation provides to programmer a more pleasant visual to use a struct, but some problems remain, for example the need to send the struct address for the function to be perfomed.
 
## Example
```C
String str = newString();
str.value = "Some text";
printf("%s", str.subString(&str, 0,2));
printf("%s\n", str.upperCase(&str));
printf("%s\n", str.lowerCase(&str));
printf("Size: %d", str.length(&str));
```
- Output: So
- Output: SOME TEXT
- Output: some text
- Output: Size: 9
