#pragma once

class TestResult
{
private:
	bool	failed_;
	int		vectorComparisons_;
	int		dequeComparisons_;
	double	vectorElapsedTime_;
	double	dequeElapsedTime_;

public:
	TestResult();
	~TestResult();

	bool	hasFailed();
	int		getVectorComparisons();
	int		getDequeComparisons();
	double	getVectorElapsedTime();
	double	getDequeElapsedTime();

	void	addTestFailedStatus(bool status);
	void	setVectorComparisons(int comparisons);
	void	setDequeComparisons(int comparisons);
	void	setVectorElapsedTime(double elapsedTime);
	void	setDequeElapsedTime(double elapsedTime);

	TestResult	&operator=(const TestResult &other);
	TestResult	&operator+=(const TestResult &other);
	TestResult	&operator/=(const double factor);
};
