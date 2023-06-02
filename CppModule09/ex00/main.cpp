#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    std::ifstream fileData;
    std::ifstream inputfile;

    if (argc != 2)
    {
        std::cout<< "Error: could not open file."<<std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange *B = new BitcoinExchange(argv[1], fileData, inputfile);
        B->readFileMultiplication(fileData, inputfile);
        B->closeFile(fileData, inputfile);
        delete B;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}