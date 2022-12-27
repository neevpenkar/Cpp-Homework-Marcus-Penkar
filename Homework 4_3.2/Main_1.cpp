//#include <iostream>
//#include "DataFile.h"
//#include "Folder.h"
//using namespace std;
//void main() {
//	Folder* root = &Folder::Root;
//	Folder* curr = root;
//	bool quit = false; string path;
//	string command, p_command;
//	char echoStream[256];
//	do {
//		cout << "Enter Command: ";
//		std::cout << curr->getFullPath().substr(5) << ">";
//		cin.ignore(cin.rdbuf()->in_avail());
//		cin >> command;
//		if (command == "cd"); /* {
//			try {
//				cin.ignore(1);
//				cin >> p_command;
//				if (p_command == Root->getFileName())
//					curr = Root;
//				else curr = Folder::cd(p_command);
//			}
//			catch (const char* msg) {
//				cout << msg << endl;
//				quit = true;
//			};
//			continue;
//		}*/
//		if (command == "mkdir") {
//			try {
//				cout << "Enter name of new folder: ";
//				cin.ignore(1);
//				cin >> p_command;
//				curr->mkdir(p_command);
//			}
//			catch (const char* msg) {
//				cout << msg << endl;
//				quit = true;
//			}
//			continue;
//		}
//		if (command == "dir") {
//			curr->dir();
//			continue;
//		}
//		if (command == "echo") {
//			cout << "Enter name of newfile: ";
//			cin.ignore(1);
//			std::cin.getline(echoStream, 256);
//			command = echoStream;
//			try {
//				curr->mkfile(command.substr(0, command.find('<') -
//					1), command.substr(command.find('<') + 2));
//			}
//			catch (const char* msg) {
//				cout << msg << endl;
//				quit = true;
//			};
//			continue;
//		}
//	} while (!quit);
//	cout << "The end!" << endl;
//}