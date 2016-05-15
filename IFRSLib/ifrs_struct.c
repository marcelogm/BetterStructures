#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ifrs_io.h"
#include "ifrs_struct.h"

//
// Data Structure functions
//

//
// Obs.: bool is an int defined.
// #define bool int
//

// DEPRECATED, FULLY DOCUMENTED
#pragma region Stack (Array implementation)
//
// StackArray
//

//	__stackAEmpty(StackArray self);
//
//	Using:
//	StackArray stack = newStackArray();
//	bool response = stack.isEmpty(&stack);
//
//	INPUT: 
//	StackArray *localStack as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of stack, if it's empty or not.

bool __stackAEmpty(StackArray *localStack) {
	if (localStack->top == 0) return true;
	else return false;
}

//	__stackAFull(StackArray self);
//
//	Using:
//	StackArray stack = newStackArray();
//	bool response = stack.isFull(&stack);
//
//	INPUT: 
//	StackArray *localStack as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of stack, if it's full or not.
bool __stackAFull(StackArray *localStack) {
	if (localStack->top >= MAX_STACK_LEN) return true;
	else return false;
}

//	__stackAPush(StackArray self, int value);
//
//	Using:
//	StackArray stack = newStackArray();
//	bool response = stack.push(&stack, 20);
//
//	INPUT: 
//	StackArray *localStack as self indicator.
//	int value as variable to be inserted in the stack.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Inserts a value to stack and returns the insertion result.
bool __stackAPush(StackArray *localStack, int value) {
	if (__stackAFull(localStack) == true) {
		printf("\nERRO: Stack Overflow\n");
		system("pause");
		return false;
	}
	else {
		localStack->top++;
		localStack->stackArray[localStack->top] = value;
		return true;
	}
}

//	__stackAPop(StackArray self);
//
//	Using:
//	StackArray stack = newStackArray();
//	... 
//	int response = stack.pop(&stack);
//
//	INPUT: 
//	StackArray *localStack as self indicator.
//
//	OUTPUT:
//	Last inserted value in the stack. (FILO)
//	
//	Description:
//	Pops a value from stack and returns it
int __stackAPop(StackArray *localStack) {
	if (__stackAEmpty(localStack) == true) {
		printf("\nERRO: Stack Underflow\n");
		system("pause");
		return localStack->stackArray[localStack->top];
	}
	else {
		int temp = 0;
		temp = localStack->stackArray[localStack->top];
		localStack->stackArray[localStack->top] = 0;
		localStack->top--;
		return temp;
	}
}

