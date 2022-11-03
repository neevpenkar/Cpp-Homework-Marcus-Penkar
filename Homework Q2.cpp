#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Triangle
float Area(int a, int b);

// Trapezoid
float Area(int a, int b, int h);

// Circle
float Area(float R);

// Donut
float Area(float R, float r);

int main() {
	int sideA, sideB;
	cout << "Enter two sides of triangle: " << endl;
	cin >> sideA; cin >> sideB;
	cout << endl << "Area is: " << Area(sideA, sideB) << endl;

	int height;
	cout << "Enter two sides and one height of a trapezoid: ";
	cin >> sideA; cin >> sideB; cin >> height;
	cout << endl << "Area is: " << Area(sideA, sideB, height) << endl;

	float R, r;
	cout << "Enter Radius of a circle: " << endl;
	cin >> R;
	cout << endl << "Area is: " << Area(R) << endl;

	cout << "Enter two radiuses of a ring: " << endl;
	cin >> R; cin >> r;
	cout << endl << "Area is: " << Area(R, r) << endl;

	return 0;
}


// Right Angled - Triangle
float Area(int a, int b) {
	return a * b * 0.5f;
}
// Trapezoid
float Area(int a, int b, int h) {
	return (a + b) * h * 0.5f;
}

// Circle
float Area(float R) {
	const float pi = 3.14159;
	return pi * R * R;
}
// Donut
float Area(float R, float r) {
	if (R >= r) return Area(R) - Area(r);
	else {
		cout << "r is smaller than R, redirecting" << endl;
		return Area((int)R, (int)r);
	}
}