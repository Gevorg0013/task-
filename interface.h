#pragma once

#include <iostream>
#include <vector>

template <class T>
class abstract_operator
{
public:
	virtual T operator()(const T& x, const T& y) noexcept = 0;
};

template <class T>
class sum : public abstract_operator<T>
{
public:
	virtual T operator()(const T&, const T&) noexcept override;
};

template <class T>
class sub : public abstract_operator<T>
{
public:
	virtual T operator()(const T& x, const T& y) noexcept override;
};

template <class T>
class mul : public abstract_operator<T>
{
public:
	virtual T operator()(const T& x, const T& y) noexcept override;
};

template <class T>
class Div : public abstract_operator<T>
{
public:
	virtual T operator()(const T&, const T&) noexcept override;
};

template <class T>
struct helper
{
	void print(std::vector<std::vector<std::pair<int, bool>>>& x);
	void f(std::vector<std::vector<std::pair<int, bool>>>& x, int index1, int index2, int new_i, int new_j, T const_value);
};

template <class T>
T sum<T>::operator()(const T& a, const T& b) noexcept
{
	return a + b;
}

template <class T>
T sub<T>::operator()(const T& a, const T& b) noexcept
{
	return a - b;
}

template <class T>
T mul<T>::operator()(const T& x, const T& y) noexcept
{
	return x * y;
}

template <class T>
T Div<T>::operator()(const T& x, const T& y) noexcept
{
	return x / y;
}

template <class T>
inline void helper<T>::print(std::vector<std::vector<std::pair<int,bool>>>&x)
{
	// 70x76 is just for design
	for (int i = 0; i < 70; ++i)
	{
		for (int j = 0; j < 75; ++j)
		{
			if (x[i][j].second == true) { std::cout << x[i][j].first; }
			else { std::cout << ","; }
		}
		std::cout << std::endl;
	}
}

template <class T>
inline void helper<T>::f(std::vector<std::vector<std::pair<int, bool>>>& x, int index1, int index2, int new_i, int new_j, T const_value)
{
	x[index1][index2].first = const_value + x[new_i][new_j].first;
	x[index1][index2].second = true;
}