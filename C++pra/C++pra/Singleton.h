#pragma once
#include<iostream>
template <class T>
class Singleton
{
public:
	static T* GetInstance()
	{
		return pInstance;
	}

	static void Create()
	{
		if (pInstance != NULL) return;
		pInstance = new T();
	}

	static void Destroy()
	{
		delete pInstance;
		pInstance = NULL;
	}
protected:
	static T *pInstance;
	Singleton() {};
	virtual ~Singleton() {};
private:
	void operator = (const Singleton& obj) {}
	Singleton(const Singleton &obj) {}
};
template<class T>
static T* Singleton<T>::GetInstance();
template<class T>
static void Singleton<T>::Create();
template<class T>
static void Singleton<T>::Destroy();
template<class T>
T* Singleton<T>::pInstance;