#pragma once

#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/error_code.hpp>
#include <libtorrent/torrent_handle.hpp>
#include <libtorrent/magnet_uri.hpp>
#include <libtorrent/storage_defs.hpp>
#include "add_torrent_params.h"
#include "error_code.h"

namespace libtorrent
{
	struct magnet_uri;
}

namespace ltnet
{
	public ref class magnet_uri
	{
	public:
		void magnet_uri::parse_magnet_uri(System::String^ uri, ltnet::add_torrent_params^ p, ltnet::error_code^ ec);
	};
}