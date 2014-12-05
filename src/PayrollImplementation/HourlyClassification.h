/* 
 * File:   HourlyClassification.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 21:35
 */

#ifndef HOURLYCLASSIFICATION_H
#define	HOURLYCLASSIFICATION_H

#include "PaymentClassification.h"
#include <map>
#include "Date.h"

class TimeCard;

class HourlyClassification : public PaymentClassification
{
public:
    HourlyClassification(double hourly);
    ~HourlyClassification();
    
    void setHourly( double hourly ) { m_hourly = hourly; }
    double getHourly() const { return m_hourly; }
    
    void AddTimeCard( TimeCard *timeCard );
    TimeCard *GetTimeCard( const Date &date );
    
    double CalculatePay( Paycheck *paycheck ) override;

private:
    double CalculatePayForTimeCard( TimeCard *card );
    
    double m_hourly;
    std::map<Date, TimeCard*> m_timeCards;
};

#endif	/* HOURLYCLASSIFICATION_H */

