#include "torrent_info.h"
#include "file_storage.h"

#include <libtorrent/torrent_info.hpp>
#include <libtorrent/file_storage.hpp>

#include <msclr/marshal_cppstd.h>

#include "interop.h"

using namespace ltnet;

TorrentInfo::TorrentInfo(cli::array<System::Byte>^ buffer)
{
    pin_ptr<unsigned char> ptr = &buffer[0];
    const char *pbegin = reinterpret_cast<const char*>(static_cast<const unsigned char*>(ptr));
    info_ = new libtorrent::torrent_info(pbegin, buffer->Length);
}

TorrentInfo::TorrentInfo(System::String^ fileName)
{
    std::string file = interop::to_std_string(fileName);
    info_ = new libtorrent::torrent_info(file);
}

TorrentInfo::TorrentInfo(const libtorrent::torrent_info& info)
{
    info_ = new libtorrent::torrent_info(info);
}

TorrentInfo::~TorrentInfo()
{
	this->!TorrentInfo();
}

TorrentInfo::!TorrentInfo()
{
	delete info_;
}

long long TorrentInfo::total_size()
{
    return info_->total_size();
}

FileStorage^ TorrentInfo::files()
{
    FileStorage^ storage = gcnew FileStorage(info_->files());
	return storage;
}

libtorrent::torrent_info* TorrentInfo::ptr()
{
    return info_;
}