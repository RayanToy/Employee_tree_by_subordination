# Employee_tree_by_subordination
Решение задачи на C++ с деревьями сотрудников по иерархии
Необходимо реализовать консольное приложение, которое выведет на экран дерево сотрудников по подчиненности. Входными данными является файл *.txt, в котором указаны id сотрудников, затем id сотрудника, к которому подчиняется, затем фамилия сотрудника. Разделителем является символ '|'.

Пример входного файла:
1|0|Петров
2|1|Иванов
3|1|Сидоров

Результат:
Петров
---Сидоров
------Волков
------Медведев
---------Морозов
---Иванов
---Ульянов
------Козлов
------Овечкин

