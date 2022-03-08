/**
 * @file TimeTEST.CPP
 * @author Lim Wen Chao
 * @brief Unit test for Time
 * @version 0.1
 * @date 2022-02-24
 * 
 * 
 */
#include "TIME.H"

#include <iostream>

using namespace std;

int testtime_main ()
{
    //Check constructor correctly initializes the data and all getters are able to retrieve the data
    Time testTime1;
    cout << "Default Constructor" << endl;
    cout << "Hour: " << testTime1.GetHour() << endl;
    cout << "Minute: " << testTime1.GetMinute() << endl << endl;

    Time testTime2(1,1);
    cout << "Constructor" << endl;
    cout << "Hour: " << testTime2.GetHour() << endl;
    cout << "Minute: " << testTime2.GetMinute() << endl << endl;

    //Check that setters are working correctly
    testTime2.SetHour(3);
    testTime2.SetMinute(3);

    cout << "Test Setters" << endl;
    cout << "Hour: " << testTime2.GetHour() << endl;
    cout << "Minute: " << testTime2.GetMinute() << endl << endl;

    return 0;
}