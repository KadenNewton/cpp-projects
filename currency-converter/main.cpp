#include <unordered_map> // use for assigning value to currencies
#include <string>
#include <iostream>
#include <Windows.h>
#include <iomanip>

std::unordered_map<std::string, float> values = {
    {"EUR", 0.94889}, {"GBP", 0.81199}, {"JPY", 130.072}}; // Idk make a list of different currencies and shit, whatever.

int main()
{
  std::string c;
  float c2;
  std::cout << "Enter \"list\" for list of currencies" << std::endl;
  std::cout << "Enter Currency: " << std::endl;
  std::cout << "  >> ";
  std::cin >> c;
  if (c == "list") // when user inputs "list" print list of currencies
  {
    system("cls");
    std::cout << "EUR, GBP, JPY\n";
    system("PAUSE");
    system("cls");
    main();
  }
  system("cls");
  std::cout << "Enter Amount (in USD): " << std::endl;
  std::cout << "  >> ";
  std::cin >> c2;

  std::cout << "USD Amount: " << c2 << "\n"
            << c << " Amount: " << std::fixed << std::setprecision(2) << values[c] * c2 << "\n";
  system("PAUSE");
  system("cls");
  main();

  return 0;
}