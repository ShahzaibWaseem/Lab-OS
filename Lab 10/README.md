# Lab 10: Inter-Process Communication using Pipes

## Task
Design a simple C program using ordinary pipes in which a parent and child processes exchange greeting messages. For example, the parent process may send the message “Hello Child Process”, and the child process may return “Hi Parent Process”. Use UNIX pipes to write this program.

For reference, see http://tldp.org/LDP/lpg/node11.html.
Note that this URL only shows an example of a unidirectional pipe. You need to have bidirectional behavior in your program for which you will need two pipes.