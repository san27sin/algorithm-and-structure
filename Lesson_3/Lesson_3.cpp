#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");

	char reply;
	do
	{
		std::cout << "Введите число для проверки: " << std::endl;
		int i;
		std::cin >> i;

		if (i == 1)
		{
			std::cout << "Именно чтобы обеспечить единственность в этой теореме, единица не считается простым числом!" << std::endl;
		}

		if (i % 2 == 0)
		{

			if (i == 2)
			{
				std::cout << "Простое число!" << std::endl;
			}
			else
			{
				std::cout << "Не простое!" << std::endl;
			}

		}


		else if (i == 3)
		{
			std::cout << "Простое число!" << std::endl;
		}


		else
		{

			if (i % 3 == 0)
			{
				std::cout << "Не простое число!" << std::endl;
			}

			else
			{
				std::cout << "Простое число!" << std::endl;
			}
		}
		std::cout << "Хотите продолжить? Y/N " << std::endl;
		std::cin >> reply;

	} while (reply == 'Y');

}