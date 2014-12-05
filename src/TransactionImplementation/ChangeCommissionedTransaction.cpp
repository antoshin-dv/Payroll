#include "ChangeCommissionedTransaction.h"
#include "CommissionedClassification.h"
#include "BiweeklySchedule.h"

ChangeCommissionedTransaction::ChangeCommissionedTransaction(int id, double salary, double commissionRate)
	: ChangeClassificationTransaction(id), m_salary(salary), m_commissionRate(commissionRate)
{}

PaymentClassification *ChangeCommissionedTransaction::getClassification()
{
	return new CommissionedClassification(m_salary, m_commissionRate);
}

PaymentSchedule *ChangeCommissionedTransaction::getSchedule()
{
	return new BiweeklySchedule();
}
