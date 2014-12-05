#include "Employee.h"
#include "PayrollDatabase.h"

#include "AddSalariedEmployee.h"
#include "AddHourlyEmployee.h"
#include "AddCommissionedEmployee.h"
#include "DeleteEmployeeTransaction.h"
#include "TimeCardTransaction.h"
#include "SalesReceiptTransaction.h"
#include "ServiceChargeTransaction.h"
#include "ChangeNameTransaction.h"
#include "ChangeAddressTransaction.h"
#include "ChangeHourlyTransaction.h"
#include "ChangeSalariedTransaction.h"
#include "ChangeCommissionedTransaction.h"
#include "ChangeMemberTransaction.h"
#include "ChangeUnaffiliatedTransaction.h"
#include "PaydayTransaction.h"

#include "SalariedClassification.h"
#include "HourlyClassification.h"
#include "CommissionedClassification.h"

#include "MonthlySchedule.h"
#include "WeeklySchedule.h"
#include "BiweeklySchedule.h"

#include "HoldMethod.h"
#include "TimeCard.h"
#include "UnionAffiliation.h"
#include "NoAffiliation.h"
#include "ServiceCharge.h"

#define BOOST_TEST_MODULE testPayroll
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(TestClassDate)
{
	Date date(3, 1, 2014);
	BOOST_CHECK_EQUAL(date.getDay(), 3);
	BOOST_CHECK_EQUAL(date.getMonth(), 1);
	BOOST_CHECK_EQUAL(date.getYear(), 2014);
	BOOST_CHECK(!date.isLastDayOfMonth());
	BOOST_CHECK_EQUAL(date.DayOfWeek(), 5);

	Date date1 = date.DayWasWeekAgo();
	BOOST_CHECK_EQUAL(date1.getDay(), 28);
	BOOST_CHECK_EQUAL(date1.getMonth(), 12);
	BOOST_CHECK_EQUAL(date1.getYear(), 2013);
}

BOOST_AUTO_TEST_CASE(TestAddSalariedEmployee)
{
	int empId = 1;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000.0);
	t.Execute();

	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK_EQUAL(e->getName(), "Bob");
	
	SalariedClassification *sc = dynamic_cast<SalariedClassification*>(e->getClassification());
	BOOST_CHECK(sc != NULL);
	BOOST_CHECK_EQUAL(sc->getSalary(), 1000.0);

	MonthlySchedule *ms = dynamic_cast<MonthlySchedule*>(e->getSchedule());
	BOOST_CHECK(ms != NULL);

	HoldMethod *hm = dynamic_cast<HoldMethod*>(e->getMethod());
	BOOST_CHECK(hm != NULL);
}

BOOST_AUTO_TEST_CASE(TestAddHourlyEmployee)
{
	int empId = 2;
	AddHourlyEmployee h(empId, "Martin", "Home", 10.9);
	h.Execute();

	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK_EQUAL(e->getName(), "Martin");

	HourlyClassification *hc = dynamic_cast<HourlyClassification*>(e->getClassification());
	BOOST_CHECK(hc != NULL);
	BOOST_CHECK_EQUAL(hc->getHourly(), 10.9);

	WeeklySchedule *ws = dynamic_cast<WeeklySchedule*>(e->getSchedule());
	BOOST_CHECK(ws != NULL);

	HoldMethod *hm = dynamic_cast<HoldMethod*>(e->getMethod());
	BOOST_CHECK(hm != NULL);
}

BOOST_AUTO_TEST_CASE(TestAddCommissionedEmployee)
{
	int empId = 3;
	AddCommissionedEmployee h(empId, "Pit", "Home", 1000.0, 5.1);
	h.Execute();

	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK_EQUAL(e->getName(), "Pit");

	CommissionedClassification *cc = dynamic_cast<CommissionedClassification*>(e->getClassification());
	BOOST_CHECK(cc != NULL);
	BOOST_CHECK_EQUAL(cc->getBaseRate(), 1000.0);
	BOOST_CHECK_EQUAL(cc->getCommissionRate(), 5.1);

	BiweeklySchedule *bs = dynamic_cast<BiweeklySchedule*>(e->getSchedule());
	BOOST_CHECK(bs != NULL);

	HoldMethod *hm = dynamic_cast<HoldMethod*>(e->getMethod());
	BOOST_CHECK(hm != NULL);
}

