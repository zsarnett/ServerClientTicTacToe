# Server Client TicTacToe
##### TicTacToe Game Over Server Client Connection

This Application allows you to set up a TicTacToe Server on any device within your Network and run a client on a different/same device that will connect to the server and start the game of TicTacToe

### Installation

To install both the Server and Client executables:
  ```
   $ make
  ```

To install only the Server executable:
  ```
   $ make server
  ```
  
To install only the Client executable:
  ```
   $ make client
  ```
  
To clean out old executables:
  ```
   $ make clean
  ```
  
### Running Executables

To run the Server executable:
  ```
   $ ./server
  ```
  
To run the Client executable:
  ```
   $ ./client [IP_Address]
  ```
  * Where [IP_Address] is the IP Address of the Server Device on the Network. You can get this by running ifconfig on linux machines
    * You will use the inet address or IPv4 address
  
### Playing

Example Move:
```
  0 1 2
0 ? ? ? 
1 ? ? ? 
2 ? ? ? 

Which cell would you like to mark (row and column)? 1 1
```

The Client will ask `Which cell would you like to mark (row and column)?` and the appropriate input is two numbers with a space between them. No Spaces before or after. Ex. `1 1`

The Server will then respond with a move and the board will be updated.
