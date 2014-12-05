/* 
 * File:   ChangeHourlyTransaction.cpp
 * Author: denis
 * 
 * Created on 23 октября 2014 г., 12:54
 */

#include "ChangeHourlyTransaction.h"
#include "HourlyClassification.h"
#include "WeeklySchedule.h"

ChangeHourlyTransaction::ChangeHourlyTransaction( int id, double hourlyRate )
    : ChangeClassificationTransaction( id ), m_hourlyRate( hourlyRate )
{}

PaymentClassification *ChangeHourlyTransaction::getClassification()
{
    return new HourlyClassification( m_hourlyRate );
}

PaymentSchedule *ChangeHourlyTransaction::getSchedule()
{
    return new WeeklySchedule();
}
