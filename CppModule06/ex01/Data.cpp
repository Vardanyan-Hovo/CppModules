#include "Data.hpp"

Data::Data()
{
    
}

Data::~Data()
{
    
}

Data::Data(uintptr_t raw)
{
    ui = raw;
}

Data::Data(const Data &obj):ui(obj.ui)
{
}

Data & Data::operator=(const Data &obj)
{
    if (this != &obj)
        this->ui = obj.ui;
    return *this;
}

uintptr_t Data::getUi()
{
    return ui;
}
