#pragma once

template <class T>
class CSingleton {
public:
	static T* getInstance() {
		if (s_instance == nullptr) {
			s_instance = new T();
		}
		return s_instance;
	}

	static bool hasInstance() {
		return s_instance != nullptr;
	}

	static void freeInstance() {
		if (s_instance) {
			delete s_instance;
		}
	}
protected:
	CSingleton(){}
	virtual ~CSingleton() {
		delete s_instance;
	}
private:
	static T* s_instance;
};

template <class T> T* CSingleton<T>::s_instance = nullptr;