BOOST_AUTO_TEST_CASE(TestDeleteEmployee)
{
	int empId = 4;
	AddCommissionedEmployee c(empId, "Bill", "Home", 2500, 3.2);
	c.Execute();
	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK(e != NULL);

	DeleteEmployeeTransaction et(empId);
	et.Execute();

	e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK(e == NULL);
}

BOOST_AUTO_TEST_CASE(TestTimeCardTransaction)
{
	int empId = 5;
	AddHourlyEmployee h(empId, "Bill", "Home", 15.23);
	h.Execute();

	Date date(15, 7, 2014);
	TimeCardTransaction tct(date, 8, empId);
	tct.Execute();

	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK(e != NULL);

	PaymentClassification *pc = e->getClassification();
	HourlyClassification *hc = dynamic_cast<HourlyClassification*>(pc);
	BOOST_CHECK(hc != NULL);

	TimeCard *tc1 = hc->GetTimeCard(date);
	BOOST_CHECK(tc1 != NULL);
	BOOST_CHECK_EQUAL(tc1->getHours(), 8);
}

BOOST_AUTO_TEST_CASE(TestSalesReceiptTransaction)
{
	int empId = 6;
	AddCommissionedEmployee h(empId, "Bill", "Home", 15000, 12.3);
	h.Execute();

    Date date(31, 7, 2014);
	SalesReceiptTransaction srt(date, 15000, empId);
	srt.Execute();

	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK(e != NULL);

	CommissionedClassification *cc = dynamic_cast<CommissionedClassification*>(e->getClassification());
	BOOST_CHECK(cc != NULL);

	SalesReceipt *sr = cc->GetSalesReceipt(date);
	BOOST_CHECK( sr != NULL );
	BOOST_CHECK_EQUAL( sr->getAmount(), 15000 );
}

BOOST_AUTO_TEST_CASE(TestAddServiceCharge)
{
    int empId = 2;
    AddHourlyEmployee t( empId, "Bill", "Home", 15.25 );
    t.Execute();
    
    std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee( empId );
    BOOST_CHECK( e != NULL );
    
    UnionAffiliation *uf = new UnionAffiliation(84, 32.1);
    e->setAffiliation(uf);
    int memberId = 84;
    PayrollDatabase::instance().AddUnionMember(memberId, e);
     
    Date date(16, 2, 2014);
    ServiceChargeTransaction sct(memberId, date, 12.95);
    sct.Execute();
    
    const ServiceCharge *sc = uf->getServiceCharge(date);
    BOOST_CHECK(sc != NULL);
    BOOST_CHECK_EQUAL(sc->getAmount(), 12.95);
}

BOOST_AUTO_TEST_CASE(TestChangeNameTransaction)
{
	int empId = 2;
	AddHourlyEmployee h(empId, "Bill", "Home", 15.25);
	h.Execute();

	ChangeNameTransaction cnt(empId, "Bob");
	cnt.Execute();

	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK(e != NULL);
	BOOST_CHECK_EQUAL(e->getName(), "Bob");
}

BOOST_AUTO_TEST_CASE(TestChangeAddressTransaction)
{
	int empId = 2;
	AddHourlyEmployee h(empId, "Bill", "Home", 15.25);
	h.Execute();

	ChangeAddressTransaction cat(empId, "Street");
	cat.Execute();

	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK(e != NULL);
	BOOST_CHECK_EQUAL(e->getName(), "Bill");
}

