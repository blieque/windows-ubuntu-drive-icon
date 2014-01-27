#include <cstdlib>
#include <cxxabi.h>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <windows.h>

using namespace std;

/* 
string demangle(const char* mangled) {
	int status;
	unique_ptr<char[], void (*)(void*)> result(
		abi::__cxa_demangle(mangled, 0, 0, &status), free);
	return result.get() ? string(result.get()) : "ERROR";
}

template<class T>
void foo(T t) { std::cout << demangle(typeid(t).name()) << std::endl; }
*/

int main() {
	string input[2];
	const char * inputChar[2];
	const char * hKeyCreate;
	HKEY hKey = NULL;

	cout << "\nWindows Ubuntu Drive Icon Setup, by Blieque Mariguan (@blieque)\nInstall or uninstall the icon? [I/U]: ";
	cin >> input[0];

	if (input[0] == "I") {
		cout << "Ubuntu drive letter: ";
		cin >> input[1];
	
		stringstream sstm[2];
		sstm[0] << "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\DriveIcons\\" << input[1] << "\\DefaultIcon";
		sstm[1] << input[1];
		hKeyCreate = sstm[0].str().c_str();
		inputChar[1] = sstm[1].str().c_str();

		long hKeyCreator = RegCreateKeyEx(
			HKEY_LOCAL_MACHINE,
			hKeyCreate,
			0,
			NULL,
			REG_OPTION_NON_VOLATILE,
			KEY_ALL_ACCESS,
			NULL,
			&hKey,
			NULL
		);

		long hKeySetter = RegSetValueEx(
			HKEY_LOCAL_MACHINE,
			hKeyCreate,
			0,
			REG_SZ,
			(LPBYTE)"C:\\Users\\Public\\Pictures\\ubuntu-drive.ico",
			strlen("C:\\Users\\Public\\Pictures\\ubuntu-drive.ico")*sizeof(char)
		);

		bool move = CopyFile(
			"assets\\ubuntu-drive.ico",
			"C:\\Users\\Public\\Pictures\\ubuntu-drive-new.ico",
			TRUE
		);
	
		/*
		int ren = rename( "ubuntu-drive.ico" , "\%PUBLIC\%\\Pictures\\ubuntu-drive.ico" );
		if ( ren == 0 ) {
			puts( "File successfully renamed" );
		} else {
			perror( "Error renaming file" );
		}
		*/
	} else if (input[0] == "U") {
		// Uninstall
	} else {
		// note
	}

	return EXIT_SUCCESS;
}