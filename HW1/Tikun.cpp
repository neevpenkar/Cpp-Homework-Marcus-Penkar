//int main() {
//	char str[] = "hello world what is this?";
//	int length;
//	char*** temp = dividestring(str, length);
//	char** container = *temp;
//
//
//	for (int i = 0; i < length + 1; i++) {
//		change_string(container + i);
//	}
//
//	for (int i = 0; i < length + 1; i++) {
//		cout << container[i] << endl;
//		delete[] container[i];
//	}
//
//	delete[] * temp;
//
//	return 0;
//}