#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE



#include <iostream>
#include <exception>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class BitcoinExchange
{
    public:
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange(const char *s, std::ifstream &myfile, std::ifstream &inputfile);
        BitcoinExchange& operator=(const BitcoinExchange &obj);

        class Excp : public std::exception
		{
			public:
				Excp(const char *s);
				virtual const char *what() const throw();
			private:
				char *s;
		};
        std::string getFileName() const;
        std::string getKey(void) const;
        double      getValue(void ) const;
        void        setMap(std::ifstream &fileData);
        std::string getData() const;
        std::map<std::string, double> getDbase() const;

        int         chackInputFileValue(std::string strInput);
        int         checkTwoString(std::string s0, std::string s1);
        int         dataCheck(std::string day);

        std::string changDay(std::string news);
        void        readFileMultiplication(std::ifstream &fileData, std::ifstream &inputfile);
        std::map<std::string, double>::iterator        searchValue(std::string s0, std::string s1);
        void        printMap(void);
        void        closeFile(std::ifstream &fileData, std::ifstream &inputfile);
        std::map<std::string, double>::iterator DayLowerBound(std::string news);
        ~BitcoinExchange();
    private:
        BitcoinExchange(const char *s);
        BitcoinExchange();
        std::string fileName;
        const std::string data;
        std::map<std::string, double> Dbase;
        double value;
        std::string key;
};

#endif
