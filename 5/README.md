При обычной компиляции отладочные символы не собираются, поэтому при попытке отладки кода нет возможности получить исходный код.
Для создания отладочной информации достаточно указать ключ `-g` при компиляции:
```bash
gcc -g main.c -o main
```

В таком случае при попытке отладки итогового приложения main символьная информация будет доступна - например, можно будет с помощью команды `list` распечатать содержимое исполняемого файла:
```bash
$ gdb main
GNU gdb (Debian 10.1-1.7) 10.1.90.20210103-git
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from main...
(gdb) list
warning: Source file is more recent than executable.
1       #include <stdio.h>
2
3       void reverse_print(const int arr[], size_t size) {
4           for (size_t index = size; index >= 0; --index) {
5               printf("%d ", arr[index]);
6           }
7       }
8
9       int main() {
10          int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
```

Основные команды gdb:
- start - начать исполнение программы и остановиться на первой инструкции
- run - запустить программу
- run arg1 arg2 - запустить программу с аргументами командной строки
- run <input - запустить программу с содержимым файла input в качестве stdin
- next - следующая команда без захода
- step - следующая команда с заходом
- finish - продолжить выполнение до выхода из текущей функции
- list - вывести область исходного кода вокруг исполняемой команды
- print X - вывести содержимое X (например, локального массива или сигнатуру функции)
- break N - разместить точку останова на строчке с номером N
- backtrace - вывести стек
- frame N - переход к положению программы в соответствии с фреймом номер N (номер 0 - текущий фрейм)
- continue - продолжить выполнение до следующей точки останова/конца программы
- info X - вывести информацию о сущности X (в качестве X можно использовать, например, breakpoints для точек останова или locals для локальных переменных. Полный список доступен по нажатии `<Tab>`)
- disable N/enable N - отключить/включить точку останова номер N
- delete N - удалить точку останова номер N
- watch x - установка "наблюдения" за значением переменной x. При изменении - срабатывает остановка
- x/b arr - прочитать значение байта по адресу в 10-ной системе. x arr - в 16-ричной. x/10b - прочитать 10 байт
- `<Enter>` - выполнить предыдущую команду ещё раз
- quit - выйти из отладчика

Вместо полного названия команд можно использовать их префикс - например, можно выполнять код с помощью команды `n` вместо `next`.

Также в gdb существует визуальный отладчик `tui`, в который можно перейти с помощью команды
```
(gdb) tui enable
```
Выйти из этого отладчика можно с помощью
```
(gdb) tui disable
```
В нём доступны все те же команды, но также отображается в более привычном виде положение текущей выполняемой команды, точки останова и пр. информация.

Ещё одной интересной возможностью является наличие встроенного интерпретатора python:
```python
(gdb) python import os; print(os.getpid())
77179
(gdb) python
> import os
> print(os.getpid())
> end
77179
```

Можно подключиться к запущенному процессу, указав его идентификатор
```bash
gdb -p 77179

```
(для демонстрации в Docker, нужно запустить контейнер с разрешённой опцией ptrace ```--cap-add=SYS_PTRACE --security-opt seccomp=unconfined```)
В таком случае выполнение программы приостанавливается на выполнение отладки и продолжается после выхода из отладчика.

Наконец, бывает полезно получить "крешлог" (core dump), по которому с помощью gdb можно попытаться восстановить состояние программы в момент падения.
По умолчанию, размер файла крешлога (```ulimit -c```) равен 0, поэтому нужно настроить систему, выполнив следующую команду:
```bash
ulimit -c unlimited
```
После этого при запуске программы в текущей директории (путь можно явно задать в файле ```/proc/sys/kernel/core_pattern```) файл `core`, который можно передать дополнительным параметром в gdb вместе с исполняемым файлом.
```
$ ./main
Segmentation fault (core dumped)
$ gdb ./main core
GNU gdb (Debian 10.1-1.7) 10.1.90.20210103-git
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from main...
[New LWP 86890]
Core was generated by `./main'.
Program terminated with signal SIGSEGV, Segmentation fault.
#0  0x0000000000401151 in reverse_print (arr=0x7ffdf9d9ee20, size=11) at main.c:6
6               printf("%d ", arr[index]);
(gdb) bt
#0  0x0000000000401151 in reverse_print (arr=0x7ffdf9d9ee20, size=11) at main.c:6
#1  0x00000000004011db in main () at main.c:19
(gdb) info locals
index = 18446744073707456631
```

