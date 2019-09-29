#pragma once

#include <libtorrent/error_code.hpp>

namespace ltnet
{
    public ref class error_code
    {
    internal:
        error_code(const libtorrent::error_code& ec);

    public:
		error_code();
        ~error_code();
		!error_code();

        System::String^ message();
        int value();

	internal:
		libtorrent::error_code* ptr();

    private:
        libtorrent::error_code* error_;
    };
}
