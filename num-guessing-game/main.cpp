#include <iostream>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    int max_attempts = 7;

    int secretNum = rand() % 100 + 1;
    int userInput = 0;
    std::string name;
    std::cout << "What's your name?" << std::endl;
    std::cout << "  >> ";
    std::cin >> name;
    system("cls");

    std::cout << "Hello, " << name << "!"
              << "\nGuess the secret number" << std::endl;
    std::cout << "  >> ";

    int att = 1;

    do
    {
        if (!(std::cin >> userInput))
        {
            std::cout << "You must enter a number" << std::endl;
        }
        else
        {
            if (userInput > secretNum)
                std::cout << "You guessed too high!\n"
                          << max_attempts - att << " attempts remaining!" << std::endl;
            if (userInput < secretNum)
                std::cout << "You guessed too low!\n"
                          << max_attempts - att << " attempts remaining!" << std::endl;

            att++;
        }
    } while (userInput != secretNum && att < max_attempts);

    if (att >= max_attempts)
    {
        std::cout << "You ran out of attempts!" << std::endl
                  << "The number was: " << secretNum;
        system("PAUSE");
    }
    else
        std::cout << "You guessed correctly! The Secret Number was " << secretNum << std::endl;
    system("PAUSE");

    return 0;
}