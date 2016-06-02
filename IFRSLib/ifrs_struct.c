//	IFRSLib 
//  Author: Marcelo Gomes Martins 
//  Github: marcelogm
//  Link: https://github.com/marcelogm/IFRSLib
//  License: https://github.com/marcelogm/IFRSLib/blob/master/LICENSE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ifrs_struct.h"

//
// Data Structure functions
//

// DEPRECATED, FULLY DOCUMENTED
#pragma region Stack (Array implementation)
//
// StackArray
//

#pragma region DEFINITION

// DEFINITIONS

bool __stackAEmpty(StackArray *self);
// ===> stack.isEmpty(&stack);
bool __stackAFull(StackArray *self);
// ===> stack.isFull(&stack);
bool __stackAPush(StackArray *self, int value);
// ===> stack.push(&stack, 20);
int __stackAPop(StackArray *self);
// ===> stack.pop(&stack);
int __stackALastItem(StackArray *self);
// ===> stack.getValue(&stack); CAN CHANGE

#pragma endregion

#pragma region EXTERNAL USE SECTION

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

#pragma region DEFINITION

// DEFINITIONS
bool __queueAEmpty(QueueArray *self);
// ===> queue.isEmpty(&queue);
bool __queueAFull(QueueArray *self);
// ===> queue.isFull(&queue);
int __dequeueA(QueueArray *self);
// ===> queue.dequeue(&queue);
bool __enqueueA(QueueArray *self, int value);
// ===> queue.enqueue(&queue, 20);
int __queueALastItem(QueueArray *self);
// ===> queue.lastItem(&queue);
int __queueAFirstItem(QueueArray *self);
// ===> queue.firstItem(&queue);

#pragma endregion

#pragma region EXTERNAL USE SECTION

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

#pragma region DEFINITION

// DEFINITIONS
bool __oListIsEmpty(OrderedList *self);
// ===> list.isEmpty(&list);
bool __oListIsFull(OrderedList *self);
// ===> list.isFull(&list);
bool __oListInsert(OrderedList *self, int value);
// ===> list.insert(&list, 20);
bool __oListRemove(OrderedList *self, int value);
// ===> list.remove(&list, 20);
bool __oListRemoveAtIndex(OrderedList *self, int index);
// ===> list.removeAtIndex(&list, 3);
int __oListGetItem(OrderedList *self, int index);
// ===> list.getItem(&list, 3);
int __oListLastItem(OrderedList *self);
// ===> list.lastItem(&list);
int __oListFirtItem(OrderedList *self);
// ===> list.firstItem(&list);
int __oListItemAmout(OrderedList *self);
// ===> list.itemAmout(&list);

#pragma endregion

#pragma region EXTERNAL USE SECTION

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

#pragma endregion

// FULLY DOCUMENTED, NEW FEATURES CAN BE ADDED
#pragma region Ordered List (Linked Node implementation)
//
// OrderedLinkedList
//

#pragma region DEFINITION

// DEFINITIONS
bool __oLListIsEmpty(OrderedLinkedList *self);
// ===> list.isEmpty(&list);
void __oLListInsert(OrderedLinkedList * self, int value);
// ===> list.insert(&list, 20);
bool __oLListRemove(OrderedLinkedList * self, int value);
// ===>	list.remove(&list, 20);
bool __oLListRemoveAtIndex(OrderedLinkedList * self, int index);
// ===> list.removeAtIndex(&list, 3);
int __oLListGetItem(OrderedLinkedList * self, int index);
// ===> list.getItem(&list, 3);
int __oLListLastItem(OrderedLinkedList * self);
// ===> list.lastItem(&list);
int __oLListFirstItem(OrderedLinkedList * self);
// ===> list.firstItem(&list);
int __oLListItemAmout(OrderedLinkedList * self);
// ===> list.itemAmout(&list);
void __oLListClear(OrderedLinkedList * self);
// ===> list.clear(&list);

#pragma endregion

#pragma region EXTERNAL USE SECTION

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
			// Returns an item
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

#pragma endregion

// FULLY DOCUMENTED, NEW FEATURES CAN BE ADDED
#pragma region Ordered List (Doubly Linked Node implementation)
//
// OrderedLinkedList
//

#pragma region DEFINITION

// DEFINITIONS
// EXTERNAL USE
void __oDLListInsert(OrderedDoublyLinkedList * self, int value);
// ===> list.insert(&list, 20);
bool __oDLListRemove(OrderedDoublyLinkedList * self, int value);
// ===> list.remove(&list, 20);
bool __oDLListRemoveAtIndex(OrderedDoublyLinkedList * self, int index);
// ===> list.removeAtIndex(&list, 3);
int __oDLListGetItem(OrderedDoublyLinkedList * self, int index);
// ===> list.getItem(&list, 3);
int __oDLListLastItem(OrderedDoublyLinkedList * self);
// ===> list.lastItem(&list);
int __oDLListFirstItem(OrderedDoublyLinkedList * self);
// ===> list.firstItem(&list);
bool __oDLListIsEmpty(OrderedDoublyLinkedList * self);
// ===> list.isEmpty(&list);
int __oDLListItemAmout(OrderedDoublyLinkedList * self);
// ===> list.itemAmout(&list);
void __oDLListClear(OrderedDoublyLinkedList * self);
// ===> list.clear(&list);

// INTERNAL USE
DNode* __oDLListFind(OrderedDoublyLinkedList *self, int value);

#pragma endregion

#pragma region EXTERNAL USE SECTION

//  LIBRARY INTERNAL USE
//	__oDLListFind(OrderedDoublyLinkedList * self, int value);
//
//	INPUT: 
//	OrderedLinkedList *self as self indicator.
//  int value as reference to find a node.
//
//	OUTPUT:
//	Returns a DNode pointer in the list.
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

#pragma endregion

// FULLY DOCUMENTED, NEW FEATURES CAN BE ADDED
#pragma region Binary Tree
//
// OrderedLinkedList
//

#pragma region DEFINITION

#define NIL_TNode &sentinelForTNode
#define RESET_SENTINEL_TNODE			\
sentinelForTNode.data = 0;			\
sentinelForTNode.left = NIL_TNode;		\
sentinelForTNode.right = NIL_TNode;		
TNode sentinelForTNode = { NIL_TNode, 0, NIL_TNode };
#define callbackForTNode void (*function)(struct TNode*, int *counter)

