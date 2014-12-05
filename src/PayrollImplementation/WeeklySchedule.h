/* 
 * File:   WeeklySchedule.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 21:40
 */

#ifndef WEEKLYSCHEDULE_H
#define	WEEKLYSCHEDULE_H

#include "PaymentSchedule.h"

class WeeklySchedule : public PaymentSchedule
{
public:
	WeeklySchedule() {};
    
	bool IsPayDate(const Date& date) const override { return date.DayOfWeek() == 5; }
    
    Date GetPayPeriodStartDate( const Date &date ) override { return date.DayWasWeekAgo(); }
};

#endif	/* WEEKLYSCHEDULE_H */

