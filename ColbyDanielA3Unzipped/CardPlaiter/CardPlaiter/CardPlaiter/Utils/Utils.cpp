#include "Utils.h"
using System::Runtime::InteropServices::Marshal;

/// \brief Converts a managed string to a standard (native) string
///	\precondition none
/// \param string The managed string to convert
/// \return The converted string as a standard(native) string
std::string toStandardString(System::String^ string)
{
	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);

	return returnString;
}
