#include "ChangeSalariedTransaction.h"
#include "SalariedClassification.h"
#include "MonthlySchedule.h"

ChangeSalariedTransaction::ChangeSalariedTransaction(int id, double salary)
	: ChangeClassificationTransaction(id), m_salary(salary)
{}

PaymentClassification *ChangeSalariedTransaction::getClassification()
{
	return new SalariedClassification(m_salary);
}

PaymentSchedule *ChangeSalariedTransaction::getSchedule()
{
	return new MonthlySchedule();
}
