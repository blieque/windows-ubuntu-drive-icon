#include <iostream>
#include <stdio.h>
#include <Windows.h>

int main() { // int argc, char* argv[]
	LONG WINAPI RegOpenKeyEx(
		_In_        HKEY hKey,
		_In_opt_    LPCTSTR lpSubKey,
		_Reserved_  DWORD ulOptions,
		_In_        REGSAM samDesired,
		_Out_       PHKEY phkResult
	);
	
	BOOL WINAPI MoveFile(
		_In_  LPCTSTR lpExistingFileName,
		_In_  LPCTSTR lpNewFileName
	);

	return 0;
}

/*

	result= rename( oldname , newname );
	if ( result == 0 )
		puts ( "File successfully renamed" );
	else
		perror( "Error renaming file" );
		*/