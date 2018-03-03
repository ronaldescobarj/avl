#pragma once
#include "Nodo.h"
template <class T>
class AVL
{
private:
	Nodo<T>* raiz;
public:
	AVL();
	~AVL();
	void insertar(T elem, Nodo<T>*& raiz, bool& continuar);
	void rotarDerechaSimple(Nodo<T>*& n);
	void rotarIzquierdaSimple(Nodo<T>*& n);
	void rotarDerechaComp(Nodo<T>*& n);
	void rotarIzquierdaComp(Nodo<T>*& n);
	Nodo<T>* buscar(T elem, Nodo<T>* raiz);
	void mostrarInorder(Nodo<T>* raiz);
	long calcularAltura(Nodo<T>* raiz);
	long contarNodos(Nodo<T>* raiz);
	T encontrarMax(Nodo<T>* raiz);
	T encontrarMin(Nodo<T>* raiz);
	void mostrarAncestros(Nodo<T>* raiz, T elem, bool b);
	void eliminarElem(T elem, Nodo<T>*& raiz, char& lado, bool& b);
	void podar(Nodo<T>*& n, int nivelApodar, int nivelActual);
	void espejo(Nodo<T>*& n);
	Nodo<T>*& getRaiz();
};

template<class T>
inline AVL<T>::AVL()
{
	raiz = nullptr;
}

template<class T>
inline AVL<T>::~AVL()
{
}

template<class T>
inline void AVL<T>::insertar(T elem, Nodo<T>*& raiz, bool& continuar)
{
	if (raiz == nullptr)
	{
		Nodo<T>* n = new Nodo<T>;
		n->setElem(elem);
		raiz = n;
		continuar = true;
	}
	else
	{
		if (elem < raiz->getElem())
		{
			insertar(elem, raiz->getIzq(), continuar);
			if (continuar)
			{
				raiz->setFactor(raiz->getFactor() + 1);
				if (raiz->getFactor() == 0)
					continuar = false;
				else
				{
					if (raiz->getFactor() == 2)
					{
						continuar = false;
						if (raiz->getIzq()->getFactor() == 1)
							rotarDerechaSimple(raiz);
						else
							rotarDerechaComp(raiz);
					}
				}
			}
		}
		if (elem > raiz->getElem())
		{
			insertar(elem, raiz->getDer(), continuar);
			if (continuar)
			{
				raiz->setFactor(raiz->getFactor() - 1);
				if (raiz->getFactor() == 0)
					continuar = false;
				else
				{
					if (raiz->getFactor() == -2)
					{
						continuar = false;
						if (raiz->getDer()->getFactor() == -1)
							rotarIzquierdaSimple(raiz);
						else
							rotarIzquierdaComp(raiz);
					}
				}
			}
		}
	}
}

template<class T>
inline void AVL<T>::rotarDerechaSimple(Nodo<T>*& n)
{
	Nodo<T>* nuevaRaiz = n->getIzq();
	Nodo<T>* flotante;
	if (nuevaRaiz->getDer() != nullptr)
	{
		flotante = nuevaRaiz->getDer();
		flotante->setFactor(0);
		//n->setFactor(1);
		n->setFactor(0);
		//nuevaRaiz->setFactor(-1);
		nuevaRaiz->setFactor(0);
	}
	else
	{
		flotante = nullptr;
		n->setFactor(0);
		nuevaRaiz->setFactor(0);
	}
	nuevaRaiz->setDer(n);
	n->setIzq(flotante);
	n = nuevaRaiz;
}

template<class T>
inline void AVL<T>::rotarIzquierdaSimple(Nodo<T>*& n)
{
	Nodo<T>* nuevaRaiz = n->getDer();
	Nodo<T>* flotante;
	if (nuevaRaiz->getIzq() != nullptr)
	{
		flotante = nuevaRaiz->getIzq();
		flotante->setFactor(0);
		//n->setFactor(-1);
		n->setFactor(0);
		//nuevaRaiz->setFactor(1);
		nuevaRaiz->setFactor(0);
	}
	else
	{
		flotante = nullptr;
		n->setFactor(0);
		nuevaRaiz->setFactor(0);
	}
	nuevaRaiz->setIzq(n);
	n->setDer(flotante);
	n = nuevaRaiz;
}

template<class T>
inline void AVL<T>::rotarDerechaComp(Nodo<T>*& n)
{
	Nodo<T>* nuevaRaiz = n->getIzq()->getDer();
	Nodo<T>* p1 = nuevaRaiz->getIzq();
	Nodo<T>* p2 = nuevaRaiz->getDer();
	nuevaRaiz->setIzq(n->getIzq());
	nuevaRaiz->setDer(n);
	nuevaRaiz->getIzq()->setDer(p1);
	nuevaRaiz->getDer()->setIzq(p2);
	nuevaRaiz->setFactor(0);
	nuevaRaiz->getDer()->setFactor(0);
	nuevaRaiz->getIzq()->setFactor(0);
	if (p1 != nullptr)
		nuevaRaiz->getDer()->setFactor(-1);
	if (p2 != nullptr)
		nuevaRaiz->getIzq()->setFactor(1);
	n = nuevaRaiz;
}

