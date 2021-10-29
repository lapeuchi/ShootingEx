#pragma once

template <class T>

class SingleTon
{
private:
	static T* m_Single;

public:
	SingleTon();
	virtual ~SingleTon()
	{
		delete m_Single;
	}

	static T* GetInstance()
	{
		if (m_Single == NULL)
		{
			m_Single = new T();
		}
		return m_Single;
	}
};

template <class T> T* SingleTon<T>::m_Single = 0;