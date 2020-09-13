#include <memory>

#include "interface.h"

int main()
{
	size_t rown, column;
	std::cout << "input rown ";
	std::cin >> rown;
	std::cout << " inoyut column";
	std::cin >> column;
	std::vector<std::vector<int>> x(70, std::vector<int>(76));

	for (size_t i = 0; i < 70; ++i)
	{
		for (size_t j = 0; j < 76; ++j)
		{
			x[i][j] = 0;
		}
	}

	for (size_t i = 0; i < rown; ++i)
	{
		for (size_t j = 0; j < column; ++j)
		{
			std::cin >> x[i][j];
		}
	}

	std::unique_ptr<abstract_operator<int>> u_ptr;
	char c;
	std::cout << "now to input operator throught character  ";
	std::cin >> c;

	switch (c)
	{
	case '+':
		u_ptr = std::unique_ptr<abstract_operator<int>>(new sum<int>);
		break;

	case '-':
		u_ptr = std::unique_ptr<abstract_operator<int>>(new sub<int>);
		break;

	case '*':
		u_ptr = std::unique_ptr<abstract_operator<int>>(new mul<int>);
		break;

	case '/':
		u_ptr = std::unique_ptr<abstract_operator<int>>(new Div<int>);
		break;

	default:
		break;
	}
	int number1, number2;
	std::cout << "\n\ninput first number  for operation";
	std::cin >> number1;
	std::cout << "\n\ninput second number for operatiion";
	std::cin >> number2;
	std::cout << u_ptr->operator()(number1, number2) << std::endl;
	std::cout << "\n\n\n\n";

	size_t n_row, n_column, old_row, old_column;
	int const_value;
	std::cout << "\n\ninput i and j index,where we want to add sum ";
	std::cin >> n_row >> n_column;

	std::cout << "\n\ninput index of element,form where we have to use ";
	;
	std::cin >> old_row >> old_column;
	std::cout << "\n\ninput const value ";
	std::cin >> const_value;

	helper<int> help;
	help.f(x, n_row, n_column, old_row, old_column, const_value); //isk es function -@ kanchvuma vor mer uzac (i j) rd texum mer mot et nshvaca(3,4) axyusaki meji inchvor dirqi elementin(mer mot (i=0,j=1)-rd elementin) gumarenq kamayakan konstant tiv (mer mot 100)
	std::cout << std::endl;

	help.print(x);
}