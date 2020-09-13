template<class T>
inline T sum<T>::operator()(const T&a, const T&b)noexcept
{
	return a + b;
}



template<class T>
inline T sub<T>::operator()(const T&a, const T&b)noexcept
{
	return a-b;
}

template<class T>
inline T multypl<T>::operator()(const T& x, const T& y)noexcept
{
	return x*y;
}

template<class T>
inline T divide<T>::operator()(const T& x, const T& y)noexcept
{
	return x / y;
}



