#include <iostream>
#include <list>
#include <ctime>
#include "main.h"


int TodoItem::getId() const {
    return id;
}


std::string TodoItem::getDescription() const {
    return description;
}


bool TodoItem::isCompleted() const {
    return completed;
}


bool TodoItem::create(std::string new_description) {
    id = rand() % 100 + 1;
    description = new_description;
    return true;
}


void TodoItem::setCompleted(bool val) {
    completed = val;
}


int main() {
    std::string version = "0.1.0";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;
    char input_option;
    int input_id;
    std::string input_description;

    srand(time(NULL));

    todoItems.clear();

    while (1) {
        system("cls");
        std::cout << "TodoPP " << version << std::endl;
        std::cout << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {
            std::string completed = it->isCompleted() ? "Done" : "Not done";
            std::cout << it->getId() << " | " << it->getDescription() << " | ";
            std::cout << completed << std::endl;
        }

        if (todoItems.empty()) {
            std::cout << "Add a new item" << std::endl;
        }

        std::cout << std::endl;
        std::cout << "[a] Add new item" << std::endl;
        std::cout << "[c] Complete item" << std::endl;
        std::cout << "[q] Quit" << std::endl;

        std::cout << "Choose an option: ";
        std::cin >> input_option;
        std::cin.ignore(10000, '\n');

        if (input_option == 'q') {
            std::cout << "Exiting..." << std::endl;
            break;
        } else if (input_option == 'a') {
            std::cout << "Enter the description: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            std::getline(std::cin, input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);
        } else if (input_option == 'c') {
            std::cout << "Enter the item id: ";
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {
                if (it->getId() == input_id) {
                    it->setCompleted(true);
                    break;
                }
            }
        }
    }
    return 0;
}
