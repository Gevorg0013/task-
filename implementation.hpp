template<class T>
inline T sum<T>::operator()(const T& a, const T& b)noexcept
{
	return a + b;
}



template<class T>
inline T sub<T>::operator()(const T& a, const T& b)noexcept
{
	return a - b;
}

template<class T>
inline T mul<T>::operator()(const T& x, const T& y)noexcept
{
	return x * y;
}


template<class T>
inline T Div<T>::operator()(const T& x, const T& y)noexcept
{
	return x/y;
}




template<class T>
 inline void helper<T>::print(std::vector<std::vector<int>>& x)
	{
		// 70x76 is just for design
		for (int i = 0; i < 70; ++i)
		{
			for (int j = 0; j < 76; ++j)
			{
				std::cout << x[i][j] << "";
			}
			std::cout << std::endl;
		}
	}

 template<class T>

	inline void helper<T>:: f(std::vector<std::vector<int>>& x, int index1, int index2, int new_i, int new_j, int const_value)
	{
		x[index1][index2] = const_value + x[new_i][new_j];
	}




