#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <windows.h>

using namespace std;

int main() {
	string input[2];
	const char* inputChar[2];
	const char* hKeyCreate;
	HKEY hKey = NULL;
	HKEY hKeyOut = NULL;

	cout << "\nWindows Ubuntu Drive Icon Setup, by Blieque Mariguan (@blieque)\nInstall or uninstall the icon? [I/U]: ";
	cin >> input[0];

	if (input[0] == "I") {
		cout << "Ubuntu drive letter: ";
		cin >> input[1];
	
		stringstream sstm;
		sstm << "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\DriveIcons\\" << input[1] << "\\DefaultIcon";
		hKeyCreate = sstm.str().c_str();

		inputChar[1] = input[1].c_str();

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
			(LPCSTR)inputChar[1],
			2
		);
		/*
	
			int ren = rename( "ubuntu-drive.ico" , "%PUBLIC%\Pictures\ubuntu-drive.ico" );
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

	return 0;
}