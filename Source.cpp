#include"Header.h"




int main()
{
	int rown, column;
	sum<int> obj1;
	sub<int>obj2;
	multypl<int>obj3;
	divide<int>obj4;
	cout << "input rown "; cin >> rown;
	cout << " inoyut column"; cin >> column;
	vector<vector<int>>x(70, vector<int>(70));


	for (int i = 0; i < 70; ++i)
	{
		for (int j = 0; j < 70; ++j)
		{
			x[i][j] = 0;
		}
	}

	for (int i = 0; i < rown; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			cin >> x[i][j];
		}
		
	}






	for (int i = 0; i < 70; ++i)
	{
		for (int j = 0; j < 70; ++j)
		{
			cout<<x[i][j];
		}
		cout << endl;
	}

	abstract_operator<int>* ptr = nullptr;
	char c;
	cout << "now to input operator throught character  "; cin >> c;

	switch (c)
	{
	case '+':
		 ptr = &obj1;
		 break;

	case'-':
		ptr = &obj2;
		break;

	case'*':
		ptr = &obj3;
		break;

	case '/':
		ptr = &obj4;
			break;



	default:
		break;
	}


	cout << ptr->operator()(1, 2) << endl;


}