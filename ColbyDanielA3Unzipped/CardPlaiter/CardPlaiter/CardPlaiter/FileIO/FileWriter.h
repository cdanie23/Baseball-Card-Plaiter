#pragma once
#include <fstream>
#include "../Model/PlaitedLinkedList.h"
using namespace Model;

namespace FileIO
{
	/// <summary>
	/// The file writer class is responsible for writing the plaited linked list to a file.
	/// </summary>
	class FileWriter
	{
	private:
		std::string fileName;
		std::ofstream fileStream;

	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="FileWriter"/> class.
		/// </summary>
		/// <param name="fileName">Name of the file.</param>
		FileWriter(const std::string& fileName);
		/// <summary>
		/// Finalizes an instance of the <see cref="FileWriter"/> class.
		/// </summary>
		~FileWriter();
		/// <summary>
		/// Writes the file.
		/// </summary>
		/// <param name="list">The list.</param>
		/// @post fileStream is closed
		void writeFile(PlaitedLinkedList* list);
	};
}
