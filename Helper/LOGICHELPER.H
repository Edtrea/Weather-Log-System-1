/**
 * @file LOGICHELPER.H
 * @author Lim Wen Chao
 * @brief A helper class for main.cpp
 * Handles task such as displaying menu, converting of data types, addition..
 * Function for writing to file will be including in this helper class in this program as there is only 1 function in this program that will write output to file.
 * @version 0.1
 * @date 2022-02-21
 * 
 * 
 */

#ifndef LOGICHELPER_H
#define LOGICHELPER_H

#include "../VECTOR.H"
#include "../DATE.H"
#include "../TIME.H"
#include "../WEATHER.H"
#include "VALIDATIONHELPER.H"

#include <iostream>
#include <fstream>
//#include <string>

using namespace std;

class LogicHelper
{
    public: 
            /**
             * @brief Load the data of an input data file and store it in a Vector
             * 
             * @param inputFile - The input file
             * @param WindLog - The Vector
             */
        void LoadDataFileCSV(ifstream& inputFile, Vector<Weather>& WindLog);
            /**
             * @brief Displays the menu
             * 
             */
        void DisplayMenu();
            /**
             * @brief Removes leading 0s from a given string
             * 
             * @param input - The input string
             * @return string - The string after removing leading 0s
             */
        string RemoveLeadingZeros(string input);
            /**
             * @brief Search and Calculates the average wind speed of a month when given the month and year to search for
             * 
             * @param array - The Vector to search in
             * @param month - The month to search for
             * @param year - The year to search for
             * @return float - The average wind speed of a month
             */
        float AverageWindSpeedMonth(const Vector<Weather>& array, const int month, const int year);
            /**
             * @brief Search and Calculates the average air temperature of a month when given the month and year to search for
             * 
             * @param array - The Vector to search in
             * @param month - The month to search for
             * @param year - The year to search for
             * @return float - The average air temperature of a month
             */
        float AverageAirTemperatureMonth(const Vector<Weather>& array, const int month, const int year);
            /**
             * @brief Search and Calculates the total solar radiation of a month when given the month and year to search for
             * 
             * @param array - The Vector to search in
             * @param month - The month to search for
             * @param year - The year to search for
             * @return float - The total solar radiation of a month
             */
        float SumSolarRadiationMonth(const Vector<Weather>& array, const int month, const int year);
            /**
             * @brief Converts a given integer month to string month
             * 
             * @param month - A month in integer
             * @return string - A month in string
             */
        string IntMonthToString(const int& month);
            /**
             * @brief Converts wind speed m/s  to km/h
             * 
             * @param windSpeed - wind speed in m/s
             * @return float - wind speed in km/h
             */
        float ConvertWindMStoKMH(const float& windSpeed);
            /**
             * @brief Converts solar radiation from W per 10 min to kWh
             * 
             * @param radiation - Radiation in W per 10min
             * @return float - Radiation in kWh
             */
        float ConvertSolarRadiationWMtoKWH(const float& radiation);
            /**
             * @brief Create/Appends a given string into "WindTempSolar.csv"
             * 
             * @param output - The string to append
             */
        void WriteAppendFile(const string& output);
};

#endif