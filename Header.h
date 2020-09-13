#include<iostream>
#include<vector>
using namespace std;

template<class T>
class abstract_operator {
public:
	virtual T operator()(const T&x, const T&y)noexcept= 0;
};





template<class T1>
class sum :public abstract_operator<T1> {
public:
	virtual T1 operator()(const T1&, const T1&)noexcept override;
};






template<class T>
class sub :public abstract_operator<T> {
public:
	virtual T operator()(const T&x, const T&y)noexcept override;
};







template<class T>
class multypl :public abstract_operator<T> {
public:
	virtual T operator()(const T&x, const T&y)noexcept override;
};








template<class T>
class divide :public abstract_operator <T>{
public:
	virtual T operator()(const T&x, const T&y)noexcept ;
};





#include"Source1.hpp"
#pragma once

