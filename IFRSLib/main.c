#include <stdio.h>
#include <stdio.h>
#include <stdarg.h>
#include "ifrs_io.h"
#include "ifrs_struct.h"
#include <windows.h>
// New
#include <stdbool.h>

#define MAX_LEN 255

int main(){
	short a;
	int b;
	long c;
	float d;
	double e;
	char g;
	char h[MAX_LEN];

	//---- LEITURA DE DADOS ----//

	printf("\n\n LEITURA DE DADOS \n\n\n");

	readShort(&a, "Digite um short:\n", "Somente Short\n");
	readInt(&b, "Digite um int:\n", "Somente int\n");
	readLong(&c, "Digite um long:\n", "Somente long\n");
	readFloat(&d, "Digite um float:\n", "Somente float\n");
	readDouble(&e, "Digite um double:\n", "Somente Double\n");
	readChar(&g, "Digite um char:\n");
	readString(h, MAX_LEN, "Digite uma string:\n");

	//---- IMPRIMIR DADOS ----//

	printf("\n\n\n IMPRESSAO DE DADOS \n\n\n");

	printShort("Short:\n", a);
	printInt("Int:\n", b);
	printLong("Long:\n", c);
	printFloat("Float:\n", d);
	printDouble("Double:\n", e);
	printChar("Char:\n", g);
	printString("String:\n", h);

	//---- FUNгуES ANTIGAS ----//

	printf("\n\n\n FUNCOES ANTIGAS \n\n\n");

	b = readIntRet("\nDigite um int:\n", "Somente int\n");
	c = readLongRet("Digite um long:\n", "Somente long\n");
	d = readFloatRet("Digite um float:\n", "Somente float\n");
	g = readCharRet("Digite um char:\n");

	printInt("Int:\n", b);
	printLong("Long:\n", c);
	printFloat("Float:\n", d);
	printChar("Char:\n", g);

	char *i = readStringRet("Digite uma string:\n", MAX_LEN);

	printString("String:\n", i);

	char **j = readStringArrayRet("\nLeitura de array de String:\n",
		"Digite um elemento do array:\n",
		3, MAX_LEN);
	printStringArray("Valores do array:\n",
		"Elemento do array:\n",
		3, j);
	
	//---- PSEUDO OBJETOS ----//

	printf("\n\n\n PSEUDO OBJETOS \n\n\n");

	printf("\nSCANNER\n\n");

	Scanner input = newScanner();

	puts("Digite um int:");
	b = input.nextInt();
	puts("Digite um long:");
	c = input.nextLong();
	puts("Digite um float:");
	d = input.nextFloat();
	puts("Digite um char:");
	g = input.nextChar();
	puts("Digite um array de char:");
	char *l = input.nextCharArray(MAX_LEN);

	printInt("Int:\n", b);
	printLong("Long:\n", c);
	printFloat("Float:\n", d);
	printChar("Char:\n", g);
	printString("String:\n", l);

	puts(" ");

	printf("\nSTRING\n\n");

	String strA = newString();

	strA.value = "Ola Mundo!";

	printf("STRING: %s\n", strA.value);
	printf("LENGTH: %d\n", strA.length((void *)&strA));
	printf("SUBSTRING: %s\n", strA.subString((void *)&strA, 0, 5));
	printf("UPPERCASE: %s\n", strA.upperCase((void *)&strA));
	printf("LOWERCASE: %s\n", strA.lowerCase((void *)&strA));
	
	//---- ESTRUTURAS ----//

	printf("\n\n\n ESTRUTURAS DE DADOS \n\n\n");

	printf("\nSTACK\n\n");

	StackArray stk = newStackArray();

	printf("15 enviado para a Pilha\n");
	stk.push((void *)&stk, 15);
	printf("16 enviado para a Pilha\n");
	stk.push((void *)&stk, 16);
	printInt("Ultimo valor da Pilha: ", stk.getValue((void *)&stk));
	printf("Retira o ultimo valor da Pilha (%d) e retorna ele na funcao.\n", stk.pop((void *)&stk));
	printInt("Ultimo valor da Pilha: ", stk.getValue((void *)&stk));
	printf("Retira o ultimo valor da Pilha (%d) e retorna ele na funcao.\n", stk.pop((void *)&stk));

	if (stk.isEmpty((void *)&stk) == TRUE) {
		puts("A Pilha esta vazia.");
	}
	if (stk.isFull((void *)&stk) != TRUE) {
		puts("A Pilha nao esta cheia.");
	}

	printf("\nQUEUE\n\n");

	QueueArray que = newQueueArray();

	printf("4 enviado para a Fila\n");
	que.enqueue((void *)&que, 4);
	printf("6 enviado para a Fila\n");
	que.enqueue((void *)&que, 6);
	printInt("Ultimo valor da Fila: ", que.lastItem((void *)&que));
	printInt("Primeiro valor da Fila: ", que.firstItem((void *)&que));
	printf("Retira o primeiro valor da Fila (%d) e retorna ele na funcao.\n", que.dequeue((void *)&que));
	printInt("Ultimo valor da Fila: ", que.lastItem((void *)&que));
	printInt("Primeiro valor da Fila: ", que.firstItem((void *)&que));
	printf("Retira o primeiro valor da Fila (%d) e retorna ele na funcao.\n", que.dequeue((void *)&que));

	if (que.isEmpty((void *)&que) == TRUE) {
		puts("A Fila esta vazia.");
	}
	if (que.isFull((void *)&que) != TRUE) {
		puts("A Fila nao esta cheia.");
	}

	printf("\nORDERED LIST\n\n");

	OrderedList OList = newOrderedList();

	printf("23 enviado para a Lista Ordenada\n");
	OList.insert((void *)&OList, 23);
	printf("10 enviado para a Lista Ordenada\n");
	OList.insert((void *)&OList, 10);
	printInt("Ultimo valor da Lista Ordenada: ", OList.lastItem((void *)&OList));
	printInt("Primeiro valor da Lista Ordenada: ", OList.firstItem((void *)&OList));
	printf("Retira o 23 da Lista Ordenada e retorna true: %d.\n", OList.remove((void *)&OList, 23));
	printf("4 enviado para a Lista Ordenada\n");
	OList.insert((void *)&OList, 4);
	printf("2 enviado para a Lista Ordenada\n");
	OList.insert((void *)&OList, 2);
	printf("6 enviado para a Lista Ordenada\n");
	OList.insert((void *)&OList, 6);
	printf("15 enviado para a Lista Ordenada\n");
	OList.insert((void *)&OList, 15);
	printf("Retira o valor no indice 2 da Lista Ordenada e retorna true: %d.\n", OList.removeAtIndex((void *)&OList, 2));
	printf("Mostra o valor no indice 0 da Lista Ordenada: %d.\n", OList.getItem((void *)&OList, 0));
	printf("Mostra o valor no indice 1 da Lista Ordenada: %d.\n", OList.getItem((void *)&OList, 1));
	printf("Mostra o valor no indice 2 da Lista Ordenada: %d.\n", OList.getItem((void *)&OList, 2));

	if (OList.isEmpty((void *)&OList) == TRUE) {
		puts("A Lista Ordenada esta vazia.");
	}
	if (OList.isFull((void *)&OList) != TRUE) {
		puts("A Lista Ordenada nao esta cheia.");
	}

	printf("\nORDERED LINKED LIST\n\n");

	OrderedLinkedList OLList = newOrderedLinkedList();

	printf("23 enviado para a Lista Encadeada Ordenada\n");
	OLList.insert((void *)&OLList, 23);
	printf("10 enviado para a Lista Encadeada Ordenada\n");
	OLList.insert((void *)&OLList, 10);
	printInt("Ultimo valor da Lista Encadeada Ordenada: ", OLList.lastItem((void *)&OLList));
	printInt("Primeiro valor da Lista Encadeada Ordenada: ", OLList.firstItem((void *)&OLList));
	printf("Retira o 23 da Lista Encadeada Ordenada e retorna true: %d.\n", OLList.remove((void *)&OLList, 23));
	printf("4 enviado para a Lista Encadeada Ordenada\n");
	OLList.insert((void *)&OLList, 4);
	printf("2 enviado para a Lista Encadeada Ordenada\n");
	OLList.insert((void *)&OLList, 2);
	printf("6 enviado para a Lista Encadeada Ordenada\n");
	OLList.insert((void *)&OLList, 6);
	printf("15 enviado para a Lista Encadeada Ordenada\n");
	OLList.insert((void *)&OLList, 15);
	printf("Retira o valor no indice 2 da Lista Encadeada Ordenada e retorna true: %d.\n", OLList.removeAtIndex((void *)&OLList, 2));
	printf("Mostra o valor no indice 0 da Lista Encadeada Ordenada: %d.\n", OLList.getItem((void *)&OLList, 0));
	printf("Mostra o valor no indice 1 da Lista Encadeada Ordenada: %d.\n", OLList.getItem((void *)&OLList, 1));
	printf("Mostra o valor no indice 2 da Lista Encadeada Ordenada: %d.\n", OLList.getItem((void *)&OLList, 2));

	puts("Limpa estrutura");
	OLList.clear((void *)&OLList);

	if (OLList.isEmpty((void *)&OLList) == TRUE) {
		puts("A Lista Encadeada Ordenada esta vazia.");
	}

	printf("\nORDERED DOUBLY LINKED LIST\n\n");

	OrderedDoublyLinkedList ODLList = newOrderedDoublyLinkedList();

	printf("23 enviado para a Lista Duplamente Encadeada Ordenada\n");
	ODLList.insert((void *)&ODLList, 23);
	printf("10 enviado para a Lista Duplamente Encadeada Ordenada\n");
	ODLList.insert((void *)&ODLList, 10);
	printInt("Ultimo valor da Lista Duplamente Encadeada Ordenada: ", ODLList.lastItem((void *)&ODLList));
	printInt("Primeiro valor da Lista Duplamente Encadeada Ordenada: ", ODLList.firstItem((void *)&ODLList));
	printf("Retira o 23 da Lista Duplamente Encadeada Ordenada e retorna true: %d.\n", ODLList.remove((void *)&ODLList, 23));
	printf("4 enviado para a Lista Duplamente Encadeada Ordenada\n");
	ODLList.insert((void *)&ODLList, 4);
	printf("2 enviado para a Lista Duplamente Encadeada Ordenada\n");
	ODLList.insert((void *)&ODLList, 2);
	printf("6 enviado para a Lista Duplamente Encadeada Ordenada\n");
	ODLList.insert((void *)&ODLList, 6);
	printf("15 enviado para a Lista Duplamente Encadeada Ordenada\n");
	ODLList.insert((void *)&ODLList, 15);
	printf("Retira o valor no indice 2 da Lista Duplamente Encadeada Ordenada e retorna true: %d.\n", ODLList.removeAtIndex((void *)&ODLList, 2));
	printf("Mostra o valor no indice 0 da Lista Duplamente Encadeada Ordenada: %d.\n", ODLList.getItem((void *)&ODLList, 0));
	printf("Mostra o valor no indice 1 da Lista Duplamente Encadeada Ordenada: %d.\n", ODLList.getItem((void *)&ODLList, 1));
	printf("Mostra o valor no indice 2 da Lista Duplamente Encadeada Ordenada: %d.\n", ODLList.getItem((void *)&ODLList, 2));

	puts("Limpa estrutura");
	ODLList.clear((void *)&ODLList);

	if (ODLList.isEmpty((void *)&ODLList) == TRUE) {
		puts("A Lista Duplamente Encadeada Ordenada esta vazia.");
	}
	printf("\n BINARY TREE\n\n");

	BinaryTree BTree = newBinaryTree();

	printf("23 enviado para a Arvore Binaria\n");
	BTree.insert((void *)&BTree, 23);
	printf("10 enviado para a Arvore Binaria\n");
	BTree.insert((void *)&BTree, 10);
	printf("Retira o 23 da Arvore Binaria\n");
	BTree.remove((void *)&BTree, 23);
	printf("4 enviado para a Arvore Binaria\n");
	BTree.insert((void *)&BTree, 4);
	printf("2 enviado para a Arvore Binaria\n");
	BTree.insert((void *)&BTree, 2);
	printf("6 enviado para a Arvore Binaria\n");
	BTree.insert((void *)&BTree, 6);
	printf("15 enviado para a Arvore Binaria\n");
	BTree.insert((void *)&BTree, 15);
	printf("Altura da Arvore Binaria: %d\n", BTree.height((void*)&BTree));
	printf("Quantidade de itens da Arvore Binaria: %d\n", BTree.itemAmount((void*)&BTree));
	printf("Menor item da Arvore Binaria: %d\n", BTree.lowerValue((void*)&BTree));
	printf("Maior item da Arvore Binaria: %d\n", BTree.higherValue((void*)&BTree));
	puts("PreOrder");
	BTree.printInPreOrder((void*)&BTree);
	puts("\nPostOrder");
	BTree.printInPostOrder((void*)&BTree);
	puts("\nInOrder");
	BTree.printInOrder((void*)&BTree);
	puts("\nPerLevel");
	BTree.printPerLevel((void*)&BTree);

	puts("\nLimpa estrutura");
	BTree.clear((void*)&BTree);

	if (BTree.isEmpty((void *)&BTree) == TRUE) {
		puts("A Arvore Binaria esta vazia.");
	}

	system("pause");
	return 0;
}

