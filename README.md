## Named Pipes using C++

The current implementation focuses on implementing named pipes using the GNU library unistd.h for Linux systems.

## How to run
- Compile the server.cpp using:
``` g++ -o main server.cpp NamedPipeOperations.cpp```
- Compile client.cpp using:
```g++ -o client client.cpp NamedPipeOperations.cpp```
- Copy helloworld.service from resources folder and add to to /lib/systemd/system
- Within helloworld.service change ExecStart to the path of the compiled server.cpp
e.g. ExecStart=/home/murtaza/99X/C++/HelloWorld/main
  - To run the service:
```sudo systemctl start helloworld.service```
  - To check the logs of the service
```journalctl -u helloworld.service```
  - To stop the service:
```sudo systemctl stop helloworld.service```
- Run the client.cpp using a different terminal:
```./client ```
- Writing to the named pipe using:
  - Go to the root and go to /tmp directory
  - Go to sudo mode i.e. ```sudo su```
  - Run this command to write to the pipe```echo "Hello world is fun" > queryfifoin```

After doing the following you can print the helloworld.service log and client program. You will be able to see the processed data.