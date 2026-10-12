#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32
#include <Windows.h>

void set_cp_stdout()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
}

#endif

int main(int argc, char* argv[])
{
#ifdef _WIN32
	set_cp_stdout();
#endif

	if (argc < 2)
	{
		std::cerr << "Invalid or no arg\n";
		return 1;
	}

	int n = 0;
	bool nums_of_lines = false;
	bool string_count = false;
	int status = 0;
	int no_line = 0;
	int first_flag = 1;

	while (first_flag < argc && argv[first_flag][0] == '-')
	{
		std::string arg = argv[first_flag];


		if (arg == "-n")
		{
			nums_of_lines = true;
		}

		else if (arg == "-s")
		{
			string_count = true;
		}

		else if (arg == "-h")
		{
			std::cout << "mycat, analog of cat in unix systems\n";
			std::cout << "flags: \n";
			std::cout << "-n - toggle numbers of lines\n";
			std::cout << "-s - display the total number of lines\n";
			return 0;
		}

		else
		{
			std::cerr << "Invalid flag " << arg << '\n';
			return 1;
		}

		first_flag++;
	}

	if (first_flag >= argc)
	{
		std::cerr << "No input files\n";
		return 1;
	}


	for (int i = first_flag; i < argc; i++) {
		std::ifstream f(argv[i]);

		if (!f)
		{
			std::cerr << argv[i] << ": open failed\n";
			status = 1;
			continue;
		}

		std::string line;

		while (std::getline(f, line))
		{
			if (nums_of_lines)
			{
				no_line++;
				std::cout << no_line << ' ';
			}

			if (string_count)
			{
				n++;
			}

			std::cout << line << '\n';
		}
	}

	if (string_count)
	{
		std::cout << "strings: " << n << '\n';
	}

	return status;
}

// ну и хуета
