#pragma once
using namespace std;
template <class T>
class Nodo
{
private:
	T elem;
	int factor;
	Nodo<T>* izq;
	Nodo<T>* der;
public:
	Nodo();
	~Nodo();
	void setIzq(Nodo<T>* izq);
	void setDer(Nodo<T>* der);
	void setElem(T elem);
	void setFactor(int f);
	Nodo<T>*& getIzq();
	Nodo<T>*& getDer();
	T getElem();
	int getFactor();
};

template<class T>
inline Nodo<T>::Nodo()
{
	izq = nullptr;
	der = nullptr;
	factor = 0;
}

template<class T>
inline Nodo<T>::~Nodo()
{
}

template<class T>
inline void Nodo<T>::setIzq(Nodo<T>* izq)
{
	this->izq = izq;
}

template<class T>
inline void Nodo<T>::setDer(Nodo<T>* der)
{
	this->der = der;
}

template<class T>
inline void Nodo<T>::setElem(T elem)
{
	this->elem = elem;
}

template<class T>
inline void Nodo<T>::setFactor(int f)
{
	factor = f;
}

template<class T>
inline Nodo<T>*& Nodo<T>::getIzq()
{
	return izq;
}

template<class T>
inline Nodo<T>*& Nodo<T>::getDer()
{
	return der;
}

template<class T>
inline T Nodo<T>::getElem()
{
	return elem;
}

template<class T>
inline int Nodo<T>::getFactor()
{
	return factor;
}
