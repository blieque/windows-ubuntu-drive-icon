@echo off
echo Windows Ubuntu Drive Icon Setup, by Blieque Mariguan (@blieque)
set /p iu=Install or uninstall? [I/U]: 
IF "%iu%"=="I" (
	set /p drive=Ubuntu drive letter: 
	copy assets\ubuntu-drive.ico %PUBLIC%\Pictures\ubuntu-drive.ico
	reg add HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\DriveIcons\%drive%\DefaultIcon
	reg add HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\DriveIcons\%drive%\DefaultIcon /ve /t REG_SZ /d "\"%PUBLIC%\Pictures\ubuntu-drive.ico\"" /f
) ELSE (
	IF "%iu%"=="U" (
		set /p drive=Ubuntu drive letter: 
		del %PUBLIC%\Pictures\ubuntu-drive.ico
		reg delete HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\DriveIcons\%drive% /f
	) ELSE (
		echo Neither "U" or "I" was entered. No action taken.
		timeout /t 10
	)
)
set iu=
set drive=