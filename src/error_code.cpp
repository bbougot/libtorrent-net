#include "error_code.h"

#include "interop.h"

using namespace ltnet;

error_code::error_code(const libtorrent::error_code& ec)
{
    error_ = new libtorrent::error_code(ec);
}

error_code::error_code()
{
	error_ = new libtorrent::error_code();
}

error_code::~error_code()
{
	this->!error_code();
}

error_code::!error_code()
{
	delete error_;
}

System::String^ error_code::message()
{
    return interop::from_std_string(error_->message());
}

int error_code::value()
{
    return error_->value();
}

libtorrent::error_code* error_code::ptr()
{
	return error_;
}
