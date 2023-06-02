#include "PmergeMe.hpp"

//								----------------------- Orthodox Canonical Form ---------------------------------

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj) : _l(obj.getListDb()),_v(obj.getVectorDb()),
		_startTimeV(obj.get_startTimeV()),
		_endTimeV(obj.get_endTimeV()),
		_startTimeL(obj.get_startTimeL()),
		_endTimeL(obj.get_endTimeL())
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		this->_l = obj.getListDb();
		this->_v = obj.getVectorDb();
		_startTimeV = obj.get_startTimeV();
		_endTimeV = obj.get_endTimeV();
		_startTimeL = obj.get_startTimeL();
		_endTimeL = obj.get_endTimeL();
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

//								----------------------------------------- getr -------------------------------

std::list<int> PmergeMe::getListDb() const
{
	return _l;
}

std::vector<int> PmergeMe::getVectorDb() const
{
	return _v;
}

struct timeval PmergeMe::get_startTimeV() const
{
	return _startTimeV;
}
struct timeval PmergeMe::get_endTimeV() const
{
	return _endTimeV;
}
struct timeval PmergeMe::get_startTimeL() const
{
	return _startTimeL;
}
struct timeval PmergeMe::get_endTimeL() const
{
	return _endTimeL;
}

//  							---------------------------------------  Parsing    -----------------------------

void PmergeMe::pars_inputToIntVector(char **s)
{
    std::string word;
	std::string strNumber;
	std::string newString;

    double x;
	int i = 1;
	int k;
	int j;

	while (s[i])
	{
		std::string("").swap(newString);
		j = -1;
		while (s[i][++j])
		{
			newString += s[i][j];
		}
		std::stringstream ss(newString);
		while (ss >> word) {
				k = -1;
			while (word[++k])
			{
				if (word[0] == '-')
					throw PmergeMe::Excp("Error");
				if (!isdigit(word[k]))
				{
					throw PmergeMe::Excp("input is not digit");
				}
			}
			x = atof(word.c_str());
			if (x >= INT_MAX)
				throw PmergeMe::Excp("Max value out in int range");
			if (x < 0)
				throw PmergeMe::Excp("Error");
			this->_v.push_back(x);
		}
		i++;
	}
	// this->printVector(this->_v,0);
}

void PmergeMe::pars_inputToIntList(char **s)
{
    std::string word;
	std::string strNumber;
	std::string newString;

    double x;
	int i = 1;
	int k;
	int j;

	while (s[i])
	{
		std::string("").swap(newString);
		j = -1;
		while (s[i][++j])
		{
			newString += s[i][j];
		}
		std::stringstream ss(newString);
		while (ss >> word) {
			k = -1;
			while (word[++k])
			{
				if (word[0] == '-')
					throw PmergeMe::Excp("Error");
				if (!isdigit(word[k]))
					throw PmergeMe::Excp("input is not digit");
			}
			x = atof(word.c_str());
			if (x >= INT_MAX)
				throw PmergeMe::Excp("Max value out in int range");
			if (x < 0)
				throw PmergeMe::Excp("Error");
			_l.push_back(x);
		}
		i++;
	}
	this->printList(_l, 0);
}

// 									-----------------------------------------   for Vector logic ------

void PmergeMe::startTimVector()
{
	gettimeofday(&_startTimeV, NULL);       //start
}

void PmergeMe::insertionSort(int start, int end)
{
	std::vector<int>::iterator i = _v.begin() + start;
	std::vector<int>::iterator k = _v.begin() + end + 1;
	std::vector<int>::iterator j;
	int num;

	for ( ; i != k; i++)
	{
		j = i;
		while (j != (_v.begin() + start) && *j < *(j-1))
		{
			num = *j;
			*j = *(j - 1);
			*(j - 1) = num;
			j--;
		}
	}
}

void PmergeMe::merge(int low, int mid, int high)
{
    int i, j;

	std::vector<int> newV;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;
    int arrLeft[lengthLeft], arrRight[lengthRight];

    for (int a = 0; a < lengthLeft; a++) {
        arrLeft[a] = this->_v[low + a];
    }
    for (int a = 0; a < lengthRight; a++) {
        arrRight[a] = this->_v[mid + 1 + a];
    }

    i = 0;
	j = 0;

    while (i < lengthLeft && j < lengthRight) {
        if (arrLeft[i] <= arrRight[j]) {
            newV.push_back(arrLeft[i]);
            i++;
        } else {
            newV.push_back(arrRight[j]);
            j++;
        }
    }
	while (i < lengthLeft) {
        newV.push_back(arrLeft[i]);
        i++;
    }
    while (j < lengthRight) {
        newV.push_back(arrRight[j]);
        j++;
    }
	for (int i = low; i < high; i++)
	{
		this->_v[i] = newV[i - low];
	}

}

void PmergeMe::margSort(int start, int end)
{
	int mid=0;

	mid = (end + start)/ 2;
	if ((end - start) < 16)
	{
		this->insertionSort(start, end);
		return ;
	}
	margSort(start,  mid);
	margSort(mid + 1,  end);
	this->merge(start, mid, end);
}

