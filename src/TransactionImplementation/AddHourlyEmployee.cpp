/* 
 * File:   AddHourlyEmployee.cpp
 * Author: denis
 * 
 * Created on 21 октября 2014 г., 21:30
 */

#include "AddHourlyEmployee.h"
#include "HourlyClassification.h"
#include "WeeklySchedule.h"
#include "HoldMethod.h"

AddHourlyEmployee::AddHourlyEmployee(
    int id, const std::string &name, const std::string &address, double hourly)
    : AddEmployeeTransaction( id, name, address ), m_hourly( hourly )
{
}

PaymentClassification *AddHourlyEmployee::MakeClassification()
{
	return new HourlyClassification(m_hourly);
}

PaymentSchedule *AddHourlyEmployee::MakeSchedule()
{
	return new WeeklySchedule;
}

PaymentMethod * AddHourlyEmployee::MakeMethod()
{
	return new HoldMethod;
}
