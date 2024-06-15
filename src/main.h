//
// Created by matheusduarte on 6/15/2024.
//

#ifndef TODOPP_MAIN_H
#define TODOPP_MAIN_H

#include <string>

class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}

    ~TodoItem() = default;

    int getId() const;

    std::string getDescription() const;

    bool isCompleted() const;

    bool create(std::string new_description);

    void setCompleted(bool val);
};

#endif //TODOPP_MAIN_H