void PmergeMe::MergInsertionSort()
{
	margSort(0 , _v.size() - 1);	 		 //logic
	gettimeofday(&_endTimeV, NULL);  		 //end
}


//														-----------------------------------------   for List logic ------

void PmergeMe::startTimList()
{
	gettimeofday(&_startTimeL, NULL);
}

//to give ability to apply index of list directly
std::list<int>::iterator PmergeMe::plusIterator(std::list<int>::iterator i, int count)
{
	int minus = 0;
	
	if (count < 0)
	{
		minus = 1;
		count = count * -1;
	}
	for ( ; 0 < count; count--)
	{
		if (minus > 0)
			i--;
		else
			i++;
	}
	return i;
}

void PmergeMe::insertionSortList(int start, int end)
{
	std::list<int>::iterator i = plusIterator(_l.begin(), start);
	std::list<int>::iterator k = plusIterator(_l.begin() , end + 1);
	std::list<int>::iterator j;
	int num;

	for ( ; i != k; i++)
	{
		j = i;
		while (j != plusIterator( _l.begin(), start) && *j < *plusIterator(j, -1))
		{
			num = *j;
			*j = *plusIterator(j, -1);
			j = plusIterator(j, -1);
			*j = num;
		}
	}
}

void PmergeMe::mergeList(int low, int mid, int high)
{
    int i, j;

	std::list<int> newV;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;
    int arrLeft[lengthLeft], arrRight[lengthRight];

    for (int a = 0; a < lengthLeft; a++) {
        arrLeft[a] = *plusIterator(this->_l.begin(), low + a);
    }
    for (int a = 0; a < lengthRight; a++) {
        arrRight[a] = *plusIterator(this->_l.begin(),mid + 1 + a);
    }

    i = 0;
	j = 0;

    while (i < lengthLeft && j < lengthRight) {
        if (arrLeft[i] <= arrRight[j]) {
            newV.push_back(arrLeft[i]);
            i++;
        } else {
            newV.push_back(arrRight[j]);
            j++;
        }
    }
	while (i < lengthLeft) {
        newV.push_back(arrLeft[i]);
        i++;
    }
    while (j < lengthRight) {
        newV.push_back(arrRight[j]);
        j++;
    }
	for (int i = low; i < high; i++)
	{
		this->_v[i] = *plusIterator(newV.begin(),i - low);
	}

}

void PmergeMe::margSortList(int start, int end)
{
	int mid=0;


	mid = (end + start)/ 2;
	if (end - start < 16)
	{
		this->insertionSortList(start, end);
		return ;
	}
	margSortList(start,  mid);					//	1) 0,7  mid=3  2) 0,3 mid=1  3) 0,1 mid=0  4) 0,0 mid=null
	margSortList(mid + 1,  end);
	this->mergeList(start, mid, end);
}

void PmergeMe::MergInsertionSortList(void)
{
	margSortList(0 , _l.size() - 1);	 //logic
	gettimeofday(&_endTimeL, NULL);  //end
}

// 							-------------------------------------------   Print ----------------

void PmergeMe::printVector(std::vector<int> &v, int flag)
{
	std::vector<int>::iterator i = v.begin();

	if (flag == 0)
		std::cout<<"Before: ";
	else
		std::cout<<"After : ";
	for (; i != v.end() && i != v.begin() + 8; i++)
	{
		std::cout << *i << " ";
	}
	if (v.size() > 8)
	{
		std::cout<<" [...]";
	}
	std::cout<<std::endl;
}

void PmergeMe::printList(std::list<int> l, int flag)
{
	std::list<int>::iterator i = l.begin();

	if (flag == 0)
		std::cout<<"Before: ";
	else
		std::cout<<"After : ";
	for (size_t j = 0; i != l.end() && j < 8; j++,i++)
	{
		std::cout << *i << " ";
	}
	if (l.size() > 8)
	{
		std::cout<<" [...]";
	}
	std::cout<<std::endl;
}

void PmergeMe::printDuration()
{
	printVector(this->_v, 1);
	// printList(this->_l, 1);
	double sec1 = ((_endTimeV.tv_sec * 1000 + _endTimeV.tv_usec * 0.001) - (_startTimeV.tv_sec * 1000 + _startTimeV.tv_usec * 0.001));
	double sec2 =((_endTimeL.tv_sec * 1000 + _endTimeL.tv_usec * 0.001) - (_startTimeL.tv_sec * 1000 + _startTimeL.tv_usec * 0.001));
	std::cout<<"Time to process a range of   "<< _v.size() << " elements with std::vector[..] : "<<std::flush;
	std::cout<<  sec1 <<" us" << std::endl;
	std::cout<<"Time to process a range of   "<< _l.size() << " elements with std::list[..] : "<<std::flush;
	std::cout<<  sec2 <<" us" << std::endl;
}

// --------------------------------------------  Exception  -----

PmergeMe::Excp::Excp(const char *s):_s(s)
{
}

PmergeMe::Excp::Excp():_s("Error")
{
}

const char *PmergeMe::Excp::what() const throw()
{
	return _s;
}
