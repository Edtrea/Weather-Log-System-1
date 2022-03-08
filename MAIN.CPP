/**
 * @file MAIN.CPP
 * @author Lim Wen Chao
 * @brief Controls the cin and cout of the program, the logic of the program
 * @version 0.1
 * @date 2022-02-21
 * 
 * 
 */
#include "Helper/LOGICHELPER.H"
#include "Helper/VALIDATIONHELPER.H"
#include "DATE.H"
#include "TIME.H"
#include "WEATHER.H"
#include "VECTOR.H"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


int main ()
{
        //Vector that store all the data of the data file
    Vector<Weather> WindLog;
        //Initialize LogicHelper and Validationhelper for use
    LogicHelper LogicHelp;
    ValidationHelper Validate;

    cout << "Enter file name to read (Must be in data folder)" << endl;

    string inputFileName;
    cin >> inputFileName;

    ifstream inputFile("data/" + inputFileName);

    while(inputFile.is_open() == false)
    {
        cout << "File not found, please enter a existing file's name" << endl;
        inputFileName = "";
        cout << "Enter file name to read (Must be in data folder)" << endl;
        cin >> inputFileName;
        inputFile.open("data/" + inputFileName);
    }

    LogicHelp.LoadDataFileCSV(inputFile, WindLog);

    inputFile.close();

    bool flag = true;
    string input;
    while(flag)
    {
        LogicHelp.DisplayMenu();
        cin >> input;
            //Check which function user wants to use
        if(input == "1")
        {
                //Ask user which month and year they want to search for and validate those input
            string monthInput, yearInput;
            cout << "Input month to search(1-12)" << endl;
            cin >> monthInput;
            while(Validate.IsInteger(monthInput) == false)
            {
                cout << "Error: invalid month. Expects integer." << endl;
                cout << "Input month to search(1-12)" << endl;
                cin >> monthInput;
            }
            cout << "Input year to search" << endl;
            cin >> yearInput;
            while(Validate.IsInteger(yearInput) == false)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }
            if(Validate.IsValidDate(stoi(monthInput), stoi(yearInput)) == false)
            {
                cout << "Error: invalid date." << endl;
                break;
            }

                //Get Average wind speed and air temperature of that month and year
            float averageWind = LogicHelp.AverageWindSpeedMonth(WindLog, stoi(monthInput), stoi(yearInput));
            float averageTemp = LogicHelp.AverageAirTemperatureMonth(WindLog, stoi(monthInput), stoi(yearInput));

                //If record for that month and year dont exist then print no data else print the data
            if(averageWind == -1 && averageTemp == -1)
            {
                cout << LogicHelp.IntMonthToString(stoi(monthInput)) << " " << yearInput << ": " << "No Data" << endl;
            }
            else
            {
                float convertedWind = LogicHelp.ConvertWindMStoKMH(averageWind);

                cout << LogicHelp.IntMonthToString(stoi(monthInput)) << " " << yearInput << ": " << convertedWind << " km/h, " << averageTemp << " degrees C" << endl; 
            }
        }
        else if (input == "2")
        {
                //Ask user for year to search for and validate the input
            string yearInput;
            cout << "Input year to search(YYYY)" << endl;
            cin >> yearInput;
            while(Validate.IsInteger(yearInput) == false ||yearInput.size() != 4)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }

            cout << yearInput << endl;
            float averageWind, averageTemp, convertedWind;

                //For each month of the year get average wind speed and air temperature
            for(int month = 1; month <= 12; month++)
            {
                averageWind = LogicHelp.AverageWindSpeedMonth(WindLog, month, stoi(yearInput));
                averageTemp = LogicHelp.AverageAirTemperatureMonth(WindLog, month, stoi(yearInput));

                    //If records are not found then print no date else print the a converted windspeed and air temperature
                if(averageWind == -1 && averageTemp == -1)
                {
                    cout << LogicHelp.IntMonthToString(month) << " " << yearInput << ": " << "No Data" << endl;
                }
                else
                {
                    convertedWind = LogicHelp.ConvertWindMStoKMH(averageWind);

                    cout << LogicHelp.IntMonthToString(month) << " " << yearInput << ": " << convertedWind << " km/h, " << averageTemp << " degrees C" << endl; 
                }
            }
        }
        else if (input == "3")
        {
                //Ask user for which year to search and validate the input
            string yearInput;
            cout << "Input year to search" << endl;
            cin >> yearInput;
            while(Validate.IsInteger(yearInput) == false || yearInput.size() != 4)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }

            cout << yearInput << endl;
            float totalRadiation, convertedRadiation;

                //For each month in a year, search for the total solar radiation
            for(int month = 1; month <= 12; month++)
            {
                totalRadiation = LogicHelp.SumSolarRadiationMonth(WindLog, month, stoi(yearInput));

                    //If there are no records then print no data else convert w/10mins/m^2 to kWh/m^2 and print result
                if(totalRadiation == -1)
                {
                    cout << LogicHelp.IntMonthToString(month) << " " << yearInput << ": " << "No Data" << endl;
                }
                else
                {
                    convertedRadiation = LogicHelp.ConvertSolarRadiationWMtoKWH(totalRadiation);

                    cout << LogicHelp.IntMonthToString(month) << " " << yearInput << ": " << convertedRadiation << " kWh/m" << u8"\u00B2" << endl;
                }
            }
        }
        else if(input == "4")
        {
                //Delete the output file if it exist
            remove("WindTempSolar.csv");

                //Ask user for which year to search for and validate the input
            string yearInput;
            cout << "Input year to search" << endl;
            cin >> yearInput;
            while(Validate.IsInteger(yearInput) == false || yearInput.size() !=4)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }

                //Write the year onto the output file
            LogicHelp.WriteAppendFile(yearInput);

            float averageWind, averageTemp, convertedWind, totalRadiation, convertedRadiation;

                //For each month in a year, find the average wind speed, air temperature and total solarr radiation
            for(int month = 1; month <= 12; month++)
            {
                averageWind = LogicHelp.AverageWindSpeedMonth(WindLog, month, stoi(yearInput));
                averageTemp = LogicHelp.AverageAirTemperatureMonth(WindLog, month, stoi(yearInput));
                totalRadiation = LogicHelp.SumSolarRadiationMonth(WindLog, month, stoi(yearInput));

                if(averageWind == -1 && averageTemp == -1 && totalRadiation == -1)
                {
                    continue;
                }
                else
                {
                    convertedWind = LogicHelp.ConvertWindMStoKMH(averageWind);
                    convertedRadiation = LogicHelp.ConvertSolarRadiationWMtoKWH(totalRadiation);

                    LogicHelp.WriteAppendFile(LogicHelp.IntMonthToString(month)+","+to_string(convertedWind)+","+to_string(averageTemp)+","+to_string(convertedRadiation));
                }
            }
        }
        else if (input == "5")
        {
            flag = false;
        }
        else
        {
            cout << "Error: Unknown command. Only numbers 1-5 accepted." << endl;
        }
        
    }
    return 0;
}