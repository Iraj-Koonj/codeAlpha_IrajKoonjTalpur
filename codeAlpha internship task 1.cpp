#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold task details
struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

// Function to display the menu
void showMenu() {
    cout << "\n===== To-Do List =====\n";
    cout << "1. Add Task\n";
    cout << "2. Mark Task as Completed\n";
    cout << "3. View Tasks\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a task
void addTask(vector<Task> &tasks) {
    string desc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, desc);
    tasks.push_back(Task(desc));
    cout << "Task added successfully!\n";
}

// Function to mark a task as completed
void markCompleted(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to complete.\n";
        return;
    }

    cout << "Enter task number to mark as completed: ";
    int index;
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

// Function to display all tasks
void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[?] " : "[ ] ") << tasks[i].description << "\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                markCompleted(tasks);
                break;
            case 3:
                viewTasks(tasks);
                break;
            case 4:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
