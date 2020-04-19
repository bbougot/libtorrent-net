#include "session.h"

#include <libtorrent/error_code.hpp>
#include <libtorrent/torrent_handle.hpp>
#include <ltnet-session.h>

#include "add_torrent_params.h"
#include "interop.h"
#include "torrent_handle.h"

using namespace ltnet;
using namespace ltnetsession;

Session::Session()
{
    session_ = new session_native();
}

Session::~Session()
{
	this->!Session();
}

Session::!Session()
{
	delete session_;
}

cli::array<TorrentHandle^>^ Session::get_torrents()
{
    std::vector<libtorrent::torrent_handle> torrents = session_->get_torrents();
    cli::array<TorrentHandle^>^ result = gcnew cli::array<TorrentHandle^>(torrents.size());

    for (size_t i = 0; i < torrents.size(); i++)
    {
        result[i] = gcnew TorrentHandle(torrents[i]);
    }

    return result;
}

TorrentHandle^ Session::add_torrent(AddTorrentParams^ params)
{
    libtorrent::torrent_handle h = session_->add_torrent(*params->ptr());

    return gcnew TorrentHandle(h);
}

void Session::remove_torrent(TorrentHandle^ handle)
{
    session_->remove_torrent(*handle->ptr());
}