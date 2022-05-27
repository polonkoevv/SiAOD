#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <clocale>
#include <vector>
#include <windows.h>
using namespace std;


/*
 Касса кинотеатра. Структура записи о проданном месте: название фильма,
 дата, время, номер ряда, номер места, номер зала (1-малый, 2-большой).
 Справочная информация о количестве мест в зале кинотеатра: массив с указанием количества мест всего в каждом зале.
Операции
1)	Заполнение записи по одному проданному билету с клавиатуры.
2)	Вставить запись в таблицу, упорядочивая по номеру зала (сортировку не использовать). Новая запись вставляется в начало подсписка по залу.
3)	Удалить записи по заданной дате.
4)	Определить количество свободных мест на заданный фильм в указанную дату и время. */

//Шаблон структуры
struct Tickets //Создание класса записи
{
    string filmName, filmDate, filmTime, rowNum, placeNum, hallNum;
};

//Заолпнение структуры
Tickets addTicket() //Конструктор записи
{
    Tickets ticket;
    cout << "Введите название фильма без пробелов: " << endl;
    cin >> ticket.filmName;
    cout << "Введите дату показа фильма в формате дд.мм: " << endl;
    cin >> ticket.filmDate;
    cout << "Введите время показа фильма в формате чч:мм: " << endl;
    cin >> ticket.filmTime;
    cout << "Введите номер зала (1 - малый, 2 - большой): " << endl;
    cin >> ticket.hallNum;
    cout << "Введите номер ряда в зале: " << endl;
    cin >> ticket.rowNum;
    cout << "Введите номер места в ряду" << endl;
    cin >> ticket.placeNum;
    cout << endl;
    return ticket;
}

//Добавление экземпляра в массив
void ticketToArray(Tickets ticket, vector<Tickets>& array)
{
    if (ticket.hallNum == "1") array.insert(array.begin(), ticket);
    else { array.push_back(ticket); }
}

//Сортировка
void sortTickets(vector<Tickets>& array)
{
    vector<Tickets> temp;
    for (int i = 0; i < array.size(); ++i) { if (array[i].hallNum == "1")temp.push_back(array[i]); }
    for (int i = array.size() - 1; i >= 0; i--) { if (array[i].hallNum == "2")temp.push_back(array[i]); }
    array = temp;
}

//Удаление по дате
void delByDate(string xDate, vector<Tickets>& array)
{
    vector <Tickets> temp;
    for (int perTick = 0; perTick < array.size(); perTick++)
    {
        if (array[perTick].filmDate != xDate) {
            temp.push_back(array[perTick]);
        }
    }
    array = temp;
}

//Кол-во мест
void placesByTime(string xDate, string xTime, string xName, vector<Tickets>& array)
{
    vector <Tickets>::iterator perTick;
    int counterBig = 150, counterSmall = 100;
    for (perTick = array.begin(); perTick != array.end(); perTick++)
    {
        if ((*perTick).filmDate == xDate && (*perTick).filmTime == xTime && (*perTick).filmName == xName)
        {
            if ((*perTick).hallNum == "1") { counterSmall--; }
            else { counterBig--; }
        }
    }
    cout << "В малом зале на " << xDate << " " << xTime << " осталось " << counterSmall << " мест." << endl;
    cout << "В большом зале на " << xDate << " " << xTime << " осталось " << counterBig << " мест." << endl;
}

//Вывод информации
void showInfo(vector <Tickets> array)
{
    cout << endl;
    cout << "| Name of film\t\t\t| Date\t| Time\t| Row Number\t| Place Number\t| Kind of hall\t|" << endl;
    cout << endl;


    for (int i = 0; i < array.size(); i++)
    {
        cout << "| " << (array[i]).filmName << "\t\t\t\t| " << (array[i]).filmDate << "\t| " << (array[i]).filmTime << "\t| " << (array[i]).rowNum << "\t\t| " << (array[i]).placeNum;
        if ((array[i]).hallNum == "1") { cout << "\t\t| Small \t|" << endl; }
        else { cout << "\t\t| Big \t\t|" << endl; }
        cout << endl;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);



    int quant;
    cout << "Введите нужное кол-во записей" << endl;
    cin >> quant;


    vector <Tickets> array;
    for (int i = 0; i < quant; ++i) {
        Tickets ticket;
        ticket = addTicket();
        ticketToArray(ticket, array);
    }
    sortTickets(array);
    cout << array.size() << endl;
    showInfo(array);

    string xDate, xTime, xName;
    cout << "Введите дату, записи на которую хотите удалить в формате дд.мм" << endl;
    cin >> xDate;

    delByDate(xDate, array);
    showInfo(array);


    cout << "Введите название фильма, кол-во свободных мест на который хотите узнать" << endl;
    cin >> xName;
    cout << "Введите дату, кол-во свободных мест на которую хотите узнать" << endl;
    cin >> xDate;
    cout << "Введите дату, кол-во свободных мест на которую хотите узнать" << endl;
    cin >> xTime;

    placesByTime(xDate, xTime, xName, array);

    return 0;
}
