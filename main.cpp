#include "./util.h"

int main()
{
	const array_2D<abstract_cell_ptr> data = util::read("D:\\Helo.txt");

	try
	{
		for (auto &i : data)
		{
			for (auto &j : i)
			{
				if (*j)
				{
					// If the cell is not empty
					std::cout << (*j)(data) << ',';
				}
				else
				{
					// If the cell is empty
					std::cout << ',';
				}
			}
			std::cout << std::endl;
		}
	}
	catch (const char *const str)
	{
		std::cerr << "Error during data calculation: " << str << std::endl;
	}

	return 0;
}