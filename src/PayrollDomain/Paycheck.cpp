/* 
 * File:   Paycheck.cpp
 * Author: denis
 * 
 * Created on 25 октября 2014 г., 17:33
 */

#include "Paycheck.h"

Paycheck::Paycheck( const Date &payPeriodStartDate, const Date &payDate ) 
    : m_payPeriodStartDate( payPeriodStartDate), m_payDate( payDate ),
      m_grossPay( 0 ), m_deductions( 0 ), m_netPay( 0 )
{}
