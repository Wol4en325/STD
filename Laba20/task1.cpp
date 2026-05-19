#include <iostream>

using namespace std;

int main()
{
    const double MAX_VOLUME = 45.0;
    const double MAX_WEIGHT = 35.0;

    const double volPerKg[4] = {1.0, 1.5, 2.0, 1.0};
    const double calPerKg[4] = {1500.0, 5000.0, 5000.0, 4000.0};
    const char* names[4] = {"Meat", "Flour", "Milk", "Sugar"};

    double calPerVol[4];
    for (int i = 0; i < 4; i++)
        calPerVol[i] = calPerKg[i] / volPerKg[i];

    cout << "Calories per dm3:" << endl;
    for (int i = 0; i < 4; i++)
        cout << names[i] << ": " << calPerVol[i] << " kcal/dm3" << endl;

    double bestCalories = -1.0;
    double bestMeat = 0, bestFlour = 0, bestMilk = 0, bestSugar = 0;

    for (double sugar = 0.0; sugar <= MAX_WEIGHT; sugar += 0.5)
    {
        for (double milk = 8.0 * sugar; milk <= MAX_WEIGHT; milk += 0.5)
        {
            for (double flour = milk; flour <= MAX_WEIGHT; flour += 0.5)
            {
                for (double meat = 2.0 * flour; meat <= MAX_WEIGHT; meat += 0.5)
                {
                    double totalWeight = meat + flour + milk + sugar;
                    if (totalWeight > MAX_WEIGHT)
                        break;

                    double totalVolume = meat * volPerKg[0] + flour * volPerKg[1]
                                      + milk * volPerKg[2] + sugar * volPerKg[3];
                    if (totalVolume > MAX_VOLUME)
                        continue;

                    double totalCal = meat * calPerKg[0] + flour * calPerKg[1]
                                    + milk * calPerKg[2] + sugar * calPerKg[3];

                    if (totalCal > bestCalories)
                    {
                        bestCalories = totalCal;
                        bestMeat = meat;
                        bestFlour = flour;
                        bestMilk = milk;
                        bestSugar = sugar;
                    }
                }
            }
        }
    }

    cout << endl << "Best combination:" << endl;
    cout << "Meat:  " << bestMeat  << " kg" << endl;
    cout << "Flour: " << bestFlour << " kg" << endl;
    cout << "Milk:  " << bestMilk  << " kg" << endl;
    cout << "Sugar: " << bestSugar << " kg" << endl;

    double totalWeight = bestMeat + bestFlour + bestMilk + bestSugar;
    double totalVolume = bestMeat * volPerKg[0] + bestFlour * volPerKg[1]
                       + bestMilk * volPerKg[2] + bestSugar * volPerKg[3];

    cout << endl << "Total weight: " << totalWeight << " kg (max " << MAX_WEIGHT << ")" << endl;
    cout << "Total volume: " << totalVolume << " dm3 (max " << MAX_VOLUME << ")" << endl;
    cout << "Total calories: " << bestCalories << " kcal" << endl;

    cout << endl << "Constraints check:" << endl;
    cout << "Meat >= 2 * Flour: " << bestMeat << " >= " << 2 * bestFlour
         << " -> " << (bestMeat >= 2 * bestFlour ? "OK" : "FAIL") << endl;
    cout << "Flour >= Milk: " << bestFlour << " >= " << bestMilk
         << " -> " << (bestFlour >= bestMilk ? "OK" : "FAIL") << endl;
    cout << "Milk >= 8 * Sugar: " << bestMilk << " >= " << 8 * bestSugar
         << " -> " << (bestMilk >= 8 * bestSugar ? "OK" : "FAIL") << endl;

    return 0;
}
