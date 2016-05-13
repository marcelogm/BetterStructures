/*
* IFRS - Osório
* Autores : John R. (johnreis) / Marcelo M. (marcelogm)
* LIB de auxílio para valores primitivos,
* ponteiros e estruturas simples
* de gravação e leitura.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ifrslib.h"

/*
* FUNÇÕES PARA ENTRADA DE DADOS
*
* Sem retorno definido, alteram a variável
* por ponteiro.
*
* É necessário enviar o endereço da variável
* para a função.
*/

/*
* Lê uma variável do tipo Short
*
* Exemplo:
* readShort(&variavel,"Digite um Short:\n","Erro!\n");
*/

void readShort1(short *variableAddress) {
	int ret;
	do {
		ret = scanf_function("\n%hi", variableAddress);
		clStdin;
	} while (ret != TRUE);
}

void readShort2(short *variableAddress, char headerMessage[]) {
	int ret;
	do {
		printf("%s", headerMessage);
		ret = scanf_function("\n%hi", variableAddress);
		clStdin;
	} while (ret != TRUE);
}

void readShort3(short *variableAddress, char headerMessage[], char errorMessage[]) {
	int ret;
	do {
		printf("%s", headerMessage);
		ret = scanf_function("\n%hi", variableAddress);
		clStdin;
		if (ret != TRUE) {
			printf("%s", errorMessage);
		}
	} while (ret != TRUE);
}

/*
* Lê uma variável do tipo Inteiro (16 bits)
*
* Exemplo:
* readInt(&variavel,"Digite um Int:\n","Erro!\n");
*/

void readInt1(int *variableAddress) {
	int ret;
	do {
		ret = scanf_function("\n%d", variableAddress);
		clStdin;
	} while (ret != TRUE);
}

void readInt2(int *variableAddress, char headerMessage[]) {
	int ret;
	do {
		printf("%s", headerMessage);
		ret = scanf_function("\n%d", variableAddress);
		clStdin;
	} while (ret != TRUE);
}

void readInt3(int *variableAddress, char headerMessage[], char errorMessage[]) {
	int ret;
	do {
		printf("%s", headerMessage);
		ret = scanf_function("\n%d", variableAddress);
		clStdin;
		if (ret != TRUE) {
			printf("%s", errorMessage);
		}
	} while (ret != TRUE);

}


/*
* Lê uma variável do tipo Inteiro (32 bits)
*
* Exemplo:
* readLong(&variavel, "Digite um Long:\n","Erro!\n");
*/

void readLong1(long *variableAddress) {
	int ret;
	do {
		ret = scanf_function("\n%ld", variableAddress);
		clStdin;
	} while (ret != TRUE);
}

void readLong2(long *variableAddress, char headerMessage[]) {
	int ret;
	do {
		printf("%s", headerMessage);
		ret = scanf_function("\n%ld", variableAddress);
		clStdin;
	} while (ret != TRUE);
}

void readLong3(long *variableAddress, char headerMessage[], char errorMessage[]) {
	int ret;
	do {
		printf("%s", headerMessage);
		ret = scanf_function("\n%ld", variableAddress);
		clStdin;
		if (ret != TRUE) {
			printf("%s", errorMessage);
		}
	} while (ret != TRUE);
}

/*
* Lê uma variável do tipo Float
* v. Single-precision floating-point format
*
* Exemplo:
* readFloat(&variavel,"Digite um Float:\n","Erro!\n");;
*/

void readFloat1(float *variableAddress) {
	int ret;
	do {
		ret = scanf_function("%f", variableAddress);
		clStdin;
	} while (ret != TRUE);
}

void readFloat2(float *variableAddress, char headerMessage[]) {
	int ret;
	do {
		printf("%s", headerMessage);
		ret = scanf_function("%f", variableAddress);
		clStdin;
	} while (ret != TRUE);
}

void readFloat3(float *variableAddress, char headerMessage[], char errorMessage[]) {
	int ret;
	do {
		printf("%s", headerMessage);
		ret = scanf_function("%f", variableAddress);
		clStdin;
		if (ret != TRUE) {
			printf("%s", errorMessage);
		}
	} while (ret != TRUE);
}

/*
* Lê uma variável do tipo Double
*
* Exemplo:
* readDouble(&variavel,"Digite um Double:\n","Erro!\n");;
*/

