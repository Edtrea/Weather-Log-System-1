/**
 * @file WEATHER.CPP
 * @author Lim Wen Chao
 * @brief .CCP for Weather class
 * @version 0.1
 * @date 2022-02-27
 * 
 * 
 */

#include "WEATHER.H"

Weather::Weather()
{
        //Sets to -1
    m_windSpeed = -1.0;
    m_solarRad = -1.0;
    m_airTemp = -1.0;
}

Weather::~Weather()
{}

    //Getters
const Date& Weather::GetDate() const
{
    return m_date;
}
const Time& Weather::GetTime() const
{
    return m_time;
}
float Weather::GetWindSpeed() const
{
    return m_windSpeed;
}
float Weather::GetSolarRadiation() const
{
    return m_solarRad;
}
float Weather::GetAirTemperature() const
{
    return m_airTemp;
}

    //Setter
void Weather::SetDate(Date& date)
{
    m_date = date;
}
void Weather::SetTime(Time& time)
{
    m_time = time;
}
void Weather::SetWindSpeed(float windSpeed)
{
    m_windSpeed = windSpeed;
}
void Weather::SetSolarRadiation(float solar)
{
    m_solarRad = solar;
}
void Weather::SetAirTemp(float temp)
{
    m_airTemp = temp;
}