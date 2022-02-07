test:
	@make -C .. re
	@cp test_printf.h tests.h
	@mv tests.c.test tests.c
	@mv main.c.test main.c
	@gcc -w tests.c main.c ../libftprintf.a
	@./a.out > printf
	@rm a.out tests.h
	@cp test_ft_printf.h tests.h
	@gcc -w tests.c main.c ../libftprintf.a
	@./a.out > ft_printf
	@rm a.out tests.h
	diff printf ft_printf || true
	@rm printf ft_printf
	@mv tests.c tests.c.test
	@mv main.c main.c.test
	@make -C .. fclean

val:
	@make -C .. re
	@mv old_main.c.test old_main.c
	@gcc -w old_main.c ../libftprintf.a
	@valgrind --leak-check=yes ./a.out
	@rm a.out
	@mv old_main.c old_main.c.test
	@make -C .. fclean