#pragma once
#include <fstream>
#include "../Model/PlaitedLinkedList.h"

using namespace Model;

namespace FileIO
{
	/// <summary>
	/// The file reader class
	/// </summary>
	class FileReader
	{
	private:
		std::string fileName;
		std::ifstream fileStream;

	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="FileReader"/> class.
		/// </summary>
		/// <param name="fileName">Name of the file.</param>
		FileReader(const std::string& fileName);
		/// <summary>
		/// Finalizes an instance of the <see cref="FileReader"/> class.
		/// </summary>
		~FileReader();
		/// <summary>
		/// Reads the file.
		/// </summary>
		/// <returns>the plaited linked list of the contents contained in the file</returns>
		/// @post fileStream is closed
		PlaitedLinkedList* readFile();
	};
}
