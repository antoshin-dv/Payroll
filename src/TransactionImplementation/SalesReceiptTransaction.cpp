/* 
 * File:   SalesReceiptTransaction.cpp
 * Author: denis
 * 
 * Created on 23 октября 2014 г., 1:10
 */

#include "SalesReceiptTransaction.h"
#include "CommissionedClassification.h"
#include "Employee.h"
#include "PayrollDatabase.h"

SalesReceiptTransaction::SalesReceiptTransaction( const Date &date, double amount, int empId )
    : m_date( date ), m_amount( amount ), m_empid( empId )
{
}

void SalesReceiptTransaction::Execute()
{
    std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee( m_empid );
    if ( e == nullptr )
        throw std::logic_error( "Работник не найден." );
    
    CommissionedClassification *cc = dynamic_cast<CommissionedClassification*>( e->getClassification() );
    if( cc == nullptr )
        throw std::logic_error( "Попытка регистрации справки о продажах для"
                "работника с некомиссионной оплатой." );
    
    cc->AddSalesReceipt( new SalesReceipt( m_date, m_amount ) );
}
