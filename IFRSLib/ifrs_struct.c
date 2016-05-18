#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ifrs_io.h"
#include "ifrs_struct.h"

//
// Data Structure functions
//

// DEPRECATED, FULLY DOCUMENTED
#pragma region Stack (Array implementation)
//
// StackArray
//

// DEFINITIONS
bool __stackAEmpty(StackArray *self);				// ===> stack.isEmpty(&stack);
bool __stackAFull(StackArray *self);				// ===> stack.isFull(&stack);
bool __stackAPush(StackArray *self, int value);			// ===> stack.push(&stack, 20);
int __stackAPop(StackArray *self);				// ===> stack.pop(&stack);
int __stackALastItem(StackArray *self);				// ===> stack.getValue(&stack); CAN CHANGE

//	__stackAEmpty(StackArray *self);
//
//	Using:
//	StackArray stack = newStackArray();
//	bool response = stack.isEmpty(&stack);
//
//	INPUT: 
//	StackArray *self as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of stack, if it's empty or not.
bool __stackAEmpty(StackArray *self) {
	if (self->top == 0) return true;
	else return false;
}

//	__stackAFull(StackArray *self);
//
//	Using:
//	StackArray stack = newStackArray();
//	bool response = stack.isFull(&stack);
//
//	INPUT: 
//	StackArray *self as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of stack, if it's full or not.
bool __stackAFull(StackArray *self) {
	if (self->top >= MAX_STACK_LEN) return true;
	else return false;
}

//	__stackAPush(StackArray *self, int value);
//
//	Using:
//	StackArray stack = newStackArray();
//	bool response = stack.push(&stack, 20);
//
//	INPUT: 
//	StackArray *self as self indicator.
//	int value as variable to be inserted in the stack.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Inserts a value to stack and returns the insertion result.
bool __stackAPush(StackArray *self, int value) {
	if (__stackAFull(self) == true) {
		printf("\nERRO: Stack Overflow\n");
		system("pause");
		return false;
	}
	else {
		self->top++;
		self->stackArray[self->top] = value;
		return true;
	}
}

//	__stackAPop(StackArray *self);
//
//	Using:
//	StackArray stack = newStackArray();
//	... 
//	int response = stack.pop(&stack);
//
//	INPUT: 
//	StackArray *self as self indicator.
//
//	OUTPUT:
//	Last inserted value in the stack. (FILO)
//	
//	Description:
//	Pops a value from stack and returns it
int __stackAPop(StackArray *self) {
	if (__stackAEmpty(self) == true) {
		printf("\nERRO: Stack Underflow\n");
		system("pause");
		return self->stackArray[self->top];
	}
	else {
		int temp = 0;
		temp = self->stackArray[self->top];
		self->stackArray[self->top] = 0;
		self->top--;
		return temp;
	}
}

//	__stackALastItem(StackArray *self);
//
//	Using:
//	StackArray stack = newStackArray();
//	... 
//	int response = stack.getValue(&stack);
//
//	INPUT: 
//	StackArray *self as self indicator.
//
//	OUTPUT:
//	Last inserted value in the stack. (FILO)
//	
//	Description:
//	Returns the last inserted value in stack.
int __stackALastItem(StackArray *self) {
	return self->stackArray[self->top];
}

//	newStackArray(void);
//
//	Using:
//	StackArray stack = newStackArray();
//
//	INPUT: 
//	Nothing
//
//	OUTUP:
//	StackArray self as a newly built structure.
//	
//	Description:
//	Construction function of structure.
StackArray newStackArray() {
	StackArray self;
	self.top = 0;
	self.stackArray[self.top] = -1;
	self.push = (void *)&__stackAPush;
	self.pop = (void *)&__stackAPop;
	// To be changed soon
	self.getValue = (void *)&__stackALastItem;
	// End to be
	self.isEmpty = (void *)&__stackAEmpty;
	self.isFull = (void *)&__stackAFull;
	return self;
}

#pragma endregion

// IMPLEMENTING
#pragma region Stack (Linked Node implementation)
	// TODO
#pragma endregion

// DEPRECATED, FULLY DOCUMENTED
#pragma region Queue (Array implementation)
//
// QueueArray
//

// DEFINITIONS
bool __queueAEmpty(QueueArray *self);					// ===> queue.isEmpty(&queue);
bool __queueAFull(QueueArray *self);					// ===> queue.isFull(&queue);
int __dequeueA(QueueArray *self);					// ===> queue.dequeue(&queue);
bool __enqueueA(QueueArray *self, int value);				// ===> queue.enqueue(&queue, 20);
int __queueALastItem(QueueArray *self);					// ===> queue.lastItem(&queue);
int __queueAFirstItem(QueueArray *self);				// ===> queue.firstItem(&queue);

//	__queueAEmpty(QueueArray *self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	bool response = queue.isEmpty(&queue);
//
//	INPUT: 
//	QueueArray *self as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of queue, if it's empty or not.
bool __queueAEmpty(QueueArray *self) {
	if (self->front == self->back) return true;
	else return false;
}

//	__queueAFull(QueueArray *self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	bool response = queue.isFull(&queue);
//
//	INPUT: 
//	QueueArray *self as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of queue, if it is full or not.
bool __queueAFull(QueueArray *self) {
	if ((self->front - self->back == 1) || ((self->back == MAX_QUEUE_LEN - 1) && (self->front == 0)))
		return true;
	return false;
}

//	__dequeueA(QueueArray *self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	... 
//	int response = queue.dequeue(&queue);
//
//	INPUT: 
//	QueueArray *self as self indicator.
//
//	OUTPUT:
//	First inserted value in the queue. (FIFO)
//	
//	Description:
//	Dequeue a value from queue and returns it.
int __dequeueA(QueueArray *self) {
	if (__queueAEmpty(self) != 1) {
		int value = self->queueArray[self->front];
		if (self->front == MAX_QUEUE_LEN - 1)	self->front = 0;
		else self->front++;
		return value;
	}
	else {
		printf("\nERRO: Queue Underflow\n");
		system("pause");
		return false;
	}
}

//	__enqueueA(QueueArray *self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	bool response = queue.enqueue(&queue, 20);
//
//	INPUT: 
//	QueueArray *self as self indicator.
//	int value as value to enqueue.
//	
//	OUTPUT:
//	true / false as response
//
//	Description:
//	Enqueue a value to queue and returns the insertion result.
bool __enqueueA(QueueArray *self, int value) {
	if (__queueAFull(self) != 1) {
		self->queueArray[self->back] = value;
		if (self->back == MAX_QUEUE_LEN - 1) self->back = 0;
		else self->back++;
		return true;
	}
	else {
		printf("\nERRO: Queue Overflow\n");
		system("pause");
		return false;
	}
}

//	__queueALastItem(QueueArray *self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	... 
//	int response = queue.lastItem(&queue);
//
//	INPUT: 
//	QueueArray *self as self indicator.
//
//	OUTUP:
//	Last inserted value in the queue. (FIFO)
//	
//	Description:
//  Returns the last inserted value
int __queueALastItem(QueueArray *self) {
	if (self->back == 0)
		return self->queueArray[MAX_QUEUE_LEN - 1];
	else
		return self->queueArray[self->back - 1];
}

//	__queueAFirstItem(QueueArray *self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	... 
//	int response = queue.firstItem(&queue);
//
//	INPUT: 
//	QueueArray *self as self indicator.
//
//	OUTUP:
//	First inserted value in the queue. (FIFO)
//	
//	Description:
//  Returns the first inserted value
int __queueAFirstItem(QueueArray *self) {
	return self->queueArray[self->front];
}

