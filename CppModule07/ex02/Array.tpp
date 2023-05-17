#include "Array.hpp"

template<typename T>
Array<T>::Array():a(0),n(0)
{
}

template<typename T>
Array<T>::Array(int n)
{
    if (n > INT_MAX || n < 0)
        throw Array<T>::GradeExcep("you don't can allocation this range");
    a = new T[n];
    this->n = n;
   if (!a)
   {
        throw Array<T>::GradeExcep("allocation error");
   }
   for(int i = 0; i < n; i++)
   {
	   a[i] = 0;
   }
}

template<typename T>
Array<T>::~Array()
{
	delete [] a;
}

template<typename T>
Array<T>::Array(const Array &arr)
{
    n = arr.size();
    this->a = new int [n];
    if (!this->a)
    {
        throw Array<T>::GradeExcep("allocation error");
    }
    for (size_t i = 0; i < n; i++)
    {
        this->a[i] = arr[i];
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T>&arr)
{
    if (this != &arr)
    {
        n = arr.size();
        this->a = new int [n];
        if (!this->a)
        {
            throw Array<T>::GradeExcep("allocation error");
        }
        for (size_t i = 0; i < n; i++)
        {
            this->a[i] = arr[i];
        }
    }
    return *this;
}

template<typename T>
T *Array<T>::getApoint()
{
    if (a)
        return a;
    return 0;
}

template<typename T>
unsigned int Array<T>::size(void) const
{
    return n;
}

template<typename T>
T &Array<T>::operator[](int i)
{
    if (i < 0)
        throw Array<T>::GradeExcep("arguments must be positive");
    if (i >= (int)n || !a || !&a[i])
        throw Array<T>::GradeExcep("the argument does not match the range");
    return a[i];
}

template<typename T>
const T& Array<T>::operator[](int i) const
{
    if (i < 0)
        throw Array<T>::GradeExcep("const:  arguments must be positive");
    if (i >= (int)n || !a || !&a[i])
       throw Array<T>::GradeExcep("const:  the argument does not match the range");
    return a[i];
}


template<typename T>
Array<T>::GradeExcep::GradeExcep():s("")
{
}

template<typename T>
Array<T>::GradeExcep::GradeExcep(const char *reason) : s(reason)
{
}

template<typename T>
const char *Array<T>::GradeExcep::what() const throw()
{
    return s;
}