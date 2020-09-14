#include "./util.h"

int main()
{
    const array_2D<abstract_cell_ptr> data = util::read("./GA13.txt");

    for (auto& i : data) {
        for (auto& j : i) {
            std::cout<<(*j)(data)<<',';
        }
        std::cout<<std::endl;
    }
    return 0;
}