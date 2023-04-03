// MoreString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

std::string space_str(std::string str);//Протатип функции
bool is_spam(std::string msg);

int main()
{
    setlocale(LC_ALL, "rus");

    //Задача 1. Пробелы в словах
    std::string str1;
    std::getline(std::cin, str1);
    std::cout << space_str(str1) << "\n\n";

    //Задача 2. Проверка спама 
    std::cout << "Введите строку: ";
    std::string str2;
    std::getline(std::cin, str2);
    if (is_spam(str2))
        std::cout << "Обнаружен спам\n";
    else
        std::cout << "Спам не обнаружен\n";

    //Задача 3. Разбивка URL
std::string URL = "http://yandex.ru/super_user/photos";
std::cout << URL << std::endl;
int domen_index = URL.find("://") + 3;
int path_index = URL.find('/', domen_index) + 1;

std::string path = URL.substr(path_index);
std::string domen = URL.substr(domen_index, path_index - 1 - domen_index);
std::string protocol = URL.substr(0, domen_index - 3);

std::cout << "Протокол: " << protocol << std::endl;
std::cout << "Домен: " << domen << std::endl;
std::cout << "Путь: " << path << std::endl;
}

std::string space_str(std::string str) {
    std::string result;
    for (int i = 0; i < str.length(); i++) {
    result += str[i];
    if(i != str.length() - 1)
    result += " ";
    }        
    return result;
}

bool is_spam(std::string msg) {
    for (int i = 0; i < msg.length(); i++)
        msg[i] = std::tolower(msg[i]);

    const int spams_number = 3;
    std::string spams[spams_number]{//Массив строк
        "100% free",
        "sales increase",
        "only today"
    };

    for (int i = 0; i < spams_number; i++)
        if (msg.find(spams[i]) < msg.length())
            return true;
    return false;
}