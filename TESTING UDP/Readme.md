### UDP RECEIVER 

The following code provides a template for beginning any application that uses UDP 
for the Windows Operating System. The library used is the Winsock library. Documention
for the library can be found [here](https://docs.microsoft.com/en-us/windows/win32/winsock/about-winsock).
To use, simply change the IP address and the port to suit the needs of the application. 
The current code interprets the received data as doubles. To receive other types, modify 
the lines that unpack the received buffer data. This code is only the receiver, the code 
for a basic sender can be found [here](https://github.com/i6zhang/UDP-Sender).