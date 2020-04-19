#pragma once

namespace boost{
	namespace system
	{
        class error_code;
	}
}

namespace ltnet
{
    public ref class ErrorCode
    {
    internal:
        ErrorCode(const boost::system::error_code& ec);

    public:
        ErrorCode();
        ~ErrorCode();
		!ErrorCode();

        System::String^ message();
        int value();

	internal:
		boost::system::error_code* ptr();

    private:
        boost::system::error_code* error_;
    };
}
