#ifndef OOP_LAB4_WAGON_H
#define OOP_LAB4_WAGON_H

#endif //OOP_LAB4_WAGON_H

class RailwayCarriage{
private:
    std::string _manufacturer;
    int _productionYear;
    int _emptyWeight;
public:

    RailwayCarriage(std::string manufacturer);
    RailwayCarriage(std::string manufacturer, int productionYear, int emptyWeight);

    void display_info();

    void set_manufacturer(std::string manufacturer);
    void set_productionYear(int productionYear);
    void set_emptyWeight(int emptyWeight);

    int get_emptyWeight();
    int get_productionYear();
};
class WagonForCars : public RailwayCarriage{
private:
    int _numberOfCars;
    int _vehicleWeight;
public:

    WagonForCars(std::string manufacturer);

    void set_numberOfCars(int numberOfCars);

    const int get_numberOfCars();
    const int get_vehicleWeight();

    const int life_time_forCarsWagon();
    int total_weight_forCarsWagon();
    // здесть происходит наследование
    WagonForCars(std::string manufacturer, int year, int emptyWeight, int numberOfCars, int vehicleWeight);
};
class TankWagon : public RailwayCarriage{
private:
    std::string _tankIsLoaded;
    int _cargoWeight;
public:
// здесть происходит наследование
    TankWagon(std::string manufacturer, int year, int emptyWeight, std::string tankIsLoaded, int cargoWeight);

    void set_tankIsLoaded(std::string tankIsLoaded);

    const std::string get_tankIsLoaded();
    const int get_cargoWeight();
    int life_time_forTankWagon();
    int total_weightTankWagon();
};