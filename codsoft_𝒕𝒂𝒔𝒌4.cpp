//TASK 4 internship TO-DO LIST
#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;

struct Task {
    string description;
    bool completed;
};

void addTask(Task tasks[], int& taskCount, const string& description) {
    if (taskCount < MAX_TASKS) {
        Task newTask = {description, false};
        tasks[taskCount++] = newTask;
        cout << "Task added: " << description << endl;
    } else {
        cout << "Task list is full. Cannot add more tasks." << endl;
    }
}

void viewTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (int i = 0; i < taskCount; ++i) {
            cout << i + 1 << ". ";
            cout << (tasks[i].completed ? "[X] " : "[ ] ");
            cout << tasks[i].description << endl;
        }
    }
}

void removeTask(Task tasks[], int& taskCount, int index) {
    if (index >= 1 && index <= taskCount) {
        cout << "Task removed: " << tasks[index - 1].description << endl;
        for (int i = index - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        --taskCount;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void markTaskCompleted(Task tasks[], int taskCount, int index) {
    if (index >= 1 && index <= taskCount) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed: " << tasks[index - 1].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;

    while (true) {
        cout << "\n=== To-Do List Manager ===" << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Remove Task\n4. Mark Task as Completed\n5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                string description;
                cin.ignore();
                getline(cin, description);
                addTask(tasks, taskCount, description);
                break;
            }
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3: {
                cout << "Enter the index of the task to remove: ";
                int index;
                cin >> index;
                removeTask(tasks, taskCount, index);
                break;
            }
            case 4: {
                cout << "Enter the index of the task to mark as completed: ";
                int index;
                cin >> index;
                markTaskCompleted(tasks, taskCount, index);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
