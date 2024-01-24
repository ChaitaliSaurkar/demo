#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    // Function to add a task to the to-do list
    void addTask(const std::string& description) {
        Task newTask{description, false};
        tasks.push_back(newTask);
        std::cout << "Task added: " << description << std::endl;
    }

    // Function to mark a task as completed
    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task completed: " << tasks[index].description << std::endl;
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }

    // Function to display the current tasks
    void displayTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the to-do list." << std::endl;
        } else {
            std::cout << "To-Do List:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << "[" << i + 1 << "] ";
                if (tasks[i].completed) {
                    std::cout << "[X] ";
                } else {
                    std::cout << "[ ] ";
                }
                std::cout << tasks[i].description << std::endl;
            }
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        std::cout << "\n===== To-Do List Menu =====" << std::endl;
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Completed\n";
        std::cout << "3. Display Tasks\n";
        std::cout << "4. Quit\n";
        std::cout << "===========================" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }
            case 2: {
                int taskIndex;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> taskIndex;
                toDoList.markTaskCompleted(taskIndex - 1); // Adjust index (1-based to 0-based)
                break;
            }
            case 3:
                toDoList.displayTasks();
                break;
            case 4:
                std::cout << "Exiting the To-Do List application. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
