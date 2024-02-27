#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <algorithm>
# include <ctime>
# include <iomanip>

# define RESET			"\033[0m"
# define BLACK			"\033[30m"				/* Black */
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define BLUE			"\033[34m"				/* Blue */

class PmergeMe
{
	public:
		void merge(int argc, char **argv);

	private:
		void _sortByList(int argc, char **argv);
		void _sortByVector(int argc, char **argv);
};

int jacobsthal(int n);

/*
** --------------------------------- TEMPLATES ---------------------------------
*/

template <typename T>
void printNumbers(const T &container)
{
    typename T::const_iterator it;

    for (it = container.begin(); it != container.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

template <typename T>
T insertionOrder(size_t listSize)
{
	T sequence;

	if (listSize < 1)
	{
		return sequence;
	}

	int jacobsthalNumber = 2;
	int nextJacobsthalNumber = jacobsthal(jacobsthalNumber++);

	while (nextJacobsthalNumber < static_cast<int>(listSize))
	{
		sequence.push_back(nextJacobsthalNumber);
		nextJacobsthalNumber = jacobsthal(jacobsthalNumber++);
	}

	nextJacobsthalNumber = listSize;
	while (sequence.size() < listSize)
	{
		if (std::find(sequence.begin(), sequence.end(), nextJacobsthalNumber) == sequence.end())
			sequence.push_back(nextJacobsthalNumber);
		nextJacobsthalNumber--;
	}

	return sequence;
}

template <typename T>
void sortedPairs(T &pairs, size_t size)
{
	if (size < 2)
	{
		return;
	}

	T left;
	T right;

	typename T::iterator it = pairs.begin();
	for(size_t i = 0; i < size / 2; i++)
	{
		left.push_back(*it++);
	}

	for(size_t i = size / 2; i < size; i++)
	{
		right.push_back(*it++);
	}

	pairs.clear();

	sortedPairs(left, left.size());
	sortedPairs(right, right.size());

	// Compara os pares e ordena ate que uma lista esteja vazia.
	while (!right.empty() && !left.empty())
	{
		if (left.front().first < right.front().first)
		{
			// Se o par estiver ordenado então adiciona o par na lista de pares
			// a ideia é sempre ordenar o par pelo primeiro elemento. [(5, 3), (12, 1)]
			pairs.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			pairs.push_back(right.front());
			right.erase(right.begin());
		}
	}

	// Acontece quando a lista da esquerda é maior que a lista da direita e não tem como comparar.
	while (!left.empty())
	{
		pairs.push_back(left.front());
		left.erase(left.begin());
	}

	while (!right.empty())
	{
		pairs.push_back(right.front());
		right.erase(right.begin());
	}
}

template <typename T>
T sortedOrder(T &sequence)
{
	int stragglers = -1;

	if (sequence.size() < 2)
	{
		return sequence;
	}

	if (sequence.size() % 2 != 0)
	{
		stragglers = sequence.back();
		sequence.pop_back();
	}

	std::list<std::pair<int, int> > pairs;

	for (typename T::iterator it = sequence.begin(); it != sequence.end(); ++it)
	{
		int first = *it;
		int second = *(++it);
		if (first < second)
		{
			pairs.push_back(std::make_pair(second, first));
		}
		else
		{
			pairs.push_back(std::make_pair(first, second));
		}
	}

	sortedPairs(pairs, pairs.size());

	T mainChain;
	T pend;

	for (typename std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		mainChain.push_back(it->first);
		pend.push_back(it->second);
	}

	if (stragglers != -1)
	{
		pend.push_back(stragglers);
	}

	// Adiciona o primeiro elemento da lista pend antes do primeiro elemento da mainchain.
	mainChain.insert(mainChain.begin(), pend.front());

	// Obtém a sequencia da jacobsthal a partir da minha lista desordenada(pend) pq mainchain já está ordenada.
	T indexOrder = insertionOrder<T>(pend.size() - 1);

	if (!indexOrder.empty())
	{
		for (typename T::iterator it = indexOrder.begin(); it != indexOrder.end(); ++it)
		{
			typename T::iterator itPend = pend.begin();
			std::advance(itPend, *it);
			typename T::iterator itPositionInsertion = std::lower_bound(mainChain.begin(), mainChain.end(), *itPend);
			mainChain.insert(itPositionInsertion, *itPend);
		}
	}

	return mainChain;
}

#endif /* ******************************************************** PMERGEME_H */