//	__stackALastItem(StackArray self);
//
//	Using:
//	StackArray stack = newStackArray();
//	... 
//	int response = stack.getValue(&stack);
//
//	INPUT: 
//	StackArray *localStack as self indicator.
//
//	OUTPUT:
//	Last inserted value in the stack. (FILO)
//	
//	Description:
//	Returns the last inserted value in stack.
int __stackALastItem(StackArray *localStack) {
	return localStack->stackArray[localStack->top];
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
//	StackArray localStack as a newly built structure.
//	
//	Description:
//	Construction function of structure.
StackArray newStackArray() {
	StackArray localStack;
	localStack.top = 0;
	localStack.stackArray[localStack.top] = -1;
	localStack.push = (void *)&__stackAPush;
	localStack.pop = (void *)&__stackAPop;
	// To be changed soon
	localStack.getValue = (void *)&__stackALastItem;
	// End to be
	localStack.isEmpty = (void *)&__stackAEmpty;
	localStack.isFull = (void *)&__stackAFull;
	return localStack;
}

#pragma endregion

// IMPLEMENTING
#pragma region Stack (Linked Node implementation)
	// TODO
#pragma endregion

// DEPRECATED, FULLY DOCUMENTED
#pragma region Queue (Array implementation)
//	__queueAEmpty(QueueArray self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	bool response = queue.isEmpty(&queue);
//
//	INPUT: 
//	QueueArray *queueLocal as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of queue, if it's empty or not.
bool __queueAEmpty(QueueArray *queueLocal) {
	if (queueLocal->front == queueLocal->back) return true;
	else return false;
}

//	__queueAFull(QueueArray self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	bool response = queue.isFull(&queue);
//
//	INPUT: 
//	QueueArray *queueLocal as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of queue, if it is full or not.
bool __queueAFull(QueueArray *queueLocal) {
	if ((queueLocal->front - queueLocal->back == 1) || ((queueLocal->back == MAX_QUEUE_LEN - 1) && (queueLocal->front == 0)))
		return true;
	return false;
}

//	__dequeueA(QueueArray self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	... 
//	int response = queue.dequeue(&queue);
//
//	INPUT: 
//	QueueArray *queueLocal as self indicator.
//
//	OUTPUT:
//	First inserted value in the queue. (FIFO)
//	
//	Description:
//	Dequeue a value from queue and returns it.
int __dequeueA(QueueArray *queueLocal) {
	if (__queueAEmpty(queueLocal) != 1) {
		int value = queueLocal->queueArray[queueLocal->front];
		if (queueLocal->front == MAX_QUEUE_LEN - 1)	queueLocal->front = 0;
		else queueLocal->front++;
		return value;
	}
	else {
		printf("\nERRO: Queue Underflow\n");
		system("pause");
		return false;
	}
}

//	__enqueueA(QueueArray self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	bool response = queue.enqueue(&queue, 20);
//
//	INPUT: 
//	QueueArray *queueLocal as self indicator.
//	int value as value to enqueue.
//	
//	OUTPUT:
//	true / false as response
//
//	Description:
//	Enqueue a value to queue and returns the insertion result.
bool __enqueueA(QueueArray *queueLocal, int value) {
	if (__queueAFull(queueLocal) != 1) {
		queueLocal->queueArray[queueLocal->back] = value;
		if (queueLocal->back == MAX_QUEUE_LEN - 1) queueLocal->back = 0;
		else queueLocal->back++;
		return true;
	}
	else {
		printf("\nERRO: Queue Overflow\n");
		system("pause");
		return false;
	}
}

//	__queueALastItem(QueueArray self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	... 
//	int response = queue.lastItem(&queue);
//
//	INPUT: 
//	QueueArray *queueLocal as self indicator.
//
//	OUTUP:
//	Last inserted value in the queue. (FIFO)
//	
//	Description:
//  Returns the last inserted value
int __queueALastItem(QueueArray *queueLocal) {
	if (queueLocal->back == 0) 
		return queueLocal->queueArray[MAX_QUEUE_LEN - 1];
	else 
		return queueLocal->queueArray[queueLocal->back - 1];
}

//	__queueAFirstItem(QueueArray self);
//
//	Using:
//	QueueArray queue = newQueueArray();
//	... 
//	int response = queue.firstItem(&queue);
//
//	INPUT: 
//	QueueArray *queueLocal as self indicator.
//
//	OUTUP:
//	First inserted value in the queue. (FIFO)
//	
//	Description:
//  Returns the first inserted value
int __queueAFirstItem(QueueArray *queueLocal) {
	return queueLocal->queueArray[queueLocal->front];
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
//	QueueArray queueLocal as a newly built structure.
//	
//	Description:
//	Construction function of structure.
QueueArray newQueueArray() {
	QueueArray queueLocal;
	queueLocal.front = 0;
	queueLocal.back = 0;
	queueLocal.enqueue = (void *)&__enqueueA;
	queueLocal.dequeue = (void *)&__dequeueA;
	queueLocal.lastItem = (void *)&__queueALastItem;
	queueLocal.firstItem = (void *)&__queueAFirstItem;
	queueLocal.isEmpty = (void *)&__queueAEmpty;
	queueLocal.isFull = (void *)&__queueAFull;
	return queueLocal;
}

#pragma endregion

// IMPLEMENTING
#pragma region Queue (Linked Node implementation)
// TODO
#pragma endregion

// DEPRECATED, FULLY DOCUMENTED
#pragma region Ordered List (Array implementation)

//	__oListIsAEmpty(OrderedList self);
//
//	Using:
//	OrderedList list = newOrderedList();
//	bool response = list.isEmpty(&list);
//
//	INPUT: 
//	OrderedList *OList as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of list, if it's empty or not.
bool __oListIsEmpty(OrderedList *OList) {
	if (OList->endIndex == 0) return true;
	return false;
}

//	__oListIsFull(OrderedList self);
//
//	Using:
//	OrderedList list = newOrderedList();
//	bool response = list.isFull(&list);
//
//	INPUT: 
//	OrderedList *OList as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of list, if it's full or not.
bool __oListIsFull(OrderedList *OList) {
	if (OList->endIndex == MAX_ORDERED_LIST_LEN) return true;
	return false;
}

//	__oListInsert(OrderedList self, int value);
//
//	Using:
//	OrderedList list = newOrderedList();
//	bool response = list.insert(&list, 20);
//
//	INPUT: 
//	OrderedList *OList as self indicator.
//	int value as item to be added in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Inserts a new item in the list, returns a response about insertion.
bool __oListInsert(OrderedList *OList, int value) {
	if (__oListIsFull(OList) == false) {
		int i, j;
		for (i = 0; i < OList->endIndex; i++)
			if (OList->orderedListArray[i] > value) break;
		if (OList->endIndex > 0)
			for (j = OList->endIndex; j > i; j--)
				OList->orderedListArray[j] = OList->orderedListArray[j - 1];
		OList->orderedListArray[i] = value;
		OList->endIndex++;
		return true;
	}
	return false;
}

//	__oListRemove(OrderedList self, int value);
//
//	Using:
//	OrderedList list = newOrderedList();
//	...
//	bool response = list.remove(&list, 20);
//
//	INPUT: 
//	OrderedList *OList as self indicator.
//	int value as item to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oListRemove(OrderedList *OList, int value) {
	if (__oListIsEmpty(OList) == false) {
		int i, j;
		bool breaked = false;
		// Search value in the list.
		for (i = 0; i < OList->endIndex; i++)
			if (OList->orderedListArray[i] == value) {
				breaked = true;
				break;
			}

		// Reorders values in the list.
		for (j = i; j < OList->endIndex; j++) {
			if (j + 1 < MAX_ORDERED_LIST_LEN)
				OList->orderedListArray[j] = OList->orderedListArray[j + 1];
			else
				OList->orderedListArray[j] = 0;
		}

		if (breaked == true) OList->endIndex--;
		return true;
	}
	return false;
}

//	__oListRemoveAtIndex(OrderedList self, int index);
//
//	Using:
//	OrderedList list = newOrderedList();
//  ...
//	bool response = list.removeAtIndex(&list, 3);
//
//	INPUT: 
//	OrderedList *OList as self indicator.
//	int index as item's reference to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oListRemoveAtIndex(OrderedList *OList, int index) {
	int i = 0;
	if ((__oListIsEmpty(OList) == false) && (index < OList->endIndex) && (index >= 0)) {
		for (i = index; i < OList->endIndex; i++) {
			if (i + 1 < MAX_ORDERED_LIST_LEN)
				OList->orderedListArray[i] = OList->orderedListArray[i + 1];
			else
				OList->orderedListArray[i] = 0;
		}
		OList->endIndex--;
		return true;
	}
	return false;
}

