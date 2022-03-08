/**
 * @file LOGICHELPERTEST.CPP
 * @author Lim Wen Chao
 * @brief Unit Test for LogicHelper class
 * @version 0.1
 * @date 2022-02-25
 * 
 * 
 */

#include "Helper/LogicHelper.H"
#include "WEATHER.H"

#include <iostream>

using namespace std;

int testlogic_main ()
{
    LogicHelper TestLogic;
    Vector<Weather> TestLog;
    //Check that RemoveLeadingZeros function can correctly remove the leading zeros when given a string
    cout << "Test RemoveLeadingZeros(string)" << endl;
    cout << "Test RemoveLeadingZeros(08): " << TestLogic.RemoveLeadingZeros("08") << endl;
    cout << "Test RemoveLeadingZeros(08.9): " << TestLogic.RemoveLeadingZeros("08.9") << endl;
    cout << endl;
    //Check that DisplayMenu function can successfully display the menu
    cout << "Test DisplayMenu()" << endl;
    TestLogic.DisplayMenu();
    cout << endl;
    //Check that IntMonthToString function can correctly return the month in string when provided with a month in integer
    cout << "Test IntMonthToString(unsigned int)" << endl;
    cout << "Test IntMonthToString(8): " << TestLogic.IntMonthToString(8) << endl;
    cout << "Test IntMonthToString(13): " << TestLogic.IntMonthToString(13) << endl;
    cout << endl;
    //Check that ConvertWindMStoKMH function can correctly convert windspeed provided in m/s to km/h
    cout << "Test ConvertWindMStoKMH(float)" << endl;
    cout << "Test ConvertWindMStoKMH(10): " << TestLogic.ConvertWindMStoKMH(10) << endl;
    cout << "Test ConvertWindMStoKMH(10.5): " << TestLogic.ConvertWindMStoKMH(10.5) << endl;
    cout << endl;
    //Check that ConvertSolarRadiationWMtoKWH function can correctly convert solar radiation provided in W/m2 to kWh/m2
    cout << "Test ConvertSolarRadiationWMtoKWH(float)" << endl;
    cout << "Test ConvertSolarRadiationWMtoKWH(120): " << TestLogic.ConvertSolarRadiationWMtoKWH(120) << endl;
    cout << "Test ConvertSolarRadiationWMtoKWH(120.42): " << TestLogic.ConvertSolarRadiationWMtoKWH(120.42) << endl;
    cout << endl;
    //Check that LoadDataFileCSV function can correctly load csv data file
    cout << "Test LoadDataFileCSV function" << endl;
    ifstream inputFile("data/Test.csv");
    //ifstream inputFile("data/MetData-31-3a.csv");
    TestLogic.LoadDataFileCSV(inputFile, TestLog);
    for(int i = 0; i < TestLog.Size(); i++)
    {
        cout << TestLog[i].GetDate().DisplayFullDate();
        cout << ",";
        cout << TestLog[i].GetTime().Display24HTime();
        cout << ",";
        cout << TestLog[i].GetWindSpeed();
        cout << ",";
        cout << TestLog[i].GetSolarRadiation();
        cout << ",";
        cout << TestLog[i].GetAirTemperature();
        cout << endl;
    }
    cout << endl;
    //Check that AverageWindSpeedMonth function can correctly find and calculate the average windspeed for a month
    cout << "Test AverageWindSpeedMonth(vector,int,int)" << endl;
    cout << "Test AverageWindSpeedMonth(TestLog,3,2016): " << TestLogic.AverageWindSpeedMonth(TestLog,3,2016) << endl;
    cout << "Test AverageWindSpeedMonth(TestLog,1,2020): " << TestLogic.AverageWindSpeedMonth(TestLog,1,2020) << endl;
    cout << endl;
    //Check that AverageAirTemperatureMonth function can correctly find and calculate the average ambient air temperature for a month
    cout << "Test AverageAirTemperatureMonth(vector,int,int)" << endl;
    cout << "Test AverageAirTemperatureMonth(TestLog,3,2016): " << TestLogic.AverageAirTemperatureMonth(TestLog,3,2016) << endl;
    cout << "Test AverageAirTemperatureMonth(TestLog,1,2020): " << TestLogic.AverageAirTemperatureMonth(TestLog,1,2020) << endl;
    cout << endl;
    //Check that SumSolarRadiationMonth function can correctly find and calculate the total solar radiation for a month
    cout << "Test SumSolarRadiationMonth(vector,int,int)" << endl;
    cout << "Test SumSolarRadiationMonth(TestLog,3,2016): " << TestLogic.SumSolarRadiationMonth(TestLog,3,2016) << endl;
    cout << "Test SumSolarRadiationMonth(TestLog,1,2020): " << TestLogic.SumSolarRadiationMonth(TestLog,1,2020) << endl;
    cout << endl;
    //Check that WriteAppendFile able to correctly write to "WindTempSolar.csv"
    cout << "Test WriteAppendFile(string)" << endl;
    TestLogic.WriteAppendFile("teststring");
    TestLogic.WriteAppendFile("teststring2");

    return 0;
}