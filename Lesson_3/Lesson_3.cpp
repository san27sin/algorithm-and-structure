#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	
	char reply;
	do
	{
		std::cout << "Введите число для проверки: " << std::endl;
		int choice{ 0 };
		std::cin >> choice;

		if (choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 5)
		{
			if (choice == 0 || choice == 1)
			{
				std::cout << "Исключение" << std::endl;
			}
			else
			{
				std::cout << "Простое число" << std::endl;
			}
			
		}

		else
		{
			if (choice % 2 == 0 || choice % 3 == 0 || choice % 5 == 0)
			{
				std::cout << "Не простое число" << std::endl;
			}

			else
			{
				std::cout << "Простое число" << std::endl;
			}
		}

		std::cout << "Хотите продолжить? Y/N " << std::endl;
		std::cin >> reply;

	} while (reply == 'Y');
	

}