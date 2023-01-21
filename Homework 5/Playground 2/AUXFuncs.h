//#pragma once
//#include <iostream>
//using namespace std;
//
//string getCurrentPane(string path) {
//	const static char token = '\\';
//	if (path.find(token) == -1) return string("<End>");
//	return path.substr(0, path.find(token));
//}
//
//string getNextPane(string path) {
//	const static char token = '\\';
//	if (path.find(token) == -1) return path;
//	return path.substr(path.find(token) + 1, path.length());
//}