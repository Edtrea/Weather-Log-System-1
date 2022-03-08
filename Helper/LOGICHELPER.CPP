/**
 * @file LOGICHELPER.CPP
 * @author Lim Wen Chao
 * @brief .cpp file for LogicHelper
 * @version 0.1
 * @date 2022-02-21
 *
 *
 */

#include "LOGICHELPER.H"

void LogicHelper::LoadDataFileCSV(ifstream &inputFile, Vector<Weather> &WindLog)
{
        // Keeps track of the number of elements split from a given string
    unsigned int recordCount = 0, rowFieldCount = 0, datetimeCount = 0, dateCount = 0, timeCount = 0;
        // A temp storage for split string
    string line, rowField, datetimeField, dateField, timeField;
        // A temp storage for split string
    Vector<string> columns, splitDateTime, splitDate, splitTime;
        // Temp storage for Date object
    Date tempDate;
        // Temp storage for Time object
    Time tempTime;
        // Initialises ValidationHelper
    ValidationHelper Validate;
        // Temp storage for Weather object
    Weather tempLog;
        // input string stream for reading and spliting of elements
    istringstream row, datetime, date, time;

        // Get and ignore csv header
    getline(inputFile, line);
        // Loops for each row of record in file
    while (getline(inputFile, line))
    {
            //Checks that line obtained is not empty
        if (line != "")
        {
                // Split a row into its component columns and store in Vector columns
            row.str(line);
            while (getline(row, rowField, ','))
            {
                columns.Insert(rowFieldCount, rowField);
                rowFieldCount++;
            }
            row.clear();

                // Split datetime column into date and time and store in Vector splitDatetime
            datetime.str(columns[0]);
            while (getline(datetime, datetimeField, ' '))
            {
                splitDateTime.Insert(datetimeCount, datetimeField);
                datetimeCount++;
            }
            datetime.clear();

                // Split date into day/month/year and store in a Date object
            date.str(splitDateTime[0]);
            while (getline(date, dateField, '/'))
            {
                splitDate.Insert(dateCount, RemoveLeadingZeros(dateField));
                dateCount++;
            }
            date.clear();
                // validate date is valid
            if (Validate.IsValidDate(stoi(splitDate[0]), stoi(splitDate[1]), stoi(splitDate[2])))
            {
                tempDate.SetDay(stoi(splitDate[0]));
                tempDate.SetMonth(stoi(splitDate[1]));
                tempDate.SetYear(stoi(splitDate[2]));
            }
            else
            {
                cout << "Error: Invalid date(WAST) detected at row " << recordCount + 1 << endl;
                cout << "Accepted date format: dd/mm/yyyy" << endl;
                EXIT_FAILURE;
            }

                // Split time into hours and minute and store them in Time object
            time.str(splitDateTime[1]);
            while (getline(time, timeField, ':'))
            {
                splitTime.Insert(timeCount, RemoveLeadingZeros(timeField));
                timeCount++;
            }
            time.clear();
                // Validate time is valid
            if (Validate.IsValid24HourTime(stoi(splitTime[0]), stoi(splitTime[1])))
            {
                tempTime.SetHour(stoi(splitTime[0]));
                tempTime.SetMinute(stoi(splitTime[1]));
            }
            else
            {
                cout << "Error: Invalid time(WAST) detected at row: " << recordCount + 1 << endl;
                cout << "Accepted time format(24h only): hh:mm" << endl;
                EXIT_FAILURE;
            }

                // Validate WindSpeed is valid
            if (Validate.IsNumber(columns[10]) == false)
            {
                cout << "Error: Invalid Wind Speed(S) detected at row: " << recordCount + 1 << endl;
                cout << "Only integer/float are accepted" << endl;
                EXIT_FAILURE;
            }
                // Validate SolarRadiation is valid
            if (Validate.IsNumber(columns[11]) == false)
            {
                cout << "Error: Invalid Solar Radiation(SR) detected at row: " << recordCount + 1 << endl;
                cout << "Only integer/float are accepted" << endl;
                EXIT_FAILURE;
            }
                // Validate AmbientAirTemperature is valid
            if (Validate.IsNumber(columns[17]) == false)
            {
                cout << "Error: Invalid Ambient Air Temperature(T) detected at row: " << recordCount + 1 << endl;
                cout << "Only integer/float are accepted" << endl;
                EXIT_FAILURE;
            }
                // Put Date, time, windspeed, solar radiation, air temperature into WindLogType tempLog
            tempLog.SetDate(tempDate);
            tempLog.SetTime(tempTime);
            tempLog.SetWindSpeed(stof(columns[10]));
            tempLog.SetSolarRadiation(stof(columns[11]));
            tempLog.SetAirTemp(stof(columns[17]));

                // Put tempLog into Vector WindLog
            WindLog.Insert(recordCount, tempLog);

                // Clear the temp storage vectors
            columns.Clear();
            splitDateTime.Clear();
            splitDate.Clear();
            splitTime.Clear();

                // Reset count
            rowFieldCount = 0;
            datetimeCount = 0;
            dateCount = 0;
            timeCount = 0;

            recordCount++;
        }
    }
}

