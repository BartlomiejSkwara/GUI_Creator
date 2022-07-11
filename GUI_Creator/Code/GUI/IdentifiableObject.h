#pragma once
#include <string>
#include <iostream>
class IdentifiableObject
{
private:
	std::string m_ID;

	static std::string generatedID;
public:

	IdentifiableObject();
	IdentifiableObject(const std::string ID) ; ///Todo przeka¿ przez referencjê
	virtual ~IdentifiableObject();

	const std::string& getID() const;
	static std::string generateID();
};

