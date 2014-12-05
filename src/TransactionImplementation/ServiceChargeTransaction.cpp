/* 
 * File:   ServiceChargeTransaction.cpp
 * Author: denis
 * 
 * Created on 23 октября 2014 г., 10:50
 */

#include "ServiceChargeTransaction.h"
#include "Employee.h"
#include "PayrollDatabase.h"
#include "UnionAffiliation.h"
#include "ServiceCharge.h"

#include <iostream>

ServiceChargeTransaction::ServiceChargeTransaction( int id, const Date &date, double charge )
    : m_memberId( id ), m_date( date ), m_charge( charge )
{
}

void ServiceChargeTransaction::Execute()
{
    std::shared_ptr<Employee> e = PayrollDatabase::instance().GetUnionMember( m_memberId );
    if (e == nullptr)
        throw std::logic_error( "Член профсоюза не найден" );
    
    UnionAffiliation *ua = dynamic_cast<UnionAffiliation*>(e->getAffiliation());
	if (ua == nullptr)
        throw std::logic_error( "Попытка добавить плату за услуги для членов не входящих в профсоюз" );
    
   ua->AddServiceCharge(new ServiceCharge( m_date, m_charge ));
}