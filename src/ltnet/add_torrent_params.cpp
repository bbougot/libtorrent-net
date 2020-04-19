#include "add_torrent_params.h"

#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/torrent_info.hpp>

#include "interop.h"
#include "torrent_info.h"

using namespace ltnet;

AddTorrentParams::AddTorrentParams()
{
    params_ = new libtorrent::add_torrent_params();
}

AddTorrentParams::~AddTorrentParams()
{
	this->!AddTorrentParams();
}

AddTorrentParams::!AddTorrentParams()
{
	delete params_;
}

System::String^ AddTorrentParams::save_path::get()
{
    return interop::from_std_string(params_->save_path);
}

void AddTorrentParams::save_path::set(System::String^ value)
{
    params_->save_path = interop::to_std_string(value);
}

TorrentInfo^ AddTorrentParams::ti::get()
{
    if(params_->ti)
    {
        return gcnew TorrentInfo(*params_->ti.get());
    }

    return nullptr;
}

void AddTorrentParams::ti::set(TorrentInfo^ value)
{
    params_->ti = std::make_shared<libtorrent::torrent_info>(*value->ptr());
}

libtorrent::add_torrent_params* AddTorrentParams::ptr()
{
    return params_;
}
