#pragma once
#include"stdafx.h"
class Subject;

class Obsever
{
public:
	virtual ~Obsever() {};
	virtual void Update() = 0;
	void SetSubject(Subject *pSub)
	{
		subject = pSub;
	}
protected:
	Subject *subject;
};

class Subject
{
public:
	virtual ~Subject()
	{
		std::list<Obsever *>::iterator it;
		for (it = obsevers.begin(); it != obsevers.end(); it++)
		{
			(*it)->SetSubject(NULL);
		}
	}

	virtual void AddObserver(Obsever *p)
	{
		obsevers.push_back(p);
	}

	virtual void Update()
	{
		std::list<Obsever *>::iterator it;
		for (it = obsevers.begin(); it != obsevers.end(); it++)
		{
			(*it)->SetSubject(NULL);
		}
	}
protected:
	std::list<Obsever *> obsevers;
};


