#include "Object.h"

Object::Object() :Identifiable(), Bordered()
{
	
}

Object::~Object()
{
}


/// <summary>
/// Function finds and returns  the object you are looking for
/// </summary>
/// <param name="soughtObj">adress in memory of sought obj</param>
/// <param name="retrieve">if set to true sought element will be removed from the object containing it (but it will still exist in memory)</param>
/// <returns></returns>
Object* Object::find(Object* soughtObj, FindMode fm)
{

	return (soughtObj==this)?soughtObj:nullptr;
}