BOOST_AUTO_TEST_CASE(TestChangeHourlyTransaction)
{
	int empId = 5;
	AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
	t.Execute();

	ChangeHourlyTransaction cht(empId, 27.52);
	cht.Execute();
	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK(e != NULL);

	PaymentClassification *pc = e->getClassification();
	BOOST_CHECK(pc != NULL);

	HourlyClassification *hc = dynamic_cast<HourlyClassification*>(pc);
	BOOST_CHECK(hc != NULL);
	BOOST_CHECK_EQUAL(hc->getHourly(), 27.52);

	WeeklySchedule *ws = dynamic_cast<WeeklySchedule*>(e->getSchedule());
	BOOST_CHECK(ws != NULL);
}

BOOST_AUTO_TEST_CASE(TestChangeSalariedTransaction)
{
	int empId = 4;
	AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
	t.Execute();

	ChangeSalariedTransaction cst(empId, 27.52);
	cst.Execute();
	
	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK(e != NULL);
	PaymentClassification *pc = e->getClassification();
	BOOST_CHECK(pc != NULL);

	SalariedClassification *sc = dynamic_cast<SalariedClassification*>(pc);
	BOOST_CHECK(sc != NULL);
	BOOST_CHECK_EQUAL(sc->getSalary(), 27.52);
	
	MonthlySchedule *ms = dynamic_cast<MonthlySchedule*>(e->getSchedule());
	BOOST_CHECK(ms != NULL);
}

BOOST_AUTO_TEST_CASE(TestChangeCommisionTransaction)
{
	int empId = 5;
	AddSalariedEmployee t(empId, "Bob", "Home", 2500.00);
	t.Execute();

	ChangeCommissionedTransaction cht(empId, 1250.00, 5.6);
	cht.Execute();

	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK(e != NULL);
	PaymentClassification *pc = e->getClassification();
	BOOST_CHECK(pc != NULL);

	CommissionedClassification *cc = dynamic_cast<CommissionedClassification*>(pc);
	BOOST_CHECK(cc != NULL);
	BOOST_CHECK_EQUAL(cc->getBaseRate(), 1250);
	BOOST_CHECK_EQUAL(cc->getCommissionRate(), 5.6);

	BiweeklySchedule *ms = dynamic_cast<BiweeklySchedule*>(e->getSchedule());
	BOOST_CHECK(ms != NULL);
}

BOOST_AUTO_TEST_CASE(TestChangeUnionMember)
{
	int empId = 9;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();

	int memberId = 643;
	ChangeMemberTransaction cmt(empId, memberId, 99.23);
	cmt.Execute();

	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK(e != NULL);

	Affiliation *aff = e->getAffiliation();
	BOOST_CHECK(aff != NULL);

	UnionAffiliation *uf = dynamic_cast<UnionAffiliation*>(aff);
	BOOST_CHECK(uf != NULL);
	BOOST_CHECK_EQUAL(uf->getDues(), 99.23);

	std::shared_ptr<Employee> member = PayrollDatabase::instance().GetUnionMember(memberId);
	BOOST_CHECK(member != NULL);
	BOOST_CHECK_EQUAL(member, e);
}

BOOST_AUTO_TEST_CASE(TestChangeUnaffiliatedMember)
{
	int empId = 10;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();
	
	int memberId = 7743;
	ChangeMemberTransaction cmt(empId, memberId, 99.42);
	cmt.Execute();

	ChangeUnaffiliatedTransaction cut(empId);
	cut.Execute();

	std::shared_ptr<Employee> e = PayrollDatabase::instance().GetEmployee(empId);
	BOOST_CHECK(e != NULL);

	Affiliation *aff = e->getAffiliation();
	BOOST_CHECK(aff != NULL);

	NoAffiliation *uf = dynamic_cast<NoAffiliation*>(aff);
	BOOST_CHECK(uf != NULL);

	std::shared_ptr<Employee> member = PayrollDatabase::instance().GetUnionMember(memberId);
	BOOST_CHECK(member == NULL);
}

