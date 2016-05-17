#ifdef __MINGW32__
	#define scanf_function scanf
	#define clStdin fflush(stdin)
#else
	#ifdef _MSC_VER
		#define scanf_function scanf_s
		#define clStdin fflush(stdin)
	#else
		#include <stdio_ext.h>
		#define scanf_function scanf
		#define clStdin __fpurge(stdin)
	#endif
#endif

#include <stdbool.h>

#define MAX_STACK_LEN 10

struct StackArray;

typedef struct {
	int top;
	int stackArray[MAX_STACK_LEN + 1];
	bool(*push)(struct Stack *, int);
	int(*pop)(struct Stack *);
	int(*getValue)(struct Stack *);
	bool(*isEmpty)(struct Stack *);
	bool(*isFull)(struct Stack *);
} StackArray;

StackArray newStackArray();

#define MAX_QUEUE_LEN 10

struct QueueArray;

typedef struct {
	int queueArray[MAX_QUEUE_LEN + 1];
	int front;
	int back;
	bool(*enqueue)(struct Queue *, int);
	int(*dequeue)(struct Queue *);
	int(*lastItem)(struct Queue *);
	int(*firstItem)(struct Queue *);
	bool(*isEmpty)(struct Queue *);
	bool(*isFull)(struct Queue *);
} QueueArray;

QueueArray newQueueArray();

#define MAX_ORDERED_LIST_LEN 10

struct OrderedList;

typedef struct {
	int orderedListArray[MAX_ORDERED_LIST_LEN];
	int endIndex;
	bool(*insert)(struct OrderedList *, int);
	bool(*remove)(struct OrderedList *, int);
	bool(*removeAtIndex)(struct OrderedList *, int);
	int(*getItem)(struct OrderedList *, int);
	int(*lastItem)(struct OrderedList *);
	int(*firstItem)(struct OrderedList *);
	bool(*isEmpty)(struct OrderedList *);
	bool(*isFull)(struct OrderedList *);
	int(*itemAmount)(struct OrderedList *);
} OrderedList;

OrderedList newOrderedList();

struct Node;

typedef struct {
	int data;
	struct Node* next;
} Node;

struct OrderedLinkedList;

typedef struct {
	struct Node* start;
	void(*insert)(struct OrderedLinkedList*, int);
	bool(*remove)(struct OrderedLinkedList*, int);
	bool(*removeAtIndex)(struct OrderedLinkedList *, int);
	int(*getItem)(struct OrderedLinkedList *, int);
	int(*lastItem)(struct OrderedLinkedList *);
	int(*firstItem)(struct OrderedLinkedList *);
	bool(*isEmpty)(struct OrderedLinkedList*);
	int(*itemAmount)(struct OrderedLinkedList *);
	void(*clear)(struct OrderedLinkedList *);
} OrderedLinkedList;

OrderedLinkedList newOrderedLinkedList();

struct DNode;

typedef struct {
	struct DNode* previous;
	int data;
	struct DNode* next;
} DNode;

struct OrderedDoublyLinkedList;

typedef struct {
	struct DNode* start;
	void(*insert)(struct OrderedDoublyLinkedList*, int);
	bool(*remove)(struct OrderedDoublyLinkedList*, int);
	bool(*removeAtIndex)(struct OrderedDoublyLinkedList *, int);
	int(*getItem)(struct OrderedDoublyLinkedList *, int);
	int(*lastItem)(struct OrderedDoublyLinkedList *);
	int(*firstItem)(struct OrderedDoublyLinkedList *);
	bool(*isEmpty)(struct OrderedDoublyLinkedList*);
	int(*itemAmount)(struct OrderedDoublyLinkedList *);
	void(*clear)(struct OrderedDoublyLinkedList *);
} OrderedDoublyLinkedList;

OrderedDoublyLinkedList newOrderedDoublyLinkedList();

struct TNode;

typedef struct {
	struct TNode* left;
	int data;
	struct TNode* right;
} TNode;

struct BinaryTree;

typedef struct {
	struct TNode* root;
	void(*insert)(struct BinaryTree*, int);
	bool(*remove)(struct BinaryTree*, int);
	bool(*isEmpty)(struct BinaryTree*);
	int(*height)(struct BinaryTree*);
	int(*itemAmount)(struct BinaryTree *);
	int(*lowerValue)(struct BinaryTree*);
	int(*higherValue)(struct BinaryTree*);
	void(*clear)(struct BinaryTree *);
	void(*printInPreOrder)(struct BinaryTree *);
	void(*printInPostOrder)(struct BinaryTree *);
	void(*printInOrder)(struct BinaryTree *);
	void(*printPerLevel)(struct BinaryTree *);
} BinaryTree;

BinaryTree newBinaryTree();

struct RBTNode;

#define colorFlag char
#define red 'r'
#define black 'b'

typedef struct {
	struct RBTNode* parent;
	struct RBTNode* left;
	int data;
	colorFlag color;
	struct RBTNode* right;
} RBTNode;

struct RedBlackTree;

typedef struct {
	struct RBTNode* root;
	void(*insert)(struct RedBlackTree*, int);
	bool(*remove)(struct RedBlackTree*, int);
	bool(*isEmpty)(struct RedBlackTree*);
	int(*height)(struct RedBlackTree*);
	int(*itemAmount)(struct RedBlackTree *);
	int(*lowerValue)(struct RedBlackTree*);
	int(*higherValue)(struct RedBlackTree*);
	void(*clear)(struct RedBlackTree *);
	void(*printInPreOrder)(struct RedBlackTree *);
	void(*printInPostOrder)(struct RedBlackTree *);
	void(*printInOrder)(struct RedBlackTree *);
	void(*printPerLevel)(struct RedBlackTree *);
} RedBlackTree;

RedBlackTree newRedBlackTree();