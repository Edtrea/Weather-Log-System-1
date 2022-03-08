/**
 * @file TESTWEATHER.CPP
 * @author Lim Wen Chao
 * @brief Unit Test for Weather
 * @version 0.1
 * @date 2022-02-27
 * 
 * 
 */

#include "WEATHER.H"

int testweather_main()
{
    //Check that constructor correctly initialize the data and all getters can retrieve the data
    cout << "Check constructor" << endl;
    Weather testWeather;
    cout << "Date: " << testWeather.GetDate().DisplayFullDate() << endl;
    cout << "Time: " << testWeather.GetTime().Display24HTime() << endl;
    cout << "Wind Speed: " << testWeather.GetWindSpeed() << endl;
    cout << "Solar Radiation" << testWeather.GetSolarRadiation() << endl;
    cout << "Air Temperature: " << testWeather.GetAirTemperature() << endl;
    cout << endl;
    //Check that setters are working correctly
    cout << "Test Setters" << endl;
    Date testDate(16,3,2016);
    Time testTime(9,15);
    testWeather.SetDate(testDate);
    testWeather.SetTime(testTime);
    testWeather.SetWindSpeed(23.1);
    testWeather.SetSolarRadiation(53.15);
    testWeather.SetAirTemp(53.25);

    cout << "Date: " << testWeather.GetDate().DisplayFullDate() << endl;
    cout << "Time: " << testWeather.GetTime().Display24HTime() << endl;
    cout << "Wind Speed: " << testWeather.GetWindSpeed() << endl;
    cout << "Solar Radiation" << testWeather.GetSolarRadiation() << endl;
    cout << "Air Temperature: " << testWeather.GetAirTemperature() << endl;

    return 0;
}