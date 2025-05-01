#include "TestResult.hpp"

TestResult::TestResult()
{
	this->failed_ = false;
	this->vectorComparisons_ = 0;
	this->dequeComparisons_ = 0;
	this->vectorElapsedTime_ = 0;
	this->dequeElapsedTime_ = 0;
}

TestResult::~TestResult()
{
}

bool	TestResult::hasFailed()
{
	return this->failed_;
}

int	TestResult::getVectorComparisons()
{
	return this->vectorComparisons_;
}

int	TestResult::getDequeComparisons()
{
	return this->dequeComparisons_;
}

double	TestResult::getVectorElapsedTime()
{
	return this->vectorElapsedTime_;
}

double	TestResult::getDequeElapsedTime()
{
	return this->dequeElapsedTime_;
}

void	TestResult::addTestFailedStatus(bool status)
{
	this->failed_ |= status;
}

void	TestResult::setVectorComparisons(int comparisons)
{
	this->vectorComparisons_ = comparisons;
}

void	TestResult::setDequeComparisons(int comparisons)
{
	this->dequeComparisons_ = comparisons;
}

void	TestResult::setVectorElapsedTime(double elapsedTime)
{
	this->vectorElapsedTime_ = elapsedTime;
}

void	TestResult::setDequeElapsedTime(double elapsedTime)
{
	this->dequeElapsedTime_ = elapsedTime;
}

TestResult	&TestResult::operator=(const TestResult &other)
{
	if (this == &other)
		return *this;

	this->failed_ = other.failed_;
	this->vectorComparisons_ = other.vectorComparisons_;
	this->dequeComparisons_ = other.dequeComparisons_;
	this->vectorElapsedTime_ = other.vectorElapsedTime_;
	this->dequeElapsedTime_ = other.dequeElapsedTime_;
	return *this;
}

TestResult	&TestResult::operator+=(const TestResult &other)
{
	this->vectorComparisons_ += other.vectorComparisons_;
	this->dequeComparisons_ += other.dequeComparisons_;
	this->vectorElapsedTime_ += other.vectorElapsedTime_;
	this->dequeElapsedTime_ += other.dequeElapsedTime_;
	return *this;
}

TestResult	&TestResult::operator/=(const double factor)
{
	this->vectorComparisons_ /= factor;
	this->dequeComparisons_ /= factor;
	this->vectorElapsedTime_ /= factor;
	this->dequeElapsedTime_ /= factor;
	return *this;
}
