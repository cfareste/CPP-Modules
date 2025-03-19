#include "Bureaucrat/Bureaucrat.hpp"
#include <iostream>

static void	test_instantiation_exception(int grade)
{
	try
	{
		Bureaucrat	bc = Bureaucrat("SUT", grade);

		std::cout << "No exceptions thrown" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void	instantiations_tests()
{
	std::cout << "Testing Bureaucrat's instantiation with grade 0: ";
	test_instantiation_exception(0);
	std::cout << "Testing Bureaucrat's instantiation with grade -1513: ";
	test_instantiation_exception(-1513);
	std::cout << "Testing Bureaucrat's instantiation with grade 1: ";
	test_instantiation_exception(1);
	std::cout << "Testing Bureaucrat's instantiation with grade 75: ";
	test_instantiation_exception(75);
	std::cout << "Testing Bureaucrat's instantiation with grade 150: ";
	test_instantiation_exception(150);
	std::cout << "Testing Bureaucrat's instantiation with grade 151: ";
	test_instantiation_exception(151);
	std::cout << "Testing Bureaucrat's instantiation with grade 41341: ";
	test_instantiation_exception(41341);
}

static void	grade_modification_tests()
{
	Bureaucrat	sut = Bureaucrat("SUT", 20);

	std::cout << sut << std::endl;
	sut.incrementGrade();
	sut.incrementGrade();
	sut.incrementGrade();
	std::cout << sut << std::endl;
	sut.decrementGrade();
	sut.decrementGrade();
	sut.decrementGrade();
	sut.decrementGrade();
	std::cout << sut << std::endl;

	try
	{
		sut = Bureaucrat("SUT", 1);
		sut.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Error incrementing bureaucrat's grade: " << e.what() << std::endl;
	}
	try
	{
		sut = Bureaucrat("SUT", 150);
		sut.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Error decrementing bureaucrat's grade: " << e.what() << std::endl;
	}
}

static void	bureaucrat_operatotions_tests()
{
	Bureaucrat	sut1 = Bureaucrat("SUT1", 20);
	Bureaucrat	sut2 = Bureaucrat(sut1);

	std::cout << sut1 << std::endl;
	std::cout << sut2 << std::endl;

	Bureaucrat	sut3 = Bureaucrat("SUT3", 140);

	sut1 = sut3;
	std::cout << sut1 << std::endl;
	std::cout << sut3 << std::endl;

	Bureaucrat	sut4 = Bureaucrat("SUT4", 111);
	std::cout << sut4 << std::endl;

	sut2 = Bureaucrat(sut4);
	std::cout << sut2 << std::endl;
}

int	main(void)
{
	instantiations_tests();
	grade_modification_tests();
	bureaucrat_operatotions_tests();
	return 0;
}
