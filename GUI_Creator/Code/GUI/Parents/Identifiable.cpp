#include "Identifiable.h"

std::string Identifiable::generatedID = "@AAAA";

Identifiable::Identifiable(): 
	m_ID(Identifiable::generateID())
{

}

Identifiable::Identifiable(std::string ID) : m_ID(ID)
{
	
}

Identifiable::~Identifiable()
{
}



const std::string& Identifiable::getID() const 
{
	return m_ID;
}

std::string Identifiable::generateID()
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

void Identifiable::resetID()
{
	generatedID = "@AAAA";
}

