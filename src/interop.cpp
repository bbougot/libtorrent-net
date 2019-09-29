#include "interop.h"

#include <windows.h>
#include <msclr/marshal.h>

using namespace ltnet;
using System::IntPtr;
using System::Runtime::InteropServices::Marshal;
using namespace msclr::interop;

System::String^ interop::from_std_string(const std::string& value)
{
	System::String^ result = gcnew System::String(value.c_str());
	return result;
}

std::string interop::to_std_string(System::String^ value)
{
	marshal_context ^ context = gcnew marshal_context();
	const char* result = context->marshal_as<const char*>(value);
	return result;
}