void readDouble1(double *variableAddress) {
	int ret;
	ret = scanf_function("\n%lf", variableAddress);
	clStdin;
	if (ret != TRUE) {
		readDouble1(variableAddress);
	}
}

void readDouble2(double *variableAddress, char headerMessage[]) {
	int ret;
	printf("%s", headerMessage);
	ret = scanf_function("\n%lf", variableAddress);
	clStdin;

	if (ret != TRUE) {
		readDouble2(variableAddress, headerMessage);
	}
}

void readDouble3(double *variableAddress, char headerMessage[], char errorMessage[]) {
	int ret;
	printf("%s", headerMessage);
	ret = scanf_function("\n%lf", variableAddress);
	clStdin;

	if (ret != TRUE) {
		printf("%s", errorMessage);
		readDouble3(variableAddress, headerMessage, errorMessage);
	}
}

/*
* Lê uma variável do tipo Char
*
* Exemplo:
* readChar(&variavel,"Digite um Char:\n");
*/

void readChar1(char *variableAddress) {
	*variableAddress = fgetc(stdin);
	clStdin;
}

void readChar2(char *variableAddress, char headerMessage[]) {
	printf("%s", headerMessage);
	*variableAddress = fgetc(stdin);
	clStdin;
}


/*
* Lê uma variável do tipo array de Char (String)
*
* Exemplo:
* readString(&variavel,255,"Digite uma String:\n");
*/

// add *
void readString1(char variable[]) {
	fgets(variable, DEFAULT_STRING_LEN, stdin);
	variable[strcspn(variable, "\n")] = '\0';
	clStdin;
}

void readString2(char variable[], int stringLength) {
	fgets(variable, stringLength, stdin);
	variable[strcspn(variable, "\n")] = '\0';
	clStdin;
}

void readString3(char variable[], int stringLength, char headerMessage[]) {
	printf("%s", headerMessage);
	fgets(variable, stringLength, stdin);
	variable[strcspn(variable, "\n")] = '\0';
	clStdin;
}


/*
*   OBSERVAÇÕES SOBRE AS FUNÇÕES ...Ret
*   As funções aqui escritas precedem às funções com overload por macro
*   Elas são uma herança do nosso inicio de programação em C
*   Foram deixadas aqui para registro.
*/

/*
*  FUNÇÕES PARA ENTRADA DE DADOS COM RETORNO DE VARIAVEL
*
*  Cria uma variável local e retorna seu valor
*
*  Não é necessário enviar o endereço da variável,
*  Entretanto é necessário uma variável para receber seu retorno.
*/

/*
*  Cria e retorna uma variável do tipo Inteiro (16 bits)
*
*  Exemplo:
*  readIntRet("Digite um Int:\n","Erro!\n");
*/

int readIntRet(char headerMessage[],
	char errorMessage[]) {
	int value, ret;
	do {
		printf("%s", headerMessage);
		ret = scanf_function("\n%d", &value);
		clStdin;

		if (ret != TRUE) {
			printf("%s", errorMessage);
		}
	} while (ret != TRUE);
	return value;
}

/*
* Cria e retorna uma variável do tipo Long (32 bits)
*
* Exemplo:
* readLongRet("Digite um Long:\n","Erro!\n");
*/


long readLongRet(char headerMessage[],
	char errorMessage[]) {
	long value;
	int ret;
	do {
		printf("%s", headerMessage);
		ret = scanf_function("\n%ld", &value);
		clStdin;

		if (ret != TRUE) {
			printf("%s", errorMessage);
		}
	} while (ret != TRUE);
	return value;
}


/*
* Cria e retorna uma variável tipo Float
*
* Exemplo:
* readFloatRet("Digite um Float:\n","Erro!\n");
*/

float readFloatRet(char headerMessage[],
	char errorMessage[]) {
	float value;
	int ret;
	do {
		printf("%s", headerMessage);
		ret = scanf_function("%f", &value);
		clStdin;

		if (ret != TRUE) {
			printf("%s", errorMessage);
		}
	} while (ret != TRUE);
	return value;
}

/*
* Cria e retorna uma variável do tipo Char
*
* Exemplo:
* readCharRet("Digite um Char:\n");
*/

char readCharRet(char headerMessage[]) {
	char value;
	printf("%s", headerMessage);
	value = fgetc(stdin);
	clStdin;
	return value;
}

