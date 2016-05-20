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

#define DEFAULT_STRING_LEN 1024

#define ID(x) x
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define GET_MACRO_2(_1,_2,NAME,...) NAME

#define readShort(...) ID(GET_MACRO(__VA_ARGS__, readShort3, readShort2, readShort1)(__VA_ARGS__))

void readShort(short *variableAddress, char headerMessage[], char errorMessage[]);

#define readInt(...) ID(GET_MACRO(__VA_ARGS__, readInt3, readInt2, readInt1)(__VA_ARGS__))

void readInt(int *variableAddress, char headerMessage[], char errorMessage[]);

#define readLong(...) ID(GET_MACRO(__VA_ARGS__, readLong3, readLong2, readLong1)(__VA_ARGS__))

void readLong(long *variableAddress, char headerMessage[], char errorMessage[]);

#define readFloat(...) ID(GET_MACRO(__VA_ARGS__, readFloat3, readFloat2, readFloat1)(__VA_ARGS__))

void readFloat(float *variableAddress, char headerMessage[], char errorMessage[]);

#define readDouble(...) ID(GET_MACRO(__VA_ARGS__, readDouble3, readDouble2, readDouble1)(__VA_ARGS__))

void readDouble(double *variableAddress, char headerMessage[], char errorMessage[]);

#define readChar(...) ID(GET_MACRO_2(__VA_ARGS__, readChar2, readChar1)(__VA_ARGS__))

void readChar(char *variableAddress, char headerMessage[]);

#define readString(...) ID(GET_MACRO(__VA_ARGS__, readString3, readString2, readString1)(__VA_ARGS__))

void readString(char *variableAddress, int stringLength, char headerMessage[]);

// FUNÇÕES SEM OVERLOAD

int readIntRet(char headerMessage[],
	char errorMessage[]);

long readLongRet(char headerMessage[],
	char errorMessage[]);

float readFloatRet(char headerMessage[],
	char errorMessage[]);

char readCharRet(char headerMessage[]);

char *readStringRet(char headerMessage[],
	int stringLength);

char **readStringArrayRet(char headerMessage[],
	char elementMessage[],
	int elementAmount,
	int stringLength);

void printInt(char headerMessage[],
	int value);

void printLong(char headerMessage[],
	long value);

void printShort(char headerMessage[],
	short value);

void printDouble(char headerMessage[],
	double value);

void printFloat(char headerMessage[],
	float value);

void printChar(char headerMessage[],
	char value);

void printString(char headerMessage[],
	char value[]);

void printStringArray(char headerMessage[],
	char elementMessage[],
	int elementAmout,
	char **stringArray);

struct Scanner;

typedef struct {
	int(*nextInt)();
	long(*nextLong)();
	float(*nextFloat)();
	char(*nextChar)();
	char* (*nextCharArray)(int);
} Scanner;

Scanner newScanner();

struct String;

typedef struct {
	char* value;
	int (*length)(struct String *);
	char* (*subString)(struct String *, int, int);
	char* (*upperCase) (struct String *);
	char* (*lowerCase) (struct String *);
}String;

String newString();
