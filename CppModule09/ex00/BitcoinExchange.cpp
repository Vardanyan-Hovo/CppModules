#include "BitcoinExchange.hpp"

// -------------   Orthodox Canonical Form ------

BitcoinExchange::BitcoinExchange():data("cpp_09/data.csv")
{
}

BitcoinExchange::BitcoinExchange(const char *s):data("cpp_09/data.csv")
{
    while (*s)
    {
        fileName += *s++;
    }
    
}

BitcoinExchange::BitcoinExchange(const char *s, std::ifstream &fileData,  std::ifstream &inputfile):data("cpp_09/data.csv")
{
    while (*s)
        fileName += *s++;

    fileData.open(data);
    inputfile.open(fileName);
    if (!fileData.is_open() || !inputfile.is_open())
    {
        BitcoinExchange::Excp("Unable to open file");
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj):data(obj.getData())
{
    this->fileName = obj.getFileName();
    Dbase = obj.getDbase();
    value = obj.getValue();
    key = obj.getKey();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
    {
        this->fileName = obj.getFileName();
        const_cast<std::string&>(this->data) = obj.getData();
        value = obj.getValue();
        key = obj.getKey();
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

// ------------    geter and seter   -----------------

std::string BitcoinExchange::getFileName() const
{
    return this->fileName;
}

double BitcoinExchange::getValue(void ) const
{
    return value;
}

std::string BitcoinExchange::getKey(void) const
{
    return key;
}

std::string BitcoinExchange::getData() const
{
    return this->data;
}

std::map<std::string, double> BitcoinExchange::getDbase() const
{
    return Dbase;
}

// ------------    logical methods   -----------------


void BitcoinExchange::closeFile(std::ifstream &myfile, std::ifstream &inputfile)
{
    myfile.close();
    inputfile.close();
}

void    BitcoinExchange::setMap(std::ifstream &fileData)
{
    std::string strData,str[2];

    getline(fileData, strData);
    if (strData.compare("date,exchange_rate"))
        throw BitcoinExchange::Excp("file CSV incorrect");
    while (getline(fileData, strData))
    {
        std::stringstream ss(strData);
        if (strData.find(',') != std::string::npos)
        {
            getline(ss, str[0], ',');                   // key    2018-05-31
            getline(ss, str[1], '\0');                  // value  7386.72

            if (!str[0].empty() && !str[1].empty())
            {
                Dbase[str[0]] = static_cast<double>(atof(str[1].c_str()));
            }
        }
    }
}

void BitcoinExchange::printMap(void)
{
    std::map<std::string, double>::iterator i;

    for (i = this->Dbase.begin(); i != this->Dbase.end(); i++)
    {
        std::cout<< "["<< i->first << "] ="<<i->second<<std::endl;
    }
}

int BitcoinExchange::chackInputFileValue(std::string strInput)
{
    size_t i = 0;
    size_t number = 0;
    size_t l = 0;
    size_t space = 0;
    size_t point = 0;

    while (strInput[i] == ' ')
        i++;
    if (strInput.empty() || i == strInput.length())
    {
        std::cout<<"there is no line";
        return 1;
    }
    i = 0;
    while (strInput[i])
    {
        if (strInput[i] == '-' && (((i == 4 || i == 7) && isdigit(strInput[i+1]) && isdigit(strInput[i + 2])) || i == 13))
            l++;
        else if (isdigit(strInput[i]))
            number++;
        if (strInput.compare(i, 3, " | ") == 0)
            space++;
        if (strInput[i] == '.')
            point++;
        i++;
    }
    if ((l != 2 && l !=3) || space != 1 || ((number + l +(space + 2) + point) != strInput.length()))
    {
        std::cout<<"Error: bad input => " << strInput;
        return 1;
    }
    return 0;
}

int BitcoinExchange::checkTwoString(std::string s0, std::string s1) // input.txt s0 == day    s1 == value
{
    size_t j = 0;
    size_t i = 0;

    if (s0.empty())
    {
        std::cout<<"Error: not a data.";
        return 1;
    }
    while (s0[i] == ' ')
        i++;
    if (i == s0.length())
    {
        std::cout<<"Error: not a data.";
        return 1;
    }
    i = 0;
    if ((s1.find('.') != s1.rfind('.')) || (s1.find('-') != std::string::npos))
    {
        std::cout<<"Error: not a positive number.";
        return 1;
    }
    for ( ; i < s1.length(); i++)
    {
        if ((s1[i] == '+' && i == 0) || isdigit(s1[i]) || (s1[i]=='.' && s1[i + 1] && isdigit(s1[i + 1])))
        {
            j++;
        }
    }
    if (i - 1 != j)
    {
        std::cout<<"Error: not a positive number.";
        return 1;
    }
    if (atof(s1.c_str()) > 1000)
    {
        std::cout<<"Error: too large a number.";
        return 1;
    }
    return 0;
}

int BitcoinExchange::dataCheck(std::string day)
{
    std::string Year;
    std::string Month;
    std::string Day;

    std::stringstream ss(day);
    getline(ss, Year, '-');
    getline(ss, Month, '-');
    getline(ss, Day, '\0');

    int Y = atof(Year.c_str());
    int M = atof(Month.c_str());
    int D = atof(Day.c_str());

    if (D <= 0 || D > 31 || M <= 0 || M > 12 || Y < 2009)
    {
        return 1;
    }
    switch (M)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return D > 30 ? 1 : 0;
    case 2:
        {
            if (Y % 4 == 0 && ((Y % 400 == 0 && Y % 100 == 0) || Y % 100 != 0))
            {
                return (D > 29 ? 1 : 0);
            }
            else 
            {
                return (D > 28 ? 1 : 0);
            }
        }    
    }
    return 0;
}


//Dbase.lower_bound(news) compare key (in map<key , value> lower(news == key)) and return map<key, value>iterator
//if input 02     [01"a", 02"b", 03"c"] return (iterator 03"c")
std::map<std::string, double>::iterator BitcoinExchange::DayLowerBound(std::string news)
{
    std::map<std::string, double>::iterator i = Dbase.find(news);

    if (!i->first.empty())
    {
        return i;
    }
    i = Dbase.lower_bound(news);
    if (i != Dbase.begin() && !Dbase.lower_bound(news)->first.empty())
    {
        --i;
    }
    return (i);
}

void BitcoinExchange::readFileMultiplication(std::ifstream &fileData, std::ifstream &inputfile)
{
    std::string strInput;
    std::string str,s[2];
    std::string newsDay;

    this->setMap(fileData);
    getline(inputfile, strInput);
    if (strInput != "date | value")
        throw BitcoinExchange::Excp("input file incorrect");

    while (getline(inputfile, strInput))                        // input get line = [2012-01-11 | -1]
    {
        if (!this->chackInputFileValue(strInput))
        {
            std::stringstream ss(strInput);
            getline(ss, s[0], '|');
            getline(ss, s[1], '\0');

            if (this->checkTwoString(s[0], s[1]))               // chack s0 = 2011-01-03  | s1 = 1.2
            {
                std::cout<<std::endl;
                continue ;
            }
            if (dataCheck(s[0]))
            {
                std::cout<<"Error: bad input => " << s[0]<<std::endl;
                continue ;
            }
            std::map<std::string, double>::iterator i = this->DayLowerBound(s[0]);
            value = atof(s[1].c_str());

            if (i != Dbase.end() && i != Dbase.upper_bound(s[0]))
            {
                std::cout<< s[0] <<" => " << s[1] <<" = "<< (value * i->second);
            }
            else
            {
                std::cout<< "input value does not have in database";
            }
        }
        std::cout<<std::endl;
    }
}

//---------------  exception  ----------------

BitcoinExchange::Excp::Excp(const char *s)
{
	this->s = const_cast<char*>(s); 
}

const char* BitcoinExchange::Excp::what() const throw()
{
    return this->s;
}

//--------------------------------------------------

std::string BitcoinExchange::changDay(std::string news)
{
    if (!Dbase.lower_bound(news)->first.empty() && Dbase.lower_bound(news) != Dbase.begin())
        return (Dbase.lower_bound(news)->first);
    else
        return (Dbase.lower_bound(news)->first);
    return NULL;
}

std::map<std::string, double>::iterator BitcoinExchange::searchValue(std::string s0, std::string s1)
{
    std::map<std::string, double>::iterator i;

    value = atof(s1.c_str());
    for (i = Dbase.begin(); i != Dbase.end(); i++)
    {
        if (!s0.compare(i->first))
        {
            return i;
        }
    }
    return Dbase.end();
}