/*
* Cria variável do tipo Array de Char e retorna um ponteiro
*
* Exemplo:
* *readStringRet("Digite uma String:\n",255);
*/

char *readStringRet(char headerMessage[],
	int stringLength) {
	char *value = (char *)malloc(stringLength * sizeof(char));
	printf("%s", headerMessage);
	fgets(value, stringLength, stdin);
	value[strcspn(value, "\n")] = '\0';
	clStdin;
	return value;
}

/*
* Cria um Array de String(Array de Char) e
* retorna um ponteiro bidimensional
*
* Exemplo:
* **readStringArrayRet("Array de String\n",
*                       "Digite uma String:\n",
*                       5,255);
*/

char **readStringArrayRet(char headerMessage[],
	char elementMessage[],
	int elementAmount,
	int stringLength) {
	printf("%s", headerMessage);
	char ** strings = (char **)malloc(elementAmount *
		stringLength *
		sizeof(char));
	int i;
	for (i = 0; i < elementAmount; i++) {
		*(strings + i) = readStringRet(elementMessage,
			stringLength);
	}
	return strings;
}

/*
* FUNÇÕES PARA SAÍDA DE DADOS
*
* Sem retorno definido, mostra na tela o parâmetro enviado
*
*/

/*
* Imprime uma variável do tipo Inteiro (16 bits)
*
* Exemplo:
* printInt("Inteiro:\n", variavel);
*/

void printInt(char headerMessage[],
	int value) {
	printf("%s", headerMessage);
	printf("%d\n", value);
}

/*
* Imprime uma variável do tipo Inteiro (32 bits)
*
* Exemplo:
* printLong("Long:\n", variavel);
*/

void printLong(char headerMessage[],
	long value) {
	printf("%s", headerMessage);
	printf("%ld\n", value);
}

/*
* Imprime uma variável do tipo Short
*
* Exemplo:
* printLong("Short:\n", variavel);
*/

void printShort(char headerMessage[],
	short value) {
	printf("%s", headerMessage);
	printf("%hi\n", value);
}

/*
* Imprime uma variável do tipo Double
*
* Exemplo:
* printLong("Double:\n", variavel);
*/

void printDouble(char headerMessage[],
	double value) {
	printf("%s", headerMessage);
	printf("%lf\n", value);
}

/*
* Imprime uma variável do tipo Float
*
* Exemplo:
* printFloat("Float:\n", variavel);
*/

void printFloat(char headerMessage[],
	float value) {
	printf("%s", headerMessage);
	printf("%f\n", value);
}

/*
* Imprime uma variável do tipo Char
*
* Exemplo:
* printChar("Char:\n", variavel);
*/

void printChar(char headerMessage[],
	char value) {
	printf("%s", headerMessage);
	printf("%c\n", value);
}

/*
* Imprime uma variável do tipo Array de Char
*
* Exemplo:
* printString("String:\n", variavel);
*/

void printString(char headerMessage[],
	char value[]) {
	printf("%s", headerMessage);
	printf("%s", value);
}

/*
* Imprime uma variável do tipo Array de Char
*
* Exemplo:
* printStringArray("TITULO:\n","String:\n", variavel);
*/

void printStringArray(char headerMessage[],
	char elementMessage[],
	int elementAmout,
	char **stringArray) {
	printf("%s", headerMessage);
	int i = 0;
	while (i < elementAmout) {
		printf("\n%s", elementMessage);
		int j = 0;
		while (*(*(stringArray + i) + j)) {
			putchar(*(*(stringArray + i) + j));
			j++;
		}
		i++;
	}
	printf("\n");
}


/*
*   Esta parte da lib se dedica a criar pseudo objetos
*   para realizar certas tarefas com mais facilidades
*   Para exemplificar isso, criamos estruturas
*   que recebem ponteiros para funções.
*/

/*
*   Struct Scanner
*   Possui um funcionamento similar ao Scanner da
*   linguagem Java
*
*   Exemplo de utilização:
*   Scanner input = newScanner();
*   int a = input.nextInt();
*
*   As funções existentes até o momento (03/03/2016):
*
*   Executa a leitura de um int
*   input.nextInt();
*   Executa a leitura de um long int
*   input.nextLong();
*   Executa a leitura de um float
*   input.nextFloat();
*   Executa a leitura de um char
*   input.nextChar();
*   Executa a leitura de um array de char, similar ao readLine do Java
*   input.nextCharArray();
*
*/

