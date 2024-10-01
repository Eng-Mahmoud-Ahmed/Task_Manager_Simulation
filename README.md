C++ Project: Task Manager Simulation
Objective:
Implement a simple task manager that simulates managing running processes using both stacks
and queues. The task manager will allow users to add, remove, and view processes based on
different scheduling mechanisms.


Classes to Implement:
1. Process: This class will represent a single process with attributes like:
- id (unique identifier)
- name (process name)
- priority (int: 1 for high, 2 for medium, 3 for low)
2. TaskManager: This class will manage processes using:
- A stack (std::stack<Process>) for LIFO mechanism.
- A queue (std::queue<Process>) for FIFO mechanism.
Features to Implement:
1. Add a Process: The user should be able to add a process to either the stack or the queue.
2. View Next Process: Display the next process in the stack (LIFO) or queue (FIFO) without
removing it.
3. Execute Process: Remove the next process from either the stack or queue and mark it as
executed.
4. List all Processes: Display all processes in the stack and queue.

--------------------
Bonus Features:
1. Sort the processes by priority before adding them to the stack or queue.
2. Simulate running processes based on priority where higher-priority tasks get executed first.

----------------
Example User Flow:
1. User adds a new process (Process ID: 1, Name: 'Update', Priority: 2).
2. User adds another process (Process ID: 2, Name: 'Compile', Priority: 1).
3. User views the next process in the stack and queue.
4. User executes the next process from the stack.
5. User lists all remaining processes.
