#include "./util.h"
#include "./operation_cell.h"

/**
 * handle such cases (1,2) + 10 - c(10, 5)
 */
int operation_cell::operator()(const array_2D<abstract_cell_ptr> &data) const
{
    int res = 0;

    char op_sign = '?';

    for (int i = 0; i < m_operator.size();)
    {

        // If it's a reference to other cell: c(i j)
        if (m_operator[i] == 'c')
        {
            i += 2;
            std::string first_index;
            while (m_operator[i] != ' ')
                first_index += m_operator[i++]; // to get 'i' of c(i j)

            // To skip ' '
            ++i;

            std::string second_index;
            while (m_operator[i] != ')')
                second_index += m_operator[i++]; // to get 'j' of c(i j)  c(100 200)

            // To skip ')
            ++i;

            // Get (i, j) as integeres
            std::pair<int, int> cur_indexes = std::make_pair(std::stoi(first_index), std::stoi(second_index)); // {100, 200}

            // If there was an operator before the operation, i.e. ... + c(i j)
            if (op_sign != '?')
            {
                res = util::get_fn(op_sign)(res, (*data[cur_indexes.first][cur_indexes.second])(data));
                op_sign = '?';
            }
            else
            {
                // If it's the first operand, e.g. c(10 12)
                res = (*data[cur_indexes.first][cur_indexes.second])(data);
            }
        }
        else
        {
            std::string int_str;
            while (i != m_operator.size() && m_operator[i] != ' ')
            {
                int_str += m_operator[i++];
            }

            // If there was an operator before the operation, i.e. ...+val
            if (op_sign != '?')
            {
                res = util::get_fn(op_sign)(res, std::stoi(int_str));
            }
            else
            {
                // If it's the first operand, e.g. 12
                res = std::stoi(int_str);
            }
        }

        // If there is a new operator
        if (i != m_operator.size())
        {
            // ++ to ignore blank space ' '
            ++i;

            char sign = m_operator[i++];
            if (!util::is_operand(sign))
            {
                throw "The operanton sign is incorrect!";
            }
            op_sign = sign;

            // ++ to ignore blank space ' '
            ++i;
        }
    }

    return res;
}
