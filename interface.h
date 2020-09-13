#pragma once

#include<iostream>
#include<vector>

template<class T>
class abstract_operator {
public:
	virtual T operator()(const T& x, const T& y)noexcept = 0;
};





template<class T>
class sum :public abstract_operator<T> {
public:
	virtual T operator()(const T&, const T&)noexcept override;
};






template<class T>
class sub :public abstract_operator<T> {
public:
	virtual T operator()(const T& x, const T& y)noexcept   ;
};







template<class T>
class mul :public abstract_operator<T> {
public:
	virtual T operator()(const T& x, const T& y)noexcept  ;
};


template<class T>
class Div :public abstract_operator<T> {
public:
	virtual T operator()(const T&, const T&)noexcept  ;
};



template<class T>
struct helper {
	void print(std::vector<std::vector<int>>& x);
	void f(std::vector<std::vector<int>>& x, int index1, int index2, int new_i, int new_j, int const_value);
};

#include"Source1.hpp"
