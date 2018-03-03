#include "AVL.h"
#include <iostream>
#include <set>
#include <time.h>
#include <stdlib.h>
#include "timer.h"
int main()
{
	srand(time(NULL));
	AVL<int> a;
	int s, e, c;
	set<int> arb;
	timer i1, b1, i2, b2;
	bool b = false;
	do
	{
		system("cls");
		cout << "1. Insertar elemento" << endl;
		cout << "2. Buscar elemento" << endl;
		cout << "3. Recorrer inorder" << endl;
		cout << "4. Contar nodos" << endl;
		cout << "5. Calcular altura" << endl;
		cout << "6. Encontrar minimo" << endl;
		cout << "7. Encontrar maximo" << endl;
		cout << "8. Eliminar elemento dado (?)" << endl;
		cout << "9. Mostrar ancestros" << endl;
		cout << "10. Insertar 100000 elementos" << endl;
		cout << "11. Buscar 100000 elementos" << endl;
		cout << "12. Insertar 100000 elementos (set)" << endl;
		cout << "13. Buscar 100000 elementos (set)" << endl;
		cout << "14. Podar arbol" << endl;
		cout << "15. Obtener arbol espejo" << endl;
		cout << "0. Salir" << endl;
		cin >> s;
		switch (s)
		{
		case 1:
			cout << "ingrese el elemento a insertar" << endl;
			cin >> e;
			a.insertar(e, a.getRaiz(), b);
			break;
		case 2:
			cout << "ingrese el elemento a buscar" << endl;
			cin >> e;
			if (a.buscar(e, a.getRaiz()) != NULL)
				cout << "se encontro el elemento" << endl;
			else
				cout << "no se encontro el elemento" << endl;
			system("pause");
			break;
		case 3:
			cout << "los elementos del arbol son" << endl;
			a.mostrarInorder(a.getRaiz());
			system("pause");
			break;
		case 4:
			cout << "el arbol tiene " << a.contarNodos(a.getRaiz()) << " nodos" << endl;
			system("pause");
			break;
		case 5:
			cout << "el arbol es de altura " << a.calcularAltura(a.getRaiz()) << endl;
			system("pause");
			break;
		case 6:
			cout << "el elemento menor es " << a.encontrarMin(a.getRaiz()) << endl;
			system("pause");
			break;
		case 7:
			cout << "el elemento mayor es " << a.encontrarMax(a.getRaiz()) << endl;
			system("pause");
			break;
		case 8:
			break;
		case 9:
			cout << "ingrese el nodo del cual desea ver los ancestros" << endl;
			cin >> e;
			cout << "sus ancestros son" << endl;
			a.mostrarAncestros(a.getRaiz(), e, false);
			system("pause");
			break;
		case 10:
			i1.start();
			for (int i=1;i<=100000;i++)
				a.insertar(i, a.getRaiz(), b);
			i1.stop();
			cout << "con el avl insertar tarda " << i1 << " segundos" << endl;
			system("pause");
			break;
		case 11:
			c = 0;
			b1.start();
			for (int i = 1; i <= 100000; i++)
			{
				if (a.buscar(1 + rand() % (100001 - 1), a.getRaiz()) != nullptr)
					c++;
			}
			cout << "se encontraron " << c << " elementos" << endl;
			b1.stop();
			cout << "con el avl buscar los 100000 tarda " << b1 << " segundos" << endl;
			system("pause");
			break;
		case 12:
			i2.start();
			for (int i = 1; i <= 100000; i++)
				arb.insert(i);
			i2.stop();
			cout << "con set insertar tarda " << i2 << " segundos" << endl;
			system("pause");
			break;
		case 13:
			c = 0;
			b2.start();
			for (int i = 1; i <= 100000; i++)
			{
				if (arb.find(1 + rand() % (100001 - 1)) != arb.end())
					c++;
			}
			cout << "se encontraron " << c << " elementos" << endl;
			b2.stop();
			cout << "con set buscar tarda " << b2 << " segundos" << endl;
			system("pause");
			break;
		case 14:
			cout << "ingrese el nivel al que desea podar" << endl;
			cin >> e;
			a.podar(a.getRaiz(), e, 1);
			cout << "arbol podado" << endl;
			cout << "ahora la altura es " << a.calcularAltura(a.getRaiz()) << endl;
			system("pause");
			break;
		case 15:
			a.espejo(a.getRaiz());
			break;
		default:
			break;
		}
	} while (s != 0);
	return 0;
}