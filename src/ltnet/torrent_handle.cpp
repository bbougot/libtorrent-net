#include "torrent_handle.h"

#include <libtorrent/torrent_handle.hpp>
#include <libtorrent/torrent_status.hpp>

#include "torrent_info.h"
#include "torrent_status.h"

using namespace ltnet;

TorrentHandle::TorrentHandle(libtorrent::torrent_handle& handle)
{
    handle_ = new libtorrent::torrent_handle(handle);
}

TorrentHandle::~TorrentHandle()
{
	this->!TorrentHandle();
}

TorrentHandle::!TorrentHandle()
{
	delete handle_;
}

libtorrent::torrent_handle* TorrentHandle::ptr()
{
    return handle_;
}

TorrentStatus^ TorrentHandle::status()
{
    return gcnew TorrentStatus(handle_->status());
}

cli::array<long long>^ TorrentHandle::file_progress(int flags)
{
    std::vector<boost::int64_t> progress;
    handle_->file_progress(progress, flags);

    cli::array<long long>^ result = gcnew cli::array<long long>(progress.size());
    for (size_t i = 0; i < progress.size(); i++)
    {
        result[i] = progress[i];
    }

    return result;
}

void TorrentHandle::pause()
{
    handle_->pause();
}

void TorrentHandle::file_priority(int index, int priority)
{
    handle_->file_priority(static_cast<libtorrent::file_index_t>(index), static_cast<libtorrent::download_priority_t>(priority));
}

TorrentInfo^ TorrentHandle::torrent_file()
{
    if (!handle_->torrent_file())
    {
        return nullptr;
    }

    return gcnew TorrentInfo(*handle_->torrent_file().get());
}

int TorrentHandle::upload_limit()
{
    return handle_->upload_limit();
}

int TorrentHandle::download_limit()
{
    return handle_->download_limit();
}

void TorrentHandle::set_upload_limit(int limit)
{
    handle_->set_upload_limit(limit);
}

void TorrentHandle::set_download_limit(int limit)
{
    handle_->set_download_limit(limit);
}

void TorrentHandle::set_sequential_download(bool m)
{
    handle_->set_flags(libtorrent::torrent_flags::sequential_download);
}