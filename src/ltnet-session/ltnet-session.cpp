#include "ltnet-session.h"

#include <libtorrent/session.hpp>
#include <libtorrent/session_status.hpp>
#include <libtorrent/aux_/session_impl.hpp>
#include <libtorrent/torrent_handle.hpp>

using namespace ltnetsession;

session_native::session_native()
{
    session_ = new libtorrent::session();
}

session_native::~session_native()
{
    delete session_;
}

std::vector<libtorrent::torrent_handle> session_native::get_torrents()
{
    return session_->get_torrents();
}

libtorrent::torrent_handle session_native::add_torrent(libtorrent::v1_2::add_torrent_params& params)
{
    libtorrent::error_code ec;
    libtorrent::torrent_handle h = session_->add_torrent(params, ec);

    if (ec)
    {
        throw ec.message();
    }

    return h;
}

void session_native::remove_torrent(libtorrent::torrent_handle& handle)
{
    session_->remove_torrent(handle, libtorrent::session_handle::delete_partfile);
}