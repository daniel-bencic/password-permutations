#include <iterator>
#include "../include/table.hpp"

int Table::char_in_row(const std::vector<int>& row) const
{
	for (int i = 0; i < row.size(); ++i) {
		if (row[i] > 9) {
			return row[i];
		}
	}

	return -1;
}

Table::Table() : rows(std::vector<std::vector<int>>()) {}

Table::Table(const std::vector<std::vector<int>>& data)
{
	this->rows = data;
}

Table Table::operator->*(const Table& t) const
{
	if (this->rows.size() == 0) {
		return Table{ t.rows };
	}
	if (t.rows.size() == 0) {
		return Table{ this->rows };
	}
	std::vector<std::vector<int>> t_cross;
	for (int i = 0; i < this->rows.size(); ++i) {
		for (int j = 0; j < t.rows.size(); ++j) {
			int char_a = this->char_in_row(this->rows[i]);
			int char_b = this->char_in_row(t.rows[j]);
			if (char_a != -1 && char_b != -1 && char_a == char_b) continue;
				
			std::vector<int> row_cross;
			row_cross.reserve(this->rows[i].size() + t.rows.size());
			row_cross.insert(std::end(row_cross), std::begin(this->rows[i]), std::end(this->rows[i]));
			row_cross.insert(std::end(row_cross), std::begin(t.rows[j]), std::end(t.rows[j]));
			t_cross.push_back(row_cross);			
		}
	}

	return Table{ t_cross };
}

const std::vector<std::vector<int>>& Table::get_data() const
{
	return this->rows;
}

Table::~Table() {}
