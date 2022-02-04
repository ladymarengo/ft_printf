test:
	@make -C .. re
	@cp test_printf.h tests.h
	@gcc tests.c main.c ../libftprintf.a
	@./a.out > printf
	@rm a.out tests.h
	@cp test_ft_printf.h tests.h
	@gcc tests.c main.c ../libftprintf.a
	@./a.out > ft_printf
	@rm a.out tests.h
	diff printf ft_printf || true
	@rm printf ft_printf
	@make -C .. fclean
	