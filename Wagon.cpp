#include <iostream>
#include "Wagon.h"
//
//RailwayCarriage
//
RailwayCarriage::RailwayCarriage(std::string manufacturer){
    this->_manufacturer = manufacturer;
}

RailwayCarriage::RailwayCarriage(std::string manufacturer, int productionYear, int emptyWeight) {
    this->_manufacturer = manufacturer;
    this->_productionYear = productionYear;
    this->_emptyWeight = emptyWeight;
}
void RailwayCarriage::display_info()
{
    if (!empty(_manufacturer))
    {
        std::cout << "Имя производителя: " << _manufacturer << std::endl;
    }
    if (_productionYear != 0)
    {
        std::cout << "Год производства: " << _productionYear << std::endl;
    }
    if ((_emptyWeight) != 0)
    {
        std::cout << "Вес пустого вагона: " << _emptyWeight << std::endl;
    }
    std::cout << "-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

void RailwayCarriage::set_manufacturer(std::string manufacturer) {
    this->_manufacturer = manufacturer;
}

void RailwayCarriage::set_productionYear(int productionYear) {
    this->_productionYear = productionYear;
}

void RailwayCarriage::set_emptyWeight(int emptyWeight) {
    this->_emptyWeight = emptyWeight;
}
int RailwayCarriage::get_emptyWeight(){
    return _emptyWeight;
}
int RailwayCarriage::get_productionYear() {
    return _productionYear;
}
//
//WagonForCars
//
WagonForCars::WagonForCars(std::string manufacturer) : RailwayCarriage(manufacturer) {
}

void WagonForCars::set_numberOfCars(int numberOfCars) {
    this->_numberOfCars = numberOfCars;
}
const int WagonForCars::get_numberOfCars() {
    return _numberOfCars;
}
const int WagonForCars::get_vehicleWeight() {
    return _vehicleWeight;
}

const int WagonForCars::life_time_forCarsWagon() {
    return 2022 - this->get_productionYear();
}
// здесть происходит наследование
WagonForCars::WagonForCars(std::string manufacturer, int productionYear, int emptyWeight, int numberOfCars, int vehicleWeight) : RailwayCarriage(manufacturer, productionYear, emptyWeight) {
    this->_numberOfCars = numberOfCars;
    this->_vehicleWeight = vehicleWeight;
}

int WagonForCars::total_weight_forCarsWagon() {
    return this->get_vehicleWeight() + this->get_emptyWeight();
}

//
//TankWagon
//
// здесть происходит наследование
TankWagon::TankWagon(std::string manufacturer, int year, int emptyWeight, std::string tankIsLoaded, int cargoWeight) : RailwayCarriage(manufacturer,year,emptyWeight) {
    this->_tankIsLoaded = tankIsLoaded;
    this->_cargoWeight = cargoWeight;
}
void TankWagon::set_tankIsLoaded(std::string tankIsLoaded) {
    this->_tankIsLoaded = tankIsLoaded;
}

const std::string TankWagon::get_tankIsLoaded() {
    return _tankIsLoaded;
}
const int TankWagon::get_cargoWeight() {
    return _cargoWeight;
}
int TankWagon::life_time_forTankWagon(){
    return 2022 - this->get_productionYear();
}
int TankWagon::total_weightTankWagon(){
    return this->get_cargoWeight() + this->get_emptyWeight();
}
