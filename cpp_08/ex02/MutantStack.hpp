#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		~MutantStack();
		class iterator
		{
			private:
				typename std::deque<T>::iterator iter;
			public:
				iterator();  
				iterator(const typename std::deque<T>::iterator &source);
				iterator(const iterator &source);
				iterator &operator=(const iterator &source);
				iterator &operator=(const typename std::deque<T>::iterator &source);
				iterator operator++();
				iterator operator--();
				bool	 operator!=(const iterator otherObj);
				bool	 operator==(const iterator otherObj);
				T 		 operator*();
				~iterator();
		};
		iterator begin();
		iterator end();
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
	return MutantStack::iterator(this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
	return MutantStack::iterator(this->c.end());
}

template <typename T>
MutantStack<T>::~MutantStack(){

}


template <typename T>
MutantStack<T>::iterator::iterator() {}

template <typename T>
MutantStack<T>::iterator::iterator(const typename std::deque<T>::iterator &source) : iter(source) {}

template <typename T>
MutantStack<T>::iterator::iterator(const MutantStack<T>::iterator &source) : iter(source.iter) {}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(const MutantStack<T>::iterator &source) {
	if (this != &source)
		iter = source.iter;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++() {
	++iter;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--() {
	--iter;
	return *this;
}

template <typename T>
bool	MutantStack<T>::iterator::operator!=(const iterator otherObj)
{
	return (otherObj.iter != iter);
}

template <typename T>
bool	MutantStack<T>::iterator::operator==(const iterator otherObj)
{
	return (otherObj.iter == iter);
}


template <typename T>
T MutantStack<T>::iterator::operator*() {
	return *iter;
}

template <typename T>
MutantStack<T>::iterator::~iterator() {}

#endif