BOOST_AUTO_TEST_CASE(TestPaySingleSalariedEmployee)
{
	int empId = 15;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000);
	t.Execute();

	Date payDate(31, 1, 2014);
	PaydayTransaction pt(payDate);
	pt.Execute();

	std::shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	BOOST_CHECK(pc != NULL);
	BOOST_CHECK(payDate == pc->getPayDate());
	BOOST_CHECK_EQUAL(pc->getGrossPay(), 1000);
	BOOST_CHECK_EQUAL(pc->getField("Disposition"), "Hold");
	BOOST_CHECK_EQUAL(pc->getDeductions(), 0);
	BOOST_CHECK_EQUAL(pc->getNetPay(), 1000);
}

BOOST_AUTO_TEST_CASE(TestPaySingleSalariedEmployeeOnWrongDate)
{
	int empId = 1;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000);
	t.Execute();

	Date payDate(30, 1, 2014);
	PaydayTransaction pt(payDate);
	pt.Execute();

	std::shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	BOOST_CHECK(pc == NULL);
}

void ValidateHourlyPaycheck(PaydayTransaction& pt, int empId, const Date& payDate, double pay)
{
	std::shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	BOOST_CHECK(pc != NULL);
	BOOST_CHECK(payDate == pc->getPayDate());
	BOOST_CHECK_EQUAL(pc->getGrossPay(), pay);
	BOOST_CHECK_EQUAL(pc->getField("Disposition"), "Hold");
	BOOST_CHECK_EQUAL(pc->getDeductions(), 0);
	BOOST_CHECK_EQUAL(pc->getNetPay(), pay);
}

BOOST_AUTO_TEST_CASE(TestPayingSingleHourlyEmployeeNoTimeCards)
{
	int empId = 2;
	AddHourlyEmployee t(empId, "Bob", "Home", 15.25);
	t.Execute();

	Date payDate(3, 1, 2014);
	PaydayTransaction pt(payDate);
	pt.Execute();

	ValidateHourlyPaycheck(pt, empId, payDate, 0.0);
}

BOOST_AUTO_TEST_CASE(TestPaySingleHourlyEmployeeOneTimeCard)
{
	int empId = 2;
	AddHourlyEmployee t(empId, "Bob", "Home", 15.25);
	t.Execute();

	Date payDate(3, 1, 2014);     // Пятница
	TimeCardTransaction tc(payDate, 2.0, empId);
	tc.Execute();

	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empId, payDate, 30.5);
}

BOOST_AUTO_TEST_CASE(TestPaySingleHourlyEmployeeOvertimeOneTimeCard)
{
	int empId = 2;
	AddHourlyEmployee t(empId, "Bob", "Home", 15.25);
	t.Execute();

	Date payDate(3, 1, 2014);     // Пятница
	TimeCardTransaction tc(payDate, 9.0, empId);
	tc.Execute();

	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empId, payDate, (8 + 1.5) * 15.25);
}

BOOST_AUTO_TEST_CASE(TestPaySingleHourlyEmployeeOnWrongDate)
{
	int empId = 2;
	AddHourlyEmployee t(empId, "Bob", "Home", 15.25);
	t.Execute();

	Date payDate(2, 1, 2014);     // Четверг
	TimeCardTransaction tc(payDate, 9.0, empId);
	tc.Execute();

	PaydayTransaction pt(payDate);
	pt.Execute();

	std::shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	BOOST_CHECK(pc == NULL);
}

BOOST_AUTO_TEST_CASE(TestPaySingleHourlyEmployeeTwoTimeCard)
{
	int empId = 2;
	AddHourlyEmployee t(empId, "Bob", "Home", 15.25);
	t.Execute();

	Date payDate(3, 1, 2014);     // Пятница
	TimeCardTransaction tc(payDate, 2.0, empId);
	tc.Execute();
	TimeCardTransaction tc1(Date(2, 1, 2014), 5.0, empId);
	tc1.Execute();

	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empId, payDate, 7 * 15.25);
}

