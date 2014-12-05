#include "TimeCardTransaction.h"
#include "PayrollDatabase.h"
#include "HourlyClassification.h"
#include "TimeCard.h"

TimeCardTransaction::TimeCardTransaction(const Date &date, double hours, int empId) 
    : m_date(date), m_hours(hours), m_empid(empId)
{}

void TimeCardTransaction::Execute()
{
	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(m_empid);
    if (e == nullptr)
        throw std::logic_error( "Работник не найден." );
    
    HourlyClassification *hc = dynamic_cast<HourlyClassification*>(e->getClassification());
    if( hc == nullptr )
        throw std::logic_error( "Попытка добавить карточку табельного учёта для"
                "работника не на почасовой оплате." );
    
    hc->AddTimeCard(new TimeCard(m_date, m_hours));
}
