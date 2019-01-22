#include <iostream>

using namespace std;

class Car
{
private:
    int gasolinGauge;
public:
    Car(int num) : gasolinGauge(num)
    {}

    int GetGasGauge()
    {
        return gasolinGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar(int num1, int num2) : electricGauge(num1), Car(num2)
    {}
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int num1, int num2, int num3) : waterGauge(num1), HybridCar(num2,num3)
    {}
    void ShowCurrentGauge()
    {
        cout << "잔여 가솔린: " << GetGasGauge() << endl;
        cout << "잔여 전기량: " << GetElecGauge() << endl;
        cout << "잔여 워터량: " << waterGauge << endl;
    }
};

int main()
{

    HybridWaterCar car1(10,20,30);
    car1.ShowCurrentGauge();

    return 0;
}
