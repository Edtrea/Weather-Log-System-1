/**
 * @file DATETEST.CPP
 * @author Lim Wen Chao
 * @brief Unit test for Date
 * @version 0.1
 * @date 2022-02-24
 * 
 * 
 */
#include "DATE.H"

#include <iostream>

using namespace std;

int testdate_main ()
{
    //Check constructor correctly initializes the data and all getters are able to retrieve the data
    Date testDate1;
    cout << "Default Constuctor" << endl;
    cout << "Day: " << testDate1.GetDay() << endl;
    cout << "Month: " << testDate1.GetMonth() << endl;
    cout << "Year: " << testDate1.GetYear() << endl << endl;

    Date testDate2(1,1,1);
    cout << "Constructor" << endl;
    cout << "Day: " << testDate2.GetDay() << endl;
    cout << "Month: " << testDate2.GetMonth() << endl;
    cout << "Year: " << testDate2.GetYear() << endl << endl;

    //Check that setters are working correctly
    testDate2.SetDay(3);
    testDate2.SetMonth(3);
    testDate2.SetYear(3);
    cout << "Test Setters" << endl;
    cout << "Day: " << testDate2.GetDay() << endl;
    cout << "Month: " << testDate2.GetMonth() << endl;
    cout << "Year: " << testDate2.GetYear() << endl;

    return 0;
}