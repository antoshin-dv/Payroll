#ifndef PAYROLL_DATABASE_H
#define	PAYROLL_DATABASE_H

#include <map>
#include <vector>
#include <memory>
#include "Employee.h"

#include <iostream>

class PayrollDatabase 
{
private:
	typedef std::shared_ptr<Employee> TPtr;
	typedef std::map<int, TPtr> TDataBase;

public:
	static PayrollDatabase& instance()
	{
		static PayrollDatabase p;
		return p;
	}

	void AddEmployee(int id, Employee* employee) { m_employees[id] = TPtr(employee); }
    
	std::shared_ptr<Employee> GetEmployee(int id) 
	{ 
		return m_employees[id];
	}
    
    void DeleteEmployee(int id) { m_employees.erase(id); }
    
//    static void DeleteAllEmploye()
//    {
//        for( auto it = m_employees.begin(); it != m_employees.end(); ++it )
//            delete (*it).second;
//        m_employees.clear();
//    }
    
   void GetAllEmployeeIds(std::vector<int> &ids)
   {
       for (auto it = m_employees.begin(); it != m_employees.end(); ++it)
           ids.push_back(it->first);
   }
    
    void AddUnionMember(int id, TPtr employee) { m_unionMember[id] = employee; }
    
	std::shared_ptr<Employee> GetUnionMember(int id) { return m_unionMember[id]; }
    
    void RemoveUnionMember(int id) { m_unionMember.erase( id ); }
    
private:
    TDataBase m_unionMember;
    TDataBase m_employees;
};

#endif	/* PAYROLL_DATABASE_H */

