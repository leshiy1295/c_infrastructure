Полезно использовать valgrind для проверки возможных утечек памяти
valgrind --tool=memcheck --leak-check=yes ./a.out

Также полезно использовать санитайзеры (особенно при стресс-тестировании)
gcc -fsanitize=address,undefined -fno-sanitize-recover=all -fsanitize-undefined-trap-on-error test.c
