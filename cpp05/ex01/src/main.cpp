#include "Form/Form.hpp"
#include "Bureaucrat/Bureaucrat.hpp"
#include <iostream>

static void	test_instantiation_exception(int sign_grade, int execution_grade)
{
	try
	{
		Form	form = Form("SUT", sign_grade, execution_grade);

		std::cout << "No exceptions thrown" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void	instantiations_tests()
{
	std::cout << "Testing Form's instantiation with sign_grade 0: ";
	test_instantiation_exception(0, 20);
	std::cout << "Testing Form's instantiation with sign_grade -1513: ";
	test_instantiation_exception(-1513, 20);
	std::cout << "Testing Form's instantiation with sign_grade 1: ";
	test_instantiation_exception(1, 20);
	std::cout << "Testing Form's instantiation with sign_grade 75: ";
	test_instantiation_exception(75, 20);
	std::cout << "Testing Form's instantiation with sign_grade 150: ";
	test_instantiation_exception(150, 20);
	std::cout << "Testing Form's instantiation with sign_grade 151: ";
	test_instantiation_exception(151, 20);
	std::cout << "Testing Form's instantiation with sign_grade 41341: ";
	test_instantiation_exception(41341, 20);
	std::cout << "Testing Form's instantiation with execution_grade 0: ";
	test_instantiation_exception(20, 0);
	std::cout << "Testing Form's instantiation with execution_grade -1513: ";
	test_instantiation_exception(20, -1513);
	std::cout << "Testing Form's instantiation with execution_grade 1: ";
	test_instantiation_exception(20, 1);
	std::cout << "Testing Form's instantiation with execution_grade 75: ";
	test_instantiation_exception(20, 75);
	std::cout << "Testing Form's instantiation with execution_grade 150: ";
	test_instantiation_exception(20, 150);
	std::cout << "Testing Form's instantiation with execution_grade 151: ";
	test_instantiation_exception(20, 151);
	std::cout << "Testing Form's instantiation with execution_grade 41341: ";
	test_instantiation_exception(20, 41341);
}

static void	form_signing_tests()
{
	Bureaucrat	higher_bureaucrat = Bureaucrat("Higher bureaucrat", 10);
	Bureaucrat	equal_bureaucrat = Bureaucrat("Equal bureaucrat", 20);
	Bureaucrat	lower_bureaucrat = Bureaucrat("Lower bureaucrat", 30);
	Form		sut = Form("SUT", 20, 100);

	std::cout << sut << std::endl;
	lower_bureaucrat.signForm(sut);
	std::cout << sut << std::endl;
	equal_bureaucrat.signForm(sut);
	std::cout << sut << std::endl;
	higher_bureaucrat.signForm(sut);
	std::cout << sut << std::endl;
}

static void	form_operations_tests()
{
	Form	sut1 = Form("SUT1", 20, 130);
	Form	sut2 = Form(sut1);

	std::cout << sut1 << std::endl;
	std::cout << sut2 << std::endl;

	Form	sut3 = Form("SUT3", 140, 65);

	sut1 = sut3;
	std::cout << sut1 << std::endl;
	std::cout << sut3 << std::endl;

	Form	sut4 = Form("SUT4", 111, 31);
	std::cout << sut4 << std::endl;

	sut2 = Form(sut4);
	std::cout << sut2 << std::endl;
}

int	main(void)
{
	instantiations_tests();
	std::cout << std::endl;
	form_signing_tests();
	std::cout << std::endl;
	form_operations_tests();
	return 0;
}
