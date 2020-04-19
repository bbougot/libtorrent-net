#include "magnet-uri.h"
#include "add_torrent_params.h"

#include <libtorrent/magnet_uri.hpp>

#include <msclr\marshal_cppstd.h>

using namespace ltnet;
using namespace System::Runtime::InteropServices;

void MagnetUri::parse_magnet_uri(System::String^ uri, ltnet::AddTorrentParams^ p, ltnet::ErrorCode^ ec)
{
	std::string unmanaged = msclr::interop::marshal_as<std::string>(uri);
	libtorrent::parse_magnet_uri(unmanaged, *p->ptr(), *ec->ptr());
}