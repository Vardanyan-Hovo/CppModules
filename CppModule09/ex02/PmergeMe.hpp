//merge-insert sort algorithm used list, vector
#ifndef PMERGEME_HPP
# define PMERGEME_HPP


#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <exception>
#include <iomanip>
#include <list>
#include <sys/time.h>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();

	public:
		void startTimVector();
		void pars_inputToIntVector(char **s);
		void MergInsertionSort(void);
		void margSort(int start, int end);
		void insertionSort(int size, int end);
		void printVector(std::vector<int> &v, int flag);
		void merge(int low, int mid, int high);

	public:
		void startTimList();
		void pars_inputToIntList(char **s);
		void MergInsertionSortList(void);
		void margSortList(int start, int end);
		void insertionSortList(int start, int end);
		void mergeList(int low, int mid, int high);
		std::list<int>::iterator plusIterator(std::list<int>::iterator i, int count);
		void printList(std::list<int> l, int flag);



		void printDuration(void);					//	list[value] = vector[value]
		std::list<int> getListDb(void) const;
		std::vector<int> getVectorDb(void) const;
		struct timeval get_startTimeV() const;
		struct timeval get_endTimeV() const;
		struct timeval get_startTimeL() const;
		struct timeval get_endTimeL() const;
		class Excp : public std::exception
		{
			public:
				Excp();
				Excp(const char *s);
				virtual const char *what() const throw();
			private:
				const char *_s;
		};

	private:
		std::list<int> _l;
		std::vector<int> _v;
		struct timeval _startTimeV;
		struct timeval _endTimeV;
		struct timeval _startTimeL;
		struct timeval _endTimeL;
};



#endif