int __readIntToPointer() {
	int value, ret;
	do {
		ret = scanf_function("%d", &value);
		clStdin;

		if (ret != TRUE) {
			printf("ERRO: Value entered is NaN.\nTry again.\n");
		}
	} while (ret != TRUE);
	return value;
}

long __readLongToPointer() {
	long value;
	int ret;
	do {
		ret = scanf_function("%ld", &value);
		clStdin;

		if (ret != TRUE) {
			printf("ERRO: Value entered is NaN.\nTry again.\n");
		}
	} while (ret != TRUE);
	return value;
}

float __readFloatToPointer() {
	float value;
	int ret;
	do {
		ret = scanf_function("%f", &value);
		clStdin;

		if (ret != TRUE) {
			printf("ERRO: Value entered is NaN.\nTry again.\n");
		}
	} while (ret != TRUE);
	return value;
}

char __readCharToPointer() {
	char value;
	value = fgetc(stdin);
	clStdin;
	return value;
}

char *__readStringToPointer(int stringLength) {
	char *value = (char *)malloc(stringLength * sizeof(char));
	fgets(value, stringLength, stdin);
	value[strcspn(value, "\n")] = '\0';
	clStdin;
	return value;
}

Scanner newScanner() {
	Scanner local;
	local.nextInt = (void *)&__readIntToPointer;
	local.nextLong = (void *)&__readLongToPointer;
	local.nextFloat = (void *)&__readFloatToPointer;
	local.nextChar = (void *)&__readCharToPointer;
	local.nextCharArray = (void *)&__readStringToPointer;
	return local;
}

/*
*   Struct String
*   Possui um funcionamento similar a uma String
*   em uma linguagem orientada a objetos
*
*   Exemplo de utilização:
*   String strA = newString();
*   strA.value = "VALOR";
*
*   As funções existentes até o momento (03/03/2016):
*   Referente ao valor real da String
*   strA.value = "VALOR";
*
*   SOBRE O &strA
*   É imporntate lembrar que por C não ser uma linguagem orientada
*   a objetos, não existe um this. local.
*   Para que a função modifique os parâmetros do próprio  struct
*   é necessario mandar seu endereço "&strA";
*
*   Retorna a quantidade (int) de "char" dentro da String
*   strA.length(&strA);
*
*   Executa uma função de subString, retornando um array de char
*   de acordo com os parâmetros utilizados.
*   strA.subString(&strA,2,5);
*   Nesse caso, pegaremos o terceiro caractere (pois contamos o 0)
*   até o quinto caractere.
*   Em um contexto utilizando os caracteres "0123456"
*   O retorno seria "234"
*
*   Retorna um array de Char em lowerCase.
*   strA.lowerCase(&strA);
*
*   Retorna um array de Char em upperCase.
*   strA.upperCase(&strA);
*/


int __stringLength(String *local) {
	return strlen(local->value);
}

char* __stringSubs(String *local, int inicio, int fim) {
	char* substring = malloc(sizeof(local->value));
	int i = 0;
	for (i = 0; inicio < fim; inicio++, i++) {
		substring[i] = local->value[inicio];
	}
	substring[i] = '\0';
	return substring;
}

char* __upperCase(String *local) {
	char* localString = malloc(strlen(local->value) + 1);
	unsigned int i = 0;
	for (i = 0; i < (unsigned int)strlen(local->value); i++) {
		int charTester = (int)local->value[i];
		if (charTester >= 97 && charTester <= 122) {
			localString[i] = (char)(charTester - 32);
		}
		else {
			localString[i] = local->value[i];
		}
	}
	localString[i] = '\0';
	return localString;
}

char* __lowerCase(String *local) {
	char* localString = malloc(strlen(local->value) + 1);
	unsigned int i = 0;
	for (i = 0; i < (unsigned int)strlen(local->value); i++) {
		int charTester = (int)local->value[i];
		if (charTester >= 65 && charTester <= 90) {
			localString[i] = (char)(charTester + 32);
		}
		else {
			localString[i] = local->value[i];
		}
	}
	localString[i] = '\0';
	return localString;
}

String newString() {
	String local;
	local.subString = (void *)&__stringSubs;
	local.length = (void *)&__stringLength;
	local.upperCase = (void *)&__upperCase;
	local.lowerCase = (void *)&__lowerCase;
	return local;
}