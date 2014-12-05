#include "ChangeClassificationTransaction.h"
#include "Employee.h"

ChangeClassificationTransaction::ChangeClassificationTransaction(int id) 
    : ChangeEmployeeTransaction(id)
{
}

void ChangeClassificationTransaction::Change(TEmployee e)
{
    e->setClassification( getClassification() );
    e->setSchedule( getSchedule() );
}
