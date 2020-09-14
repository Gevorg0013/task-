#ifndef INT_CELL
#define INT_CELL

#include "./abstract_cell.h"

class int_cell final : public abstract_cell
{
public:
    int_cell(const int val) : m_val{val}
    {
    }

    virtual int operator()(const array_2D<abstract_cell_ptr> &data) const override
    {
        return m_val;
    }

    virtual ~int_cell() = default;

private:
    const int m_val;
};

#endif