#include <iostream>
#include <stdlib.h>
#include <stdio.h>
//#include <strsafe.h>
#include <string>
#include <windows.h>

using namespace std;

int main() {
	string input [2];

	cout << "Windows Ubuntu Drive Icon Setup, by Blieque Mariguan (@blieque)\nInstall or uninstall the icon? [I/U]: ";
	cin >> input[0];

	stringstream sstm;
	sstm << "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\DriveIcons\\" << input[1] << "\\DefaultIcon",
	string hKeyCreate = sstm.str();

	if (input[0] == "I") {
		cout << "Ubuntu drive letter: ";
		cin >> input[1];
	} else if (input[0] == "U") {
		// Uninstall
	} else {
		// note
	}

	HKEY hKey = NULL;
	long create = RegCreateKeyEx(
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
/*
	int ren = rename( "setup.rc" , "assets/setup.rc" );
	if ( ren == 0 ) {
		puts( "File successfully renamed" );
	} else {
		perror( "Error renaming file" );
	}
*/
	return 0;
}

/*

	result= rename( oldname , newname );
	if ( result == 0 )
		puts ( "File successfully renamed" );
	else
		perror( "Error renaming file" );
		*/