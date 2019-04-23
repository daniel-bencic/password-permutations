#ifndef TABLE_H
#define TABLE_H

#include <vector>

class Table
{
private:
	std::vector<std::vector<int>> rows;
	
	int char_in_row(const std::vector<int>& row) const;

public:
	Table();
	Table(const std::vector<std::vector<int>>& data);
	Table operator->*(const Table& t) const;
	const std::vector<std::vector<int>>& get_data() const;
	~Table();
};

#endif /* TABLE_H */
