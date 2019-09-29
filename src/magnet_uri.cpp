#include "magnet-uri.h"

#include <msclr\marshal_cppstd.h>

using namespace ltnet;
using namespace System::Runtime::InteropServices;

void magnet_uri::parse_magnet_uri(System::String^ uri, ltnet::add_torrent_params^ p, ltnet::error_code^ ec)
{
	std::string unmanaged = msclr::interop::marshal_as<std::string>(uri);
	libtorrent::parse_magnet_uri(unmanaged, *p->ptr(), *ec->ptr());
}