//	newQueueArray(void);
//
//	Using:
//	QueueArray queue = newQueueArray();
//
//	INPUT: 
//	Nothing
//
//	OUTUP:
//	QueueArray self as a newly built structure.
//	
//	Description:
//	Construction function of structure.
QueueArray newQueueArray() {
	QueueArray self;
	self.front = 0;
	self.back = 0;
	self.enqueue = (void *)&__enqueueA;
	self.dequeue = (void *)&__dequeueA;
	self.lastItem = (void *)&__queueALastItem;
	self.firstItem = (void *)&__queueAFirstItem;
	self.isEmpty = (void *)&__queueAEmpty;
	self.isFull = (void *)&__queueAFull;
	return self;
}

#pragma endregion

// IMPLEMENTING
#pragma region Queue (Linked Node implementation)
// TODO
#pragma endregion

// DEPRECATED, FULLY DOCUMENTED
#pragma region Ordered List (Array implementation)
//
// OrderedList
//

// DEFINITIONS
bool __oListIsEmpty(OrderedList *self);						// ===> list.isEmpty(&list);
bool __oListIsFull(OrderedList *self);						// ===> list.isFull(&list);
bool __oListInsert(OrderedList *self, int value);				// ===> list.insert(&list, 20);
bool __oListRemove(OrderedList *self, int value);				// ===> list.remove(&list, 20);
bool __oListRemoveAtIndex(OrderedList *self, int index);			// ===> list.removeAtIndex(&list, 3);
int __oListGetItem(OrderedList *self, int index);				// ===> list.getItem(&list, 3);
int __oListLastItem(OrderedList *self);						// ===> list.lastItem(&list);
int __oListFirtItem(OrderedList *self);						// ===> list.firstItem(&list);
int __oListItemAmout(OrderedList *self);					// ===> list.itemAmout(&list);

//	__oListIsAEmpty(OrderedList *self);
//
//	Using:
//	OrderedList list = newOrderedList();
//	bool response = list.isEmpty(&list);
//
//	INPUT: 
//	OrderedList *self as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of list, if it's empty or not.
bool __oListIsEmpty(OrderedList *self) {
	if (self->endIndex == 0) return true;
	return false;
}

//	__oListIsFull(OrderedList *self);
//
//	Using:
//	OrderedList list = newOrderedList();
//	bool response = list.isFull(&list);
//
//	INPUT: 
//	OrderedList *self as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of list, if it's full or not.
bool __oListIsFull(OrderedList *self) {
	if (self->endIndex == MAX_ORDERED_LIST_LEN) return true;
	return false;
}

//	__oListInsert(OrderedList *self, int value);
//
//	Using:
//	OrderedList list = newOrderedList();
//	bool response = list.insert(&list, 20);
//
//	INPUT: 
//	OrderedList *self as self indicator.
//	int value as item to be added in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Inserts a new item in the list, returns a response about insertion.
bool __oListInsert(OrderedList *self, int value) {
	if (__oListIsFull(self) == false) {
		int i, j;
		for (i = 0; i < self->endIndex; i++)
			if (self->orderedListArray[i] > value) break;
		if (self->endIndex > 0)
			for (j = self->endIndex; j > i; j--)
				self->orderedListArray[j] = self->orderedListArray[j - 1];
		self->orderedListArray[i] = value;
		self->endIndex++;
		return true;
	}
	return false;
}

//	__oListRemove(OrderedList *self, int value);
//
//	Using:
//	OrderedList list = newOrderedList();
//	...
//	bool response = list.remove(&list, 20);
//
//	INPUT: 
//	OrderedList *self as self indicator.
//	int value as item to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oListRemove(OrderedList *self, int value) {
	if (__oListIsEmpty(self) == false) {
		int i, j;
		bool breaked = false;
		// Search value in the list.
		for (i = 0; i < self->endIndex; i++)
			if (self->orderedListArray[i] == value) {
				breaked = true;
				break;
			}

		// Reorders values in the list.
		for (j = i; j < self->endIndex; j++) {
			if (j + 1 < MAX_ORDERED_LIST_LEN)
				self->orderedListArray[j] = self->orderedListArray[j + 1];
			else
				self->orderedListArray[j] = 0;
		}

		if (breaked == true) self->endIndex--;
		return true;
	}
	return false;
}

//	__oListRemoveAtIndex(OrderedList *self, int index);
//
//	Using:
//	OrderedList list = newOrderedList();
//  ...
//	bool response = list.removeAtIndex(&list, 3);
//
//	INPUT: 
//	OrderedList *self as self indicator.
//	int index as item's reference to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oListRemoveAtIndex(OrderedList *self, int index) {
	int i = 0;
	if ((__oListIsEmpty(self) == false) && (index < self->endIndex) && (index >= 0)) {
		for (i = index; i < self->endIndex; i++) {
			if (i + 1 < MAX_ORDERED_LIST_LEN)
				self->orderedListArray[i] = self->orderedListArray[i + 1];
			else
				self->orderedListArray[i] = 0;
		}
		self->endIndex--;
		return true;
	}
	return false;
}

//	__oListGetItem(OrderedList *self, int index);
//
//	Using:
//	OrderedList list = newOrderedList();
//  ...
//	int response = list.getItem(&list, 3);
//
//	INPUT: 
//	OrderedList *self as self indicator.
//	int index as item's reference 
//
//	OUTPUT:
//  List item at the index as integer.	
//	
//	Description:
//	Returns an item in the list
int __oListGetItem(OrderedList *self, int index) {
	if (index < self->endIndex && index >= 0)
		return self->orderedListArray[index];
	return false;
}

//	__oListLastItem(OrderedList *self);
//
//	Using:
//	OrderedList list = newOrderedList();
//  ...
//	int response = list.lastItem(&list);
//
//	INPUT: 
//	OrderedList *self as self indicator.
//
//	OUTPUT:
//  Last list item as integer.	
//	
//	Description:
//	Returns a last item in the list.
int __oListLastItem(OrderedList *self) {
	return self->orderedListArray[self->endIndex - 1];
}

//	__oListFirstItem(OrderedList *self);
//
//	Using:
//	OrderedList list = newOrderedList();
//  ...
//	int response = list.firstItem(&list);
//
//	INPUT: 
//	OrderedList *self as self indicator.
//
//	OUTPUT:
//  First list item as integer.	
//	
//	Description:
//	Returns a first item in the list.
int __oListFirtItem(OrderedList *self) {
	return self->orderedListArray[0];
}

//	__oListItemAmout(OrderedList *self);
//
//	Using:
//	OrderedList list = newOrderedList();
//  ...
//	int response = list.itemAmout(&list);
//
//	INPUT: 
//	OrderedList *self as self indicator.
//
//	OUTPUT:
//  Item amout as integer.	
//	
//	Description:
//  Returns the amount of items in the list.
int __oListItemAmout(OrderedList *self) {
	return self->endIndex;
}

//	newOrderedList(void);
//
//	Using:
//	OrderedList list = newOrderedList();
//
//	INPUT: 
//	Nothing
//
//	OUTUP:
//	OrderedList self as a newly built structure.
//	
//	Description:
//	Construction function of structure.
OrderedList newOrderedList() {
	OrderedList self;
	self.endIndex = 0;
	self.insert = (void *)&__oListInsert;
	self.remove = (void *)&__oListRemove;
	self.removeAtIndex = (void *)&__oListRemoveAtIndex;
	self.getItem = (void *)&__oListGetItem;
	self.lastItem = (void *)&__oListLastItem;
	self.firstItem = (void *)&__oListFirtItem;
	self.isEmpty = (void *)&__oListIsEmpty;
	self.isFull = (void *)&__oListIsFull;
	self.itemAmount = (void *)&__oListItemAmout;
	return self;
}

