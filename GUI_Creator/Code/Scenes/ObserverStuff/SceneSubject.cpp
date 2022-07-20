#include "SceneSubject.h"

SceneSubject::SceneSubject()
{
}

SceneSubject::~SceneSubject()
{
	for (auto ptr:observers) {
		delete ptr;
	}
}

void SceneSubject::addObserver(ObserverScene* obs)
{
	observers.push_back(obs);
}

void SceneSubject::removeObserver(ObserverScene* obs)
{
	
	int position;
	ObserverScene* temp = nullptr;
	for (std::size_t i = 0; i < observers.size(); i++)
	{
		if (observers[i]==obs)
		{
			temp = observers[i];
			observers.at(i) = observers.back();
			observers.back() = temp;
			observers.pop_back();
			delete temp;
			break;
		}
	}
}

void SceneSubject::notify(EventType event)
{
	for (auto ptr : observers)
	{
		ptr->onNotify(event);
	}
}