// DEFINITIONS
// EXTERNAL USE
int __bTLowerValue(BinaryTree *self);
// ===> tree.lowerValue(&tree);
int __bTHighValue(BinaryTree *self);
// ===> tree.higherValue(&tree);
int __bTHeight(BinaryTree *self);
// ===> tree.height(&tree);
bool __bTIsEmpty(BinaryTree *self);
// ===> tree.isEmpty(&tree);
void __bTClear(BinaryTree *self);
// ===> tree.clear(&tree);
bool __bTContains(BinaryTree *self, int value);
// ===> tree.contains(&tree, 5);
void __bTPrintSearch(BinaryTree *self, int value);
// ===> tree.printSearch(&tree, 5);
void __bTPrintInPreOrder(BinaryTree *self);
// ===> tree.printInPreOrder(&tree);
void __bTPrintInPostOrder(BinaryTree *self);
// ===> tree.printInPostOrder(&tree);
void __bTPrintInOrder(BinaryTree *self);
// ===> tree.printInOrder(&tree);
void __bTPrintPerLevel(BinaryTree *self);
// ===> tree.printPerLevel(&tree);
int __bTItemAmout(BinaryTree *self);
// ===> tree.itemAmount(&tree);
void __bTInsert(BinaryTree *self, int value);
// ===> tree.insert(&tree, 20);
bool __bTRemove(BinaryTree *self, int value);
// ===> tree.remove(&tree, 20);

// INTERNAL USE
TNode * __bTSearchLowerValue(TNode * pointerNode);
TNode * __bTSearchHighValue(TNode* pointerNode);
int __bTHeightNode(TNode *pointerNode);
void __bTFreeNode(TNode * pointerNode, int *null);
void __bTPrintNode(TNode * pointerNode, int *null);
void __bTCounter(TNode *null, int *counter);
bool __bTContainsNode(TNode* pointerNode, int value);
void __bTPrintSearchNode(TNode *pointerNode, int value);
void __bTPreOrder(TNode *pointerNode, int* counter, callbackForTNode);
void __bTPostOrder(TNode *pointerNode, int* counter, callbackForTNode);
void __bTInOrder(TNode *pointerNode, int* counter, callbackForTNode);
void __bTPerLevel(TNode *pointerNode, int* counter, int level, callbackForTNode);
void __bTInsertNode(TNode** pointerNode, int value);
TNode* __bTRemoveNode(TNode** pointerNode, int value);
#pragma endregion

#pragma region INTERNAL USE SECTION

//	__bTSearchLowerValue(TNode *pointerNode);
//
//	INPUT: 
//	TNode *pointerNode as pointer to first node.
//
//	OUTPUT:
//	Returns a TNode pointer in the tree.
//	
//	Description:
//	Find a tree item with lower value and return it.
TNode* __bTSearchLowerValue(TNode* pointerNode) {
	if (pointerNode == NIL_TNode) return NIL_TNode;
	while (pointerNode->left != NIL_TNode) {
		pointerNode = (void *)pointerNode->left;
	}
	return pointerNode;
}

//	__bTSearchHighValue(TNode *pointerNode);
//
//	INPUT: 
//	TNode *pointerNode as pointer to first node.
//
//	OUTPUT:
//	Returns a TNode pointer in the tree.
//	
//	Description:
//	Find a tree item with higher value and return it.
TNode* __bTSearchHighValue(TNode* pointerNode) {
	if (pointerNode == NIL_TNode) return NIL_TNode;
	while (pointerNode->right != NIL_TNode) {
		pointerNode = (void *)pointerNode->right;
	}
	return pointerNode;
}

//	__bTHeightNode(TNode *pointerNode);
//
//	INPUT: 
//	TNode *pointerNode as pointer to first node.
//
//	OUTPUT:
//	Returns a int as height counter
//	
//	Description:
//	Find the tree height
int __bTHeightNode(TNode *pointerNode) {
	if (pointerNode == NIL_TNode) return -1;
	int lHighValue = __bTHeightNode((void *)pointerNode->left);
	int rHighValue = __bTHeightNode((void *)pointerNode->right);
	if (lHighValue > rHighValue)
		return lHighValue + 1;
	else
		return rHighValue + 1;
}

//	__bTFreeNode(TNode *pointerNode, NULL);
//
//	INPUT: 
//	TNode *pointerNode as pointer to node.
//	int * null as null.
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
	printf("[%d] ", pointerNode->data);
}

//	__bTCounter(NIL_TNode, int * counter);
//
//	INPUT: 
//	TNode *null as NIL_TNode.
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

//	__bTContainsNode(TNode* pointerNode, int value);
//
//	INPUT: 
//	TNode *pointerNode as pointer to a node.
//	int value as searched value
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns true if the tree contains this value
bool __bTContainsNode(TNode* pointerNode, int value) {
	if (pointerNode == NIL_TNode) 
		return false;
	else if (pointerNode->data == value) 
		return true;
	else 
		if (value < pointerNode->data)
			return __bTContainsNode((void *)pointerNode->left, value);
		else
			return __bTContainsNode((void *)pointerNode->right, value);
}