#pragma endregion

// FULLY DOCUMENTED, NEW FEATURES CAN BE ADDED
#pragma region Ordered List (Linked Node implementation)
//
// OrderedLinkedList
//

// DEFINITIONS
bool __oLListIsEmpty(OrderedLinkedList *self);						// ===> list.isEmpty(&list);
void __oLListInsert(OrderedLinkedList * self, int value);				// ===> list.insert(&list, 20);
bool __oLListRemove(OrderedLinkedList * self, int value);				// ===>	list.remove(&list, 20);
bool __oLListRemoveAtIndex(OrderedLinkedList * self, int index);			// ===> list.removeAtIndex(&list, 3);
int __oLListGetItem(OrderedLinkedList * self, int index);				// ===> list.getItem(&list, 3);
int __oLListLastItem(OrderedLinkedList * self);						// ===> list.lastItem(&list);
int __oLListFirstItem(OrderedLinkedList * self);					// ===> list.firstItem(&list);
int __oLListItemAmout(OrderedLinkedList * self);					// ===> list.itemAmout(&list);
void __oLListClear(OrderedLinkedList * self);						// ===> list.clear(&list);

//	__oLListIsAEmpty(OrderedLinkedList *self);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//	bool response = list.isEmpty(&list);
//
//	INPUT: 
//	OrderedLinkedList *self as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of list, if it's empty or not.
bool __oLListIsEmpty(OrderedLinkedList *self) {
	if (self->start == NULL) return true;
	return false;
}

//	__oLListInsert(OrderedLinkedList *self, int value);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//	bool response = list.insert(&list, 20);
//
//	INPUT: 
//	OrderedLinkedList *self as self indicator.
//	int value as item to be added in the list
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Inserts a new item in the list, returns a response about insertion.
void __oLListInsert(OrderedLinkedList *self, int value) {
	Node *prev, *next;
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = value;
	temp->next = NULL;
	if (__oLListIsEmpty(self)) self->start = (void *)temp;
	else {
		prev = NULL;
		next = (void *)self->start;
		// Search for a place to insert
		while (next != NULL && next->data <= value) {
			prev = (void *)next;
			next = (void *)next->next;
		}
		// Node manipulation
		if (next == NULL) prev->next = (void *)temp;
		else {
			if (prev != NULL) {
				temp->next = (void *)prev->next;
				prev->next = (void *)temp;
			}
			// Case: first item.
			else {
				temp->next = self->start;
				self->start = (void *)temp;
			}
		}
	}
}

//	__oLListRemove(OrderedLinkedList *self, int value);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//	...
//	bool response = list.remove(&list, 20);
//
//	INPUT: 
//	OrderedLinkedList *self as self indicator.
//	int value as item to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oLListRemove(OrderedLinkedList *self, int value) {
	Node *current = (void *)self->start;
	Node *prev = NULL;
	while (current != NULL) {
		if (current->data == value) {
			// Delete
			// Case: first item.
			if (prev == NULL) self->start = (void *)current->next;
			else prev->next = (void *)current->next;
			free(current);
			return true;
		}
		// Next item.
		prev = (void *)current;
		current = (void *)current->next;
	}
	return false;
}

//	__oLListRemoveAtIndex(OrderedLinkedList *self, int index);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	bool response = list.removeAtIndex(&list, 3);
//
//	INPUT: 
//	OrderedLinkedList *self as self indicator.
//	int index as item's reference to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oLListRemoveAtIndex(OrderedLinkedList *self, int index) {
	Node *current = (void *)self->start;
	Node *prev = NULL;
	int count = 0;
	while (current->next != NULL) {
		if (count == index) {
			// Delete
			// Case: first item.
			if (prev == NULL) self->start = (void *)current->next;
			else prev->next = (void *)current->next;
			free(current);
			return true;
		}
		// Next item
		prev = (void *)current;
		current = (void *)current->next;
		count++;
	}
	return false;
}

//	__oLListGetItem(OrderedLinkedList *self, int index);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	int response = list.getItem(&list, 3);
//
//	INPUT: 
//	OrderedLinkedList *self as self indicator.
//	int index as item's reference to be returned in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Get an item in the list
int __oLListGetItem(OrderedLinkedList *self, int index) {
	if (__oLListIsEmpty(self) != true) {
		Node *current = (void *)self->start;
		int count = 0;
		while (current != NULL) {
			// Return an item
			if (count == index)	return current->data;
			// Next item
			current = (void *)current->next;
			count++;
		}
	}
	return false;
}

//	__oLListLastItem(OrderedLinkedList *self);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	int response = list.lastItem(&list);
//
//	INPUT: 
//	OrderedLinkedList *self as self indicator.
//
//	OUTPUT:
//  Last list item as integer.
//	
//	Description:
//	Returns a last item in the list.
int __oLListLastItem(OrderedLinkedList *self) {
	if (__oLListIsEmpty(self) != true) {
		Node *current = (void *)self->start;
		while (current->next != NULL) current = (void *)current->next;
		return current->data;
	}
	return false;
}

//	__oLListFirstItem(OrderedLinkedList *self);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	int response = list.firstItem(&list);
//
//	INPUT: 
//	OrderedLinkedList *self as self indicator.
//
//	OUTPUT:
//  First list item as integer.	
//	
//	Description:
//	Returns a first item in the list.
int __oLListFirstItem(OrderedLinkedList *self) {
	if (__oLListIsEmpty(self) != true) {
		Node* current = (void *)self->start;
		return current->data;
	}
	return false;
}

//	__oLListItemAmout(OrderedLinkedList *self);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	int response = list.itemAmout(&list);
//
//	INPUT: 
//	OrderedLinkedList *self as self indicator.
//
//	OUTPUT:
//  Item amout as integer.	
//	
//	Description:
//  Returns the amount of items in the list.
int __oLListItemAmout(OrderedLinkedList *self) {
	int count = 0;
	Node *current = (void *)self->start;
	while (current != NULL) {
		current = (void *)current->next;
		count++;
	}
	return count + 1;
}

//	__oLListClear(OrderedLinkedList *self);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	list.clear(&list);
//
//	INPUT: 
//	OrderedLinkedList *self as self indicator.
//
//	OUTPUT:
//  Nothing	
//	
//	Description:
//  Clear the list completely, excluding all nodes.
void __oLListClear(OrderedLinkedList *self) {
	Node * current = (void *)self->start;
	while (current != NULL) {
		DNode *temp = (void *)current->next;
		free(current);
		current = (void *)temp;
	}
	self->start = NULL;
}

//	newOrderedLinkedList(void);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//
//	INPUT: 
//	Nothing
//
//	OUTUP:
//	OrderedLinkedList self as a newly built structure.
//	
//	Description:
//	Construction function of structure.
OrderedLinkedList newOrderedLinkedList() {
	OrderedLinkedList self;
	self.start = NULL;
	self.insert = (void *)&__oLListInsert;
	self.remove = (void *)&__oLListRemove;
	self.removeAtIndex = (void *)&__oLListRemoveAtIndex;
	self.getItem = (void *)&__oLListGetItem;
	self.isEmpty = (void *)&__oLListIsEmpty;
	self.firstItem = (void *)&__oLListFirstItem;
	self.lastItem = (void *)&__oLListLastItem;
	self.itemAmount = (void *)&__oLListItemAmout;
	self.clear = (void *)&__oLListClear;
	return self;
}

