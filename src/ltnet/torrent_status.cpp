#include "torrent_status.h"

#include <libtorrent/torrent_handle.hpp>
#include <libtorrent/torrent_status.hpp>

#include "interop.h"

using namespace ltnet;

TorrentStatus::TorrentStatus(libtorrent::torrent_status& status)
{
    status_ = new libtorrent::torrent_status(status);
}

TorrentStatus::~TorrentStatus()
{
	this->!TorrentStatus();
}

TorrentStatus::!TorrentStatus()
{
	delete status_;
}

System::String^ TorrentStatus::save_path::get()
{
    return interop::from_std_string(status_->save_path);
}

System::String^ TorrentStatus::name::get()
{
    return interop::from_std_string(status_->name);
}

int TorrentStatus::download_rate::get()
{
    return status_->download_rate;
}

int TorrentStatus::upload_rate::get()
{
    return status_->upload_rate;
}

int TorrentStatus::num_seeds::get()
{
    return status_->num_seeds;
}

int TorrentStatus::num_peers::get()
{
    return status_->num_peers;
}

bool TorrentStatus::has_metadata::get()
{
    return status_->has_metadata;
}