//	__bTPrintSearchNode(TNode *pointerNode, int value);
//
//	INPUT: 
//	TNode *pointerNode as pointer to node.
//	int value as searched value.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints a the entire war to a node.
void __bTPrintSearchNode(TNode *pointerNode, int value) {
	printf("[%d] ", pointerNode->data);
	if (pointerNode->data == value)
		return;
	else {
		printf("> ");
		if (value < pointerNode->data)
			__bTPrintSearchNode((void *)pointerNode->left, value);
		else
			__bTPrintSearchNode((void *)pointerNode->right, value);
	}
}

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
	if (pointerNode != NIL_TNode) {
		(void)function((void *)pointerNode, counter);
		__bTPreOrder((void *)pointerNode->left, counter, function);
		__bTPreOrder((void *)pointerNode->right, counter, function);
	}
}

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
	if (pointerNode != NIL_TNode) {
		__bTPostOrder((void *)pointerNode->left, counter, function);
		__bTPostOrder((void *)pointerNode->right, counter, function);
		(void)function((void *)pointerNode, counter);
	}
}

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
	if (pointerNode != NIL_TNode) {
		__bTInOrder((void *)pointerNode->left, counter, function);
		(void)function((void *)pointerNode, counter);
		__bTInOrder((void *)pointerNode->right, counter, function);
	}
}

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
	if (pointerNode == NIL_TNode) return;
	if (level == 0)
		(void)function((void *)pointerNode, counter);
	else if (level > 0) {
		__bTPerLevel((void *)pointerNode->left, counter, level - 1, function);
		__bTPerLevel((void *)pointerNode->right, counter, level - 1, function);
	}
}

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
	if (*pointerNode == NIL_TNode) {
		*pointerNode = malloc(sizeof(TNode));
		(*pointerNode)->data = value;
		(*pointerNode)->left = NIL_TNode;
		(*pointerNode)->right = NIL_TNode;
	}
	else {
		if (value < (*pointerNode)->data)
			__bTInsertNode((void *)&(*pointerNode)->left, value);
		else
			__bTInsertNode((void *)&(*pointerNode)->right, value);
	}
}

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
	// DO NOT TOUCH THIS.
	// IF YOU TOUCH HERE, OPTIMIZE AND MAKE IT WORK.
	if ((*pointerNode) == NIL_TNode) return NIL_TNode;
	if (value < (*pointerNode)->data)
		(*pointerNode)->left = (void *)__bTRemoveNode((void *)&((*pointerNode)->left), value);
	else if (value > (*pointerNode)->data)
		(*pointerNode)->right = (void *)__bTRemoveNode((void *)&((*pointerNode)->right), value);
	else {
		if ((*pointerNode)->left == NIL_TNode) {
			TNode* temp = (void*)(*pointerNode)->right;
			free((*pointerNode));
			(*pointerNode) = temp;
			return temp;
		}
		else if ((*pointerNode)->right == NIL_TNode) {
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
#pragma endregion

#pragma region EXTERNAL USE SECTION

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
	return Node != NIL_TNode ? Node->data : false;
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
	return Node != NIL_TNode ? Node->data : false;
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
	return (self->root == NIL_TNode);
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
//  Calls __bTPostOrder(self->root, NIL_TNode, &__bTFreeNode)
void __bTClear(BinaryTree *self) {
	if (self->root != NIL_TNode) __bTPostOrder((void *)self->root, 0, (void *)&__bTFreeNode);
	self->root = NIL_TNode;
}

//	__bTContais(BinaryTree *self, int value);
//
//	Using:
//	BinaryTree list = newBinaryTree();
//  ...
//	bool response = tree.contais(&tree, 5);
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//	int value as item to search in the tree
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns true if contains a value
bool __bTContains(BinaryTree *self, int value) {
	return __bTContainsNode((void *)self->root, value);
}

//	__bTPrintSearch(BinaryTree *self, int value);
//
//	Using:
//	BinaryTree tree = newBinaryTree();
//  ...
//	tree.printSearch(&tree, 15);
//
//
//	INPUT: 
//	BinaryTree *self as self indicator.
//  int value as searched value.
//
//	OUTPUT:
//  true / false
//	
//	Description:
//	Prints the entire way to a node.
//	Calls __bTPrintSearchNode(self->root, value);
void __bTPrintSearch(BinaryTree *self, int value) {
	if (__bTContainsNode(self->root, value)) 
		__bTPrintSearchNode((void *)self->root, value);
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
//	Calls __bTPreOrder(self->root, NIL_TNode, &__bTPrintNode);
void __bTPrintInPreOrder(BinaryTree *self) {
	if (self->root != NIL_TNode) __bTPreOrder((void *)self->root, 0, (void *)&__bTPrintNode);
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
//	Calls __bTPostOrder(self->root, NIL_TNode, &__bTPrintNode);
void __bTPrintInPostOrder(BinaryTree *self) {
	if (self->root != NIL_TNode) __bTPostOrder((void *)self->root, 0, (void *)&__bTPrintNode);
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
//	Calls __bTInOrder(self->root, NIL_TNode, &__bTPrintNode);
void __bTPrintInOrder(BinaryTree *self) {
	if (self->root != NIL_TNode) __bTInOrder((void *)self->root, 0, (void *)&__bTPrintNode);
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
//	Calls __bTPerLevel(self->root, NIL_TNode, i, &__bTPrintNode);
void __bTPrintPerLevel(BinaryTree *self) {
	if (self->root != NIL_TNode) {
		int h = __bTHeight((void*)self);
		int i = 0;
		for (i = 0; i <= h; i++)
			__bTPerLevel((void *)self->root, 0, i, (void *)&__bTPrintNode);
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
	if (__bTContainsNode(self->root, value))
		__bTRemoveNode((void *)&(self->root), value);
	else
		return false;
	return true;
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
	self.root = NIL_TNode;
	self.insert = (void *)&__bTInsert;
	self.remove = (void *)&__bTRemove;
	self.height = (void *)&__bTHeight;
	self.itemAmount = (void *)&__bTItemAmout;
	self.lowerValue = (void *)&__bTLowerValue;
	self.higherValue = (void *)&__bTHighValue;
	self.isEmpty = (void *)&__bTIsEmpty;
	self.clear = (void *)&__bTClear;
	self.contains = (void *)&__bTContains;
	self.printSearch = (void *)&__bTPrintSearch;
	self.printInPreOrder = (void *)&__bTPrintInPreOrder;
	self.printInPostOrder = (void *)&__bTPrintInPostOrder;
	self.printInOrder = (void *)&__bTPrintInOrder;
	self.printPerLevel = (void *)&__bTPrintPerLevel;
	return self;
}
#pragma endregion

#pragma endregion

// FULLY DOCUMENTED, NEW FEATURES CAN BE ADDED
#pragma region Red-Black Tree
//
// Red-Black Tree
//

#pragma region DEFINITION

#define NIL_RBTNode &sentinelForRBTNode
#define RESET_SENTINEL_RBTNODE			\
sentinelForRBTNode.color = black;		\
sentinelForRBTNode.data = 0;			\
sentinelForRBTNode.left = NIL_RBTNode;	\
sentinelForRBTNode.right = NIL_RBTNode;	\
sentinelForRBTNode.parent = NIL_RBTNode
RBTNode sentinelForRBTNode = { NIL_RBTNode, NIL_RBTNode, 0, black, NIL_RBTNode };
#define callbackForRBTNode void (*function)(struct RBTNode*, int *counter)

// DEFINITIONS
// EXTERNAL USE
int __rBTLowerValue(RedBlackTree *self);
// ===> tree.lowerValue(&tree);
int __rBTHigherValue(RedBlackTree *self);
// ===> tree.higherValue(&tree);
int __rBTHeight(RedBlackTree *self);
// ===> tree.height(&tree);
bool __rBTIsEmpty(RedBlackTree *self);
// ===> tree.isEmpty(&tree);
void __rBTClear(RedBlackTree *self);
// ===> tree.clear(&tree);
bool __rBTContains(RedBlackTree *self, int value);
// ===> tree.contains(&tree, 5);
void __rBTPrintSearch(RedBlackTree *self, int value);
// ===> tree.printSearch(&tree, 5);
void __rBTPrintTaggedInOrder(RedBlackTree *self);
// ===> tree.printWithColor(&tree);
void __rBTPrintInPreOrder(RedBlackTree *self);
// ===> tree.printInPreOrder(&tree);
void __rBTPrintInPostOrder(RedBlackTree *self);
// ===> tree.printInPostOrder(&tree);
void __rBTPrintInOrder(RedBlackTree *self);
// ===> tree.printInOrder(&tree);
void __rBTPrintPerLevel(RedBlackTree *self);
// ===> tree.printPerLevel(&tree);
int __rBTItemAmout(RedBlackTree *self);
// ===> tree.itemAmount(&tree);
void __rBTInsert(RedBlackTree *self, int value);
// ===> tree.insert(&tree, 20);
bool __rBTRemove(RedBlackTree *self, int value);
// ===> tree.remove(&tree, 20);

// INTERNAL USE
int __rBTHeightNode(RBTNode *pointerNode);
void __rBTFreeNode(RBTNode * pointerNode, int *null);
void __rBTPrintTaggedNode(RBTNode * pointerNode, int *null);
void __rBTPrintNode(RBTNode * pointerNode, int *null);
void __rBTCounter(RBTNode *null, int *counter);
bool __rBTContainsNode(RBTNode* pointerNode, int value);
void __rBTPrintSearchNode(RBTNode *pointerNode, int value);
void __rBTPreOrder(RBTNode *pointerNode, int* counter, callbackForRBTNode);
void __rBTPostOrder(RBTNode *pointerNode, int* counter, callbackForRBTNode);
void __rBTInOrder(RBTNode *pointerNode, int* counter, callbackForRBTNode);
void __rBTPerLevel(RBTNode *pointerNode, int* counter, int level, callbackForRBTNode);
// NODE MANIPULATION
void __rBTNodeRotateLeft(RBTNode* pointerNode, RBTNode** root);
void __rBTNodeRotateRight(RBTNode* pointerNode, RBTNode** root);
RBTNode* __rBTSearchHighValue(RBTNode* pointerNode);
RBTNode* __rBTSearchLowerValue(RBTNode* pointerNode);
RBTNode* __rBTNodeUncle(RBTNode* pointerNode);
RBTNode* __rBTNodeGrandfather(RBTNode* pointerNode);
RBTNode* __rBTNodeBrother(RBTNode* pointerNode);
RBTNode* __rBTNewNode(int value);
RBTNode* __rBTPredecessor(RBTNode *pointerNode);
// INSERT
void __rBTInsertNode(RBTNode** endPointerNode, RBTNode* parentPoiterNode, RBTNode** root, int value);
void __rBTInsertFixesCaseFive(RBTNode* pointerNode, RBTNode **root);
void __rBTInsertFixesCaseFour(RBTNode* pointerNode, RBTNode **root);
void __rBTInsertFixesCaseThree(RBTNode* pointerNode, RBTNode **root);
void __rBTInsertFixesGuidelines(RBTNode *pointerNode, RBTNode **root);
// REMOVE
RBTNode* __rBTRemoveFixupRightBrother(RBTNode *pointerNode, RBTNode ** root);
RBTNode* __rBTRemoveFixupLeftBrother(RBTNode *pointerNode, RBTNode ** root);
void __rBTRemoveFixup(RBTNode *pointerNode, RBTNode ** root);
void __rBTRemoveFixesGuidelines(RBTNode* pointerNode, RBTNode** root);
void __rBTRemoveNode(RBTNode* endPointerNode, RBTNode** root, int value);

#pragma endregion

#pragma region INTERNAL USE SECTION

#pragma region FUNCTIONS

//	__rBTHeightNode(RBTNode *pointerNode);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to first node.
//
//	OUTPUT:
//	Returns a int as height counter
//	
//	Description:
//	Find the tree height
int __rBTHeightNode(RBTNode *pointerNode) {
	if (pointerNode == NIL_RBTNode) return -1;
	int lHighValue = __rBTHeightNode((void *)pointerNode->left);
	int rHighValue = __rBTHeightNode((void *)pointerNode->right);
	if (lHighValue > rHighValue)
		return lHighValue + 1;
	else
		return rHighValue + 1;
}

//	__rBTFreeNode(RBTNode *pointerNode, NULL);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to node.
//	int * null as NULL
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Frees a tree node.
void __rBTFreeNode(RBTNode * pointerNode, int *null) {
	free(pointerNode);
}

//	__rBTPrintNode(RBTNode *pointerNode, NULL);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to node.
//	int * null as NULL
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints a tree node.
void __rBTPrintNode(RBTNode * pointerNode, int *null) {
	printf("[%d] ", pointerNode->data);
}

//	__rBTPrintTaggedNode(RBTNode *pointerNode, NULL);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to node.
//	int * null as NULL
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints a tree node with a color tag.
void __rBTPrintTaggedNode(RBTNode * pointerNode, int *null) {
	printf("[%d](%c) ", pointerNode->data, pointerNode->color);
}

//	__rBTCounter(NULL, int * counter);
//
//	INPUT: 
//	RBTNode *null as NULL.
//	int * counter as node counter.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Add one more unit to the counter
void __rBTCounter(RBTNode *null, int *counter) {
	(*counter)++;
}

//	 __rBTContainsNode(RBTNode* pointerNode, int value);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to a node.
//	int value as searched value
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns true if the tree contains this value
bool __rBTContainsNode(RBTNode* pointerNode, int value) {
	if (pointerNode == NIL_RBTNode)
		return false;
	else if (pointerNode->data == value)
		return true;
	else
		if (value < pointerNode->data)
			return __rBTContainsNode((void *)pointerNode->left, value);
		else
			return __rBTContainsNode((void *)pointerNode->right, value);
}

//	__rBTPrintSearchNode(RBTNode *pointerNode, int value);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to node.
//	int value as searched value.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints a the entire war to a node.
void __rBTPrintSearchNode(RBTNode *pointerNode, int value) {
	printf("[%d] ", pointerNode->data);
	if (pointerNode->data == value)
		return;
	else {
		printf("> ");
		if (value < pointerNode->data)
			__rBTPrintSearchNode((void *)pointerNode->left, value);
		else
			__rBTPrintSearchNode((void *)pointerNode->right, value);
	}
}

//	__rBTPreOrder(RBTNode *pointerNode, int* counter, callbackForRBTNode);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to node.
//	int * counter as node counter. (if it's needed)
//  callbackForRBTNode as "void (*function)(struct RBTNode*, int *counter)"
//	More about callback: https://en.wikipedia.org/wiki/Callback_%28computer_programming%29
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Visits each node in the tree using "Preorder" and performs the function sent via callback
void __rBTPreOrder(RBTNode *pointerNode, int* counter, callbackForRBTNode) {
	if (pointerNode != NIL_RBTNode) {
		(void)function((void *)pointerNode, counter);
		__rBTPreOrder((void *)pointerNode->left, counter, function);
		__rBTPreOrder((void *)pointerNode->right, counter, function);
	}
}

//	__rBTPostOrder(RBTNode *pointerNode, int* counter, callbackForRBTNode);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to node.
//	int * counter as node counter. (if it's needed)
//  callbackForRBTNode as "void (*function)(struct RBTNode*, int *counter)"
//	More about callback: https://en.wikipedia.org/wiki/Callback_%28computer_programming%29
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Visits each node in the tree using "Postorder" and performs the function sent via callback
void __rBTPostOrder(RBTNode *pointerNode, int* counter, callbackForRBTNode) {
	if (pointerNode != NIL_RBTNode) {
		__rBTPostOrder((void *)pointerNode->left, counter, function);
		__rBTPostOrder((void *)pointerNode->right, counter, function);
		(void)function((void *)pointerNode, counter);
	}
}

//	__rBTInOrder(RBTNode *pointerNode, int* counter, callbackForRBTNode);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to node.
//	int * counter as node counter. (if it's needed)
//  callbackForRBTNode as "void (*function)(struct RBTNode*, int *counter)"
//	More about callback: https://en.wikipedia.org/wiki/Callback_%28computer_programming%29
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Visits each node in the tree using "Inorder" and performs the function sent via callback
void __rBTInOrder(RBTNode *pointerNode, int* counter, callbackForRBTNode) {
	if (pointerNode != NIL_RBTNode) {
		__rBTInOrder((void *)pointerNode->left, counter, function);
		(void)function((void *)pointerNode, counter);
		__rBTInOrder((void *)pointerNode->right, counter, function);
	}
}

//	__rBTPerLevel(RBTNode *pointerNode, int* counter, int level, callbackForRBTNode);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to node.
//	int * counter as node counter. (if it's needed)
//	int level as current level.
//  callbackForRBTNode as "void (*function)(struct RBTNode*, int *counter)"
//	More about callback: https://en.wikipedia.org/wiki/Callback_%28computer_programming%29
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Visits each node in the level of tree using "Perlevel" and performs the function sent via callback
void __rBTPerLevel(RBTNode *pointerNode, int* counter, int level, callbackForRBTNode) {
	if (pointerNode == NIL_RBTNode) return;
	if (level == 0)
		(void)function((void *)pointerNode, counter);
	else if (level > 0) {
		__rBTPerLevel((void *)pointerNode->left, counter, level - 1, function);
		__rBTPerLevel((void *)pointerNode->right, counter, level - 1, function);
	}
}

#pragma endregion

#pragma region NODE MANIPULATION

//	__rBTNodeRotateLeft(RBTNode *pointerNode, RBTNode** root);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to the node that will be rotated.
//  RBTNode** root as pointer to root's reference.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Performs left rotation in the node.
void __rBTNodeRotateLeft(RBTNode* pointerNode, RBTNode** root) {
	RBTNode* temp = (RBTNode*)pointerNode->right;
	pointerNode->right = temp->left;
	if (temp->left != NIL_RBTNode)
		((RBTNode*)temp->left)->parent = (void *)pointerNode;
	temp->parent = pointerNode->parent;
	if (pointerNode->parent == NIL_RBTNode) *root = temp;
	else
		if ((void *)pointerNode == (void *)((RBTNode*)pointerNode->parent)->left)
			((RBTNode*)pointerNode->parent)->left = (void *)temp;
		else
			((RBTNode*)pointerNode->parent)->right = (void *)temp;
	temp->left = (void *)pointerNode;
	pointerNode->parent = (void *)temp;
}

//	__rBTNodeRotateRight(RBTNode *pointerNode, RBTNode** root);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to the node that will be rotated.
//  RBTNode** root as pointer to root's reference.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Performs right rotation in the node.
void __rBTNodeRotateRight(RBTNode* pointerNode, RBTNode** root) {
	RBTNode* temp = (RBTNode*)pointerNode->left;
	pointerNode->left = temp->right;
	if (temp->right != NIL_RBTNode)
		((RBTNode*)temp->right)->parent = (void *)pointerNode;
	temp->parent = pointerNode->parent;
	if (pointerNode->parent == NIL_RBTNode) *root = temp;
	else
		if ((void *)pointerNode == (void *)((RBTNode*)pointerNode->parent)->left)
			((RBTNode*)pointerNode->parent)->left = (void *)temp;
		else
			((RBTNode*)pointerNode->parent)->right = (void *)temp;
	temp->right = (void *)pointerNode;
	pointerNode->parent = (void *)temp;
}

//	__rBTSearchHighValue(RBTNode *pointerNode);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to first node.
//
//	OUTPUT:
//	Returns a RBTNode pointer in the tree.
//	
//	Description:
//	Find a tree item with higher value and return it.
RBTNode* __rBTSearchHighValue(RBTNode* pointerNode) {
	if (pointerNode == NIL_RBTNode) return NIL_RBTNode;
	while (pointerNode->right != NIL_RBTNode) {
		pointerNode = (void *)pointerNode->right;
	}
	return pointerNode;
}

//	__rBTSearchLowerValue(RBTNode *pointerNode);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to first node.
//
//	OUTPUT:
//	Returns a RBTNode pointer in the tree.
//	
//	Description:
//	Find a tree item with lower value and return it.
RBTNode* __rBTSearchLowerValue(RBTNode* pointerNode) {
	if (pointerNode == NIL_RBTNode) return NIL_RBTNode;
	while (pointerNode->left != NIL_RBTNode) {
		pointerNode = (void *)pointerNode->left;
	}
	return pointerNode;
}

//	__rBTNodeUncle(RBTNode *pointerNode);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to a node.
//
//	OUTPUT:
//	Returns a RBTNode pointer in the tree.
//	
//	Description:
//	Returns the RBTNode's uncle.
RBTNode* __rBTNodeUncle(RBTNode* pointerNode) {
	RBTNode* grand = __rBTNodeGrandfather(pointerNode);
	if (grand == NIL_RBTNode)
		return NIL_RBTNode;
	if (pointerNode->parent == grand->left)
		return (void *)grand->right;
	else
		return (void *)grand->left;
}

//	__rBTNodeGrandfather(RBTNode *pointerNode);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to a node.
//
//	OUTPUT:
//	Returns a RBTNode pointer in the tree.
//	
//	Description:
//	Returns the RBTNode's grandfather.
RBTNode* __rBTNodeGrandfather(RBTNode* pointerNode) {
	if ((pointerNode != NIL_RBTNode) && (pointerNode->parent != NIL_RBTNode))
		return (void *)((RBTNode*)pointerNode->parent)->parent;
	else
		return (void *)NIL_RBTNode;
}

//	__rBTNodeBrother(RBTNode *pointerNode);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to a node.
//
//	OUTPUT:
//	Returns a RBTNode pointer in the tree.
//	
//	Description:
//	Returns the RBTNode's brother.
RBTNode* __rBTNodeBrother(RBTNode* pointerNode) {
	if ((pointerNode == NIL_RBTNode) || (pointerNode->parent == NIL_RBTNode))
		return NIL_RBTNode;
	if (pointerNode == (void *)((RBTNode*)pointerNode->parent)->left)
		return (RBTNode *)((RBTNode*)pointerNode->parent)->right;
	else
		return (RBTNode *)((RBTNode*)pointerNode->parent)->left;
}

//	__rBTNewNode(int value);
//
//	INPUT: 
//	int value as new node value.
//
//	OUTPUT:
//	Returns a pointer to a new RBTNode.
//	
//	Description:
//	Returns the new RBTNode.
RBTNode* __rBTNewNode(int value) {
	RBTNode* tempNode = malloc(sizeof(RBTNode));
	tempNode->data = value;
	tempNode->left = NIL_RBTNode;
	tempNode->right = NIL_RBTNode;
	tempNode->color = red;
	tempNode->parent = NIL_RBTNode;
	return tempNode;
}

//	__rBTPredecessor(RBTNode *pointerNode);
//
//	INPUT: 
//	RBTNode *pointerNode as pointer to a node.
//
//	OUTPUT:
//	Returns a RBTNode pointer in the tree.
//	
//	Description:
//	Returns the lower RBTNode in the right subtree.
RBTNode* __rBTPredecessor(RBTNode *pointerNode) {
	return __rBTSearchLowerValue(pointerNode->right);
}

#pragma endregion

#pragma region INSERT

//	__rBTInsertNode(RBTNode** endPointerNode, RBTNode* parentPoiterNode, RBTNode** root, int value);
//
//	INPUT: 
//	RBTNode** pointerNode as pointer to a pointer that points to an node.
//  RBTNode* parentPoiterNode as pointer to parent node.
//  RBTNode** root as pointer to root's reference.
//	int value as item to be added in the tree
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Inserts a new node in the tree.
//  Calls __rBTInsertFixesGuidelines((*endPointerNode), &(*root));
void __rBTInsertNode(RBTNode** endPointerNode, RBTNode* parentPoiterNode, RBTNode** root, int value) {
	if (*endPointerNode == NIL_RBTNode) {
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

//	__rBTInsertFixesCaseFive(RBTNode* pointerNode, RBTNode **root);
//
//	INPUT: 
//	RBTNode* pointerNode as pointer to a node.
//  RBTNode** root as pointer to root's reference.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//  Performs fixes for five case.
void __rBTInsertFixesCaseFive(RBTNode* pointerNode, RBTNode **root) {
	RBTNode * grand = __rBTNodeGrandfather(pointerNode);
	((RBTNode*)pointerNode->parent)->color = black;
	grand->color = red;
	if ((void *)pointerNode == (void *)((RBTNode*)pointerNode->parent)->left)
		__rBTNodeRotateRight(grand, &(*root));
	else
		__rBTNodeRotateLeft(grand, &(*root));
}

//	__rBTInsertFixesCaseFour(RBTNode* pointerNode, RBTNode **root);
//
//	INPUT: 
//	RBTNode* pointerNode as pointer to a node.
//  RBTNode** root as pointer to root's reference.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//  Performs fixes for four case.
//  Calls __rBTInsertFixesCaseFive(pointerNode, &(*root));
void __rBTInsertFixesCaseFour(RBTNode* pointerNode, RBTNode **root) {
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
	__rBTInsertFixesCaseFive(pointerNode, &(*root));
}

//	__rBTInsertFixesCaseThree(RBTNode* pointerNode, RBTNode **root);
//
//	INPUT: 
//	RBTNode* pointerNode as pointer to a node.
//  RBTNode** root as pointer to root's reference.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//  Performs fixes for three case.
//  Calls __rBTInsertFixesGuidelines(grand, (void*)&(*root));
void __rBTInsertFixesCaseThree(RBTNode* pointerNode, RBTNode **root) {
	RBTNode* uncle = __rBTNodeUncle(pointerNode), *grand;
	((RBTNode*)pointerNode->parent)->color = black;
	uncle->color = black;
	grand = __rBTNodeGrandfather(pointerNode);
	grand->color = red;
	__rBTInsertFixesGuidelines(grand, (void*)&(*root));
}

//	__rBTInsertFixesGuidelines(RBTNode* pointerNode, RBTNode **root);
//
//	INPUT: 
//	RBTNode* pointerNode as pointer to a node.
//  RBTNode** root as pointer to root's reference.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//  Performs fixes.
//  Calls fixes for each case.
void __rBTInsertFixesGuidelines(RBTNode *pointerNode, RBTNode **root) {
	if (pointerNode->parent == NIL_RBTNode)
		pointerNode->color = black;
	else if (((RBTNode*)pointerNode->parent)->color == black) {
		return;
	}
	else if ((__rBTNodeUncle(pointerNode) != NIL_RBTNode) &&
		(((RBTNode *)__rBTNodeUncle(pointerNode))->color == red))
		__rBTInsertFixesCaseThree(pointerNode, &(*root));
	else {
		__rBTInsertFixesCaseFour(pointerNode, &(*root));
	}
}

#pragma endregion

#pragma region REMOVE

//	__rBTRemoveFixupRightBrother(RBTNode *pointerNode, RBTNode ** root);
//
//	INPUT: 
//	RBTNode* pointerNode as pointer to a node.
//  RBTNode** root as pointer to root's reference.
//
//	OUTPUT:
//	Returns a pointer to RBTNode.
//	
//	Description:
//  Performs fixes for right bother case.
RBTNode* __rBTRemoveFixupRightBrother(RBTNode *pointerNode, RBTNode ** root) {
	RBTNode *brother = ((RBTNode *)pointerNode->parent)->right;
	// RED BROTHER
	if (brother->color == red) {
		brother->color = black;
		((RBTNode *)pointerNode->parent)->color = red;
		__rBTNodeRotateLeft(pointerNode->parent, &(*root));
		brother = ((RBTNode *)pointerNode->parent)->right;
	}
	// BLACK BROTHER WITH TWO BLACK SONS
	if (((RBTNode *)brother->left)->color == black &&
		((RBTNode *)brother->right)->color == black) {
		brother->color = red;
		pointerNode = pointerNode->parent;
	}
	// BLACK BROTHER WITH ONE RED SON
	else {
		if (((RBTNode *)brother->right)->color == black) {
			((RBTNode *)brother->left)->color = black;
			brother->color = red;
			__rBTNodeRotateRight(brother, &(*root));
			brother = ((RBTNode *)pointerNode->parent)->right;
		}
		brother->color = ((RBTNode *)pointerNode->parent)->color;
		((RBTNode *)pointerNode->parent)->color = black;
		((RBTNode *)brother->right)->color = black;
		__rBTNodeRotateLeft(pointerNode->parent, &(*root));
		pointerNode = *root;
	}
	return pointerNode;
}

//	__rBTRemoveFixupLeftBrother(RBTNode *pointerNode, RBTNode ** root);
//
//	INPUT: 
//	RBTNode* pointerNode as pointer to a node.
//  RBTNode** root as pointer to root's reference.
//
//	OUTPUT:
//	Returns a pointer to RBTNode.
//	
//	Description:
//  Performs fixes for left bother case.
RBTNode* __rBTRemoveFixupLeftBrother(RBTNode *pointerNode, RBTNode ** root) {
	RBTNode *brother = ((RBTNode *)pointerNode->parent)->left;
	// RED BROTHER
	if (brother->color == red) {
		brother->color = black;
		((RBTNode *)pointerNode->parent)->color = red;
		__rBTNodeRotateRight(pointerNode->parent, &(*root));
		brother = ((RBTNode *)pointerNode->parent)->left;
	}
	// BLACK BROTHER WITH TWO BLACK SONS
	if (((RBTNode *)brother->right)->color == black && ((RBTNode *)brother->left)->color == black) {
		brother->color = red;
		pointerNode = pointerNode->parent;
	}
	// BLACK BROTHER WITH ONE RED SON
	else {
		if (((RBTNode *)brother->left)->color == black) {
			((RBTNode *)brother->right)->color = black;
			brother->color = red;
			__rBTNodeRotateLeft(brother, &(*root));
			brother = ((RBTNode *)pointerNode->parent)->left;
		}
		brother->color = ((RBTNode *)pointerNode->parent)->color;
		((RBTNode *)pointerNode->parent)->color = black;
		((RBTNode *)brother->left)->color = black;
		__rBTNodeRotateRight(pointerNode->parent, &(*root));
		pointerNode = *root;
	}
	return pointerNode;
}

//	__rBTRemoveFixup(RBTNode* pointerNode, RBTNode **root);
//
//	INPUT: 
//	RBTNode* pointerNode as pointer to a node.
//  RBTNode** root as pointer to root's reference.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//  Performs remotion's fixes.
void __rBTRemoveFixup(RBTNode *pointerNode, RBTNode ** root) {
	// IF BLACK AND NOT ROOT 
	while (pointerNode != *root && pointerNode->color == black)
		if (pointerNode == ((RBTNode *)pointerNode->parent)->left)
			pointerNode = __rBTRemoveFixupRightBrother(pointerNode, &(*root));
		else
			pointerNode = __rBTRemoveFixupLeftBrother(pointerNode, &(*root));
	pointerNode->color = black;
}

//	__rBTRemoveFixesGuidelines(RBTNode* pointerNode, RBTNode **root);
//
//	INPUT: 
//	RBTNode* pointerNode as pointer to a node.
//  RBTNode** root as pointer to root's reference.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//  Performs fixes.
//  Calls fixes for each case.
void __rBTRemoveFixesGuidelines(RBTNode* pointerNode, RBTNode** root) {
	RBTNode *local, *temp;
	// NULL, RETURN;
	if (!pointerNode || pointerNode == NIL_RBTNode) return;
	// AT LEAST ONE NULL NODE
	if (pointerNode->left == NIL_RBTNode || pointerNode->right == NIL_RBTNode)
		temp = pointerNode;
	// NO NULL NODE, TREE'S CENTER: TAKE THE LOWEST OF THE MAJORS (__rBTPredecessor)
	else temp = __rBTPredecessor(pointerNode);
	if (temp->left != NIL_RBTNode) local = temp->left;
	else local = temp->right;
	// EXCHANGE PARENT
	local->parent = temp->parent;
	// IF NOT A ROOT
	if (temp->parent != NIL_RBTNode)
		if (temp == ((RBTNode*)temp->parent)->left)
			((RBTNode*)temp->parent)->left = local;
		else ((RBTNode*)temp->parent)->right = local;
		// IS ROOT
	else *root = local;
	// EXCHANGE VALUES
	if (temp != pointerNode) pointerNode->data = temp->data;
	// IF BLACK NODE ON THE EDGE
	if (temp->color == black) __rBTRemoveFixup(local, &(*root));
	RESET_SENTINEL_RBTNODE;
	free(temp);
}

//	__rBTRemoveNode(RBTNode* endPointerNode, RBTNode** root, int value);
//
//	INPUT: 
//	RBTNode* pointerNode as pointer to an node.
//  RBTNode** root as pointer to root's reference.
//	int value as value to be removed from the tree.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Remove a node in the tree.
//  Calls __rBTRemoveFixesGuidelines(endPointerNode, &(*root));
void __rBTRemoveNode(RBTNode* endPointerNode, RBTNode** root, int value) {
	if (endPointerNode == NIL_RBTNode || !endPointerNode) return;
	if (value == endPointerNode->data) {
		__rBTRemoveFixesGuidelines(endPointerNode, &(*root));
	}
	else {
		if (value < (endPointerNode)->data)
			__rBTRemoveNode((void *)endPointerNode->left, &(*root), value);
		else
			__rBTRemoveNode((void *)endPointerNode->right, &(*root), value);
	}
}

#pragma endregion

#pragma endregion

#pragma region EXTERNAL USE SECTION

//	__rBTLowerValue(RedBlackTree *self);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	int response = tree.lowerValue(&tree);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//
//	OUTPUT:
//	Returns an int as value of lower node.
//	
//	Description:
//	Calls __rBTSearchLowerValue(self->root);
int __rBTLowerValue(RedBlackTree *self) {
	RBTNode * Node = (void *)__rBTSearchLowerValue((void *)self->root);
	return Node != NIL_RBTNode ? Node->data : false;
}

//	__rBTHigherValue(RedBlackTree *self);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	int response = tree.higherValue(&tree);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//
//	OUTPUT:
//	Returns an int as value of higher node.
//	
//	Description:
//	Calls __rBTSearchHighValue(self->root);
int __rBTHigherValue(RedBlackTree *self) {
	RBTNode * Node = (void *)__rBTSearchHighValue((void *)self->root);
	return Node != NIL_RBTNode ? Node->data : false;
}

//	__rBTHeight(RedBlackTree *self);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	int response = tree.height(&tree);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//
//	OUTPUT:
//	Returns an int as height of the tree.
//	
//	Description:
//	Calls __rBTHeightNode(self->root);
int __rBTHeight(RedBlackTree *self) {
	int value = __rBTHeightNode((void *)self->root);
	return value == -1 ? -1 : value;
}

//	__bTIsEmpty(RedBlackTree *self);
//
//	Using:
//	RedBlackTree list = newRedBlackTree();
//	bool response = tree.isEmpty(&tree);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of tree, if it's empty or not.
bool __rBTIsEmpty(RedBlackTree *self) {
	return (self->root == NIL_RBTNode);
}

//	__rBTClear(RedBlackTree * self);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	tree.clear(&tree);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//
//	OUTPUT:
//  Nothing	
//	
//	Description:
//  Clear the tree completely, excluding all nodes.
//  Calls __rBTPostOrder(self->root, NIL_RBTNode, &__rBTFreeNode)
void __rBTClear(RedBlackTree *self) {
	if (self->root != NIL_RBTNode) __rBTPostOrder((void *)self->root, 0, (void *)&__rBTFreeNode);
	self->root = NIL_RBTNode;
}

//	__rBTContains(RedBlackTree * self, int value);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	tree.clear(&tree, 15);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//  int value as searched value.
//
//	OUTPUT:
//  true / false 	
//	
//	Description:
//  Returns true if value exists in tree content.
bool __rBTContains(RedBlackTree *self, int value) {
	return __rBTContainsNode((void *)self->root, value);
}

//	__rBTPrintSearch(RedBlackTree *self, int value);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	tree.printSearch(&tree, 15);
//
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//  int value as searched value.
//
//	OUTPUT:
//  true / false
//	
//	Description:
//	Prints the entire way to a node.
//	Calls __rBTPrintSearchNode(self->root, value);
void __rBTPrintSearch(RedBlackTree *self, int value) {
	if (__rBTContainsNode(self->root, value))
		__rBTPrintSearchNode((void *)self->root, value);
}

//	__rBTPrintTaggedInOrder(RedBlackTree *self);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	tree.printWithColor(&tree);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints the entire tree with color tag.
//	Calls __rBTInOrder(self->root, NIL_RBTNode, &__rBTPrintTaggedNode);
void __rBTPrintTaggedInOrder(RedBlackTree *self) { //__rBTPrintTaggedNode
	if (self->root != NIL_RBTNode) __rBTInOrder((void *)self->root, 0, (void *)&__rBTPrintTaggedNode);
}

//	__rBTPrintInPreOrder(RedBlackTree *self);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	tree.printInPreOrder(&tree);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints the entire tree.
//	Calls __rBTPreOrder(self->root, NIL_RBTNode, &__rBTPrintNode);
void __rBTPrintInPreOrder(RedBlackTree *self) {
	if (self->root != NIL_RBTNode) __rBTPreOrder((void *)self->root, 0, (void *)&__rBTPrintNode);
}

//	__rBTPrintInPostOrder(RedBlackTree *self);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	tree.printInPostOrder(&tree);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints the entire tree.
//	Calls __rBTPostOrder(self->root, NIL_RBTNode, &__rBTPrintNode);
void __rBTPrintInPostOrder(RedBlackTree *self) {
	if (self->root != NIL_RBTNode) __rBTPostOrder((void *)self->root, 0, (void *)&__rBTPrintNode);
}

//	__rBTPrintInOrder(RedBlackTree *self);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	tree.printInOrder(&tree);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints the entire tree.
//	Calls __rBTInOrder(self->root, NIL_RBTNode, &__rBTPrintNode);
void __rBTPrintInOrder(RedBlackTree *self) {
	if (self->root != NIL_RBTNode) __rBTInOrder((void *)self->root, 0, (void *)&__rBTPrintNode);
}

//	__rBTPrintPerLevel(RedBlackTree *self);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	tree.printPerLevel(&tree);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//	Prints the entire tree.
//	Calls __rBTPerLevel(self->root, NIL_RBTNode, i, &__rBTPrintNode);
void __rBTPrintPerLevel(RedBlackTree *self) {
	if (self->root != NIL_RBTNode) {
		int h = __rBTHeight((void*)self);
		int i = 0;
		for (i = 0; i <= h; i++)
			__rBTPerLevel((void *)self->root, 0, i, (void *)&__rBTPrintNode);
	}
}

//	__rBTItemAmout(RedBlackTree *self);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	tree.itemAmout(&tree);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//
//	OUTPUT:
//	Returns the amout of itens in the tree.
//	
//	Description:
//	Calls __rBTInOrder(self->root, &counter, &__rBTCounter);
int __rBTItemAmout(RedBlackTree *self) {
	int counter = 0;
	__rBTInOrder((void *)self->root, (void *)&counter, (void *)&__rBTCounter);
	return counter;
}

//	__rBTInsert(RedBlackTree *self, int value);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//	tree.insert(&tree, 20);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//  int value as new node value.
//
//	OUTPUT:
//	Nothing
//	
//	Description:
//  Inserts a new node.
//	Calls __rBTInsertNode(&(self->root), NIL_RBTNode, &(self->root), value);
void __rBTInsert(RedBlackTree *self, int value) {
	__rBTInsertNode((void *)&(self->root), NIL_RBTNode, (void *)&(self->root), value);
}

//	__rBTRemove(RedBlackTree *self, int value);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//  ...
//	tree.remove(&tree, 20);
//
//	INPUT: 
//	RedBlackTree *self as self indicator.
//  int value as value to be removed from the tree.
//
//	OUTPUT:
//	true / false
//	
//	Description:
//  Removes a node.
//	Calls __rBTRemoveNode(self->root, &(self->root), value);
bool __rBTRemove(RedBlackTree *self, int value) {
	if (__rBTContainsNode(self->root,value))
		__rBTRemoveNode(self->root, &(self->root), value);
	else return false;
	return true;
}

//	newRedBlackTree(void);
//
//	Using:
//	RedBlackTree tree = newRedBlackTree();
//
//	INPUT: 
//	Nothing
//
//	OUTUP:
//	RedBlackTree self as a newly built structure.
//	
//	Description:
//	Construction function of structure.
RedBlackTree newRedBlackTree() {
	RedBlackTree self;
	self.root = NIL_RBTNode;
	self.insert = (void *)&__rBTInsert;
	self.remove = (void *)&__rBTRemove;
	self.height = (void *)&__rBTHeight;
	self.itemAmount = (void *)&__rBTItemAmout;
	self.lowerValue = (void *)&__rBTLowerValue;
	self.higherValue = (void *)&__rBTHigherValue;
	self.isEmpty = (void *)&__rBTIsEmpty;
	self.clear = (void *)&__rBTClear;
	self.contains = (void *)&__rBTContains;
	self.printSearch = (void *)&__rBTPrintSearch;
	self.printWithColor = (void *)&__rBTPrintTaggedInOrder;
	self.printInPreOrder = (void *)&__rBTPrintInPreOrder;
	self.printInPostOrder = (void *)&__rBTPrintInPostOrder;
	self.printInOrder = (void *)&__rBTPrintInOrder;
	self.printPerLevel = (void *)&__rBTPrintPerLevel;
	return self;
}
#pragma endregion

#pragma endregion