template<class T>
inline void AVL<T>::rotarIzquierdaComp(Nodo<T>*& n)
{
	Nodo<T>* nuevaRaiz = n->getDer()->getIzq();
	Nodo<T>* p1 = nuevaRaiz->getIzq();
	Nodo<T>* p2 = nuevaRaiz->getDer();
	nuevaRaiz->setDer(n->getDer());
	nuevaRaiz->setIzq(n);
	nuevaRaiz->getIzq()->setDer(p1);
	nuevaRaiz->getDer()->setIzq(p2);
	nuevaRaiz->setFactor(0);
	nuevaRaiz->getIzq()->setFactor(0);
	nuevaRaiz->getDer()->setFactor(0);
	if (p1 != nullptr)
		nuevaRaiz->getDer()->setFactor(-1);
	if (p2 != nullptr)
		nuevaRaiz->getIzq()->setFactor(1);
	n = nuevaRaiz;
}

template<class T>
inline Nodo<T>* AVL<T>::buscar(T elem, Nodo<T>* raiz)
{
	if (raiz == nullptr)
		return nullptr;
	else
	{
		if (elem > raiz->getElem())
			return buscar(elem, raiz->getDer());
		if (elem < raiz->getElem())
			return buscar(elem, raiz->getIzq());
		if (elem == raiz->getElem())
			return raiz;
	}
}

template<class T>
inline void AVL<T>::mostrarInorder(Nodo<T>* raiz)
{
	if (raiz != nullptr)
	{
		mostrarInorder(raiz->getIzq());
		cout << raiz->getElem() << " factor=" << raiz->getFactor() << endl;
		mostrarInorder(raiz->getDer());
	}
}

template<class T>
inline long AVL<T>::calcularAltura(Nodo<T>* raiz)
{
	if (raiz == nullptr)
		return 0;
	else
	{
		int i = calcularAltura(raiz->getIzq());
		int d = calcularAltura(raiz->getDer());
		if (i > d)
			return i + 1;
		else
			return d + 1;
	}
}

template<class T>
inline long AVL<T>::contarNodos(Nodo<T>* raiz)
{
	if (raiz == nullptr)
		return 0;
	else
		return contarNodos(raiz->getIzq()) + contarNodos(raiz->getDer()) + 1;
}

template<class T>
inline T AVL<T>::encontrarMax(Nodo<T>* raiz)
{
	if (raiz != nullptr)
	{
		if (raiz->getDer() == nullptr)
			return raiz->getElem();
		else
			return encontrarMax(raiz->getDer());
	}
}

template<class T>
inline T AVL<T>::encontrarMin(Nodo<T>* raiz)
{
	if (raiz != nullptr)
	{
		if (raiz->getIzq() == nullptr)
			return raiz->getElem();
		else
			return encontrarMin(raiz->getIzq());
	}
}

template<class T>
inline void AVL<T>::mostrarAncestros(Nodo<T>* raiz, T elem, bool b)
{
	if (buscar(elem, raiz) == nullptr && !b)
		cout << "No se encontro el elemento" << endl;
	else
	{
		if (raiz->getElem() != elem)
		{
			if (elem > raiz->getElem())
			{
				cout << raiz->getElem() << endl;
				mostrarAncestros(raiz->getDer(), elem, true);
			}
			if (elem < raiz->getElem())
			{
				cout << raiz->getElem() << endl;
				mostrarAncestros(raiz->getIzq(), elem, true);
			}
		}
	}
}

template<class T>
inline void AVL<T>::eliminarElem(T elem, Nodo<T>*& raiz, char& lado, bool& b)
{
	if (raiz == nullptr)
		cout << "el arbol esta vacio" << endl;
	else
	{
		if (elem < raiz->getElem())
		{
			eliminarElem(elem, raiz->getIzq(), 'i', false);
			if (b && lado == 'i')
				raiz->setFactor(raiz->getFactor() - 1);
		}
		if (elem > raiz->getElem())
		{
			eliminarElem(elem, raiz->getDer(), 'd', false);
			if (b && lado == 'd')
				raiz->setFactor(raiz->getFactor() + 1);
		}
		if (elem == raiz->getElem())
		{
			if (raiz->getIzq() == nullptr && raiz->getDer() == nullptr)
			{
				Nodo<T>* aux = raiz;
				delete aux;
				raiz = nullptr;
			}
			else
			{
				if (raiz->getDer() == nullptr)
				{
					T mayor = encontrarMax(raiz->getIzq());
					eliminarElem(mayor, raiz->getIzq(), 'i', false);
					raiz->setElem(mayor);
				}
				else
				{
					T menor = encontrarMin(raiz->getDer());
					eliminarElem(menor, raiz->getDer(), 'd', false);
					raiz->setElem(menor);
				}
			}
		}
	}
}

template<class T>
inline void AVL<T>::podar(Nodo<T>*& n, int nivelApodar, int nivelActual)
{
	if (raiz != nullptr)
	{
		if (n->getIzq() != nullptr)
			podar(n->getIzq(), nivelApodar, nivelActual + 1);
		if (n->getDer() != nullptr)
			podar(n->getDer(), nivelApodar, nivelActual + 1);
		if (nivelActual > nivelApodar)
		{
			delete n;
			n = nullptr;
		}
	}
}

template<class T>
inline void AVL<T>::espejo(Nodo<T>*& n)
{
	if (n != nullptr)
	{
		Nodo<T>* aux = n->getIzq();
		n->setIzq(n->getDer());
		n->setDer(aux);
		espejo(n->getIzq());
		espejo(n->getDer());
	}
}

template<class T>
inline Nodo<T>*& AVL<T>::getRaiz()
{
	return raiz;
}
