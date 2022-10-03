Методичка по занятию с инструментарием C/C++-разработчика.

0) Устанавливаем Docker + VSCode. Скачиваем образ gcc и запускаем контейнер с помощью команды
```docker run -d -it leshiy1295/gcc_linters_valgrind_cmake_gtest bash```
Через VSCode присоединяемся к контейнеру в новом окне.
Далее запускаем отдельное окно для каждой подпапки с примером (для возможности конфигурации запуска VSCode)

Можно также модифицировать Docker-контейнер, поменяв содержимое Dockerfile и собрав его самостоятельно:

```bash
$ docker build . -f Dockerfile -t my_new_image
$ docker run -d -it my_new_image bash
```
