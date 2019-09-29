#include "session.h"

#include <libtorrent/session.hpp>
#include <libtorrent/session_status.hpp>
#include <libtorrent/aux_/session_impl.hpp>

#include "add_torrent_params.h"
#include "entry.h"
#include "interop.h"
#include "torrent_handle.h"

using namespace ltnet;

session::session()
{
    session_ = new libtorrent::session();
}

session::~session()
{
	this->!session();
}

session::!session()
{
	delete session_;
}

cli::array<torrent_handle^>^ session::get_torrents()
{
    std::vector<libtorrent::torrent_handle> torrents = session_->get_torrents();
    cli::array<torrent_handle^>^ result = gcnew cli::array<torrent_handle^>(torrents.size());

    for (size_t i = 0; i < torrents.size(); i++)
    {
        result[i] = gcnew torrent_handle(torrents[i]);
    }

    return result;
}

void session::async_add_torrent(add_torrent_params^ params)
{
    session_->async_add_torrent(*params->ptr());
}

torrent_handle^ session::add_torrent(add_torrent_params^ params)
{
    libtorrent::error_code ec;
    libtorrent::torrent_handle h = session_->add_torrent(*params->ptr(), ec);

    if (ec)
    {
        throw gcnew System::Exception(interop::from_std_string(ec.message()));
    }

    return gcnew torrent_handle(h);
}

void session::pause()
{
    session_->pause();
}

void session::resume()
{
    session_->resume();
}

bool session::is_paused()
{
    return session_->is_paused();
}

void session::set_key(int key)
{
    session_->set_key(key);
}

bool session::is_listening()
{
    return session_->is_listening();
}

int session::listen_port()
{
    return session_->listen_port();
}

void session::remove_torrent(torrent_handle^ handle, int options)
{
    session_->remove_torrent(*handle->ptr(), options);
}