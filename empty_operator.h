#pragma once
#ifndef EMPTY_OP
#define EMPTY_OP

#include "./abstract_cell.h"

class empty_operator final : public abstract_cell
{
public:
	empty_operator() = default;

	virtual int operator()(const array_2D<abstract_cell_ptr> &data) const override
	{
		throw "Cell's data caluclation is not allowed for empty cell!";
	}

	// to indcate that it's not allowed to call () operator for this class objects
	virtual operator bool() const noexcept
	{
		return false;
	}

	virtual ~empty_operator() = default;
};

#endif