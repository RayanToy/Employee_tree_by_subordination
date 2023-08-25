#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    int hiearchy;
    int count = 0;
    unsigned rows = 2;
    unsigned columns = 0;    
    setlocale(LC_ALL, "ru");
    string path = "file.txt";
    // Открываю файл используя класс fstream 
    ifstream fin;
    fin.open(path);
    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        // Подсчитываю количство строк в файле
        cout << "Файл открыт!" << endl;
        string str;      
        while(!fin.eof())
        {
            str = "";
            getline(fin, str);
            columns++;
        }
        fin.close();
        /* Создаю динамические массивы для сохранения айди, иерархий и фамилий 
        используя заранее подсчитанное количество строк */
        int** id { new int* [rows] {} };  
        for (unsigned i{}; i < rows; i++)
        {
            id[i] = new int[columns] {};
        }
        string** surname{ new string* [10] {} };
        for (unsigned i{}; i < 10; i++)
        {
            surname[i] = new string[columns] {};
        }
        int j = 0;
        int k = 0;
        fin.open(path);
        while (!fin.eof())
        {
            str = "";
            getline(fin, str);
            // Записываю в динамический массив айди и соотвествующую иерархию подчинения 
            for (int i = 0; i < 4; i++)
            {
                if (str[i] != '|')
                {
                    id[k][j] = str[i]-'0';
                    k++;
                }
            }
            k = 0;
            // Записываю фамилию рабоотника
            for (int i = 4; i < str.length(); i++)
            {
                surname[i-4][j] = str[i];
            }
            j++;   
        }
        for(int j = 0; j < columns; j++)
        {
            /* Определяю для каждой итерации иерархию работника и
            двигаюсь по иерархии подчинения до тех пор пока не дойдем до начальника.
            Двигаясь по иерархии пдсчитаем количество уровней иеарархии для работника
            */
            hiearchy = id[1][j];
            while(hiearchy != 0)
            {
                for (int t = 0; t < columns; t++)
                {
                    if (id[0][t] == hiearchy)
                    {
                        hiearchy = id[1][t];
                        count++;
                        break;
                    }
                }
            }
            /*Подсчитав количество уровней для рабоотника выведем соотвествуюшее количество уровней и его фамилию
           */
            for (int i = 0; i < count; i++)
            {
                cout << "---";
            }
            for (int i = 0; i < 10; i++)
            {
                cout << surname[i][j];
            }
            cout << endl;
            count = 0;
        } 
        //Подчищаем динамические массивы //
        for (unsigned i{}; i < rows; i++)
        {
            delete[] id[i];
        }
        delete[] id;
        for (unsigned i{}; i < 10; i++)
        {
            delete[] surname[i];
        }
        delete[] surname;
    }
    fin.close();
}
