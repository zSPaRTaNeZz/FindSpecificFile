# FindSpecificFile
When start solution you need to change startup project to "FindSpecificFile".

Program works in console mode.
The input program accepts a string containing the full file name (with extension). 
It is not necessary to specify an extension if we are looking for a file without it.

On output we get the full path to the searched file if it is found. 
If the file is not found then it is displey message "File is not found.".

The program is implemented without the use of third-party libraries. 
The C ++ compiler library provided from **"out of the box"**.

The program does not view directories to which there is no permission(**"fs :: directory_options :: skip_permission_denied"**).
Fully supports only the Latin keyboard.
Also works with Cyrillic keyboard but the path to the file will not be displayed correctly if it contains Cyrillic symbol.
Does not support other languages with special characters (leads to program crash).


**#WIP**