//	__oListGetItem(OrderedList self, int index);
//
//	Using:
//	OrderedList list = newOrderedList();
//  ...
//	int response = list.getItem(&list, 3);
//
//	INPUT: 
//	OrderedList *OList as self indicator.
//	int index as item's reference 
//
//	OUTPUT:
//  List item at the index as integer.	
//	
//	Description:
//	Returns an item in the list
int __oListGetItem(OrderedList *OList, int index) {
	if (index < OList->endIndex && index >= 0)
		return OList->orderedListArray[index];
	return false;
}

//	__oListLastItem(OrderedList self);
//
//	Using:
//	OrderedList list = newOrderedList();
//  ...
//	int response = list.lastItem(&list);
//
//	INPUT: 
//	OrderedList *OList as self indicator.
//
//	OUTPUT:
//  Last list item as integer.	
//	
//	Description:
//	Returns a last item in the list.
int __oListLastItem(OrderedList *OList) {
	return OList->orderedListArray[OList->endIndex - 1];
}

//	__oListFirstItem(OrderedList self);
//
//	Using:
//	OrderedList list = newOrderedList();
//  ...
//	int response = list.firstItem(&list);
//
//	INPUT: 
//	OrderedList *OList as self indicator.
//
//	OUTPUT:
//  First list item as integer.	
//	
//	Description:
//	Returns a first item in the list.
int __oListFirtItem(OrderedList *OList) {
	return OList->orderedListArray[0];
}

//	__oListItemAmout(OrderedList self);
//
//	Using:
//	OrderedList list = newOrderedList();
//  ...
//	int response = list.itemAmout(&list);
//
//	INPUT: 
//	OrderedList *OList as self indicator.
//
//	OUTPUT:
//  Item amout as integer.	
//	
//	Description:
//  Returns the amount of items in the list.
int __oListItemAmout(OrderedList *OList) {
	return OList->endIndex;
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
//	OrderedList OListLocal as a newly built structure.
//	
//	Description:
//	Construction function of structure.
OrderedList newOrderedList() {
	OrderedList OListLocal;
	OListLocal.endIndex = 0;
	OListLocal.insert = (void *)&__oListInsert;
	OListLocal.remove = (void *)&__oListRemove;
	OListLocal.removeAtIndex = (void *)&__oListRemoveAtIndex;
	OListLocal.getItem = (void *)&__oListGetItem;
	OListLocal.lastItem = (void *)&__oListLastItem;
	OListLocal.firstItem = (void *)&__oListFirtItem;
	OListLocal.isEmpty = (void *)&__oListIsEmpty;
	OListLocal.isFull = (void *)&__oListIsFull;
	OListLocal.itemAmount = (void *)&__oListItemAmout;
	return OListLocal;
}

#pragma endregion

// FULLY DOCUMENTED, NEW FEATURES CAN BE ADDED
#pragma region Ordered List (Linked Node implementation)

//	__oLListIsAEmpty(OrderedLinkedList self);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//	bool response = list.isEmpty(&list);
//
//	INPUT: 
//	OrderedLinkedList *OLList as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of list, if it's empty or not.
bool __oLListIsEmpty(OrderedLinkedList *OLList) {
	if (OLList->start == NULL) return true;
	return false;
}

//	__oLListInsert(OrderedLinkedList self, int value);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//	bool response = list.insert(&list, 20);
//
//	INPUT: 
//	OrderedLinkedList *OLList as self indicator.
//	int value as item to be added in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Inserts a new item in the list, returns a response about insertion.
void __oLListInsert(OrderedLinkedList *OLList, int value) {
	Node *prev, *next;
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = value;
	temp->next = NULL;
	if (__oLListIsEmpty(OLList)) OLList->start = (void *)temp;
	else {
		prev = NULL;
		next = (void *)OLList->start;
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
				temp->next = OLList->start;
				OLList->start = (void *)temp;
			}
		}
	}
}

