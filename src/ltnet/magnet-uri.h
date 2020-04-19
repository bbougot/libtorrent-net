#pragma once

#include "error_code.h"

namespace libtorrent
{
	struct magnet_uri;
}

namespace ltnet
{
	ref class AddTorrentParams;
	public ref class MagnetUri
	{
	public:
		void parse_magnet_uri(System::String^ uri, ltnet::AddTorrentParams^ p, ltnet::ErrorCode^ ec);
	};
}