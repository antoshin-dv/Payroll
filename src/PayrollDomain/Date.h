/* 
 * File:   Date.h
 * Author: denis
 *
 * Created on 23 октября 2014 г., 20:52
 */

#ifndef DATE_H
#define	DATE_H

class Date
{
public:
    Date();
    Date( int day, int month, int year );
    Date( const Date &date );
    
    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
    
    bool isLastDayOfMonth() const { return m_day == getDaysInMonth( m_month, m_year ); }
    
    // Вывести день недели для данной даты
    int DayOfWeek() const;
    
    Date DayWasWeekAgo() const;
    
    bool isInPeriod( const Date &startPeriod, const Date &endPeriod );
    
    Date operator ++();
    
    friend bool operator<( Date const &date1, Date const &date2 );
    friend bool operator==( Date const &date1, Date const &date2 );
    friend bool operator>=( Date const &date1, Date const &date2 );
    friend bool operator<=( Date const &date1, Date const &date2 );
    
private:
    // Високосный год?
    bool isLeap( int year ) const;
    
    // Количество дней в месяце
    int getDaysInMonth( int month, int year ) const;
    
    bool isValidDay( int day, int month, int year ) const;

    bool isValidMonth( int month ) const { return month >= 1 && month <= 12; }
    
    bool isValidYear( int year ) const { return year >= 1900; }
    
    bool isValidDate( int day, int month, int year ) const 
        { return isValidDay( day, month, year ) && isValidMonth( month ) && isValidYear( year ); }
    
    Date nextDate( const Date &date );
    
    int m_year;
    int m_month;
    int m_day;
};

#endif	/* DATE_H */

