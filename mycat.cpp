#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32

#include <Windows.h>

void set_cp_out() {
	SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

#endif

void print_help() {
	std::cout << "mycat - analog of cat in unix-like systems\n"
		"Flags:\n"
		"  -n  number the lines\\rows\n"
		"  -s  output the total amount of rows\n"
		"  -h  this help command\n";
}

int main(int argc, char* argv[]) {

#ifdef _WIN32
	set_cp_out();
#endif

	std::string line{};
	bool numbers_of_lines{ false };
	bool total_amount_of_rows{ false };
	int n_l{ 0 };
	int first_file_idx{ argc };
	int status{ 0 };

	if (argc < 2) {
		std::cerr << "No flags or invalid\n";
		return 1;
	}

	for (int i = 1; i < argc; i++) {

		if (argv[i][0] == '-') {
			for (int j = 1; argv[i][j] != '\0'; j++) {
				switch (argv[i][j]) {
				case 'n':
					numbers_of_lines = true;
					break;

				case 's':
					total_amount_of_rows = true;
					break;

				case 'h':
					print_help();
					return 0;
					break;

				default:
					std::cerr << "Invalid flag: " << argv[i] << '\n';
					return 1;
				}
			}
		}

		else {
			first_file_idx = i;
			break;
		}
	}

	if (first_file_idx == argc) {
		std::cerr << "No file provided\n";
		return 1;
	}

	for (int i = first_file_idx; i < argc; i++) {

		std::ifstream f(argv[i]);

		if (!f) {
			std::cerr << "Open failed: " << argv[i] << '\n';
			status = 1;
			continue;
		}

		while (std::getline(f, line)) {
			n_l++;

			if (numbers_of_lines) {
				std::cout << n_l << ' ';
			}

			std::cout << line << '\n';
		}

	}

	if (total_amount_of_rows) {
		std::cout << "rows: " << n_l << '\n';
	}

	return status;
}
