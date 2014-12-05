/* 
 * File:   Date.cpp
 * Author: denis
 * 
 * Created on 23 октября 2014 г., 20:52
 */

#include "Date.h"
#include <stdexcept>

Date::Date() : m_day( 1 ), m_month( 1 ), m_year( 1900 )
{}

Date::Date( int day, int month, int year )
{
    if( !isValidDate( day, month, year ) )
        throw std::logic_error( "Введена неверная дата" );
    
    m_day = day;
    m_month = month;
    m_year = year;
}

Date::Date( const Date &date )
{
    m_day = date.m_day;
    m_month = date.m_month;
    m_year = date.m_year;
}

bool Date::isLeap( int year ) const
{
    return ( year % 4 == 0 && year % 100 != 0 ) || ( year % 400 == 0 );
}

int Date::getDaysInMonth( int month, int year ) const
{
    int days = 31;
    switch ( month )
    {
        case 2:
            days = isLeap( year ) ? 29 : 28;
            break;
            
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
    }
    return days;
}

bool Date::isValidDay( int day, int month, int year ) const
{
    return day >= 1 && day <= getDaysInMonth( month, year );
}

bool Date::isInPeriod( const Date &startPeriod, const Date &endPeriod )
{
    return ( (*this) >= startPeriod ) && ( (*this) <= endPeriod );
}

int Date::DayOfWeek() const 
{
    int a = ( 14 - m_month ) / 12;
    int y = m_year - a;
    int m = m_month + 12 * a - 2;
    
    int dayOfWeek = ( 7000 + ( m_day + y + y / 4 - y / 100 + y / 400 + ( 31 * m ) / 12 ) ) % 7;
    return dayOfWeek == 0 ? 7 : dayOfWeek;
}

Date Date::DayWasWeekAgo() const
{
    int newDay = m_day - 6;
    if ( newDay > 0 )
        return Date( newDay, m_month, m_year );
    
    // Вычитаем из предыдущего месяца
    // Текущий месяц не январь
    if ( m_month != 1 )
    {
        newDay = getDaysInMonth( m_month - 1, m_year ) - ( -newDay );
        return Date( newDay, m_month - 1, m_year );
    }
    
    // Текущий месяц январь. Придется вычитать ещё и год.
    if ( m_year == 1900 )
        throw std::logic_error( "Попытка создать дату меньше 1.1.1900" );
    
    newDay = 31 - ( -newDay );
    return Date( newDay, 12, m_year - 1 );
}

Date Date::nextDate( const Date& date ) 
{
    if ( m_day != getDaysInMonth( m_month, m_year ) )
        return Date( m_day + 1, m_month, m_year );
    
    if ( m_month != 12 )
        return Date( 1, m_month + 1, m_year );
    
    return Date( 1, 1, m_year + 1 );
}

Date Date::operator++() 
{
    *this = nextDate( *this );
    return *this;
}


bool operator<( Date const &date1, Date const &date2 )
{
    if ( date1.m_year < date2.m_year )
        return true;
    
    if ( date1.m_year == date2.m_year )
        if ( date1.m_month < date2.m_month)
            return true;
    
    if ( date1.m_year == date2.m_year && date1.m_month == date2.m_month )
        if ( date1.m_day < date2.m_day )
            return true;
    
    return false;
}

bool operator==( Date const &date1, Date const &date2 )
{
    if ( date1.m_year == date2.m_year && date1.m_month == date2.m_month && date1.m_day == date2.m_day )
        return true;
    
    return false;
}

bool operator>=( Date const &date1, Date const &date2 )
{
    return !( date1 < date2 );
}

bool operator<=( Date const &date1, Date const &date2 )
{
    return !( date2 < date1 );
}
