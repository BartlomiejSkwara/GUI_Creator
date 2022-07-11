#pragma once
#include "BorderedObject.h"
#include "RenderableObject.h"
#include "ClickableObject.h"


typedef int OBJECT_TYPE;
class ContainerObject :
    virtual public BorderedObject
{
private:
	

public:
	
	static const OBJECT_TYPE O_RENDERABLE = 1;
	static const OBJECT_TYPE O_CLICKABLE  = 2;
	static const OBJECT_TYPE O_CONTAINER  = 4;

	ContainerObject();
	virtual ~ContainerObject();

	//Poszukiwanie elementów
	virtual int searchForObject(std::string & ID, OBJECT_TYPE searchMode) = 0; //Todo referencja i string



	//Funkcje odpowiedzialne za dodawanie i usuwanie obiektów z kontenarów
	virtual void addRenderableObject(RenderableObject* object) = 0;
	virtual void addClickableObject(ClickableObject* object) = 0;
	virtual void addContainerObject(ContainerObject* object) = 0;
	

	virtual bool removeObject(std::string & ID,int depth=0) = 0;

	
};

