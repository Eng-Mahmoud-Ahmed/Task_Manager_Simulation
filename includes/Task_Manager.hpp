/********************************************************************************************************
*       Developer:  Mahmoud Ahmed                                                                       *
*       Github   :  https://github.com/Eng-Mahmoud-Ahmed                                                *
*       Linkedin :  https://www.linkedin.com/in/mahmoud-ahmed-b4a639202/                                *
*       Date     :  oct 2024                                                                            *
*                                                                                                       *
*********************************************************************************************************/
#ifndef _TASK_MANAGER_HPP_
#define _TASK_MANAGER_HPP_

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

enum priority_level
{
    high =1,
    medium,
    low 
};

class Process
{
    private:
        int id;
        string name;
        int priority;
    public:
        //Parameterized Constructor
        Process(int i, string n, int p):id(i), name(n),priority(p){};
        //Default Constructor
        Process():id(0),name(""),priority(0){};

        
        void display() const
        {   
            cout << left << setw(5) << "ID: " << id << "\t\t"
                 << left << setw(5) << "Name: " << name <<"\t\t"
                 << left << setw(5) << "Priority: " << priority << endl;
        }
        //getters
        int get_id()const {return id;}
        string get_name()const {return name;}
        int get_priority()const { return priority;}

};

class Task_Manger
{
    private: 
        stack<Process> sProcess;
        queue<Process> qProcess;
    public:
        /* 1. Add Process*/
        void AddProcess(Process p)
        {
            sProcess.push(p);
            qProcess.push(p);
        }

        /* 2. view next process in the stack*/
        void ViewNextProcess_stack()
        {
            if (!sProcess.empty())    
            {
                cout << "Next Process in the stack: \n";
                sProcess.top().display();
            }
            else
                cout << "The stack is empty\n";
        }
        void ViewNextProcess_queue()
        {
            if (!qProcess.empty())
            {
                cout << "Next Process in the queue: \n";
                qProcess.front().display();
            }
            else
                cout << "The queue is empty\n";    
        }

        /* 3. Execute Process*/
        void ExecuteProcess_stack()
        {   
            if (!sProcess.empty())
            {
                Process temp= sProcess.top();
                sProcess.pop();
                cout << "Process is executed successfully\n";
                temp.display();
            }
            else
                cout << "The Stack is empty, no process to be executed.\n";
        }
        void ExecuteProcess_queue()
        {   
            if (!qProcess.empty())
            {
                Process temp= qProcess.front();
                qProcess.pop();
                cout << "Process is executed successfully\n";
                temp.display();
            }
            else
                cout << "The Queue is empty, no process to be executed.\n";
        }

        /* 4. List all process*/
        void ListAll() // pass by value, just a copy to be printed.
        {
            cout << "\n*******************\n" 
                 <<  "All in the Stack\n";
            stack<Process> stemp=sProcess;
            if (!stemp.empty())
            {
                while( !stemp.empty() )
                {
                    stemp.top().display();
                    stemp.pop();
                    cout <<"\n";
                }
            }
            else 
                cout << "No processes in the Stack.\n";

            cout << "\n*******************\n" 
                 <<  "All in the Queue\n";
            queue<Process> qtemp=qProcess;
            if (!qtemp.empty())
            {
                while( !qtemp.empty() )
                {
                    qtemp.front().display();
                    qtemp.pop();
                    cout <<"\n";
                }
            }
            else 
                cout << "No processes in the Queue.\n";          
        }

        /*Bonus Features*/
        //1. Sort the processes by priority before adding them.
        void Add_Process_Sorted(const vector<Process> &p)
        {
            //take a copy 
            vector<Process> temp= p;
            //use lambda function
            sort(temp.begin(),temp.end(),[](const Process &a, const Process &b) {
                return a.get_priority() < b.get_priority();
              } );
            //add the processes after sorting
            for(auto i : temp)
            {
                AddProcess(i);
            }
        }
    
    void Run_By_Priority()
    {
        vector<Process> allProcesses;  // A vector to collect all processes.
        stack<Process> tempStack = sProcess;
        // Collect all processes from stack and queue
        while (!tempStack.empty()) {
            allProcesses.push_back(tempStack.top());
            tempStack.pop();
        }
        queue<Process> tempQueue = qProcess; 
        while (!tempQueue.empty()) {
            allProcesses.push_back(tempQueue.front());
            tempQueue.pop();
        }

        // Sort by priority using a lambda function
        sort(allProcesses.begin(), allProcesses.end(), [](const Process &a, const Process &b) {
            return a.get_priority() < b.get_priority();  // Compare based on priority
        });

        // Simulate execution based on priority
        cout << "Executing processes by priority:" << endl;
        
        for (auto p : allProcesses) 
        {
            p.display();
        }
        
    }
};


#endif