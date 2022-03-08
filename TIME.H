/**
 * @file TIME.H
 * @author Lim Wen Chao
 * @brief Time class for storing 24 hour time
 * Splits in hour and minute before storing as unsigned int
 * Expects only 24hour time
 * @version 0.1
 * @date 2022-02-21
 * 
 * 
 */

#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time
{
    public:
            /**
             * @brief Construct a new Time object
             * 
             */
        Time():m_hour(-1),m_minute(-1){};
            /**
             * @brief Construct a new Time object
             * 
             * @param h 
             * @param m 
             */
        Time(unsigned int h, unsigned int m);
            /**
             * @brief Destroy the Time object
             * 
             */
        ~Time(){};
        
            /**
             * @brief Get the Hour object
             * 
             * @return int 
             */
        int GetHour() const;
            /**
             * @brief Get the Minute object
             * 
             * @return int 
             */
        int GetMinute() const;
        
            /**
             * @brief Set the Hour object
             * 
             * @param h 
             */
        void SetHour(unsigned int h);
            /**
             * @brief Set the Minute object
             * 
             * @param m 
             */
        void SetMinute(unsigned int m);

            /**
             * @brief 
             * 
             * @return string 
             */
        string Display24HTime() const;

    private:
        int m_hour;
        int m_minute;
};

#endif