#include <iostream>
#include <fstream>
#include <string.h>
#include <Windows.h>

int main();

void change_color(WORD color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void login()
{
	int count = 0;
	std::string userId, password, id, pass;
	system("cls");
	std::cout << "Username:" << std::endl;
	std::cout << "  >> ";
	std::cin >> userId;
	system("cls");
	std::cout << "Password:" << std::endl;
	std::cout << "  >> ";

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	std::cin >> password;
	SetConsoleMode(hStdin, mode);

	std::ifstream input("records.txt");

	while (input >> id >> pass)
	{
		if (id == userId && pass == password)
		{
			count = 1;
			system("cls");
		}
	}
	input.close();

	if (count == 1)
	{
		std::cout << "Welcome ";
		change_color(11);
		std::cout << userId << std::endl;
		change_color(10);
		std::cout << "\nLogin Successful!";
		Sleep(5000);
		main();
	}
	else
	{
		change_color(4);
		std::cout << "\n[ERROR] ";
		change_color(15);
		std::cout << "LOGIN ERROR";
		Sleep(5000);
		main();
	}
}

void registration()
{
	std::string ruserId, rpassword, rid, rpass;
	system("cls");
	std::cout << "Username:" << std::endl;
	std::cout << "  >> ";
	std::cin >> ruserId;
	system("cls");
	std::cout << "Password:" << std::endl;
	std::cout << "  >> ";

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	std::cin >> rpassword;
	SetConsoleMode(hStdin, mode);

	std::ofstream f1("records.txt", std::ios::app);
	f1 << ruserId << ' ' << rpassword << std::endl;
	system("cls");

	change_color(10);
	std::cout << "Registration Successful!";
	Sleep(3000);
	main();

}

void forgot()
{
	int option;
	system("cls");
	std::cout << "Forgot password? No worries\n" << std::endl;
	std::cout << " [1] ";
	change_color(14);
	std::cout << "Search by Username" << std::endl;
	change_color(15);
	std::cout << " [2] ";
	change_color(14);
	std::cout << "Return to Menu\n";
	change_color(15);

	std::cout << "  >> ";
	std::cin >> option;

	switch (option)
	{
	case 1:
	{
		system("cls");
		int count = 0;
		std::string suserId, sId, spass;
		std::cout << "Username: " << std::endl;
		std::cout << "  >> ";
		std::cin >> suserId;

		std::ifstream f2("records.txt");
		while (f2 >> sId >> spass)
		{
			if (sId == suserId)
			{
				count = 1;
				break;
			}
		}
		f2.close();

		if (count == 1)
		{
			system("cls");
			change_color(10);
			std::cout << "Account found!" << std::endl;
			change_color(15);
			std::cout << "Password: ";
			change_color(11);
			std::cout << spass << std::endl;
			change_color(15);
			do
			{
				std::cout << '\n' << "Press ENTER to continue...";
			} while (std::cin.get() != '\n');

			std::cin.get();

			main();
		}
		else {
			system("cls");
			change_color(4);
			std::cout << "[ERROR] ";
			change_color(15);
			std::cout << "Account not found";
			Sleep(3000);
			main();
		}
	}
	case 2:
		main();

	default:
	{
		change_color(4);
		std::cout << "[ERROR] ";
		change_color(15);
		std::cout << "Select from choices above!" << std::endl;
		Sleep(2000);
		main();
	}
	}

}

int main()
{
	system("cls");

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	SetConsoleTitleA("Registration System");
	MoveWindow(console, r.left, r.top, 380, 300, TRUE);


	int c;
	change_color(15);
	std::cout << "_________________________________________\n\n";
	std::cout << "    Registration System by ";
	change_color(11);
	std::cout << "Kaden#6112\n";
	change_color(15);
	std::cout << "_________________________________________\n\n";
	std::cout << " [1] ";
	change_color(14);
	std::cout << "LOGIN             " << std::endl;
	change_color(15);
	std::cout << " [2] ";
	change_color(14);
	std::cout << "REGISTER          " << std::endl;
	change_color(15);
	std::cout << " [3] ";
	change_color(14);
	std::cout << "FORGOT PASSWORD   " << std::endl;
	change_color(15);
	std::cout << " [4] ";
	change_color(14);
	std::cout << "EXIT              " << std::endl;
	change_color(15);
	std::cout << "\n  >> ";
	std::cin >> c;

	switch (c)
	{
	case 1:
		login();
	case 2:
		registration();
	case 3:
		forgot();
	case 4:
		break;
	default:
		change_color(4);
		std::cout << "[ERROR] ";
		change_color(15);
		std::cout << "Select from choices above!" << std::endl;
		Sleep(2000);
		main();
	}

	return 0;
}