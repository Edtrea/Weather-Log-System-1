/**
 * @file VALIDATIONHELPER.H
 * @author Lim Wen Chao
 * @brief Collection of functions for checking validity of data
 * @version 0.1
 * @date 2022-02-21
 * 
 * @version 0.2
 * @date 2022-03-01
 * Added new function is valid month
 */

#ifndef VALIDATION_HELPER_H
#define VALIDATION_HELPER_H

#include <regex>

using namespace std;

class ValidationHelper
{
    public:
            /**
             * @brief Checks if a set of int is is valid date
             * 
             * @param day - The day of the date
             * @param month - The month of the date
             * @param year - The year of the date
             * @return true - Date is valid
             * @return false - Date is invalid
             */
        bool IsValidDate(const int& day, const int& month, const int& year);
            /**
             * @brief Checks if a set of int is valid date
             * 
             * @param month - The month of the date
             * @param year - The year of the date
             * @return true - Date is valid
             * @return false - Date is invalid
             */
        bool IsValidDate(const int& month, const int& year);
            /**
             * @brief Set if int is valid month
             * 
             * @param month - the int input
             * @return true - int input is a valid month
             * @return false - int input is invalid month
             */
        bool IsValidMonth(const int& month);
            /**
             * @brief Checks if a year is a leap year
             * 
             * @param year - The year to check
             * @return true - Its a leap year
             * @return false - Its not a leap year
             */
        bool IsLeapYear(const int& year);
            /**
             * @brief Checks if a set of int is valid 24hour time
             * 
             * @param hour - the hour of time
             * @param minute - the minute of time
             * @return true - time is valid
             * @return false - time is invalid
             */
        bool IsValid24HourTime(const int& hour,const int& minute);
            /**
             * @brief Check if a given string is valid number
             * A number is valid as long as it contains digits and at most 1 decimal point
             * The  decimal point must be after at least 1 digit
             * 
             * @param input - string input
             * @return true - string is number
             * @return false - string is not a number
             */
        bool IsNumber(const string& input);
            /**
             * @brief Checks if a given string is a valid integer
             * A integer is valid as long as it contains only digits
             * 
             * @param input - string input
             * @return true - string is integer
             * @return false - string is not integer
             */
        bool IsInteger(const string& input);
};


#endif