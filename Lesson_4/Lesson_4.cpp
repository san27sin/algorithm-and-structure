#include <iostream>
using namespace std;


int convert(int a)
{
    if (a < 2)
    {
        cout << "\t"<< a;
    }
   
    else
    {
        convert(a / 2);
        cout << "\t" << a % 2;
    }
    
    return 0;
}

int power_1 (int a, int b)
{
    if (b==1)
    {
        return a;
    }
    
    else
    {
        return (a * power_1 (a, b - 1));
    }
}


int power_2(int a, int b)
{
   
    if (b == 0)
    {
        return 1;
    }
            
    if (b % 2 == 1)
    {
        return power_2(a, b - 1) * a;
    }
            
    else
    {
        int temp = power_2(a, b / 2);
        return temp * temp;
    }
     
}

int KingRoutes(int x, int y)
{
    if (x == 0 && y == 0)
    {
        return 0;
    }

    else if (x == 0 || y == 0)
    {
        return 1;
    }

    else
    {
        return KingRoutes(x, y - 1) + KingRoutes(x - 1, y);
    }

    return 0;
}



int main()
{
    setlocale(LC_ALL, "rus");
   
    
    //Реализовать функцию перевода чисел из десятичной системы в двоичную, 
    //используя рекурсию.
    cout << "Задание 1\nВведите число для конвертации его из десятичной системы в двоичную" << endl;
    int a{ 0 };
    cin >> a;
    convert(a);
    cout << endl;
  
    
   
    cout << "Задание 2.1.\nРеализовать функцию возведения числа[a] в степень[b]." << endl;
    cout << "\nВыберет число:" << endl;
    int number;
    cin >> number;

    cout << "Выберет степень в которую хотите возвести число: " << endl;
    int degree;
    cin >> degree;
    cout << "Результат возведения:\n" << power_1(number, degree);

   
    cout << "\n\nЗадание 2.2.\nРеализовать функцию возведения числа[a] в степень[b]." << endl;
    cout << "\nВыберет число:" << endl;
    cin >> number;

    cout << "Выберет степень в которую хотите возвести число: " << endl;
    cin >> degree;
    cout << "Результат возведения:\n" << power_2(number, degree);
   

    /*
    Реализовать нахождение количества маршрутов шахматного короля с препятствиями 
    (где единица - это наличие препятствия, а ноль - свободная для хода клетка)
    (король начинает путь с клетки 0,0)
    */
     


    //S(m, n) = S(m-1, n) + S(m, n-1);
    //S(m, n) = 1, если одна из координат равна нулю
    //S(m, n) = 0, если m и n это стартовые координаты
    
    //из видео
   
    cout << "\n\n";
    const int sizeX = 8;
    const int sizeY = 8;
  
    for (int y = 0; y < sizeY; ++y)
    {
        for (int x = 0; x < sizeX; ++x)
        {
            cout << KingRoutes(x, y)<<"\t";
   
        }

        cout << endl;
    }
   
    // мое решение с препядствиями, не могу понять как должны складываться количество путей в массиве?
    ;
    int array[sizeX][sizeY] =
    {
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},


    };

    cout << "Choose the space for a king?" << endl;
    int X, Y;
    cin >> X;
    cin >> Y;
    array[X][Y]={ 0 };
   

    int x, y;

    
    

    
    
    for (int y = 0; y < sizeY; ++y)
    {
        for (int x = 0; x < sizeX; ++x)
        {
            if (Y == y || X == x)
            {
       
                array[x][y] = 1;
            }

            if (Y == y && X == x)
            {
                array[x][y] = 0;
            }
        
        }

        cout << endl;
    }


    for (int y = 0; y < sizeY; ++y)
    {
        for (int x = 0; x < sizeX; ++x)
        {
            cout << array[x][y] << "\t";

        }

        cout << endl;
    }

    cout << "============================================" << endl;

    /*
    for (int y = 0; y < sizeY; ++y)
    {
        for (int x = 0; x < sizeX; ++x)
        {
            //не понимаю почему по индексам массива нельзя сложить и получить результат 
            //array[x][y] = array[x][y - 1] + array[x - 1][y]; - вот мое решение, но компилятор не разрешает его сделать
        }

        cout << endl;
    }

    */

    //Не понимаю как вынести отдельно в функцию печати массива потому что выдает ошибку при одном указатели и при двух указателей.

    for (int y = 0; y < sizeY; ++y)
    {
        for (int x = 0; x < sizeX; ++x)
        {
            cout << array[x][y] << "\t";

        }

        cout << endl;
    }

 
    return 0;
}

