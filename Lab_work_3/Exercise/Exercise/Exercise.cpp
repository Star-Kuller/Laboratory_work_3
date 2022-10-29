#include <iostream>     
using namespace std;


void N_1()
{
    struct employee
    {
        int Number;
        float Salary;
    };

    const int amount = 3;
    employee employee_arr[amount];

    cout << "------------------------------------------------------\n";
    for (int i = 0; i < amount; i++) {
        cout << "\nВведите номер сотрудника: "; cin >> employee_arr[i].Number;
        cout << "Введите размер зарплаты сотрудника: "; cin >> employee_arr[i].Salary;
    }
    cout << "------------------------------------------------------\n";
    for (int i = 0; i < amount; i++) {
        cout << "Сотрудник под номером " << employee_arr[i].Number;
        cout << " зарабатывает - " << employee_arr[i].Salary << " рублей\n";
    }
    cout << "------------------------------------------------------\n";
}

void N_2()
{
    enum etype {laborer, secretary, manager, accountant, executive, researcher};
    char user_input;
    int temp;
    etype output_etype;
    cout << "------------------------------------------------------\n";
    cout << "\n{laborer, secretary, manager, accountant, executive, researcher}\n";
    cout << "Введите первую букву должности: ";cin >> user_input;
    switch (user_input)
    {
    case 'l':
        temp = 0;
        break;
    case 's':
        temp = 1;
        break;
    case 'm':
        temp = 2;
        break;
    case 'a':
        temp = 3;
        break;
    case 'e':
        temp = 4;
        break;
    case 'r':
        temp = 5;
        break;
    default:
        cout << "\n           Ошибка!\nТакой должности не существует!\n";
        cout << "------------------------------------------------------\n";
        return;
    }
    output_etype = etype(temp);
    cout << "\nПолное название должности: ";
    switch (output_etype)
    {
    case etype::laborer:
        cout << "laborer";
        break;
    case etype::secretary:
        cout << "secretary";
        break;
    case etype::manager:
        cout << "manager";
        break;
    case etype::accountant:
        cout << "accountant";
        break;
    case etype::executive:
        cout << "executive";
        break;
    case etype::researcher:
        cout << "researcher";
        break;
    }
    cout << "\n\n------------------------------------------------------\n";
}

void N_3()
{
    //int a, b, c, d, answ_up, answ_down, nod;
    int nod = 1;
    struct fraction
    {
        int up;
        int down;
    };
    char dummychar;
    fraction fraction_A, fraction_B, fraction_ansver;
    cout << "------------------------------------------------------\n";
    cout << "\nВведите первую дробь: "; cin >> fraction_A.up >> dummychar >> fraction_A.down;
    cout << "Введите вторую дробь: "; cin >> fraction_B.up >> dummychar >> fraction_B.down;
    // сложение
    fraction_ansver.up = (fraction_A.up * fraction_B.down + fraction_A.down * fraction_B.up);
    fraction_ansver.down = (fraction_A.down * fraction_B.down);
    // сокращение
    if (fraction_ansver.up < fraction_ansver.down) {
        for (int i = 1; i < fraction_ansver.down; i++) {
            if ((fraction_ansver.up % i == 0) & (fraction_ansver.down % i == 0)) { // нахождение НОД, если знаменатель больше числителя
                nod = i;
            }
        }
    }
    else {
        for (int i = 1; i < fraction_ansver.up; i++) {
            if ((fraction_ansver.up % i == 0) & (fraction_ansver.down % i == 0)) { // нахождение НОД, если числитель больше знаменателя
                nod = i;
            }
        }
    }
    if (fraction_ansver.up % fraction_ansver.down == 0) { // проверка является ли число целым
        cout << "Сумма равна: " << fraction_ansver.up / nod; // вывод целого числа, если целое
    }
    else {
        cout << "Сумма равна: " << fraction_ansver.up / nod << "/" << fraction_ansver.down / nod; // вывод дробного числа, если дробное
    }
    cout << "\n\n------------------------------------------------------\n";
}

void N_4()
{
    struct time
    {
        int hours;
        int minutes;
        int seconds;
    };
    time clock;
    char dummychar;
    cout << "------------------------------------------------------\n";
    cout << "Введите время в формате (Часы:Минуты:Секунды): "; cin >> clock.hours >> dummychar >> clock.minutes >> dummychar >> clock.seconds;
    long totalsecs = clock.hours * 3600 + clock.minutes * 60 + clock.seconds;
    cout << "Всего секунд: " << totalsecs;
    cout << "\n\n------------------------------------------------------\n";
}

void N_5()
{
    struct time
    {
        int days;
        int hours;
        int minutes;
        int seconds;
    };
    time clock_A, clock_B, clock_ansver;
    char dummychar;
    cout << "------------------------------------------------------\n";
    cout << "Введите первое время в формате (Часы:Минуты:Секунды): "; cin >> clock_A.hours >> dummychar >> clock_A.minutes >> dummychar >> clock_A.seconds;
    cout << "Введите второе время в формате (Часы:Минуты:Секунды): "; cin >> clock_B.hours >> dummychar >> clock_B.minutes >> dummychar >> clock_B.seconds;
    long totalsecs = (clock_A.hours * 3600 + clock_A.minutes * 60 + clock_A.seconds) + (clock_B.hours * 3600 + clock_B.minutes * 60 + clock_B.seconds);
    // << "Всего секунд: " << totalsecs;
    clock_ansver.days = totalsecs / 86400;
    totalsecs = totalsecs - clock_ansver.days * 86400;
    clock_ansver.hours = totalsecs / 3600;
    totalsecs = totalsecs - clock_ansver.hours * 3600;
    clock_ansver.minutes = totalsecs / 60;
    clock_ansver.seconds = totalsecs- clock_ansver.minutes * 60;
    //cout << "\nСумма времени: " << clock_ansver.hours << ":" << clock_ansver.minutes << ":" << clock_ansver.seconds;
    printf("\nСумма времени: %d:%02d:%02d:%02d", clock_ansver.days, clock_ansver.hours, clock_ansver.minutes, clock_ansver.seconds);
    cout << "\n\n------------------------------------------------------\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int selected;
    while (true) {
        cout << "\n0 - Завершить работу\n1,2,3,4,5 - доступные задания\n";
        cout << "Выберите задание или 0: "; cin >> selected;
        switch (selected)
        {
        case 0:
            return 0;
            break;
        case 1:
            N_1();
            break;
        case 2:
            N_2();
            break;
        case 3:
            N_3();
            break;
        case 4:
            N_4();
            break;
        case 5:
            N_5();
            break;
        default:
            break;
        }
    }
    return 0;
}