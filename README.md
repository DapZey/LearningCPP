## Raylib download: 
GOTO:

https://www.raylib.com/

When the download is finished run the raylib laucher.
## setup
paste the project cmake into cmakelists.txt
## DEV NOTES
winsock and raylib have conflicts so you need to use them in seperate namespaces as shown in the project.

camera2d object needs to move by int values to not be jittery

included some useful gamedev math functions in main that are not in use
