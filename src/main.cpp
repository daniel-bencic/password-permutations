#include <iostream>
#include <fstream>
#include <string>
#include "../include/table.hpp"

int write_tables_to_file(std::vector<Table>& tables, std::string filename);

int main(int argc, char *argv[])
{
	std::vector<std::vector<int>> digits_data = { 
		{ 0 }, { 1 }, { 2 }, { 3 }, { 4 },
		{ 5 }, { 6 }, { 7 }, { 8 }, { 9 }
	};

	std::vector<std::vector<int>> chars_data = {
		{ 97 }, { 98 },	{ 99 },	{ 100 }, { 101 }, { 102 }, { 103 }, { 104 },
		{ 105 }, { 106 }, { 107 }, { 108 }, { 109 }, { 110 }, { 111 }, { 112 },
		{ 113 }, { 114 }, { 115 }, { 116 }, { 117 }, { 118 }, { 119 }, { 120 },
		{ 121 }, { 122 }
	};

	Table digits{ digits_data };
	Table chars{ chars_data };
	
	std::vector<Table> tables;

	std::cout << "Calculating permutations ...";

	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 6; ++j) {
			Table t;
			for (int k = 0; k < 6; ++k) {
				if (k == i || k == j) {
					t = t ->* chars;
				} else {
					t = t ->* digits;
				}
			}
			tables.push_back(t);
		}
	}

	std::cout << " done" << std::endl;

	std::string filename = "permutations.txt";

	std::cout << "Writing permutations to file: " << filename << " ...";
	int permu_cnt = write_tables_to_file(tables, filename);
	std::cout << " done" << std::endl;
	std::cout << "[" <<  permu_cnt << "] permutations written to file." << std::endl;

	return 0;
}

int write_tables_to_file(std::vector<Table>& tables, std::string filename)
{
	int cnt = 0;
	
	std::ofstream f{};
	f.open(filename);

	for (auto t : tables) {
		for (int i = 0; i < t.get_data().size(); ++i) {
			for (int j = 0; j < t.get_data()[i].size(); ++j) {
				int num = t.get_data()[i][j];
				if (num > 9) {
					f << (char)num;
				} else {
					f << num;
				}
			}

			f << std::endl;
			cnt++;
		}
	}
	
	f.close();

	return cnt;
}
