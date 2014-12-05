/* 
 * File:   TimeCard.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 22:27
 */

#ifndef TIMECARD_H
#define	TIMECARD_H

#include "Date.h"

class TimeCard {
public:
    TimeCard( const Date &date, double hours );
    
    double getHours() const { return m_hours; }
    Date getDate() const { return m_date; }
    
private:
    Date m_date;
    double m_hours;
};

#endif	/* TIMECARD_H */
