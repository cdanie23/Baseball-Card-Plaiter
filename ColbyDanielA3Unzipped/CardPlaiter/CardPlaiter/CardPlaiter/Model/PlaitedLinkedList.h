#pragma once
#include "BaseballCard.h"

namespace Model
{
	/// <summary>
	/// A node that is used to store the baseball card and the next node in the plaited linked list.
	/// </summary>
	class Node
	{
	private:
		Model::BaseballCard* card;
		Node* nextName;
		Node* nextYear;
		Node* nextCondition;

	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Node"/> class.
		/// </summary>
		/// <param name="card">The card.</param>
		Node(Model::BaseballCard* card)
		{
			this->card = card;
			this->nextName = nullptr;
			this->nextYear = nullptr;
			this->nextCondition = nullptr;
		}

		/// <summary>
		/// Finalizes an instance of the <see cref="Node"/> class.
		/// </summary>
		~Node()
		{
			delete this->card;
			delete this->nextName;
		}

		/// <summary>
		/// Gets the card.
		/// </summary>
		/// <returns>the card of the node</returns>
		BaseballCard* getCard() const
		{
			return this->card;
		}

		/// <summary>
		/// Gets the name of the next.
		/// </summary>
		/// <returns>the next name node</returns>
		Node* getNextName() const
		{
			return this->nextName;
		}

		/// <summary>
		/// Gets the next year.
		/// </summary>
		/// <returns>the next year node</returns>
		Node* getNextYear() const
		{
			return this->nextYear;
		}

		/// <summary>
		/// Gets the next condition.
		/// </summary>
		/// <returns>the next condition node</returns>
		Node* getNextCondition() const
		{
			return this->nextCondition;
		}

		/// <summary>
		/// Sets the name of the next.
		/// </summary>
		/// <param name="next">The next.</param>
		/// @post this->nextName = next
		void setNextName(Node* next)
		{
			this->nextName = next;
		}

		/// <summary>
		/// Sets the next year.
		/// </summary>
		/// <param name="next">The next.</param>
		/// @post this->nextYear = next
		void setNextYear(Node* next)
		{
			this->nextYear = next;
		}

		/// <summary>
		/// Sets the next condition.
		/// </summary>
		/// <param name="next">The next.</param>
		/// @post this->nextCondition = next
		void setNextCondition(Node* next)
		{
			this->nextCondition = next;
		}
	};

	/// <summary>
	/// A plaited linked list that is used to store the cards in the plaited deck.
	/// </summary>
	class PlaitedLinkedList
	{
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="PlaitedLinkedList"/> class.
		/// </summary>
		/// @post all strands are initialized to nullptr
		PlaitedLinkedList();
		/// <summary>
		/// Finalizes an instance of the <see cref="PlaitedLinkedList"/> class.
		/// </summary>
		/// @post all nodes are deleted and memory is freed
		~PlaitedLinkedList();

		/// <summary>
		/// The strands enum of the plaited linked list.
		/// </summary>
		enum Strands { NAME, YEAR, CONDITION };

		/// <summary>
		/// Gets the next.
		/// </summary>
		/// <param name="strand">The strand.</param>
		/// <param name="current">The current.</param>
		/// <returns>the next node in the strand</returns>
		Node* getNext(Strands strand, Node* current) const;
		/// <summary>
		/// Inserts the node.
		/// </summary>
		/// <param name="node">The node.</param>
		/// @post node is inserted into all strands in ascending order
		void insertNode(Node& node);
		/// <summary>
		/// Removes the node.
		/// </summary>
		/// <param name="firstName">The first name.</param>
		/// <param name="lastName">The last name.</param>
		/// @post node is removed from all strands and memory is freed
		void removeNode(const std::string& firstName, const std::string& lastName);
		/// <summary>
		/// Gets the node.
		/// </summary>
		/// <param name="firstName">The first name.</param>
		/// <param name="lastName">The last name.</param>
		/// <returns>the node corresponding to the first and last name</returns>
		Node* getNode(const std::string& firstName, const std::string& lastName) const;
		/// <summary>
		/// Gets the head.
		/// </summary>
		/// <param name="strand">The strand.</param>
		/// <returns>the head of the given strand</returns>
		Node* getHead(Strands strand) const;

	private:
		Node* nameHead;
		Node* yearHead;
		Node* conditionHead;
		void removeNode(Node* node, Node*& head, Strands strand) const;
		void insertNode(Node& node, Node*& head, Strands strand);
	};
};
