#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
	{
		std::cout<<"Error"<<std::endl;
		return 1;
	}
	 try{
        PmergeMe *B = new PmergeMe();

        B->startTimVector();
        B->pars_inputToIntVector(argv);
        B->MergInsertionSort();

        B->startTimList();
        B->pars_inputToIntList(argv);
        B->MergInsertionSortList();
	   	B->printDuration();
		delete B;
	  }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}
