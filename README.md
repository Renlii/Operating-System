# Operating-System
A Simple Remote Procedure Call Service for my operating system class.

The calculator is structured as two programs: frontend and backend. The frontend does not do the
actual calculations. It just prints the prompt, get the input from the user, parses the input into a
message. The frontend passes the message to the backend that does the actual calculations and
passes the result back to the frontend, where it is printed to the user. The backend has some functions it wants to expose for the frontend.
The frontend needs to call those functions that are exposed by the backend. The remote procedure
call service (RPCServ) is responsible for linking the two.
