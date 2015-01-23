@echo off
echo Windows Ubuntu Drive Icon Setup, by Blieque Mariguan <himself AT blieque.co.uk>
set /p iu=Install or uninstall? [I/U]: 
set /p drive=Ubuntu drive letter: 
IF "%iu%"=="I" (
	copy ubuntu-drive.ico %PUBLIC%\Pictures\ubuntu-drive.ico
	reg add HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\DriveIcons\%drive%\DefaultIcon
	reg add HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\DriveIcons\%drive%\DefaultIcon /ve /t REG_SZ /d "\"%PUBLIC%\Pictures\ubuntu-drive.ico\"" /f
) ELSE (
	IF "%iu%"=="U" (
		del %PUBLIC%\Pictures\ubuntu-drive.ico
		reg delete HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\DriveIcons\%drive% /f
	) ELSE (
		echo Neither "U" or "I" was entered. No action taken.
		timeout /t 10
	)
)
set iu=
set drive=
