Steps to be followed to run the application are as follows:
1)	Extract deliverables.7z to the local machine
2)	Launch the solution in Visual Studio 2013, ..\deliverables\code\application\application.sln
3)	Make sure scheduler project is set as the startup project, choose release configuration
4)	Build the solution
5)	Make sure the following 2 .exe-s are generated in the folder, ..\deliverables\code\application\Release
	scheduler.exe, test.exe
6)	Rename ..\deliverables\runTests.txt to runTests.bat
7)	Rename ..\deliverables\runApplication.txt to runApplication.bat
8)	Make sure the file ..\deliverables\input.txt is present and is in the expected format
9)	Launch test cases using ..\deliverables\runTests.bat
	At the end, the reulst is shown in terms of test cases failed/passed
10)	Launch scheduler application using ..\deliverables\runApplication.bat
	An output file, output.txt,  will be created in ..\deliverables with the desired output

The folder ..\deliverables have the following folder:
1)	code: contains the code for the application and the test suite

The folder ..\deliverables have the following files:
1)	input.txt: sample input file to be used by the application; it shows the format
2)	runApplication.txt: batch application file renamed as txt file to run the application
3)	runTests.txt: batch application file renamed as txt file to run the test suite
4)	schedulerDocument.xmind: a mind map file created using xmind (https://www.xmind.net/xmind/downloads/xmind-8-windows.exe) which captures the whole development process
5)	schedulerDocument.png: image exported from the mind map file
6)	readme.txt: contains the steps to be followed 

The application and the test suite were run to verify the output:
1) on a Windows 7 machine,
2) using Visual Studio 2013
3) in 32-bit mode
