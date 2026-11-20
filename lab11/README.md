# Языки программирования
## Лабораторная работа 11

### Задание 1 **(2)**

*Что надо дописать в приведенный пример программы, чтобы она транслировалась без ошибок?
Существующий код нельзя изменять или переставлять.*

```
int foo(int x) {
    return bar(x);
}
int bar(int x) {
    return x+1;
}
int main() {
    foo(0);
    return 0;
}
```

**Решение**

![01](01/01.png)

```cpp
int bar(int x);

int foo(int x) {
    return bar(x);
}
int bar(int x) {
    return x+1;
}
int main() {
    foo(0);
    return 0;
}
```

### Задание 2 **(1)**

*Функция* **dswap** *должна была обменивать значения своих параметров.* 
*(На выводе должно было получиться* ```3.4 1.5```.)
*В чем ошибка при написании этой функции? Как ее исправить? 
Что передавалось в параметры у исходной функции и у исправленной?* 
```
#include <iostream>
void dswap(double x, double y) {
   double t = x;
   x = y;
   y = t;
}
int main(void) {
   double x = 1.5, y = 3.4;
   dswap(x, y);
   std::cout << x << " " << y << std::endl;
   return 0;
}
```

**Решение**

```cpp
#include <iostream>

void dswap(double &x, double &y) {
   double t = x;
   x = y;
   y = t;
}

int main(void) {
   double x = 1.5, y = 3.4;
   dswap(x, y);
   std::cout << x << " " << y << std::endl;
   return 0;
}
```


### Задание 3 **(3)**

*Известно, что функция* **dosome** *не изменяет значений вектора* **V**.
*Какие из способов объявления функции является правильным с точки зрения 
корректности работы программы? В чем разница между этими способами?*



```
void dosome(const vector<int> &V);
void dosome(vector<int> &V);
void dosome(const vector<int> V);
void dosome(vector<int> V);
```

*Проверьте в какие из этих функций можно передать константные вектора. ОЛбъясните результат.*
```
dosome({1, 2, 3});
```

**Решение**

```cpp
#include <iostream>
#include <vector>

void dosome_1(const std::vector<int> &V){
    int s = 0;
    for (auto x: V){
        s += x;
    }
    std::cout << V[0] << ' ' << s << std::endl;
}
void dosome_2(std::vector<int> &V){
    int s = 0;
    for (auto x: V){
        s += x;
    }
    std::cout << V[0] << ' ' << s << std::endl;
}
void dosome_3(const std::vector<int> V){
    int s = 0;
    for (auto x: V){
        s += x;
    }
    std::cout << V[0] << ' ' << s << std::endl;
}
void dosome_4(std::vector<int> V){
    int s = 0;
    for (auto x: V){
        s += x;
    }
    std::cout << V[0] << ' ' << s << std::endl;
}

int main(){
    std::vector<int> A = {1,2,3,4,5};
    dosome_1(A);
    dosome_2(A);
    dosome_3(A);
    dosome_4(A);
    dosome_1(1,2,3);
    dosome_2(1,2,3);
    dosome_3(1,2,3);
    dosome_4(1,2,3);
    return 0;
}
```

### Задание 4 **(2)**

*Напишите программу в которой будет создаваться восемь массивов из 128 целых чисел четырьмя способами,
каждым способом по два массива.
Первые два массива должны быть глобальными, вторые — локальными статическими, третьи — локальными на стеке,
четвертые — локальными в куче. Выведите адреса первого и последнего элемента в каждом массиве.
Сравните, насколько далеко они располагаются друг от друга. Какие выводы можно из этого сделать.*

*В отчет запишите программу и скриншот ее работы.*

**Решние**

![04](04/04.png)

```cpp
#include <iostream>

int G1[128], G2[128];

void foo(void){
    int L1[128] = {0}, L2[128] = {0};
    static int S1[128] = {0}, S2[128] = {0};
    int* H1 = new int [128];
    int* H2 = new int [128];
    std::cout << "global 1 " << &G1[0] << ' ' << &G1[127] << std::endl;
    std::cout << "global 2 " << &G2[0] << ' ' << &G2[127] << std::endl;
    std::cout << "local 1 " << &L1[0] << ' ' << &L1[127] << std::endl;
    std::cout << "local 2 " << &L2[0] << ' ' << &L2[127] << std::endl;
    std::cout << "static 1 " << &S1[0] << ' ' << &S1[127] << std::endl;
    std::cout << "static 2 " << &S2[0] << ' ' << &S2[127] << std::endl;
    std::cout << "in heap 1 " << &H1[0] << ' ' << &H1[127] << std::endl;
    std::cout << "in heap 2 " << &H2[0] << ' ' << &H2[127] << std::endl;
    delete[] H1;
    delete[] H2;
    int s = 0;
    for (int i=0;i<128;i++){
        s+=S1[i];
        S1[i]+=1;
        }
    std::cout << "sum static = " << s << std::endl;
    s = 0;
    for (int i=0;i<128;i++){
        s+=L1[i];
        L1[i]+=1;
        }
    std::cout << "sum local = " << s << std::endl;
}

int main(){
    foo();
    foo();
}
```