#pragma endregion

// FULLY DOCUMENTED,, NEW FEATURES CAN BE ADDED
#pragma region Ordered List (Doubly Linked Node implementation)
//
// OrderedLinkedList
//

// DEFINITIONS
void __oDLListInsert(OrderedDoublyLinkedList * self, int value);			// ===> list.insert(&list, 20);
bool __oDLListRemove(OrderedDoublyLinkedList * self, int value);			// ===> list.remove(&list, 20);
bool __oDLListRemoveAtIndex(OrderedDoublyLinkedList * self, int index);			// ===> list.removeAtIndex(&list, 3);
int __oDLListGetItem(OrderedDoublyLinkedList * self, int index);			// ===> list.getItem(&list, 3);
int __oDLListLastItem(OrderedDoublyLinkedList * self);					// ===> list.lastItem(&list);
int __oDLListFirstItem(OrderedDoublyLinkedList * self);					// ===> list.firstItem(&list);
bool __oDLListIsEmpty(OrderedDoublyLinkedList * self);					// ===> list.isEmpty(&list);
int __oDLListItemAmout(OrderedDoublyLinkedList * self);					// ===> list.itemAmout(&list);
void __oDLListClear(OrderedDoublyLinkedList * self);					// ===> list.clear(&list);

DNode* __oDLListFind(OrderedDoublyLinkedList *self, int value);				// ===> INTERNAL USE

//  LIBRARY INTERNAL USE
//	__oDLListFind(OrderedDoublyLinkedList * self, int value);
//
//	INPUT: 
//	OrderedLinkedList *self as self indicator.
//  int value as reference to find a node.
//
//	OUTPUT:
//	Return a DNode pointer in the list.
//	
//	Description:
//	Find a list item and return it.
DNode* __oDLListFind(OrderedDoublyLinkedList *self, int value) {
	DNode *temp = (void *)self->start;
	if (temp == NULL) return NULL;
	while (temp->next != NULL && ((DNode*)temp->next)->data < value)
		temp = (void *)temp->next;
	return temp;
}

//	__oDLListInsert(OrderedDoublyLinkedList * self, int value);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//	bool response = list.insert(&list, 20);
//
//	INPUT: 
//	OrderedDoublyLinkedList *self as self indicator.
//	int value as item to be added in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Inserts a new item in the list, returns a response about insertion.
void __oDLListInsert(OrderedDoublyLinkedList *self, int value) {
	DNode *prev = __oDLListFind(self, value);
	DNode *current = (DNode *)malloc(sizeof(DNode));
	current->data = value;
	if (prev == NULL || prev->data > value) {
		// First item
		current->next = self->start;
		self->start = (void *)current;
		if (current->next != NULL)
			((DNode*)current->next)->previous = (void *)current;
		current->previous = NULL;
	}
	else {
		current->next = prev->next;
		if (current->next != NULL)
			((DNode*)current->next)->previous = (void *)current;
		current->previous = (void *)prev;
		prev->next = (void *)current;
	}
}

//	__oDLListRemove(OrderedDoublyLinkedList * self, int value);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//	...
//	bool response = list.remove(&list, 20);
//
//	INPUT: 
//	OrderedDoublyLinkedList *self as self indicator.
//	int value as item to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oDLListRemove(OrderedDoublyLinkedList *self, int value) {
	DNode * current = (void *)self->start;
	while (current != NULL && current->data != value) {
		current = (void *)current->next;
	}
	if (current == NULL) return false;
	if (current->next != NULL) ((DNode *)current->next)->previous = current->previous;
	if (current->previous != NULL) ((DNode *)current->previous)->next = current->next;
	else self->start = current->next;
	free(current);
	return true;
}

//	__oDLListRemoveAtIndex(OrderedDoublyLinkedList * self, int index);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	bool response = list.removeAtIndex(&list, 3);
//
//	INPUT: 
//	OrderedDoublyLinkedList *self as self indicator.
//	int index as item's reference to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oDLListRemoveAtIndex(OrderedDoublyLinkedList *self, int index) {
	DNode * current = (void *)self->start;
	int count = 0;
	while (current != NULL) {
		if (count == index) break;
		current = (void *)current->next;
		count++;
	}
	if (current == NULL) return false;
	if (current->next != NULL) ((DNode *)current->next)->previous = current->previous;
	if (current->previous != NULL) ((DNode *)current->previous)->next = current->next;
	else self->start = current->next;
	free(current);
	return true;
}

//	__oDLListGetItem(OrderedDoublyLinkedList * self, int index);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	int response = list.getItem(&list, 3);
//
//	INPUT: 
//	OrderedDoublyLinkedList *self as self indicator.
//	int index as item's reference to be returned in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Get an item in the list
int __oDLListGetItem(OrderedDoublyLinkedList *self, int index) {
	DNode * current = (void *)self->start;
	int count = 0;
	while (current != NULL) {
		if (count == index) break;
		current = (void *)current->next;
		count++;
	}
	if (current == NULL) return false;
	else return current->data;
}

//	__oDLListLastItem(OrderedDoublyLinkedList * self);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	int response = list.lastItem(&list);
//
//	INPUT: 
//	OrderedDoublyLinkedList *self as self indicator.
//
//	OUTPUT:
//  Last list item as integer.
//	
//	Description:
//	Returns a last item in the list.
int __oDLListLastItem(OrderedDoublyLinkedList *self) {
	if (self->start == NULL) return false;
	DNode * current = (void *)self->start;
	while (current->next != NULL) current = (void *)current->next;
	return current->data;
}

//	__oDLListFirstItem(OrderedDoublyLinkedList * self);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	int response = list.firstItem(&list);
//
//	INPUT: 
//	OrderedDoublyLinkedList *self as self indicator.
//
//	OUTPUT:
//  First list item as integer.	
//	
//	Description:
//	Returns a first item in the list.
int __oDLListFirstItem(OrderedDoublyLinkedList *self) {
	if (self->start == NULL) return false;
	else return ((DNode *)self->start)->data;
}

//	__oDLListIsAEmpty(OrderedDoublyLinkedList * self);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//	bool response = list.isEmpty(&list);
//
//	INPUT: 
//	OrderedDoublyLinkedList *self as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of list, if it's empty or not.
bool __oDLListIsEmpty(OrderedDoublyLinkedList *self) {
	return (self->start == NULL);
}

//	__oDLListItemAmout(OrderedDoublyLinkedList * self);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	int response = list.itemAmout(&list);
//
//	INPUT: 
//	OrderedDoublyLinkedList *self as self indicator.
//
//	OUTPUT:
//  Item amout as integer.	
//	
//	Description:
//  Returns the amount of items in the list.
int __oDLListItemAmout(OrderedDoublyLinkedList *self) {
	int count = 0;
	DNode *current = (void *)self->start;
	while (current != NULL) {
		current = (void *)current->next;
		count++;
	}
	return count + 1;
}

//	__oDLListClear(OrderedDoublyLinkedList * self);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	list.clear(&list);
//
//	INPUT: 
//	OrderedDoublyLinkedList *self as self indicator.
//
//	OUTPUT:
//  Nothing	
//	
//	Description:
//  Clear the list completely, excluding all nodes.
void __oDLListClear(OrderedDoublyLinkedList *self) {
	DNode * current = (void *)self->start;
	while (current != NULL) {
		DNode *temp = (void *)current->next;
		free(current);
		current = temp;
	}
	self->start = NULL;
}

