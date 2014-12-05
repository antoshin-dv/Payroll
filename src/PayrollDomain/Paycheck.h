/* 
 * File:   Paycheck.h
 * Author: denis
 *
 * Created on 25 октября 2014 г., 17:33
 */

#ifndef PAYCHECK_H
#define	PAYCHECK_H

#include <map>
#include "Date.h"

class Paycheck {
public:
    Paycheck( const Date &payPeriodStartDate, const Date &payDate );
    
    Date getPayDate() const { return m_payDate; }
    
    Date PayPeriodStartDate() const { return m_payPeriodStartDate; }
    
    Date PayPeriodEndDate() const { return m_payDate; }
    
    void setGrossPay( double grossPay ) { m_grossPay = grossPay; }
    double getGrossPay() const { return m_grossPay; }
    
    void setDeductions( double deductions ) { m_deductions = deductions; }
    double getDeductions() const { return m_deductions; }
    
    void setNetPay( double netPay ) { m_netPay = netPay; }
    double getNetPay() const { return m_netPay; }
    
    void setField( const std::string &fieldName, const std::string &value )
    {
        m_fields[fieldName] = value;
    }
    
    std::string getField(const std::string &fieldName ) { return m_fields[fieldName]; }
    
private:
    Date m_payDate;
    Date m_payPeriodStartDate;
    double m_grossPay;
    double m_deductions;
    double m_netPay;
    std::map<std::string, std::string> m_fields;
};

#endif	/* PAYCHECK_H */

