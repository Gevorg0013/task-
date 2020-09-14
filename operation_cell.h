#ifndef OPERATION_CELL
#define OPERATION_CELL

#include <string>

#include "./abstract_cell.h"

class operation_cell final : public abstract_cell
{
public:
    template <class T = std::string>
    operation_cell(T &&val) : m_operator{std::forward<T>(val)}
    {
    }

    virtual int operator()(const array_2D<abstract_cell_ptr> &data) const override;

    virtual ~operation_cell() = default;

private:
    const std::string m_operator;
};

#endif