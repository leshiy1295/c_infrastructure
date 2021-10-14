Получение отчёта о покрытии кода:
- нужно добавить флаги на этапе компиляции:
```
-fprofile-arcs -ftest-coverage -fPIC -O0
```

- нужно добавить флаги на этапе линковки:
```
-coverage -lgcov
```

- после запуска тестов нужно выполнить команды (из папки build для текущего примера):
```
lcov -t "tests/tests_fib" -o coverage.info -c -d fib_lib/ 
genhtml -o report coverage.info
```

- в результате сформируется html-отчёт о покрытии в папке build/report
(можно открыть в браузере с помощью поднятия локального сервера из директории:
```python3 -m http.server 8000```
)
