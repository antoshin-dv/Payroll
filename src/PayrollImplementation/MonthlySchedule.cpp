/* 
 * File:   MonthlySchedule.cpp
 * Author: denis
 * 
 * Created on 21 октября 2014 г., 19:57
 */

#include "MonthlySchedule.h"

MonthlySchedule::MonthlySchedule() {
}

bool MonthlySchedule::IsPayDate( const Date &date ) const
{
    return date.isLastDayOfMonth();
}

Date MonthlySchedule::GetPayPeriodStartDate( const Date& date ) 
{
    return Date( 1, date.getMonth(), date.getYear() );
}

