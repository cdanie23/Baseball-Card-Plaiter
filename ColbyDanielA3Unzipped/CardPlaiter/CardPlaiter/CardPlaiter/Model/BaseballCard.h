#pragma once
#include <string>

/// <summary>
/// The condition enum
/// </summary>
enum Condition { POOR, FAIR, GOOD, EXCELLENT, MINT };

/// \brief Returns a string representation of the Condition
///	\precondition none
/// \param type The condition type 
/// \return The condition as a string
inline std::string GetConditionName(Condition type)
{
	std::string classificationNames[] = {"Poor", "Fair", "Good", "Excellent", "Mint"};
	return classificationNames[type];
}

namespace Model
{
	/// \brief Defines the BaseballCard class which stores basic information about the card
	class BaseballCard
	{
	private:
		std::string firstName;
		std::string lastName;
		int year;
		double price;
		Condition condition;

	public:
		/// \brief Min price
		const double MIN_PRICE = 0.0;

		/// \brief Min of the baseball card year
		const int MIN_YEAR = 1886;

		/// \brief Creates a card object based on passed in data
		///	\precondition firstName not empty string;
		///               lastName not empty string;
		///				  year >= MIN_YEAR
		///				  price >= MIN_PRICE
		///	\postcondition getFirstName() == firstName; getLastName() == lastName; getYear() == year; getPrice() == price; getCondition() == condition
		/// \param firstName BaseballCard's first name
		/// \param lastName BaseballCard's last name
		/// \param year BaseballCard's year
		/// \param price BaseballCard's price
		/// \param condition  BaseballCard's condition
		BaseballCard(const std::string& firstName, const std::string& lastName, int year, double price,
		             Condition condition);

		/// \brief Gets the first name
		///	\precondition none
		/// \return The first name
		const std::string& GetFirstName() const;

		/// \brief Sets the first name
		/// \precondition firstName not empty string
		///	\postcondition getFirstName() == firstName
		/// \param firstName The first name
		void SetFirstName(const std::string& firstName);

		/// \brief Gets the last name
		/// \return The last name
		const std::string& GetLastName() const;

		/// \brief Sets the last name
		/// \precondition lastName not empty string
		///	\postcondition getLastName() == lastName
		/// \param lastName The last name
		void SetLastName(const std::string& lastName);

		/// \brief Gets the year
		///	\precondition none
		/// \return The year
		int GetYear() const;

		/// \brief Sets the year
		///	\precondition year >= MIN_YEAR
		///	\postcondition getYear() == year
		/// \param grade The year
		void SetYear(int year);

		/// \brief Gets the [roce]
		///	\precondition none
		/// \return The price
		double GetPrice() const;

		/// \brief Sets the price
		///	\precondition price >= MIN_PRICE}
		///	\postcondition getPrice() == price
		/// \param price The price]
		void SetPrice(double price);

		/// \brief Gets the condition
		///	\precondition none
		/// \return The condition
		Condition GetCondition() const;

		/// \brief Sets the condition
		///	\precondition none
		///	\postcondition getCondition() == condition
		/// \param condition The  condition
		void SetCondition(Condition condition);

		/// <summary>
		/// Compares the name.
		/// </summary>
		/// <param name="firstName">The first name.</param>
		/// <param name="lastName">The last name.</param>
		/// <returns>value corresponding to which is greater</returns>
		int compareName(const std::string& firstName, const std::string& lastName) const;
		/// <summary>
		/// Compares the year.
		/// </summary>
		/// <param name="year">The year.</param>
		/// <param name="price">The price.</param>
		/// <returns>value corresponding to which is greater</returns>
		int compareYear(int year, double price) const;
		/// <summary>
		/// Compares the condition.
		/// </summary>
		/// <param name="condition">The condition.</param>
		/// <param name="price">The price.</param>
		/// <returns>value corresponding to which is greater</returns>
		int compareCondition(const Condition& condition, double price) const;
	};
}
