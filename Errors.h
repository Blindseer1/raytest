#ifndef EXCEPTIONS_H 
#define EXCEPTIONS_H
#include <iostream>

class GameException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "General game exception";
    }
};

class StaminaException : public GameException {
public:
    const char* what() const noexcept override {
        return "Not enough stamina to perform this action";
    }
};


class FileLoadException : public GameException {
public:
    const char* what() const noexcept override {
        return "Failed to load game file";
    }
};
#endif