//	newOrderedDoublyLinkedList(void);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//
//	INPUT: 
//	Nothing
//
//	OUTUP:
//	OrderedDoublyLinkedList self as a newly built structure.
//	
//	Description:
//	Construction function of structure.
OrderedDoublyLinkedList newOrderedDoublyLinkedList() {
	OrderedDoublyLinkedList self;
	self.start = NULL;
	self.insert = (void *)&__oDLListInsert;
	self.remove = (void *)&__oDLListRemove;
	self.removeAtIndex = (void *)&__oDLListRemoveAtIndex;
	self.getItem = (void *)&__oDLListGetItem;
	self.lastItem = (void *)&__oDLListLastItem;
	self.firstItem = (void *)&__oDLListFirstItem;
	self.isEmpty = (void *)&__oDLListIsEmpty;
	self.itemAmount = (void *)&__oDLListItemAmout;
	self.clear = (void *)&__oDLListClear;
	return self;
}

#pragma endregion

// FULLY DOCUMENTED,, NEW FEATURES CAN BE ADDED
#pragma region Binary Tree
//
// OrderedLinkedList
//

// DEFINITIONS
#define callbackForTNode void (*function)(struct TNode*, int *counter)

TNode * __bTSearchLowerValue(TNode * pointerNode);						// ===> INTERNAL USE
TNode * __bTSearchHighValue(TNode* pointerNode);						// 
int __bTHeightNode(TNode *pointerNode);								//
void __bTFreeNode(TNode * pointerNode, int *null);						//
void __bTPrintNode(TNode * pointerNode, int *null);						//
void __bTCounter(TNode *null, int *counter);							//
void __bTPreOrder(TNode *pointerNode, int* counter, callbackForTNode);				//
void __bTPostOrder(TNode *pointerNode, int* counter, callbackForTNode);				//
void __bTInOrder(TNode *pointerNode, int* counter, callbackForTNode);				//
void __bTPerLevel(TNode *pointerNode, int* counter, int level, callbackForTNode);		//
void __bTInsertNode(TNode** pointerNode, int value);						//
TNode* __bTRemoveNode(TNode** pointerNode, int value);						//

int __bTLowerValue(BinaryTree *self);				// ===> tree.lowerValue(&tree);
int __bTHighValue(BinaryTree *self);				// ===> tree.higherValue(&tree);
int __bTHeight(BinaryTree *self);				// ===> tree.height(&tree);
bool __bTIsEmpty(BinaryTree *self);				// ===> tree.isEmpty(&tree);
void __bTClear(BinaryTree *self);				// ===> tree.clear(&tree);
void __bTPrintInPreOrder(BinaryTree *self);			// ===> tree.printInPreOrder(&tree);
void __bTPrintInPostOrder(BinaryTree *self);			// ===> tree.printInPostOrder(&tree);
void __bTPrintInOrder(BinaryTree *self);			// ===> tree.printInOrder(&tree);
void __bTPrintPerLevel(BinaryTree *self);			// ===> tree.printPerLevel(&tree);
int __bTItemAmout(BinaryTree *self);				// ===> tree.itemAmount(&tree);
void __bTInsert(BinaryTree *self, int value);			// ===> tree.insert(&tree, 20);
bool __bTRemove(BinaryTree *self, int value);			// ===> tree.remove(&tree, 20);

// INTERNAL USE SECTION

//  LIBRARY INTERNAL USE
//	__bTSearchLowerValue(TNode *pointerNode);
//
//	INPUT: 
//	TNode *pointerNode as pointer to first node.
//
//	OUTPUT:
//	Return a TNode pointer in the tree.
//	
//	Description:
//	Find a tree item with lower value and return it.
TNode* __bTSearchLowerValue(TNode* pointerNode) {
	if (pointerNode == NULL) return NULL;
	while (pointerNode->left != NULL) {
		pointerNode = (void *)pointerNode->left;
	}
	return pointerNode;
}

//  LIBRARY INTERNAL USE
//	__bTSearchHighValue(TNode *pointerNode);
//
//	INPUT: 
//	TNode *pointerNode as pointer to first node.
//
//	OUTPUT:
//	Return a TNode pointer in the tree.
//	
//	Description:
//	Find a tree item with higher value and return it.
TNode* __bTSearchHighValue(TNode* pointerNode) {
	if (pointerNode == NULL) return NULL;
	while (pointerNode->right != NULL) {
		pointerNode = (void *)pointerNode->right;
	}
	return pointerNode;
}

//  LIBRARY INTERNAL USE
//	__bTHeightNode(TNode *pointerNode);
//
//	INPUT: 
//	TNode *pointerNode as pointer to first node.
//
//	OUTPUT:
//	Return a int as height counter
//	
//	Description:
//	Find the tree height
int __bTHeightNode(TNode *pointerNode) {
	if (pointerNode == NULL) return -1;
	int lHighValue = __bTHeightNode((void *)pointerNode->left);
	int rHighValue = __bTHeightNode((void *)pointerNode->right);
	if (lHighValue > rHighValue)
		return lHighValue + 1;
	else
		return rHighValue + 1;
}

//  LIBRARY INTERNAL USE
//	__bTFreeNode(TNode *pointerNode, NULL);
//
//	INPUT: 
//	TNode *pointerNode as pointer to node.
//	int * null as NULL
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Frees a tree node.
void __bTFreeNode(TNode * pointerNode, int *null) {
	free(pointerNode);
	pointerNode = NULL;
}

//  LIBRARY INTERNAL USE
//	__bTPrintNode(TNode *pointerNode, NULL);
//
//	INPUT: 
//	TNode *pointerNode as pointer to node.
//	int * null as NULL
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints a tree node.
void __bTPrintNode(TNode * pointerNode, int *null) {
	printf("%d ", pointerNode->data);
}

//  LIBRARY INTERNAL USE
//	__bTCounter(NULL, int * counter);
//
//	INPUT: 
//	TNode *null as NULL.
//	int * counter as node counter.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Add one more unit to the counter
void __bTCounter(TNode *null, int *counter) {
	(*counter)++;
}

//  LIBRARY INTERNAL USE
//	__bTPreOrder(TNode *pointerNode, int* counter, callbackForTNode);
//
//	INPUT: 
//	TNode *pointerNode as pointer to node.
//	int * counter as node counter. (if it's needed)
//  callbackForTNode as "void (*function)(struct TNode*, int *counter)"
//	More about callback: https://en.wikipedia.org/wiki/Callback_%28computer_programming%29
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Visits each node in the tree using "Preorder" and performs the function sent via callback
void __bTPreOrder(TNode *pointerNode, int* counter, callbackForTNode) {
	if (pointerNode != NULL) {
		(void)function((void *)pointerNode, counter);
		__bTPreOrder((void *)pointerNode->left, counter, function);
		__bTPreOrder((void *)pointerNode->right, counter, function);
	}
}

