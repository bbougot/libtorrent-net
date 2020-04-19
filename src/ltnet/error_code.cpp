#include "error_code.h"
#include <boost/system/error_code.hpp>

#include "interop.h"

using namespace ltnet;

ErrorCode::ErrorCode(const boost::system::error_code& ec)
{
    error_ = new boost::system::error_code(ec);
}

ErrorCode::ErrorCode()
{
	error_ = new boost::system::error_code();
}

ErrorCode::~ErrorCode()
{
	this->!ErrorCode();
}

ErrorCode::!ErrorCode()
{
	delete error_;
}

System::String^ ErrorCode::message()
{
    return interop::from_std_string(error_->message());
}

int ErrorCode::value()
{
    return error_->value();
}

boost::system::error_code* ErrorCode::ptr()
{
	return error_;
}
