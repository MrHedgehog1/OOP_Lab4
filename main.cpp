#include "iostream"
#include "vector"
#include "Wagon.h"

std::string enter_manufacturer()
{
    std::string name_of;
    std::cout << "Введите имя производителя:" << std::endl;
    getline(std::cin, name_of);
    return name_of;
}

int enter_year()
{
    int year;
    std::cout << "Введите год производства вагона:" << std::endl;
    std::cin >> year;
    std::cin.ignore();
    return year;
}

int enter_emptyWeight()
{
    int empWeight;
    std::cout << "Введите вес пустого вагона:" << std::endl;
    std::cin >> empWeight;
    std::cin.ignore();
    return empWeight;
}

int enter_cargoWeight(){
    int cargWeight;
    std::cout << "Введите вес груза вагона:" << std::endl;
    std::cin >> cargWeight;
    std::cin.ignore();
    return cargWeight;
}

std::string enter_tankIsLoaded()
{
    std::string name_of;
    std::cout << "Введите название груза:" << std::endl;
    getline(std::cin, name_of);
    return name_of;
}
int enter_numberOfCars(){
    int numCars;
    std::cout << "Введите колличество машин в вагоне:" << std::endl;
    std::cin >> numCars;
    std::cin.ignore();
    return numCars;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<RailwayCarriage> railwayCarriage_entry;
    std::vector<WagonForCars> wagonForCars_entry;
    std::vector<TankWagon> TankWagon_entry;

    int emptyWeight, i, numberOfCars, vehicleWeight, cargoWeight, registry_index, year = 0;

    std::string manufacturer;
    std::string tankIsLoaded;

    wagonForCars_entry.push_back(WagonForCars("test",2021,5,10,24));
    wagonForCars_entry.push_back(WagonForCars("test1",2019,4,9,23));
    TankWagon_entry.push_back(TankWagon("test0", 2020, 10, "oil", 22));
    bool exit = false;
    char command1, command2, command3;
    while (!exit)
    {
        std::cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
        std::cout << "Что вы хотите сделать?:\n";
        std::cout << "\t1. Создать запись о вагоне.\n";
        std::cout << "\t2. Внести или изменить данные вагона.\n";
        std::cout << "\t3. Добавить машины вагон для перевозки машин.\n";
        std::cout << "\t4. Добавить добавить груз в цистерну.\n";
        std::cout << "\t5. Рассчитать вес вагона.\n";
        std::cout << "\t6. Рассчитать колличество лет эксплуатации.\n";
        std::cout << "\t7. Посмотреть данные о вагонах.\n";
        std::cout << "\t8. Выход из программы.\n";
        std::cout << "Команда: ";
        std::cin >> command1;
        std::cin.ignore();
        switch (command1)
        {
            case '1':
                std::cout << "Вы хотите добавить:\n";
                std::cout << "\t1. Пустой вагон.\n";
                std::cout << "\t2. Вагон для перевозки машин.\n";
                std::cout << "\t3. Цистерну.\n";
                std::cin >> command2;
                std::cin.ignore();
                if (command2 == '1')
                {
                    std::cout << "Вы хотите добавить:\n";
                    std::cout << "\t1. Только имя производителя.\n";
                    std::cout << "\t2. Полные данные вагона.\n";
                    std::cin >> command3;
                    std::cin.ignore();
                    if (command3 == '1')
                    {
                        manufacturer = enter_manufacturer();
                        railwayCarriage_entry.push_back(RailwayCarriage(manufacturer));
                    }
                    else if (command3 == '2')
                    {
                        manufacturer = enter_manufacturer();
                        year = enter_year();
                        emptyWeight = enter_emptyWeight();
                        railwayCarriage_entry.push_back(RailwayCarriage(manufacturer, year, emptyWeight));
                    }
                    else
                    {
                        std::cout << "Вы ввели неверную командую" << std::endl;
                    }
                }
                else if (command2 == '2')
                {
                    manufacturer = enter_manufacturer();
                    year = enter_year();
                    emptyWeight = enter_emptyWeight();
                    numberOfCars = enter_numberOfCars();
                    vehicleWeight = enter_cargoWeight();
                    wagonForCars_entry.push_back(WagonForCars(manufacturer,year,emptyWeight,numberOfCars,vehicleWeight));
                }
                else if (command2 == '3')
                {
                    manufacturer = enter_manufacturer();
                    year = enter_year();
                    emptyWeight = enter_emptyWeight();
                    tankIsLoaded = enter_tankIsLoaded();
                    cargoWeight = enter_cargoWeight();
                    TankWagon_entry.push_back(TankWagon(manufacturer, year, emptyWeight, tankIsLoaded, cargoWeight));
                }
                else
                {
                    std::cout << "Вы ввели неверную командую" << std::endl;
                }
                break;
            case '2':

                std::cout << "Вы хотите добавить или изменить:\n";
                std::cout << "\t1. Имя производителя.\n";
                std::cout << "\t2. Год производства.\n";
                std::cout << "\t3. Вес пустого вагона.\n";
                std::cin >> command2;
                std::cin.ignore();
                if (command2 == '1')
                {
                    std::cout << "Вы хотите добавить или изменить:\n";
                    std::cout << "\t1. Запись о пустом вагоне.\n";
                    std::cout << "\t2. Запись о вагоне для перевозки машин.\n";
                    std::cout << "\t3. Запись о Цистерне.\n";
                    std::cin >> command3;
                    std::cin.ignore();
                    if (command3 == '1')
                    {
                        for (i = 0; i < size(railwayCarriage_entry); i++)
                        {
                            std::cout << i << " ";
                            railwayCarriage_entry[i].display_info();
                        }
                        std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                        std::cin >> registry_index;
                        std::cin.ignore();
                        if (registry_index >= 0 && registry_index < size(railwayCarriage_entry))
                        {
                            manufacturer = enter_manufacturer();
                            railwayCarriage_entry[registry_index].set_manufacturer(manufacturer);
                        }
                        else
                        {
                            std::cout << "Введен неверный номер записи." << std::endl;
                        }
                    }
                    else if (command3 == '2')
                    {
                        for (i = 0; i < size(wagonForCars_entry); i++)
                        {
                            std::cout << i << " ";
                            wagonForCars_entry[i].display_info();
                        }
                        std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                        std::cin >> registry_index;
                        std::cin.ignore();
                        if (registry_index >= 0 && registry_index < size(wagonForCars_entry))
                        {
                            manufacturer = enter_manufacturer();
                            wagonForCars_entry[registry_index].set_manufacturer(manufacturer);
                        }
                        else
                        {
                            std::cout << "Введен неверный номер записи." << std::endl;
                        }
                    }
                    else if (command3 == '3')
                    {
                        for (i = 0; i < size(TankWagon_entry); i++)
                        {
                            std::cout << i << " ";
                            TankWagon_entry[i].display_info();
                        }
                        std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                        std::cin >> registry_index;
                        std::cin.ignore();
                        if (registry_index >= 0 && registry_index < size(TankWagon_entry))
                        {
                            manufacturer = enter_manufacturer();
                            TankWagon_entry[registry_index].set_manufacturer(manufacturer);
                        }
                        else
                        {
                            std::cout << "Введен неверный номер записи." << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "Введен неверный номер записи." << std::endl;
                    }
                }
                else if (command2 == '2')
                {
                    std::cout << "Вы хотите добавить или изменить:\n";
                    std::cout << "\t1. Запись о пустом вагоне.\n";
                    std::cout << "\t2. Запись о вагоне для перевозки машин.\n";
                    std::cout << "\t3. Запись о цистерне.\n";
                    std::cin >> command3;
                    std::cin.ignore();
                    if (command3 == '1')
                    {
                        for (i = 0; i < size(railwayCarriage_entry); i++)
                        {
                            std::cout << i << " ";
                            railwayCarriage_entry[i].display_info();
                        }
                        std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                        std::cin >> registry_index;
                        std::cin.ignore();
                        if (registry_index >= 0 && registry_index < size(railwayCarriage_entry))
                        {
                            year = enter_year();
                            railwayCarriage_entry[registry_index].set_productionYear(year);
                        }
                        else
                        {
                            std::cout << "Введен неверный номер записи." << std::endl;
                        }
                    }
                    else if (command3 == '2')
                    {
                        for (i = 0; i < size(wagonForCars_entry); i++)
                        {
                            std::cout << i << " ";
                            wagonForCars_entry[i].display_info();
                        }
                        std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                        std::cin >> registry_index;
                        std::cin.ignore();
                        if (registry_index >= 0 && registry_index < size(wagonForCars_entry))
                        {
                            year = enter_year();
                            wagonForCars_entry[registry_index].set_productionYear(year);
                        }
                        else
                        {
                            std::cout << "Введен неверный номер записи." << std::endl;
                        }
                    }
                    else if (command3 == '3')
                    {
                        for (i = 0; i < size(TankWagon_entry); i++)
                        {
                            std::cout << i << " ";
                            TankWagon_entry[i].display_info();
                        }
                        std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                        std::cin >> registry_index;
                        std::cin.ignore();
                        if (registry_index >= 0 && registry_index < size(TankWagon_entry))
                        {
                            year = enter_year();
                            TankWagon_entry[registry_index].set_productionYear(year);
                        }
                        else
                        {
                            std::cout << "Введен неверный номер записи." << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "Введен неверный номер записи." << std::endl;
                    }
                }
                else if (command2 == '3')
                {
                    std::cout << "Вы хотите добавить или изменить:\n";
                    std::cout << "\t1. Запись о пустом вагоне.\n";
                    std::cout << "\t2. Запись о вагоне для перевозки машин.\n";
                    std::cout << "\t3. Запись о цистерне.\n";
                    std::cin >> command3;
                    std::cin.ignore();
                    if (command3 == '1')
                    {
                        for (i = 0; i < size(railwayCarriage_entry); i++)
                        {
                            std::cout << i << " ";
                            railwayCarriage_entry[i].display_info();
                        }
                        std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                        std::cin >> registry_index;
                        std::cin.ignore();
                        if (registry_index >= 0 && registry_index < size(railwayCarriage_entry))
                        {
                            emptyWeight = enter_emptyWeight();
                            railwayCarriage_entry[registry_index].set_emptyWeight(emptyWeight);
                        }
                        else
                        {
                            std::cout << "Введен неверный номер записи." << std::endl;
                        }
                    }
                    else if (command3 == '2')
                    {
                        for (i = 0; i < size(wagonForCars_entry); i++)
                        {
                            std::cout << i << " ";
                            wagonForCars_entry[i].display_info();
                        }
                        std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                        std::cin >> registry_index;
                        std::cin.ignore();
                        if (registry_index >= 0 && registry_index < size(wagonForCars_entry))
                        {
                            emptyWeight = enter_emptyWeight();
                            wagonForCars_entry[registry_index].set_emptyWeight(emptyWeight);
                        }
                        else
                        {
                            std::cout << "Введен неверный номер записи." << std::endl;
                        }
                    }
                    else if (command3 == '3')
                    {
                        for (i = 0; i < size(TankWagon_entry); i++)
                        {
                            std::cout << i << " ";
                            TankWagon_entry[i].display_info();
                        }
                        std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                        std::cin >> registry_index;
                        std::cin.ignore();
                        if (registry_index >= 0 && registry_index < size(TankWagon_entry))
                        {
                            emptyWeight = enter_emptyWeight();
                            TankWagon_entry[registry_index].set_emptyWeight(emptyWeight);
                        }
                        else
                        {
                            std::cout << "Введен неверный номер записи." << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "Введен неверный номер записи." << std::endl;
                    }
                }
                else
                {
                    std::cout << "Введен неверный номер записи." << std::endl;
                }
                break;
            case '3':
                if (size(wagonForCars_entry) == 0)
                {
                    std::cout << "Отсутствуют записи о вагонах." << std::endl;
                    break;
                }
                for (i = 0; i < size(wagonForCars_entry); i++)
                {
                    std::cout << i << " ";
                    wagonForCars_entry[i].display_info();
                }
                std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                std::cin >> registry_index;
                std::cin.ignore();
                if (registry_index >= 0 && registry_index < size(wagonForCars_entry))
                {
                    int new_cars;
                    std::cout << "Введите количество машин погруженных в вагон: ";
                    std::cin >> new_cars;
                    std::cin.ignore();

                    wagonForCars_entry[registry_index].set_numberOfCars(new_cars);
                    std::cout << "Машины добавлены, теперь машин: " <<
                              wagonForCars_entry[registry_index].get_numberOfCars() << std::endl;
                }
                else
                {
                    std::cout << "Введен неверный номер записи." << std::endl;
                }
                break;
            case '4':
                if (size(TankWagon_entry) == 0)
                {
                    std::cout << "Отсутствуют записи о вагонах." << std::endl;
                    break;
                }
                for (i = 0; i < size(TankWagon_entry); i++)
                {
                    std::cout << i << " ";
                    TankWagon_entry[i].display_info();
                }
                std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
                std::cin >> registry_index;
                std::cin.ignore();
                if (registry_index >= 0 && registry_index < size(TankWagon_entry))
                {
                    std::string new_load;
                    std::cout << "Введите название груза в цистерне: ";
                    std::cin >> new_load;
                    std::cin.ignore();

                    TankWagon_entry[registry_index].set_tankIsLoaded(new_load);
                    std::cout << "Груз добавлен, теперь груз: : " <<
                              TankWagon_entry[registry_index].get_tankIsLoaded() << std::endl;
                }
                else
                {
                    std::cout << "Введен неверный номер записи." << std::endl;
                }
                break;
            case '5':
                if (size(wagonForCars_entry) == 0)
                {
                    std::cout << "Отсутствуют записи о вагонах." << std::endl;
                    break;
                }
                std::cout << "Вы хотите расчитать:\n";
                std::cout << "\t1. Вагон для перевозки машин.\n";
                std::cout << "\t2. Цистерну.\n";
                std::cin >> command2;
                std::cin.ignore();
                if (command2 == '1'){
                    if (size(wagonForCars_entry) > 0)
                    {
                        std::cout << "Вагоны для перевозки машин:" << std::endl;
                        for (i = 0; i < size(wagonForCars_entry); i++)
                        {
                            std::cout << i << " ";
                            wagonForCars_entry[i].display_info();
                        }
                    }
                    std::cout << "Для которой по номеру записи вы хотите посмотреть данные?\n";
                    std::cin >> registry_index;
                    std::cin.ignore();
                    if (registry_index >= 0 && registry_index < size(wagonForCars_entry))
                    {
                        std::cout << "Колличество машин  : " << wagonForCars_entry[registry_index].get_numberOfCars() <<
                                  " суммарный вес : " << wagonForCars_entry[registry_index].total_weight_forCarsWagon() << std::endl;
                    }
                    else
                    {
                        std::cout << "Введен неверный номер записи." << std::endl;
                    }
                    break;
                } else if (command2 == '2'){
                    if (size(TankWagon_entry) > 0)
                    {
                        for (i = 0; i < size(TankWagon_entry); i++)
                        {
                            std::cout << i << " ";
                            TankWagon_entry[i].display_info();
                        }
                    }
                    std::cout << "Для которой по номеру записи вы хотите посмотреть данные?\n";
                    std::cin >> registry_index;
                    std::cin.ignore();
                    if (registry_index >= 0 && registry_index < size(TankWagon_entry))
                    {
                        std::cout << " Вид груза в цистерне : " << TankWagon_entry[registry_index].get_tankIsLoaded() <<
                                  " Сумарный вес вагона : " << TankWagon_entry[registry_index].total_weightTankWagon() << std::endl;
                    }
                    else
                    {
                        std::cout << "Введен неверный номер записи." << std::endl;
                    }
                    break;
                }

                std::cout << "Для которой по номеру записи вы хотите посмотреть данные?\n";
                std::cin >> registry_index;
                std::cin.ignore();
                if (registry_index >= 0 && registry_index < size(wagonForCars_entry))
                {
                    std::cout << "Дата производства : " << wagonForCars_entry[registry_index].get_productionYear() <<
                              " колличество лет эксплуатации : " << wagonForCars_entry[registry_index].life_time_forCarsWagon() << std::endl;
                }
                else
                {
                    std::cout << "Введен неверный номер записи." << std::endl;
                }
                break;
            case '6':
                if (size(wagonForCars_entry) == 0)
                {
                    std::cout << "Отсутствуют записи о вагонах." << std::endl;
                    break;
                }
                std::cout << "Вы хотите расчитать:\n";
                std::cout << "\t1. Вагон для перевозки машин.\n";
                std::cout << "\t2. Цистерну.\n";
                std::cin >> command2;
                std::cin.ignore();
                if (command2 == '1'){
                    if (size(wagonForCars_entry) > 0)
                    {
                        std::cout << "Вагоны для перевозки машин:" << std::endl;
                        for (i = 0; i < size(wagonForCars_entry); i++)
                        {
                            std::cout << i << " ";
                            wagonForCars_entry[i].display_info();
                        }
                    }
                    std::cout << "Для которой по номеру записи вы хотите посмотреть данные?\n";
                    std::cin >> registry_index;
                    std::cin.ignore();
                    if (registry_index >= 0 && registry_index < size(wagonForCars_entry))
                    {
                        std::cout << "Дата производства : " << wagonForCars_entry[registry_index].get_productionYear() <<
                                  " колличество лет эксплуатации : " << wagonForCars_entry[registry_index].life_time_forCarsWagon() << std::endl;
                    }
                    else
                    {
                        std::cout << "Введен неверный номер записи." << std::endl;
                    }
                    break;
                } else if (command2 == '2'){
                    if (size(TankWagon_entry) > 0)
                    {
                        for (i = 0; i < size(TankWagon_entry); i++)
                        {
                            std::cout << i << " ";
                            TankWagon_entry[i].display_info();
                        }
                    }
                    std::cout << "Для которой по номеру записи вы хотите посмотреть данные?\n";
                    std::cin >> registry_index;
                    std::cin.ignore();
                    if (registry_index >= 0 && registry_index < size(TankWagon_entry))
                    {
                        std::cout << "Дата производства : " << TankWagon_entry[registry_index].get_productionYear() <<
                                  " колличество лет эксплуатации : " << TankWagon_entry[registry_index].life_time_forTankWagon() << std::endl;
                    }
                    else
                    {
                        std::cout << "Введен неверный номер записи." << std::endl;
                    }
                    break;
                }

                std::cout << "Для которой по номеру записи вы хотите посмотреть данные?\n";
                std::cin >> registry_index;
                std::cin.ignore();
                if (registry_index >= 0 && registry_index < size(wagonForCars_entry))
                {
                    std::cout << "Дата производства : " << wagonForCars_entry[registry_index].get_productionYear() <<
                              " колличество лет эксплуатации : " << wagonForCars_entry[registry_index].life_time_forCarsWagon() << std::endl;
                }
                else
                {
                    std::cout << "Введен неверный номер записи." << std::endl;
                }
                break;
            case '7':
                if (size(railwayCarriage_entry) > 0)
                {
                    std::cout << "Вагоны в базе:" << std::endl;
                    for (i = 0; i < size(railwayCarriage_entry); i++)
                    {
                        std::cout << i << " ";
                        railwayCarriage_entry[i].display_info();
                    }
                }
                if (size(wagonForCars_entry) > 0)
                {
                    std::cout << "Вагоны для перевозки машин:" << std::endl;
                    for (i = 0; i < size(wagonForCars_entry); i++)
                    {
                        std::cout << i << " ";
                        wagonForCars_entry[i].display_info();
                    }
                }
                if (size(TankWagon_entry) > 0)
                {
                    std::cout << "Цистерны:" << std::endl;
                    for (i = 0; i < size(TankWagon_entry); i++)
                    {
                        std::cout << i << " ";
                        TankWagon_entry[i].display_info();
                    }
                }
                break;
            case '8':
                exit = true;
                break;
            default:
                std::cout << "Вы ввели некорректную команду. Введите от 1 до 8." << std::endl;
                break;
        }
    }
    return 0;
}
