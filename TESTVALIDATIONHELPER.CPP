/**
 * @file VALIDATIONHELPERTEST.CPP
 * @author Lim Wen Chao
 * @brief Unit Test for Validation Helper
 * @version 0.1
 * @date 2022-02-25
 * 
 * 
 */

#include "Helper/VALIDATIONHELPER.H"

#include <iostream>

using namespace std;

int testvalid_main ()
{
    ValidationHelper validate;
    //Check that IsValidDate function can correctly determine if a date is valid when given the day, month and year
    cout << "Checking IsValidDate(int day, int month, int year)" << endl;
    cout << "Positive case (29/2/2020): " << validate.IsValidDate(29,2,2020) << endl;
    cout << "Negative case, wrong day (31/2/2020):  " << validate.IsValidDate(31,2,2020) << endl;
    cout << "Negative case, wrong month (29/13/2020): " << validate.IsValidDate(29,13,2020) << endl;
    cout << "Negative case, wrong year (29/2/99): " << validate.IsValidDate(29,2,99) << endl;
    cout << "Negative case, not leap year (29/2/2022): " << validate.IsValidDate(29,2,2022) << endl << endl;
    //Check that IsValidDate function can correctly determine if a date is valid when given the month and year only
    cout << "Checking IsValidDate(int month, int year)" << endl;
    cout << "Positive case (2/2020): " << validate.IsValidDate(2,2020) << endl;
    cout << "Negative case, wrong month (13/2020): " << validate.IsValidDate(13,2020) << endl;
    cout << "Negative case, wrong year (2/99): " << validate.IsValidDate(2,99) << endl << endl;
    //Check that IsValidMonth function can correctly determine if a int is valid month
    cout << "Checking IsValidMonth(int month)" << endl;
    cout << "Positive case (2): " << validate.IsValidMonth(2) << endl;
    cout << "Negative case, wrong month (13): " << validate.IsValidMonth(13) << endl;
    //Check that IsLeapYear function can correctly determine if a year is a leap year
    cout << "Checking IsLeapYear(int year)" << endl;
    cout << "Positive case (2020): " << validate.IsLeapYear(2020) << endl;
    cout << "Negative case (2022): " << validate.IsLeapYear(2022) << endl << endl;
    //Check that IsValid24HourTime function can correctly determine if a given hour and minute is valid 24 hour time
    cout << "Checking IsValid24HourTime(int hour, int minute)" << endl;
    cout << "Positive case (8,50): " << validate.IsValid24HourTime(8,50) << endl;
    cout << "Negative case, wrong hour (25,50): " << validate.IsValid24HourTime(25,50) << endl;
    cout << "Negative case, wrong minute (24,60): " << validate.IsValid24HourTime(24,60) << endl << endl;
    //Check that IsNumber function can correctly determine if a provided string is positive int/float
    cout << "Checking IsNumber(string input)" << endl;
    cout << "Positive case (415): " << validate.IsNumber("415") << endl;
    cout << "Positive case (63.41): " << validate.IsNumber("63.41") << endl;
    cout << "Negative case, negative int (-1): " << validate.IsNumber("-1") << endl;
    cout << "Negative case, negative float (-1.2): " << validate.IsNumber("-1.2") << endl;
    cout << "Negative case, octal numbers (08): " << validate.IsNumber("08") << endl << endl;
    //Check that IsInteger function can correctly determine if a provided string is a positive integer
    cout << "Checking IsInteger(string input)" << endl;
    cout << "Positive case (415): " << validate.IsInteger("415") << endl;
    cout << "Negative case (45.21): " << validate.IsInteger("45.21") << endl;
    cout << "Negative case (-1): " << validate.IsInteger("-1") << endl;
    cout << "Negative case (08): " << validate.IsInteger("08") << endl << endl;

    return 0;
}