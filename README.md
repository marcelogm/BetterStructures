
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

# ifrs_struct.h
# Structures
### How to use?
Declaring a new structure:
```C
NameOfStructure structure = newNameOfStructure();
```
Using a function:
```C
structure.function(&structure, args);
```
## Array implementation
## Stack
A stack is an abstract data type that serves as a collection of elements, with two principal operations: push, which adds an element to the collection, and pop, which removes the most recently added element that was not yet removed.
More about: https://www.cs.bu.edu/teaching/c/stack/array/

Available functions:
- push(self, int) (Returns bool)
- pop(self) (Returns int)
- getValue(self) (Returns int)
- isEmpty(self) (Returns bool)
- isFull(self) (Returns bool)

## Example
```C
StackArray stk = newStackArray();
stk.push(&stk, 15);
stk.push(&stk, 16);
printf("Value: %d", stk.pop(&stk));
```
- Output: Value: 16

## Queue
A queueis a particular kind of abstract data type or collection in which the entities in the collection are kept in order and the principal (or only) operations on the collection are the addition of entities to the rear terminal position, known as enqueue, and removal of entities from the front terminal position, known as dequeue.
More about: https://www.cs.bu.edu/teaching/c/queue/array/types.html

Available functions:
- enqueue(self, value) (Returns bool)
- dequeue(self) (Returns int)
- lastItem(self) (Returns int)
- firstItem(self) (Returns int)
- isEmpty(self) (Returns bool)
- isFull(self) (Returns bool)

## Example
```C
QueueArray que = newQueueArray();
que.enqueue(&que, 4);
que.enqueue(&que, 6);
printf("Value: %d", que.dequeue(&que));
```
- Output: Value: 4

## OrderedList
A list or sequence is an abstract data type that represents an ordered sequence of values, where the same value may occur more than once.
More about: https://courses.cs.vt.edu/~csonline/DataStructures/Lessons/OrderedListImplementationView/index.html

Available functions:
- insert(self, value) (Returns bool)
- remove(self, value) (Returns bool)
- removeAtIndex(self, index) (Returns bool)
- getItem(self, index) (Returns int)
- lastItem(self) (Returns int)
- firstItem(self) (Returns int)
- isEmpty(self) (Returns bool)
- isFull(self) (Returns bool)
- itemAmout(self) (Returns int)

## Example
```C
OrderedList OList = newOrderedList();
OList.insert(&OList, 15);
OList.insert(&OList, 16);
printf("Value: %d", OList.getItem(&OList, 1));
```
- Output: Value: 16

## Linked-List Implementation
## Stack
Soon.
## Queue
Soon.
## OrderedLinkedList / OrderedDoublyLinkedList
A linked list is a linear collection of data elements, called nodes pointing to the next node by means of a pointer. It is a data structure consisting of a group of nodes which together represent a sequence. 
More about: https://en.wikipedia.org/wiki/Linked_list

Available functions:
- insert(self, value) 
- remove(self, value) (Returns bool)
- removeAtIndex(self, index) (Returns bool)
- getItem(self, index) (Returns int)
- lastItem(self) (Returns int)
- firstItem(self) (Returns int)
- isEmpty(self) (Returns bool)
- itemAmout(self) (Returns int)
- clear(self)

## Example
```C
OrderedLinkedList OLList = newOrderedLinkedList();
OLList.insert(&OLList, 15);
OLList.insert(&OLList, 16);
printf("Value: %d", OLList.getItem(&OLList, 1));
```
- Output: Value: 16

## BinaryTree / RedBlackTree
A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child. 
More about: https://www.cs.cmu.edu/~adamchik/15-121/lectures/Trees/trees.html

RedBlackTree:
A red–black tree is a kind of self-balancing binary search tree. Each node of the binary tree has an extra bit, and that bit is often interpreted as the color (red or black) of the node. These color bits are used to ensure the tree remains approximately balanced during insertions and deletions.
More about: https://www.cs.cornell.edu/Courses/cs3110/2012sp/lectures/lec11-balanced-trees/lec11.html

Available functions:
- insert(self, value) 
- remove(self, value) (Returns bool)
- isEmpty(self) (Returns bool)
- height(self) (Returns int)
- itemAmount(self) (Returns int)
- lowerValue(self) (Returns int)
- higherValue(self) (Returns int)
- clear(self)
- printInPreOrder(self)
- printInPostOrder(self)
- printInOrder(self)
- printPerLevel(self)

## Example
```C
BinaryTree tree = newBinaryTree();
tree.insert(&tree, 15);
tree.insert(&tree, 16);
tree.printInOrder(&tree);
```
- Output: 15 16
