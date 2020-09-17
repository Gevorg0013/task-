Program to prepare data from a file like excel and by calculating values of the cells, provide the final result of the calculations.

File format requirements:
1. Cells in the file should be comma-seperated, e.g. 12,13,c(0 1) + 1
2. each opreation sign should be surrounded with spaces from left and right operants, e.g. c(0 0) + 12 - 2 * c(0 1)
3. it's not allowed to have ciclic dependency between cells. E.g. c(0 0) = c(1 1) + 10, c(1 1) = c(0, 1) + 2,  c(0 1) = c(0 0)
    In the above example between c(0 0) and c(1 1) cells there is an indirect dependency
    Note: based on the current implementation it would lead to stack owerflow. The imeplementation will be improved to provide just an error message instead of stack owerflow
4. Each operation cell must start with a reference to other cell: c(0 1) + 12 + c(1 1) allowed, 10 + c(0 0) - not allowed

Future possible improvements:
1. Eliminate multi calculation of the same cell, i.e. based on the current implementation, if there are multiple cells having a reference to the same operational cell, the operational cell's value will be calculated as many time as it's occurred in the cells
