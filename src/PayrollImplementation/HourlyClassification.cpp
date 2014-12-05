/* 
 * File:   HourlyClassification.cpp
 * Author: denis
 * 
 * Created on 21 октября 2014 г., 21:35
 */

#include "HourlyClassification.h"
#include "TimeCard.h"
#include "Paycheck.h"

HourlyClassification::HourlyClassification(double hourly) : m_hourly(hourly)
{
}

HourlyClassification::~HourlyClassification()
{
    for( auto it = m_timeCards.begin(); it != m_timeCards.end(); ++it )
        delete (*it).second;
}

void HourlyClassification::AddTimeCard( TimeCard *card )
{
    m_timeCards[card->getDate()] = card;
}

TimeCard *HourlyClassification::GetTimeCard( const Date &date )
{
    return m_timeCards[date];
}

double HourlyClassification::CalculatePay( Paycheck* paycheck )
{
    double totalPay = 0.0;
    for ( auto it = m_timeCards.begin(); it != m_timeCards.end(); ++it )
    {
        Date date = it->first;
        TimeCard *card = it->second;
        if ( date.isInPeriod( paycheck->PayPeriodStartDate(), paycheck->PayPeriodEndDate() ) )
            totalPay += CalculatePayForTimeCard( card );
    }
    return totalPay;
}

double HourlyClassification::CalculatePayForTimeCard( TimeCard *card )
{
    double overtimeHours = ( card->getHours() - 8 ) > 0 ? ( card->getHours() - 8 ) : 0.0;
    double normalHours = card->getHours() - overtimeHours;
    return m_hourly * normalHours + m_hourly * 1.5 * overtimeHours;
}
