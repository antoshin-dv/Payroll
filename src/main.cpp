#include "Date.h"
#include "PaymentSchedule.h"
#include "Paycheck.h"
#include "SalariedClassification.h"
#include "MonthlySchedule.h"
#include "UnionAffiliation.h"
#include "PayrollDatabase.h"
#include "AddHourlyEmployee.h"
#include "AddSalariedEmployee.h"
#include "ServiceChargeTransaction.h"

#include <iostream>

int main(int argc, char *argv[])
{
	try
	{
		int empId = 2;
		AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
		t.Execute();

		std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
		UnionAffiliation *uf = new UnionAffiliation(84, 32.1);
		e->setAffiliation(uf);
		int memberId = 84;
		PayrollDatabase::instance().AddUnionMember(memberId, e);

		Date date(16, 2, 2014);
		ServiceChargeTransaction sct(memberId, date, 12.95);
		sct.Execute();
	}
	catch (std::runtime_error &err)
	{
		std::cout << err.what() << std::endl;
	}
	int n;
	std::cin >> n;
	return 0;
}