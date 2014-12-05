#include "ChangeAddressTransaction.h"
#include "Employee.h"

ChangeAddressTransaction::ChangeAddressTransaction(int id, const std::string &address)
    : ChangeEmployeeTransaction(id), m_newAddress(address)
{
}

void ChangeAddressTransaction::Change( TEmployee e )
{
    e->setAddress(m_newAddress);
}
