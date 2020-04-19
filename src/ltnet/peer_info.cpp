#include "peer_info.h"

#include <libtorrent/peer_info.hpp>

#include "interop.h"

using namespace ltnet;

PeerInfo::PeerInfo(libtorrent::peer_info& info)
{
    info_ = new libtorrent::peer_info(info);
}

PeerInfo::~PeerInfo()
{
	this->!PeerInfo();
}

PeerInfo::!PeerInfo()
{
	delete info_;
}