### Задание 5 **(2)**

*Приведенная ниже программа вызывает ошибку. Почему?*

*Что будет, если перенести объявление массива выше функции* **foo**?

*Что будет, если объявить массив с использованием ключевого слова* **static**?

*Что будет, если создать массив такого же размера с использованием* **new**?
```
#include <iostream>
int foo() {
    int x[100010001];
    return x[100010000];
}
int main() {
    std::cout << foo();
    return 0;
}
```


### Задание 6 **(3)**

*Запишите следующую программу. Выполните ее трансляцию с нулевым оровнем оптимизации.
Нарисуйте схематично расположение переменных в памяти в момент вызова при \verb*|a=0|. 
Отметьте кадры стека.*

```
#include <iostream>
long long foo(long long a, long long b) {
   if (a == 0) 
      return 0;
   else {
      long long x, y;
      std::cout << "Enter a=" << a << ", b=" << b << std::endl;
      std::cout << "Ptrs " << &a << ' ' << &b <<' '<< &x<<' '<<&y << std::endl;
      x = a * b;
      y = foo(a - 1, b + 1);
      return x + y;
   }
}
int main() {
   foo(5, 5);
   return 0;
}
```

### Задание 7 **(3)**

*Рассмотрите следующую программу. Выполните ее трансляцию, используя  компилятор g++ без
оптимизации (уровень оптимизации 0). Объясните ее работу.*
```
#include <iostream>
double &choose(double &a, bool flg) {
    double pi = 3.14;
    double &r = flg ? pi : a;
    return r;
}

int main(void)
{
    double a = 2.7;
    double &pi = choose(a, true);
    std::cout << pi << std::endl;
    double &e = choose(a, false);
    std::cout << e << std::endl;
    std::cout << pi << std::endl;
    return 0;
}
```

### Задание 8 **(3)**

*Объясните работу приведенной ниже программы.
Какие ошибки в ней имеются? (Виды ошибок смотрите в лекции.)*
```
#include <iostream>
int main() {
    int *p = new int [10];
    int *q = new int [10];
    for (int i = 0; i <= 10; i++)
        p[i] = i;
    q = p;
    delete[] p;
    for (int i = 0; i <= 10; i++)
        std::cout << q[i] <<" ";
    delete[] q;
    return 0;
}
```


## Дополнительные задания

### Задание 1 **(2)**

*В чем ошибка данного примера? Будет ли он работать при замене типа* **double** на **int**
*в функции bar?*
```
#include <iostream>
int foo(int x) {return x+1;}
double bar(double x) {return x-1;}
int main () {
    decltype(foo) *pf;
    pf = bar;
    std::cout << pf(0);
    return 0;
}

```

### Задание 2 **(10)**

*С использованием стандартных функций сортировки напишите на Java, C++ и Python программу
для сортировки вещественных чисел по возрастанию целой части числа и убыванию дробной.
Например, правильный порядок чисел после сортировки будет выглядеть так:*
```1.9; 1.32; 1.0; 5.8; 5.1; 12.6; 13.2; 13.1.``` 

*При реализации требуется использовать лямбда-функции.*

### Задание 3 **(4)**
*Напишите фрагмент программы вместо многоточия, 
в котором в начало массива* **data** *будет вставляться новый элемент* **t**. *Существующие
элементы при этом должны сместиться назад. Другие исправления вносить нельзя.
Для этого потребуется выделить новый участок памяти и перенести в него все элементы.*
```
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    *data = new int [n];
    for (int i=0; i<n; i++)
        std::cin >> data[i];
     int t;
     std::cin >> t;
     ...
     for (int i=0;i<n+1;i++)
         std::cout << data[i] <<' '; 
     return 0;
}
```

### Задание 4 **(4)**
*Напишите программу, которая создаст в памяти треугольник Паскаля размера* **n**.
*Размер должен вводиться во время работы программы. 
В программе не должна выделяться память для несуществующих элементов. В программе требуется использовать 
массив указателей.* 