//  LIBRARY INTERNAL USE
//	__bTPostOrder(TNode *pointerNode, int* counter, callbackForTNode);
//
//	INPUT: 
//	TNode *pointerNode as pointer to node.
//	int * counter as node counter. (if it's needed)
//  callbackForTNode as "void (*function)(struct TNode*, int *counter)"
//	More about callback: https://en.wikipedia.org/wiki/Callback_%28computer_programming%29
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Visits each node in the tree using "Postorder" and performs the function sent via callback
void __bTPostOrder(TNode *pointerNode, int* counter, callbackForTNode) {
	if (pointerNode != NULL) {
		__bTPostOrder((void *)pointerNode->left, counter, function);
		__bTPostOrder((void *)pointerNode->right, counter, function);
		(void)function((void *)pointerNode, counter);
	}
}

//  LIBRARY INTERNAL USE
//	__bTInOrder(TNode *pointerNode, int* counter, callbackForTNode);
//
//	INPUT: 
//	TNode *pointerNode as pointer to node.
//	int * counter as node counter. (if it's needed)
//  callbackForTNode as "void (*function)(struct TNode*, int *counter)"
//	More about callback: https://en.wikipedia.org/wiki/Callback_%28computer_programming%29
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Visits each node in the tree using "Inorder" and performs the function sent via callback
void __bTInOrder(TNode *pointerNode, int* counter, callbackForTNode) {
	if (pointerNode != NULL) {
		__bTInOrder((void *)pointerNode->left, counter, function);
		(void)function((void *)pointerNode, counter);
		__bTInOrder((void *)pointerNode->right, counter, function);
	}
}

//  LIBRARY INTERNAL USE
//	__bTPerLevel(TNode *pointerNode, int* counter, int level, callbackForTNode);
//
//	INPUT: 
//	TNode *pointerNode as pointer to node.
//	int * counter as node counter. (if it's needed)
//	int level as current level.
//  callbackForTNode as "void (*function)(struct TNode*, int *counter)"
//	More about callback: https://en.wikipedia.org/wiki/Callback_%28computer_programming%29
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Visits each node in the level of tree using "Perlevel" and performs the function sent via callback
void __bTPerLevel(TNode *pointerNode, int* counter, int level, callbackForTNode) {
	if (pointerNode == NULL) return;
	if (level == 0)
		(void)function((void *)pointerNode, counter);
	else if (level > 0) {
		__bTPerLevel((void *)pointerNode->left, counter, level - 1, function);
		__bTPerLevel((void *)pointerNode->right, counter, level - 1, function);
	}
}

//  LIBRARY INTERNAL USE
//	__bTInsertNode(TNode **pointerNode, int value);
//
//	INPUT: 
//	TNode **pointerNode as pointer to a pointer that points to an node.
//	int value as item to be added in the tree
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Inserts a new node in the tree.
void __bTInsertNode(TNode** pointerNode, int value) {
	if (*pointerNode == NULL) {
		*pointerNode = malloc(sizeof(TNode));
		(*pointerNode)->data = value;
		(*pointerNode)->left = NULL;
		(*pointerNode)->right = NULL;
	}
	else {
		if (value < (*pointerNode)->data)
			__bTInsertNode((void *)&(*pointerNode)->left, value);
		else
			__bTInsertNode((void *)&(*pointerNode)->right, value);
	}
}

//  LIBRARY INTERNAL USE
//	__bTRemoveNode(TNode **pointerNode, int value);
//
//	INPUT: 
//	TNode **pointerNode as pointer to a pointer that points to an node.
//	int value as item to be removed from the tree
//
//	OUTPUT:
//	Returns a TNode used in recursive execution.
//	
//	Description:
//	Removes a node from the tree.
TNode* __bTRemoveNode(TNode** pointerNode, int value) {
	if ((*pointerNode) == NULL) return NULL;
	if (value < (*pointerNode)->data)
		(*pointerNode)->left = (void *)__bTRemoveNode((void *)&((*pointerNode)->left), value);
	else if (value >(*pointerNode)->data)
		(*pointerNode)->right = (void *)__bTRemoveNode((void *)&((*pointerNode)->right), value);
	else {
		if ((*pointerNode)->left == NULL) {
			TNode* temp = (void*)(*pointerNode)->right;
			free((*pointerNode));
			(*pointerNode) = temp;
			return temp;
		}
		else if ((*pointerNode)->right == NULL) {
			TNode* temp = (void*)(*pointerNode)->left;
			free((*pointerNode));
			(*pointerNode) = temp;
			return temp;
		}
		TNode* temp = (void*)__bTSearchLowerValue((void *)&((*pointerNode)->right));
		(*pointerNode)->data = temp->data;
		(*pointerNode)->right = (void *)__bTRemoveNode((void *)&((*pointerNode)->right), temp->data);
	}
	return (*pointerNode);
}

// EXTERNAL USE SECTION

//	__bTLowerValue(BinaryTree *self);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//  ...
//	int response = tree.lowerValue(&tree);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//
//	OUTPUT:
//	Returns an int as value of lower node.
//	
//	Description:
//	Calls __bTSearchLowerValue(self->root);
int __bTLowerValue(BinaryTree *self) {
	TNode * Node = (void *)__bTSearchLowerValue((void *)self->root);
	return Node != NULL ? Node->data : false;
}

//	__bTHighValue(BinaryTree *self);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//  ...
//	int response = tree.higherValue(&tree);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//
//	OUTPUT:
//	Returns an int as value of higher node.
//	
//	Description:
//	Calls __bTSearchHighValue(self->root);
int __bTHighValue(BinaryTree *self) {
	TNode * Node = __bTSearchHighValue((void *)self->root);
	return Node != NULL ? Node->data : false;
}

//	__bTHeight(BinaryTree *self);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//  ...
//	int response = tree.height(&tree);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//
//	OUTPUT:
//	Returns an int as height of the tree.
//	
//	Description:
//	Calls __bTHeightNode(self->root);
int __bTHeight(BinaryTree *self) {
	int value = __bTHeightNode((void *)self->root);
	return value == -1 ? -1 : value;
}

//	__bTIsEmpty(BinaryTree *self);
//
//	Using:
//	BinaryTree list = newBinaryTree();
//	bool response = tree.isEmpty(&tree);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of tree, if it's empty or not.
bool __bTIsEmpty(BinaryTree *self) {
	return (self->root == NULL);
}

//	__bTClear(BinaryTree * self);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//  ...
//	tree.clear(&tree);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//
//	OUTPUT:
//  Nothing	
//	
//	Description:
//  Clear the tree completely, excluding all nodes.
//  Calls __bTPostOrder(self->root, NULL, &__bTFreeNode)
void __bTClear(BinaryTree *self) {
	if (self->root != NULL) __bTPostOrder((void *)self->root, NULL, (void *)&__bTFreeNode);
	self->root = NULL;
}

//	__bTPrintInPreOrder(BinaryTree *self);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//  ...
//	tree.printInPreOrder(&tree);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints the entire tree.
//	Calls __bTPreOrder(self->root, NULL, &__bTPrintNode);
void __bTPrintInPreOrder(BinaryTree *self) {
	if (self->root != NULL) __bTPreOrder((void *)self->root, NULL, (void *)&__bTPrintNode);
}

//	__bTPrintInPostOrder(BinaryTree *self);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//  ...
//	tree.printInPostOrder(&tree);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints the entire tree.
//	Calls __bTPostOrder(self->root, NULL, &__bTPrintNode);
void __bTPrintInPostOrder(BinaryTree *self) {
	if (self->root != NULL) __bTPostOrder((void *)self->root, NULL, (void *)&__bTPrintNode);
}

//	__bTPrintInOrder(BinaryTree *self);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//  ...
//	tree.printInOrder(&tree);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints the entire tree.
//	Calls __bTInOrder(self->root, NULL, &__bTPrintNode);
void __bTPrintInOrder(BinaryTree *self) {
	if (self->root != NULL) __bTInOrder((void *)self->root, NULL, (void *)&__bTPrintNode);
}