BOOST_AUTO_TEST_CASE(TestPaySingleHourlyEmployeeWithTimeCardsSpanningTwoPayPeriods)
{
	int empId = 2;
	AddHourlyEmployee t(empId, "Bob", "Home", 15.25);
	t.Execute();

	Date payDate(3, 1, 2014);     // Пятница
	TimeCardTransaction tc(payDate, 2.0, empId);
	tc.Execute();
	TimeCardTransaction tc1(Date(4, 1, 2014), 5.0, empId);
	tc1.Execute();

	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empId, payDate, 2 * 15.25);
}

BOOST_AUTO_TEST_CASE(TestSalariedUnionMembersDues)
{
	int empId = 2;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000);
	t.Execute();

	int memberId = 234;
	ChangeMemberTransaction cmt(empId, memberId, 9.42);
	cmt.Execute();

	Date payDate(31, 12, 2013);
	PaydayTransaction pt(payDate);
	pt.Execute();

	std::shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	BOOST_CHECK(pc != NULL);
	BOOST_CHECK(pc->getPayDate() == payDate);
	BOOST_CHECK_EQUAL(pc->getGrossPay(), 1000);
	BOOST_CHECK_EQUAL(pc->getField("Disposition"), "Hold");
	BOOST_CHECK_EQUAL(pc->getDeductions(), 37.68);
	BOOST_CHECK_EQUAL(pc->getNetPay(), (1000 - 37.68));
}

BOOST_AUTO_TEST_CASE(TestHourlyUnionMemberServiceCharge)
{
	int empId = 1;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.24);
	t.Execute();

	int memberId = 1234;
	ChangeMemberTransaction cmt(empId, memberId, 9.42);
	cmt.Execute();

	Date payDate(3, 1, 2014);
	ServiceChargeTransaction sct(memberId, payDate, 19.42);
	sct.Execute();

	TimeCardTransaction tct(payDate, 8.0, empId);
	tct.Execute();

	PaydayTransaction pt(payDate);
	pt.Execute();
	
	std::shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	BOOST_CHECK(pc != NULL);
	BOOST_CHECK(pc->PayPeriodEndDate() == payDate);
	BOOST_CHECK_EQUAL(pc->getGrossPay(), 8 * 15.24);
	BOOST_CHECK_EQUAL(pc->getField("Disposition"), "Hold");
	BOOST_CHECK_EQUAL(pc->getDeductions(), 19.42 + 9.42);
	BOOST_CHECK_EQUAL(pc->getNetPay(), (8 * 15.24) - 19.42 - 9.42);
}

BOOST_AUTO_TEST_CASE(TestServiceChargeSpanningMultiplePayPeriod)
{
	int empId = 1;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.24);
	t.Execute();

	int memberId = 1234;
	ChangeMemberTransaction cmt(empId, memberId, 9.42);
	cmt.Execute();

	Date payDate(10, 1, 2014);
	Date earlyDate(3, 1, 2014);
	Date lateDate(17, 1, 2014);
	ServiceChargeTransaction sct(memberId, payDate, 19.42);
	sct.Execute();
	ServiceChargeTransaction sctEarly(memberId, earlyDate, 100);
	sctEarly.Execute();
	ServiceChargeTransaction sctLate(memberId, lateDate, 200);
	sctLate.Execute();

	TimeCardTransaction tct(payDate, 8, empId);
	tct.Execute();

	PaydayTransaction pt(payDate);
	pt.Execute();
	
	std::shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	BOOST_CHECK(pc != NULL);
	BOOST_CHECK(pc->PayPeriodEndDate() == payDate);
	BOOST_CHECK_EQUAL(pc->getGrossPay(), 8 * 15.24);
	BOOST_CHECK_EQUAL(pc->getField("Disposition"), "Hold");
	BOOST_CHECK_EQUAL(pc->getDeductions(), 19.42 + 9.42);
	BOOST_CHECK_EQUAL(pc->getNetPay(), (8 * 15.24) - 19.42 - 9.42);
}