void LogicHelper::DisplayMenu()
{
    cout << "1. The average wind speed and average ambient air temperature for a specified month and  year." << endl;
    cout << "2. Average wind speed and average ambient air temperature for each month of a specified year." << endl;
    cout << "3. Total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "4. Write average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year to CSV." << endl;
    cout << "5. Exit the program." << endl;
}

string LogicHelper::RemoveLeadingZeros(string input)
{
    return input.erase(0, min(input.find_first_not_of('0'), input.size() - 1));
}

float LogicHelper::AverageWindSpeedMonth(const Vector<Weather> &array, const int month, const int year)
{
    float totalWindSpeed = 0.0;
    int count = 0;

        //For each record in file, search for matching month and year and add to totalwindspeed
        //The number of matches are counted
    for (unsigned int i = 0; i < array.Size(); i++)
    {
        if (array[i].GetDate().GetMonth() == month && array[i].GetDate().GetYear() == year)
        {
            count++;
            totalWindSpeed += array[i].GetWindSpeed();
        }
    }
        //If no record with matching month and year is found then return -1 else return calculated average windspeed
    if (count == 0)
    {
        return -1;
    }
    else
    {
        return totalWindSpeed / count;
    }
}

float LogicHelper::AverageAirTemperatureMonth(const Vector<Weather> &array, const int month, const int year)
{
    float totalAirTemperature = 0.0;
    int count = 0;

        //Loops through each record in file, search for match month and year and add to totalAirTemperature
        //The number of matching records are kept track of
    for (unsigned int i = 0; i < array.Size(); i++)
    {
        if (array[i].GetDate().GetMonth() == month && array[i].GetDate().GetYear() == year)
        {
            count++;
            totalAirTemperature += array[i].GetAirTemperature();
        }
    }

        //If no record with matching month and year is found then return -1 else return calculated average airTemperature
    if (count == 0)
    {
        return -1;
    }
    else
    {
        return totalAirTemperature / count;
    }
}

float LogicHelper::SumSolarRadiationMonth(const Vector<Weather> &array, const int month, const int year)
{
    float totalSolarRadiation = 0.0;
    int count = 0;

        //Loops through each record in file, search for matching month and year and add to totalsolarRadiation
        //The number of matching records are kept track of
    for (unsigned int i = 0; i < array.Size(); i++)
    {
        if (array[i].GetDate().GetMonth() == month && array[i].GetDate().GetYear() == year)
        {
            count++;
            if (array[i].GetSolarRadiation() > 100)
            {
                totalSolarRadiation += array[i].GetSolarRadiation();
            }
        }
    }

        //If no records with matching month and year is found then return -1 else return the totalSolarRadiation
    if (count > 0)
    {
        return totalSolarRadiation;
    }
    else
    {
        return -1;
    }
}

string LogicHelper::IntMonthToString(const int &month)
{
    switch (month)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        cout << endl << "Error converting int month to string" << endl;
        return "ERROR";
    }
}

float LogicHelper::ConvertWindMStoKMH(const float &windSpeed)
{
    return windSpeed * 3.6;
}

float LogicHelper::ConvertSolarRadiationWMtoKWH(const float &radiation)
{
    if (radiation > 0)
    {
        return radiation / 6 / 1000;
    }
    return 0;
}

void LogicHelper::WriteAppendFile(const string &output)
{
    ofstream OutputFile("WindTempSolar.csv", ofstream::app);
        //appends the string and proceed to nextline
    OutputFile << output << endl;

    OutputFile.close();
}