//	__bTPrintPerLevel(BinaryTree *self);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//  ...
//	tree.printPerLevel(&tree);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints the entire tree.
//	Calls __bTPerLevel(self->root, NULL, i, &__bTPrintNode);
void __bTPrintPerLevel(BinaryTree *self) {
	if (self->root != NULL) {
		int h = __bTHeight((void*)self);
		int i = 0;
		for (i = 0; i <= h; i++)
			__bTPerLevel((void *)self->root, NULL, i, (void *)&__bTPrintNode);
	}
}

//	__bTItemAmout(BinaryTree *self);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//  ...
//	tree.itemAmout(&tree);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//
//	OUTPUT:
//	Returns the amout of itens in the tree.
//	
//	Description:
//	Calls __bTInOrder(self->root, &counter, &__bTCounter);
int __bTItemAmout(BinaryTree *self) {
	int counter = 0;
	__bTInOrder((void *)self->root, &counter, (void *)&__bTCounter);
	return counter;
}

//	__bTInsert(BinaryTree *self, int value);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//	tree.insert(&tree, 20);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//  int value as new node value.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//  Inserts a new node.
//	Calls __bTInsertNode(&(self->root), value);
void __bTInsert(BinaryTree *self, int value) {
	__bTInsertNode((void*)&(self->root), value);
}

//	__bTRemove(BinaryTree *self, int value);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//  ...
//	tree.remove(&tree, 20);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//  int value as value to be removed from the tree.
//
//	OUTPUT:
//	Nothing working yet. :D
//	
//	Description:
//  Removes a node.
//	Calls __bTRemoveNode(&(self->root), value);
bool __bTRemove(BinaryTree *self, int value) {
	return (__bTRemoveNode((void *)&(self->root), value) != NULL);
}

//	newBinaryTree(void);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//
//	INPUT: 
//	Nothing
//
//	OUTUP:
//	BinaryTree self as a newly built structure.
//	
//	Description:
//	Construction function of structure.
BinaryTree newBinaryTree() {
	BinaryTree self;
	self.root = NULL;
	self.insert = (void *)&__bTInsert;
	self.remove = (void *)&__bTRemove;
	self.height = (void *)&__bTHeight;
	self.itemAmount = (void *)&__bTItemAmout;
	self.lowerValue = (void *)&__bTLowerValue;
	self.higherValue = (void *)&__bTHighValue;
	self.isEmpty = (void *)__bTIsEmpty;
	self.clear = (void *)__bTClear;
	self.printInPreOrder = (void *)&__bTPrintInPreOrder;
	self.printInPostOrder = (void *)&__bTPrintInPostOrder;
	self.printInOrder = (void *)&__bTPrintInOrder;
	self.printPerLevel = (void *)&__bTPrintPerLevel;
	return self;
}

#pragma endregion

// IMPLEMENTING
#pragma region Red-Black Tree
// Definitions
void __rBTInsertFixesGuidelines(RBTNode *pointerNode, RBTNode **root);
RBTNode* __rBTNodeBrother(RBTNode* pointerNode);
RBTNode* __rBTNodeGrandfather(RBTNode* pointerNode);


int __rBTHeightNode(RBTNode *pointerNode) {
	if (pointerNode == NULL) return -1;
	int lHighValue = __rBTHeightNode((void *)pointerNode->left);
	int rHighValue = __rBTHeightNode((void *)pointerNode->right);
	if (lHighValue > rHighValue)
		return lHighValue + 1;
	else
		return rHighValue + 1;
}

int __rBTHeight(RedBlackTree *BTree) {
	int value = __rBTHeightNode((void *)BTree->root);
	return value == -1 ? -1 : value;
}

void __rBTFreeNode(RBTNode * pointerNode, int *null) {
	free(pointerNode);
	pointerNode = NULL;
}

void __rBTPrintNode(RBTNode * pointerNode, int *null) {
	printf("%d ", pointerNode->data);
}

void __rBTCounter(RBTNode *null, int *counter) {
	(*counter)++;
}

void __rBTPreOrder(RBTNode *pointerNode, int* counter, void * (function)(struct RBTNode*, int *counter)) {
	if (pointerNode != NULL) {
		(void)function((void *)pointerNode, counter);
		__rBTPreOrder((void *)pointerNode->left, counter, function);
		__rBTPreOrder((void *)pointerNode->right, counter, function);
	}
}

void __rBTPostOrder(RBTNode *pointerNode, int* counter, void * (function)(struct RBTNode*, int *counter)) {
	if (pointerNode != NULL) {
		__rBTPostOrder((void *)pointerNode->left, counter, function);
		__rBTPostOrder((void *)pointerNode->right, counter, function);
		(void)function((void *)pointerNode, counter);
	}
}

void __rBTInOrder(RBTNode *pointerNode, int* counter, void * (function)(struct RBTNode*, int *counter)) {
	if (pointerNode != NULL) {
		__rBTInOrder((void *)pointerNode->left, counter, function);
		(void)function((void *)pointerNode, counter);
		__rBTInOrder((void *)pointerNode->right, counter, function);
	}
}

void __rBTPerLevel(RBTNode *pointerNode, int* counter, int level, void * (function)(struct RBTNode*, int *counter)) {
	if (pointerNode == NULL) return;
	if (level == 0)
		(void)function((void *)pointerNode, counter);
	else if (level > 0) {
		__rBTPerLevel((void *)pointerNode->left, counter, level - 1, function);
		__rBTPerLevel((void *)pointerNode->right, counter, level - 1, function);
	}
}

void __rBTPrintInPreOrder(RedBlackTree *RBTree) {
	if (RBTree->root != NULL) __rBTPreOrder((void *)RBTree->root, NULL, (void *)&__rBTPrintNode);
}

void __rBTPrintInPostOrder(RedBlackTree *RBTree) {
	if (RBTree->root != NULL) __rBTPostOrder((void *)RBTree->root, NULL, (void *)&__rBTPrintNode);
}

void __rBTPrintInOrder(RedBlackTree *RBTree) {
	if (RBTree->root != NULL) __rBTInOrder((void *)RBTree->root, NULL, (void *)&__rBTPrintNode);
}

void __rBTPrintPerLevel(RedBlackTree *RBTree) {
	if (RBTree->root != NULL) {
		int h = __rBTHeight((void*)RBTree);
		int i = 0;
		for (i = 0; i <= h; i++)
			__rBTPerLevel((void *)RBTree->root, NULL, i, (void *)&__rBTPrintNode);
	}
}

int __rBTClear(RedBlackTree *RBTree) {
	if (RBTree->root != NULL) __rBTPostOrder((void *)RBTree->root, NULL, (void *)&__rBTFreeNode);
	RBTree->root = NULL;
}

RBTNode* __rBTSearchHighValue(RBTNode* pointerNode) {
	if (pointerNode == NULL) return NULL;
	while (pointerNode->right != NULL) {
		pointerNode = (void *)pointerNode->right;
	}
	return pointerNode;
}

int __rBTHigherValue(RedBlackTree *BTree) {
	RBTNode * Node = (void *)__rBTSearchHighValue((void *)BTree->root);
	return Node != NULL ? Node->data : false;
}

RBTNode* __rBTSearchLowerValue(RBTNode* pointerNode) {
	if (pointerNode == NULL) return NULL;
	while (pointerNode->left != NULL) {
		pointerNode = (void *)pointerNode->left;
	}
	return pointerNode;
}

