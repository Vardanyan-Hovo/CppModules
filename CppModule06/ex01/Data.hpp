#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data {
    public:
        Data();
        Data(const uintptr_t raw);
        uintptr_t getUi();
        Data(const Data &obj);
        Data & operator=(const Data&obj);
        ~Data();
    private:
        uintptr_t ui;
};

#endif
