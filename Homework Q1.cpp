#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define NUM1 0
#define NUM2 1
#define NUM3 2

using namespace std;

typedef struct Expression {
	char sign;
	char* arrNums[3];
}Expression;

void makeString(int num, char** arr) {

	// Find out how many digits in number
	int length = 0, temp = num;
	while (temp > 0) {
		length++;
		temp /= 10;
	}
	//cout << length;

	// Allocate memory
	*arr = new char[length + 1];
	
	// Add number to string
	int temp2 = num;
	for (int i = 0; i < length; i++) {
		char current_number = num % 10 + 48;
		(*arr)[length - i - 1] = current_number;
		num /= 10;
	}
	(*arr)[length] = '\0';
	//cout << *arr;
}

void createExpression(Expression& exp) {
	// As if the user has entered these fields
	// cin >> num1;
	// // cin >> sign;
	// cin >> num2;
	const char num1[] = "600";
	const char sign = '-';
	const char num2[] = "400";

	// Checks
	if (num1[0] < 48 || num1[0] > 57) exit(-2);
	if (num2[0] < 48 || num2[0] > 57) exit(-2);

	// Allocation
	exp.arrNums[NUM1] = new char[strlen(num1) + 1];
	exp.arrNums[NUM2] = new char[strlen(num2) + 1];

	// Assignment
	exp.sign = sign;
	strcpy(exp.arrNums[NUM1], num1);
	strcpy(exp.arrNums[NUM2], num2);

}
int makeNumber(char* str) {
	int digits = strlen(str), num = 0;
	for (int i = 0; i < digits; i++)
		num += (str[digits - i - 1] - '0') * pow(10, i);
	return num;
}
void calculate(Expression & exp) {
	int result = 0;
	// After lots of thinking, the best way to tackle the problem will be to convert the strings
	// to integers, solve, then convert the result back to a string

	if (exp.sign == '+')
		result = makeNumber(exp.arrNums[NUM1]) + makeNumber(exp.arrNums[NUM2]);
	// Code -4: Negative number in result
	else if (exp.sign == '-') {
		result = makeNumber(exp.arrNums[NUM1]) - makeNumber(exp.arrNums[NUM2]);
		if (result < 0) exit(-4);
	}
	else if (exp.sign == '*')
		result = makeNumber(exp.arrNums[NUM1]) * makeNumber(exp.arrNums[NUM2]);

	// Code -3: '0' used as denominator
	else if (exp.sign == '/') {
		if (makeNumber(exp.arrNums[NUM2]) == 0) exit(-3);
		result = (int)(makeNumber(exp.arrNums[NUM1]) / makeNumber(exp.arrNums[NUM2]));
	}
	else if (exp.sign == '%') {
		if (makeNumber(exp.arrNums[NUM2]) == 0) exit(-3);
		result = makeNumber(exp.arrNums[NUM1]) % makeNumber(exp.arrNums[NUM2]);
	}
	makeString(result, exp.arrNums + NUM3);
}
void printExpression(const Expression& exp) {
	char s = ' ';
	cout << exp.arrNums[NUM1] << s;
	cout << exp.sign << s;
	cout << exp.arrNums[NUM2] << s;
	cout << '=' << s;
	cout << exp.arrNums[NUM3] << endl;
}
int main() {

	Expression e1;
	createExpression(e1);
	calculate(e1);
	
	printExpression(e1);

	delete[] e1.arrNums[NUM1];
	delete[] e1.arrNums[NUM2];
	delete[] e1.arrNums[NUM3];
	return 0;
}

