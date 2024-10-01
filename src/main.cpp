/********************************************************************************************************
*       Developer:  Mahmoud Ahmed                                                                       *
*       Github   :  https://github.com/Eng-Mahmoud-Ahmed                                                *
*       Linkedin :  https://www.linkedin.com/in/mahmoud-ahmed-b4a639202/                                *
*       Date     :  oct 2024                                                                            *
*                                                                                                       *
*********************************************************************************************************/
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

#include "Task_Manager.hpp"


int main()
{
    Task_Manger tm;

    // Adding processes using Process Constructor
    tm.AddProcess(Process(1, "Update", 2));
    tm.AddProcess(Process(2, "Compile", 1));
    tm.AddProcess(Process(3, "Link", 3));
        // View next process in stack and queue
    tm.ViewNextProcess_stack();
    tm.ViewNextProcess_queue();

    // Execute a process from stack and queue
    tm.ExecuteProcess_stack();
    tm.ExecuteProcess_queue();

    // List all remaining processes
    tm.ListAll();

    // Bonus feature: Adding processes with priority sorting
    vector<Process> processes = {
        Process(4, "Build", 13),
        Process(5, "Test", 1),
        Process(6, "Deploy", 5)
    };
    tm.Add_Process_Sorted(processes);
    tm.ListAll();

    // Bonus feature: Run processes by priority
    tm.Run_By_Priority();   


    return 0;
}
