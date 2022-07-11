#include "IdentifiableObject.h"

std::string IdentifiableObject::generatedID = "@AAAA";

IdentifiableObject::IdentifiableObject() 
{
	//Now Id generates at the object creation
	m_ID = (IdentifiableObject::generatedID);

}

IdentifiableObject::IdentifiableObject(std::string ID) : m_ID(ID)
{
	
}

IdentifiableObject::~IdentifiableObject()
{
}



const std::string& IdentifiableObject::getID() const 
{
	return m_ID;
}

std::string IdentifiableObject::generateID()
{
	
	generatedID[0]++;
	for (int i = 1; i<5 ;i++)
	{
		if (generatedID[i - 1] >= 'Z'+1) {
			generatedID[i - 1] = 'A';
			generatedID[i]++;
		}
		
	}
	
	return generatedID;
}