//	__oLListRemove(OrderedLinkedList self, int value);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//	...
//	bool response = list.remove(&list, 20);
//
//	INPUT: 
//	OrderedLinkedList *OLList as self indicator.
//	int value as item to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oLListRemove(OrderedLinkedList *OLList, int value) {
	Node *current = (void *)OLList->start;
	Node *prev = NULL;
	while (current != NULL) {
		if (current->data == value) {
			// Delete
			// Case: first item.
			if (prev == NULL) OLList->start = (void *)current->next;
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

//	__oLListRemoveAtIndex(OrderedLinkedList self, int index);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	bool response = list.removeAtIndex(&list, 3);
//
//	INPUT: 
//	OrderedLinkedList *OLList as self indicator.
//	int index as item's reference to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oLListRemoveAtIndex(OrderedLinkedList *OLList, int index) {
	Node *current = (void *)OLList->start;
	Node *prev = NULL;
	int count = 0;
	while (current->next != NULL) {
		if (count == index) {
			// Delete
			// Case: first item.
			if (prev == NULL) OLList->start = (void *)current->next;
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

//	__oLListGetItem(OrderedLinkedList self, int index);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	int response = list.getItem(&list, 3);
//
//	INPUT: 
//	OrderedLinkedList *OLList as self indicator.
//	int index as item's reference to be returned in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Get an item in the list
int __oLListGetItem(OrderedLinkedList *OLList, int index) {
	if (__oLListIsEmpty(OLList) != true) {
		Node *current = (void *)OLList->start;
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

//	__oLListLastItem(OrderedLinkedList self);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	int response = list.lastItem(&list);
//
//	INPUT: 
//	OrderedLinkedList *OLList as self indicator.
//
//	OUTPUT:
//  Last list item as integer.
//	
//	Description:
//	Returns a last item in the list.
int __oLListLastItem(OrderedLinkedList *OLList) {
	if (__oLListIsEmpty(OLList) != true) {
		Node *current = (void *)OLList->start;
		while (current->next != NULL) current = (void *)current->next;
		return current->data;
	}
	return false;
}

//	__oLListFirstItem(OrderedLinkedList self);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	int response = list.firstItem(&list);
//
//	INPUT: 
//	OrderedLinkedList *OLList as self indicator.
//
//	OUTPUT:
//  First list item as integer.	
//	
//	Description:
//	Returns a first item in the list.
int __oLListFirstItem(OrderedLinkedList *OLList) {
	if (__oLListIsEmpty(OLList) != true) {
		Node* current = (void *)OLList->start;
		return current->data;
	}
	return false;
}

//	__oLListItemAmout(OrderedLinkedList self);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	int response = list.itemAmout(&list);
//
//	INPUT: 
//	OrderedLinkedList *OLList as self indicator.
//
//	OUTPUT:
//  Item amout as integer.	
//	
//	Description:
//  Returns the amount of items in the list.
int __oLListItemAmout(OrderedLinkedList *OLList) {
	int count = 0;
	Node *current = (void *)OLList->start;
	while (current != NULL) {
		current = (void *)current->next;
		count++;
	}
	return count + 1;
}

//	__oLListClear(OrderedLinkedList self);
//
//	Using:
//	OrderedLinkedList list = newOrderedLinkedList();
//  ...
//	list.clear(&list);
//
//	INPUT: 
//	OrderedLinkedList *OLList as self indicator.
//
//	OUTPUT:
//  Nothing	
//	
//	Description:
//  Clear the list completely, excluding all nodes.
void __oLListClear(OrderedLinkedList *OLList) {
	Node * current = (void *)OLList->start;
	while (current != NULL) {
		DNode *temp = (void *)current->next;
		free(current);
		current = (void *)temp;
	}
	OLList->start = NULL;
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
//	OrderedLinkedList OLList as a newly built structure.
//	
//	Description:
//	Construction function of structure.
OrderedLinkedList newOrderedLinkedList() {
	OrderedLinkedList OLList;
	OLList.start = NULL;
	OLList.insert = (void *)&__oLListInsert;
	OLList.remove = (void *)&__oLListRemove;
	OLList.removeAtIndex = (void *)&__oLListRemoveAtIndex;
	OLList.getItem = (void *)&__oLListGetItem;
	OLList.isEmpty = (void *)&__oLListIsEmpty;
	OLList.firstItem = (void *)&__oLListFirstItem;
	OLList.lastItem = (void *)&__oLListLastItem;
	OLList.itemAmount = (void *)&__oLListItemAmout;
	OLList.clear = (void *)&__oLListClear;
	return OLList;
}

#pragma endregion

// DOCUMENTING, NEW FEATURES CAN BE ADDED
#pragma region Ordered List (Doubly Linked Node implementation)

//  LIBRARY INTERNAL USE
//	__oDLListFind(OrderedDoublyLinkedList self, int value);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//	DNode *temp = list.isEmpty(&list, 20);
//
//	INPUT: 
//	OrderedLinkedList *OLList as self indicator.
//  int value as reference to find a node.
//
//	OUTPUT:
//	Return a DNode pointer in the list.
//	
//	Description:
//	Find a list item and return it.
DNode* __oDLListFind(OrderedDoublyLinkedList *ODLList, int value) {
	DNode *temp = (void *)ODLList->start;
	if (temp == NULL) return NULL;
	while (temp->next != NULL && ((DNode*)temp->next)->data < value)
		temp = (void *)temp->next;
	return temp;
}

//	__oDLListInsert(OrderedDoublyLinkedList self, int value);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//	bool response = list.insert(&list, 20);
//
//	INPUT: 
//	OrderedDoublyLinkedList *ODLList as self indicator.
//	int value as item to be added in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Inserts a new item in the list, returns a response about insertion.
void __oDLListInsert(OrderedDoublyLinkedList *ODLList, int value) {
	DNode *prev = __oDLListFind(ODLList, value);
	DNode *current = (DNode *)malloc(sizeof(DNode));
	current->data = value;
	if (prev == NULL || prev->data > value) {
		// First item
		current->next = ODLList->start;
		ODLList->start = (void *)current;
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

//	__oDLListRemove(OrderedDoublyLinkedList self, int value);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//	...
//	bool response = list.remove(&list, 20);
//
//	INPUT: 
//	OrderedDoublyLinkedList *ODLList as self indicator.
//	int value as item to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oDLListRemove(OrderedDoublyLinkedList *ODLList, int value) {
	DNode * current = (void *)ODLList->start;
	while (current != NULL && current->data != value) {
		current = (void *)current->next;
	}
	if (current == NULL) return false;
	if (current->next != NULL) ((DNode *)current->next)->previous = current->previous;
	if (current->previous != NULL) ((DNode *)current->previous)->next = current->next;
	else ODLList->start = current->next;
	free(current);
	return true;
}

//	__oDLListRemoveAtIndex(OrderedDoublyLinkedList self, int index);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	bool response = list.removeAtIndex(&list, 3);
//
//	INPUT: 
//	OrderedDoublyLinkedList *OLList as self indicator.
//	int index as item's reference to be removed in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Removes an item in the list, returns a response about the remotion
bool __oDLListRemoveAtIndex(OrderedDoublyLinkedList *ODLList, int index) {
	DNode * current = (void *)ODLList->start;
	int count = 0;
	while (current != NULL) {
		if (count == index) break;
		current = (void *)current->next;
		count++;
	}
	if (current == NULL) return false;
	if (current->next != NULL) ((DNode *)current->next)->previous = current->previous;
	if (current->previous != NULL) ((DNode *)current->previous)->next = current->next;
	else ODLList->start = current->next;
	free(current);
	return true;
}

//	__oDLListGetItem(OrderedDoublyLinkedList self, int index);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	int response = list.getItem(&list, 3);
//
//	INPUT: 
//	OrderedDoublyLinkedList *ODLList as self indicator.
//	int index as item's reference to be returned in the list
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Get an item in the list
int __oDLListGetItem(OrderedDoublyLinkedList *ODLList, int index) {
	DNode * current = (void *)ODLList->start;
	int count = 0;
	while (current != NULL) {
		if (count == index) break;
		current = (void *)current->next;
		count++;
	}
	if (current == NULL) return false;
	else return current->data;
}

//	__oDLListLastItem(OrderedDoublyLinkedList self);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	int response = list.lastItem(&list);
//
//	INPUT: 
//	OrderedDoublyLinkedList *ODLList as self indicator.
//
//	OUTPUT:
//  Last list item as integer.
//	
//	Description:
//	Returns a last item in the list.
int __oDLListLastItem(OrderedDoublyLinkedList *ODLList) {
	if (ODLList->start == NULL) return false;
	DNode * current = (void *)ODLList->start;
	while (current->next != NULL) current = (void *)current->next;
	return current->data;
}

//	__oDLListFirstItem(OrderedDoublyLinkedList self);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	int response = list.firstItem(&list);
//
//	INPUT: 
//	OrderedDoublyLinkedList *ODLList as self indicator.
//
//	OUTPUT:
//  First list item as integer.	
//	
//	Description:
//	Returns a first item in the list.
int __oDLListFirstItem(OrderedDoublyLinkedList *ODLList) {
	if (ODLList->start == NULL) return false;
	else return ((DNode *)ODLList->start)->data;
}

//	__oDLListIsAEmpty(OrderedDoublyLinkedList self);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//	bool response = list.isEmpty(&list);
//
//	INPUT: 
//	OrderedDoublyLinkedList *ODLList as self indicator.
//
//	OUTPUT:
//	true / false as response
//	
//	Description:
//	Returns the current state of list, if it's empty or not.
bool __oDLListIsEmpty(OrderedDoublyLinkedList *ODLList) {
	return (ODLList->start == NULL);
}

//	__oDLListItemAmout(OrderedDoublyLinkedList self);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	int response = list.itemAmout(&list);
//
//	INPUT: 
//	OrderedDoublyLinkedList *ODLList as self indicator.
//
//	OUTPUT:
//  Item amout as integer.	
//	
//	Description:
//  Returns the amount of items in the list.
int __oDLListItemAmout(OrderedDoublyLinkedList *ODLList) {
	int count = 0;
	DNode *current = (void *)ODLList->start;
	while (current != NULL) {
		current = (void *)current->next;
		count++;
	}
	return count + 1;
}

//	__oDLListClear(OrderedDoublyLinkedList self);
//
//	Using:
//	OrderedDoublyLinkedList list = newOrderedDoublyLinkedList();
//  ...
//	list.clear(&list);
//
//	INPUT: 
//	OrderedDoublyLinkedList *ODLList as self indicator.
//
//	OUTPUT:
//  Nothing	
//	
//	Description:
//  Clear the list completely, excluding all nodes.
void __oDLListClear(OrderedDoublyLinkedList *ODLList) {
	DNode * current = (void *)ODLList->start;
	while (current != NULL) {
		DNode *temp = (void *)current->next;
		free(current);
		current = temp;
	}
	ODLList->start = NULL;
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
//	OrderedDoublyLinkedList ODLList as a newly built structure.
//	
//	Description:
//	Construction function of structure.
OrderedDoublyLinkedList newOrderedDoublyLinkedList() {
	OrderedDoublyLinkedList ODLList;
	ODLList.start = NULL;
	ODLList.insert = (void *)&__oDLListInsert;
	ODLList.remove = (void *)&__oDLListRemove;
	ODLList.removeAtIndex = (void *)&__oDLListRemoveAtIndex;
	ODLList.getItem = (void *)&__oDLListGetItem;
	ODLList.lastItem = (void *)&__oDLListLastItem;
	ODLList.firstItem = (void *)&__oDLListFirstItem;
	ODLList.isEmpty = (void *)&__oDLListIsEmpty;
	ODLList.itemAmount = (void *)&__oDLListItemAmout;
	ODLList.clear = (void *)&__oDLListClear;
	return ODLList;
}

#pragma endregion

// DOCUMENTING, NEW FEATURES CAN BE ADDED
#pragma region Binary Tree

TNode* __bTSearchLowerValue(TNode* pointerNode) {
	if (pointerNode == NULL) return NULL;
	while (pointerNode->left != NULL) {
		pointerNode = (void *)pointerNode->left;
	}
	return pointerNode;
}

int __bTLowerValue(BinaryTree *BTree) {
	TNode * Node = (void *)__bTSearchLowerValue((void *)BTree->root);
	return Node != NULL ? Node->data : false;
}

TNode* __bTSearchHighValue(TNode* pointerNode) {
	if (pointerNode == NULL) return NULL;
	while (pointerNode->right != NULL) {
		pointerNode = (void *)pointerNode->right;
	}
	return pointerNode;
}

int __bTHighValue(BinaryTree *BTree) {
	TNode * Node = __bTSearchHighValue((void *)BTree->root);
	return Node != NULL ? Node->data : false;
}

int __bTHeightNode(TNode *pointerNode) {
	if (pointerNode == NULL) return -1;
	int lHighValue = __bTHeightNode((void *)pointerNode->left);
	int rHighValue = __bTHeightNode((void *)pointerNode->right);
	if (lHighValue > rHighValue)
		return lHighValue + 1;
	else
		return rHighValue + 1;
}

int __bTHeight(BinaryTree *BTree) {
	int value = __bTHeightNode((void *)BTree->root);
	return value == -1 ? -1 : value;
}

bool __bTIsEmpty(BinaryTree *BTree) {
	return (BTree->root == NULL);
}

void __bTFreeNode(TNode * pointerNode, int *null) {
	free(pointerNode);
}

void __bTPrintNode(TNode * pointerNode, int *null) {
	printf("%d ", pointerNode->data);
}

void __bTCounter(TNode *null, int *counter) {
	(*counter)++;
}

void __bTPreOrder(TNode *pointerNode, int* counter, void * (function)(struct TNode*, int *counter)) {
	if (pointerNode != NULL) {
		(void)function((void *)pointerNode, counter);
		__bTPreOrder((void *)pointerNode->left, counter, function);
		__bTPreOrder((void *)pointerNode->right, counter, function);
	}
}

void __bTPostOrder(TNode *pointerNode, int* counter, void * (function)(struct TNode*, int *counter)) {
	if (pointerNode != NULL) {
		__bTPostOrder((void *)pointerNode->left, counter, function);
		__bTPostOrder((void *)pointerNode->right, counter, function);
		(void)function((void *)pointerNode, counter);
	}
}

void __bTInOrder(TNode *pointerNode, int* counter, void * (function)(struct TNode*, int *counter)) {
	if (pointerNode != NULL) {
		__bTInOrder((void *)pointerNode->left, counter, function);
		(void)function((void *)pointerNode, counter);
		__bTInOrder((void *)pointerNode->right, counter, function);
	}
}

void __bTPerLevel(TNode *pointerNode, int* counter, int level, void * (function)(struct TNode*, int *counter)) {
	if (pointerNode == NULL) return;
	if (level == 0)
		(void)function((void *)pointerNode, counter);
	else if (level > 0) {
		__bTPerLevel((void *)pointerNode->left, counter, level - 1, function);
		__bTPerLevel((void *)pointerNode->right, counter, level - 1, function);
	}
}

void __bTClear(BinaryTree *BTree) {
	if (BTree->root != NULL) __bTPostOrder((void *)BTree->root, NULL, (void *)&__bTFreeNode);
	BTree->root = NULL;
}

void __bTPrintInPreOrder(BinaryTree *BTree) {
	if (BTree->root != NULL) __bTPreOrder((void *)BTree->root, NULL, (void *)&__bTPrintNode);
}

void __bTPrintInPostOrder(BinaryTree *BTree) {
	if (BTree->root != NULL) __bTPostOrder((void *)BTree->root, NULL, (void *)&__bTPrintNode);
}

void __bTPrintInOrder(BinaryTree *BTree) {
	if (BTree->root != NULL) __bTInOrder((void *)BTree->root, NULL, (void *)&__bTPrintNode);
}

void __bTPrintPerLevel(BinaryTree *BTree) {
	if (BTree->root != NULL) {
		int h = __bTHeight((void*)BTree);
		int i = 0;
		for (i = 0; i <= h; i++)
			__bTPerLevel((void *)BTree->root, NULL, i, (void *)&__bTPrintNode);
	}
}

int __bTItemAmout(BinaryTree *BTree) {
	int counter = 0;
	__bTInOrder((void *)BTree->root, &counter, (void *)&__bTCounter);
	return counter;
}

void __bTInsertNode(TNode** endPointerNode, int value) {
	if (*endPointerNode == NULL) {
		*endPointerNode = malloc(sizeof(TNode));
		(*endPointerNode)->data = value;
		(*endPointerNode)->left = NULL;
		(*endPointerNode)->right = NULL;
	}
	else {
		if (value < (*endPointerNode)->data)
			__bTInsertNode((void *)&(*endPointerNode)->left, value);
		else
			__bTInsertNode((void *)&(*endPointerNode)->right, value);
	}
}

void __bTInsert(BinaryTree *BTree, int value) {
	__bTInsertNode((void*)&(BTree->root), value);
}

TNode* __bTRemoveNode(TNode** endPointerNode, int value) {
	if ((*endPointerNode) == NULL) return NULL;
	if (value < (*endPointerNode)->data)
		(*endPointerNode)->left = (void *)__bTRemoveNode((void *)&((*endPointerNode)->left), value);
	else if (value >(*endPointerNode)->data)
		(*endPointerNode)->right = (void *)__bTRemoveNode((void *)&((*endPointerNode)->right), value);
	else {
		if ((*endPointerNode)->left == NULL) {
			TNode* temp = (void*)(*endPointerNode)->right;
			free((*endPointerNode));
			(*endPointerNode) = temp;
			return temp;
		}
		else if ((*endPointerNode)->right == NULL) {
			TNode* temp = (void*)(*endPointerNode)->left;
			free((*endPointerNode));
			(*endPointerNode) = temp;
			return temp;
		}
		TNode* temp = (void*)__bTSearchLowerValue((void *)&((*endPointerNode)->right));
		(*endPointerNode)->data = temp->data;
		(*endPointerNode)->right = (void *)__bTRemoveNode((void *)&((*endPointerNode)->right), temp->data);
	}
	return (*endPointerNode);
}

bool __bTRemove(BinaryTree *BTree, int value) {
	return (__bTRemoveNode((void *)&(BTree->root), value) != NULL);
}

BinaryTree newBinaryTree() {
	BinaryTree BTree;
	BTree.root = NULL;
	BTree.insert = (void *)&__bTInsert;
	BTree.remove = (void *)&__bTRemove;
	BTree.height = (void *)&__bTHeight;
	BTree.itemAmount = (void *)&__bTItemAmout;
	BTree.lowerValue = (void *)&__bTLowerValue;
	BTree.higherValue = (void *)&__bTHighValue;
	BTree.isEmpty = (void *)__bTIsEmpty;
	BTree.clear = (void *)__bTClear;
	BTree.printInPreOrder = (void *)&__bTPrintInPreOrder;
	BTree.printInPostOrder = (void *)&__bTPrintInPostOrder;
	BTree.printInOrder = (void *)&__bTPrintInOrder;
	BTree.printPerLevel = (void *)&__bTPrintPerLevel;
	return BTree;
}

#pragma endregion

// IMPLEMENTING
#pragma region Red-Black Tree
// Definitions
void __rBTInsertFixesGuidelines(RBTNode *pointerNode);
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
	RBTNode* tempNode = __rBTNewNode(value);
	if (*endPointerNode == NULL) {
		tempNode->parent = parentPoiterNode;
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
		((RBTNode*)temp->left)->parent = pointerNode;
	temp->parent = pointerNode->parent;
	if (pointerNode->parent == NULL) *root = temp;
	else
		if (pointerNode == ((RBTNode*)pointerNode->parent)->left)
			((RBTNode*)pointerNode->parent)->left = temp;
		else
			((RBTNode*)pointerNode->parent)->right = temp;
	temp->left = pointerNode;
	pointerNode->parent = temp;
}

void __rBTNodeRotateRight(RBTNode* pointerNode, RBTNode** root) {
	RBTNode* temp = (RBTNode*)pointerNode->left;
	pointerNode->left = temp->right;
	if (temp->right != NULL)
		((RBTNode*)temp->right)->parent = pointerNode;
	temp->parent = pointerNode->parent;
	if (pointerNode->parent == NULL) *root = temp;
	else
		if (pointerNode == ((RBTNode*)pointerNode->parent)->left)
			((RBTNode*)pointerNode->parent)->left = temp;
		else
			((RBTNode*)pointerNode->parent)->right = temp;
	temp->right = pointerNode;
	pointerNode->parent = temp;
}

RBTNode* __rBTNodeUncle(RBTNode* pointerNode) {
	RBTNode* grand = __rBTNodeGrandfather(pointerNode);
	if (grand == NULL)
		return NULL;
	if (pointerNode->parent == grand->left)
		return grand->right;
	else
		return grand->left;
}

RBTNode* __rBTNodeGrandfather(RBTNode* pointerNode) {
	if ((pointerNode != NULL) && (pointerNode->parent != NULL))
		return ((RBTNode*)pointerNode->parent)->parent;
	else
		return (void*)NULL;
}

void __rBTFixesCaseFive(RBTNode* pointerNode, RBTNode **root) {
	RBTNode * grand = __rBTNodeGrandfather(pointerNode);
	((RBTNode*)pointerNode->parent)->color = black;
	grand->color = red;
	if ((pointerNode == ((RBTNode*)pointerNode->parent)->left))// && (pointerNode->parent == grand->left))
		__rBTNodeRotateRight(grand, &(*root));
	else
		__rBTNodeRotateLeft(grand, &(*root));
}

void __rBTFixesCaseFour(RBTNode* pointerNode, RBTNode **root) {
	RBTNode *grand = __rBTNodeGrandfather(pointerNode);
	if ((pointerNode == ((RBTNode *)pointerNode->parent)->right) && (pointerNode->parent == grand->left)) {
		__rBTNodeRotateLeft(pointerNode->parent, &(*root));
		pointerNode = pointerNode->left;
	}
	else if ((pointerNode == ((RBTNode *)pointerNode->parent)->left) && (pointerNode->parent == grand->right)) {
		__rBTNodeRotateRight(pointerNode->parent, &(*root));
		pointerNode = pointerNode->right;
	}
	__rBTFixesCaseFive(pointerNode, &(*root));
}

void __rBTFixesCaseThree(RBTNode* pointerNode, RBTNode **root) {
	RBTNode* uncle = __rBTNodeUncle(pointerNode), *grand;
	((RBTNode*)pointerNode->parent)->color = black;
	uncle->color = black;
	grand = __rBTNodeGrandfather(pointerNode);
	grand->color = red;
	__rBTInsertFixesGuidelines(grand, &(*root));
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