int __rBTLowerValue(RedBlackTree *RBTree) {
	RBTNode * Node = (void *)__rBTSearchLowerValue((void *)RBTree->root);
	return Node != NULL ? Node->data : false;
}

int __rBTItemAmout(RedBlackTree *RBTree) {
	int counter = 0;
	__rBTInOrder((void *)RBTree->root, &counter, (void *)&__rBTCounter);
	return counter;
}

bool __rBTIsEmpty(RedBlackTree *RBTree) {
	return (RBTree->root == NULL);
}

RBTNode* __rBTNewNode(int value) {
	RBTNode* tempNode = malloc(sizeof(RBTNode));
	tempNode->data = value;
	tempNode->left = NULL;
	tempNode->right = NULL;
	tempNode->color = red;
	tempNode->parent = NULL;
	return tempNode;
}

void __rBTInsertNode(RBTNode** endPointerNode, RBTNode* parentPoiterNode, RBTNode** root, int value) {
	//RBTNode* tempNode = __rBTNewNode(value); aloca um node a cada execução recursiva
	if (*endPointerNode == NULL) {
		RBTNode* tempNode = __rBTNewNode(value);
		tempNode->parent = (void *)parentPoiterNode;
		*endPointerNode = tempNode;
		__rBTInsertFixesGuidelines((*endPointerNode), &(*root));
	}
	else {
		if (value < (*endPointerNode)->data)
			__rBTInsertNode((void *)&((*endPointerNode)->left), *endPointerNode, &(*root), value);
		else
			__rBTInsertNode((void *)&((*endPointerNode)->right), *endPointerNode, &(*root), value);
	}
}

void __rBTNodeRotateLeft(RBTNode* pointerNode, RBTNode** root) {
	RBTNode* temp = (RBTNode*)pointerNode->right;
	pointerNode->right = temp->left;
	if (temp->left != NULL)
		((RBTNode*)temp->left)->parent = (void *)pointerNode;
	temp->parent = pointerNode->parent;
	if (pointerNode->parent == NULL) *root = temp;
	else
		if ((void *)pointerNode == (void *)((RBTNode*)pointerNode->parent)->left)
			((RBTNode*)pointerNode->parent)->left = (void *)temp;
		else
			((RBTNode*)pointerNode->parent)->right = (void *)temp;
	temp->left = (void *)pointerNode;
	pointerNode->parent = (void *)temp;
}

void __rBTNodeRotateRight(RBTNode* pointerNode, RBTNode** root) {
	RBTNode* temp = (RBTNode*)pointerNode->left;
	pointerNode->left = temp->right;
	if (temp->right != NULL)
		((RBTNode*)temp->right)->parent = (void *)pointerNode;
	temp->parent = pointerNode->parent;
	if (pointerNode->parent == NULL) *root = temp;
	else
		if ((void *)pointerNode == (void *)((RBTNode*)pointerNode->parent)->left)
			((RBTNode*)pointerNode->parent)->left = (void *)temp;
		else
			((RBTNode*)pointerNode->parent)->right = (void *)temp;
	temp->right = (void *)pointerNode;
	pointerNode->parent = (void *)temp;
}

RBTNode* __rBTNodeUncle(RBTNode* pointerNode) {
	RBTNode* grand = __rBTNodeGrandfather(pointerNode);
	if (grand == NULL)
		return NULL;
	if (pointerNode->parent == grand->left)
		return (void *)grand->right;
	else
		return (void *)grand->left;
}

RBTNode* __rBTNodeGrandfather(RBTNode* pointerNode) {
	if ((pointerNode != NULL) && (pointerNode->parent != NULL))
		return (void *)((RBTNode*)pointerNode->parent)->parent;
	else
		return (void *)NULL;
}

void __rBTFixesCaseFive(RBTNode* pointerNode, RBTNode **root) {
	RBTNode * grand = __rBTNodeGrandfather(pointerNode);
	((RBTNode*)pointerNode->parent)->color = black;
	grand->color = red;
	if ((void *)pointerNode == (void *)((RBTNode*)pointerNode->parent)->left)// && (pointerNode->parent == grand->left))
		__rBTNodeRotateRight(grand, &(*root));
	else
		__rBTNodeRotateLeft(grand, &(*root));
}

void __rBTFixesCaseFour(RBTNode* pointerNode, RBTNode **root) {
	RBTNode *grand = __rBTNodeGrandfather(pointerNode);
	if (((void *)pointerNode == (void *)((RBTNode *)pointerNode->parent)->right) &&
		((void *)pointerNode->parent == (void *)grand->left)) {
		__rBTNodeRotateLeft((void *)pointerNode->parent, &(*root));
		pointerNode = (void *)pointerNode->left;
	}
	else if (((void *)pointerNode == (void*)((RBTNode *)pointerNode->parent)->left) &&
		((void *)pointerNode->parent == (void *)grand->right)) {
		__rBTNodeRotateRight((void *)pointerNode->parent, &(*root));
		pointerNode = (void *)pointerNode->right;
	}
	__rBTFixesCaseFive(pointerNode, &(*root));
}

void __rBTFixesCaseThree(RBTNode* pointerNode, RBTNode **root) {
	RBTNode* uncle = __rBTNodeUncle(pointerNode), *grand;
	((RBTNode*)pointerNode->parent)->color = black;
	uncle->color = black;
	grand = __rBTNodeGrandfather(pointerNode);
	grand->color = red;
	__rBTInsertFixesGuidelines(grand, (void*)&(*root));
}

void __rBTInsertFixesGuidelines(RBTNode *pointerNode, RBTNode **root) {
	if (pointerNode->parent == NULL)
		pointerNode->color = black;
	else if (((RBTNode*)pointerNode->parent)->color == black) {
		return;
	}
	else if ((__rBTNodeUncle(pointerNode) != NULL) && (((RBTNode *)__rBTNodeUncle(pointerNode))->color == red))
		__rBTFixesCaseThree(pointerNode, &(*root));
	else {
		__rBTFixesCaseFour(pointerNode, &(*root));
	}
}

void __rBTInsert(RedBlackTree *RBTree, int value) {
	__rBTInsertNode((void *)&(RBTree->root), NULL, (void *)&(RBTree->root), value);
}



RBTNode* __rBTRemoveNode(RBTNode** endPointerNode, int value) {
	// REMOVE
}


bool __rBTRemove(RedBlackTree *RBTree, int value) {

}

RedBlackTree newRedBlackTree() {
	RedBlackTree RBTree;
	RBTree.root = NULL;
	RBTree.insert = (void *)&__rBTInsert;
	RBTree.remove = (void *)&__rBTRemove;
	RBTree.height = (void *)&__rBTHeight;
	RBTree.itemAmount = (void *)&__rBTItemAmout;
	RBTree.lowerValue = (void *)&__rBTLowerValue;
	RBTree.higherValue = (void *)&__rBTHigherValue;
	RBTree.isEmpty = (void *)&__rBTIsEmpty;
	RBTree.clear = (void *)&__rBTClear;
	RBTree.printInPreOrder = (void *)&__rBTPrintInPreOrder;
	RBTree.printInPostOrder = (void *)&__rBTPrintInPostOrder;
	RBTree.printInOrder = (void *)&__rBTPrintInOrder;
	RBTree.printPerLevel = (void *)&__rBTPrintPerLevel;
	return RBTree;
}
#pragma endregion
