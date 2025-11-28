#include "BaseballCard.h"

#include <algorithm>
#include <stdexcept>

namespace Model
{
	BaseballCard::BaseballCard(const std::string& firstName, const std::string& lastName, int year, double price,
	                           Condition condition)
	{
		this->SetFirstName(firstName);
		this->SetLastName(lastName);
		this->SetYear(year);
		this->SetPrice(price);
		this->SetCondition(condition);
	}

	void BaseballCard::SetFirstName(const std::string& firstName)
	{
		if (firstName.empty())
		{
			throw std::invalid_argument("firstName cannot be empty.");
		}

		this->firstName = firstName;
	}

	const std::string& BaseballCard::GetFirstName() const
	{
		return this->firstName;
	}

	void BaseballCard::SetLastName(const std::string& lastName)
	{
		if (lastName.empty())
		{
			throw std::invalid_argument("lastName cannot be empty.");
		}

		this->lastName = lastName;
	}

	const std::string& BaseballCard::GetLastName() const
	{
		return this->lastName;
	}

	void BaseballCard::SetYear(int year)
	{
		if (year < MIN_YEAR)
		{
			throw std::invalid_argument("year must be greater than or equal to 1886.");
		}

		this->year = year;
	}

	int BaseballCard::GetYear() const
	{
		return this->year;
	}

	void BaseballCard::SetPrice(double price)
	{
		if (price < MIN_PRICE)
		{
			throw std::invalid_argument("price must be greater than or equal to 0.");
		}

		this->price = price;
	}

	double BaseballCard::GetPrice() const
	{
		return this->price;
	}

	void BaseballCard::SetCondition(Condition classification)
	{
		this->condition = classification;
	}

	Condition BaseballCard::GetCondition() const
	{
		return this->condition;
	}

	int BaseballCard::compareName(const std::string& firstName, const std::string& lastName) const
	{
		std::string lowerLastName = this->lastName;
		std::transform(lowerLastName.begin(), lowerLastName.end(), lowerLastName.begin(), ::tolower);
		std::string lowerFirstName = this->firstName;
		std::transform(lowerFirstName.begin(), lowerFirstName.end(), lowerFirstName.begin(), ::tolower);

		std::string lowerInputLastName = lastName;
		std::transform(lowerInputLastName.begin(), lowerInputLastName.end(), lowerInputLastName.begin(), ::tolower);
		std::string lowerInputFirstName = firstName;
		std::transform(lowerInputFirstName.begin(), lowerInputFirstName.end(), lowerInputFirstName.begin(), ::tolower);

		if (lowerLastName == lowerInputLastName)
		{
			return lowerFirstName.compare(lowerInputFirstName);
		}
		return lowerLastName.compare(lowerInputLastName);
	}

	int BaseballCard::compareYear(int year, double price) const
	{
		if (this->year == year)
		{
			return this->price - price;
		}
		return this->GetYear() - year;
	}

	int BaseballCard::compareCondition(const Condition& condition, double price) const
	{
		if (this->condition == condition)
		{
			return this->price - price;
		}
		return this->GetCondition() - condition;
	}
}
