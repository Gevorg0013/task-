#ifndef ABSTRACT_CELL
#define ABSTRACT_CELL

#include <vector>

#include <memory>

template <class T>
using array_2D = std::vector<std::vector<T>>;

// defination of the class
class abstract_cell;

using abstract_cell_ptr = std::unique_ptr<abstract_cell>;

class abstract_cell
{
public:
    virtual int operator()(const array_2D<abstract_cell_ptr> &data) const = 0;

    // to indcate that it's allowed(true) or not allowed(false) to call () operator for this class objects
    // default its allowed for all class types objects
    virtual operator bool() const noexcept
    {
        return true;
    }

    virtual ~abstract_cell() = default;
};

#endif