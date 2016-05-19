# IFRSLib
Didactic library in C for input/output processing and data structures handling. 
# Examples
## ifrs_io.h
### Reading 
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

## ifrs_struct.h
### Binary Tree
```C
BinaryTree tree = newBinaryTree();
for(size_t i = 0; i < 10; i++)
  tree.insert(&tree, rand()%5);        // 0 - 4 randomized number
tree.printInOrder(&tree);
```
