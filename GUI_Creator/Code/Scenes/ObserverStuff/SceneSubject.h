#pragma once
#include <vector>
#include "ObserverScene.h"
#include "../GUI_Creator/Code/GUI/Parents/Object.h"
class SceneSubject
{
private:
	std::vector<ObserverScene*> observers;
public :
	SceneSubject();
	~SceneSubject();

	void addObserver(ObserverScene* obs);
	void removeObserver(ObserverScene* obs);

	void notify(EventType event);
};

