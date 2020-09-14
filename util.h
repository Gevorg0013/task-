#ifndef UTIL_H
#define UTIL_H

#include <cmath>
#include <iostream>
#include <fstream>

#include "./operation_cell.h"
#include "./int_cell.h"
#include "./empty_oprator.h"

class util
{
public:
    static auto get_fn(char op_sign)
    {
        return [op_sign](int x, int y) noexcept {
            switch (op_sign)
            {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            case '%':
                return x % y;
            case '^':
                return (int)std::pow(x, y);
            default:
            {
                std::cerr << "The operant isn't supported: " << op_sign << std::endl;
            }
                return 0;
            }
        };
    }

    static bool is_operand(const char c)
    {
        switch (c)
        {
        case '+':
        case '-':
        case '%':
        case '*':
        case '/':
        case '^':
            return true;
        default:
            return false;
        }
    }

    static array_2D<abstract_cell_ptr> read(const std::string file_path) noexcept
    {
        array_2D<abstract_cell_ptr> cells;

        std::ifstream in{file_path};

        std::string cur_line;

        while (std::getline(in, cur_line))
        {
            std::vector<abstract_cell_ptr> col_cells;
            if (cur_line.empty())
            {
                cells.push_back(std::move(col_cells));
            }

            // generate cell values for the column
            int i = 0;
            while (i < cur_line.size())
            {
                // In case of ',,' current cell consider as empty
                if (cur_line[i] == ',')
                {
                    col_cells.push_back(std::make_unique<empty_operator>());
                }
                // If the cell is like C(i j) ..., consider it as functional cell
                else if (cur_line[i] != 'c')
                {
                    std::string int_str;
                    while (i < cur_line.size() && cur_line[i] != ',')
                    {
                        int_str += cur_line[i++];
                    }
                    col_cells.push_back(std::make_unique<int_cell>(std::stoi(int_str)));

                    // to skip ','
                    if (i != cur_line.size())
                        ++i;
                }
                // otherwice consider it as int, e.g. 43543
                else
                {
                    std::string op_str;

                    while (i < cur_line.size() && cur_line[i] != ',')
                    {
                        op_str += cur_line[i++];
                    }
                    col_cells.push_back(std::make_unique<operation_cell>(std::move(op_str)));

                    // to skip ','
                    if (i != cur_line.size())
                        ++i;
                }
            }

            cells.push_back(std::move(col_cells));
        }

        in.close();

        // fill missing cells with empty operator
        size_t max_column_size = 0;
        for (const auto &column : cells)
        {
            if (column.size() > max_column_size)
            {
                max_column_size = column.size();
            }
        }

        for (auto &column : cells)
        {
            while (column.size() != max_column_size)
            {
                column.push_back(std::make_unique<empty_operator>());
            }
        }

        return cells;
    }
};

#endif