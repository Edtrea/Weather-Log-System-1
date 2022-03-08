/**
 * @file WEATHER.H
 * @author Lim Wen Chao
 * @brief Class for storing Windlog details such as date, time, wind speed, solar radiation and air temperature. Each Object correspond to a line of record from data file
 * @version 0.1
 * @date 2022-02-27
 * 
 * 
 */

#ifndef WEATHER_H
#define WEATHER_H

#include "DATE.H"
#include "TIME.H"

using namespace std;

class Weather
{
    public:
            /**
             * @brief Construct a new Weather object
             * 
             */
        Weather();
            /**
             * @brief Destroy the Weather object
             * 
             */
        ~Weather();

            /**
             * @brief Get m_date
             * 
             * @return const Date& - Date object
             */
        const Date& GetDate() const;
            /**
             * @brief Get m_time
             * 
             * @return const Time&  -Time Object
             */
        const Time& GetTime() const;
            /**
             * @brief Get m_windSpeed
             * 
             * @return float - Wind Speed
             */
        float GetWindSpeed() const;
            /**
             * @brief Get m_solarRad
             * 
             * @return float - Solar Radiation
             */
        float GetSolarRadiation() const;
            /**
             * @brief Get m_airTemp
             * 
             * @return float - Ambient Air Temperature
             */
        float GetAirTemperature() const;

            /**
             * @brief Set m_date
             * 
             * @param date - Date object
             */
        void SetDate(Date& date);
            /**
             * @brief Set m_time
             * 
             * @param time - Time object
             */
        void SetTime(Time& time);
            /**
             * @brief Set m_windSpeed
             * 
             * @param windSpeed - wind speed
             */
        void SetWindSpeed(float windSpeed);
            /**
             * @brief Set m_solarRad
             * 
             * @param solar - Solar Radiation
             */
        void SetSolarRadiation(float solar);
            /**
             * @brief Set m_airTemp
             * 
             * @param temp - Ambient Air Temperature
             */
        void SetAirTemp(float temp);

    private:
            //Stores the date part includes the day, month & year
        Date m_date;
            //Stores the time part include hour and minutes
        Time m_time;
            //Stores the wind speed in m/s for each record
        float m_windSpeed;
            //Stores the solar radiation in W/m^2
        float m_solarRad;
            //Stores the ambient air temperature in degress C
        float m_airTemp;
};

#endif