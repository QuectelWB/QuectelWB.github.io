Windows Scrtipt
=========


autologin.vbs
----

	Dim WshShell 
	Set WshShell=WScript.CreateObject("WScript.Shell") 
	WshShell.Run "cmd.exe"
	WScript.Sleep 1500 
	WshShell.SendKeys  "ssh m@10.66.125.234"
	WshShell.SendKeys  "{ENTER}"
	WScript.Sleep 1500 
	WshShell.SendKeys "m"
	WshShell.SendKeys "{ENTER}"


