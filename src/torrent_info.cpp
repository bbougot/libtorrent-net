#include "torrent_info.h"
#include "file_storage.h"

#include <libtorrent/torrent_info.hpp>
#include <libtorrent/announce_entry.hpp>
#include <libtorrent/file_storage.hpp>

#include <msclr/marshal_cppstd.h>

#include "announce_entry.h"
#include "interop.h"

using namespace ltnet;

torrent_info::torrent_info(cli::array<System::Byte>^ buffer)
{
    pin_ptr<unsigned char> ptr = &buffer[0];
    const char *pbegin = (const char*)(const unsigned char*)ptr;
    info_ = new libtorrent::torrent_info(pbegin, buffer->Length);
}

torrent_info::torrent_info(System::String^ fileName)
{
    std::string file = interop::to_std_string(fileName);
    info_ = new libtorrent::torrent_info(file);
}

torrent_info::torrent_info(const libtorrent::torrent_info& info)
{
    info_ = new libtorrent::torrent_info(info);
}

torrent_info::~torrent_info()
{
	this->!torrent_info();
}

torrent_info::!torrent_info()
{
	delete info_;
}

void torrent_info::rename_file(int index, System::String^ new_filename)
{
    info_->rename_file(index, interop::to_std_string(new_filename));
}

file_storage^ torrent_info::files()
{
	file_storage^ storage = gcnew file_storage(info_->files());
	return storage;
}

cli::array<announce_entry^>^ torrent_info::trackers()
{
    std::vector<libtorrent::announce_entry> trackers = info_->trackers();
    cli::array<announce_entry^>^ result = gcnew cli::array<announce_entry^>(trackers.size());

    for (size_t i = 0; i < trackers.size(); i++)
    {
        result[i] = gcnew announce_entry(trackers[i]);
    }

    return result;
}

void torrent_info::add_tracker(System::String^ url, int tier)
{
    info_->add_tracker(interop::to_std_string(url), tier);
}

int torrent_info::num_pieces()
{
    return info_->num_pieces();
}

long long torrent_info::total_size()
{
    return info_->total_size();
}

int torrent_info::piece_length()
{
    return info_->piece_length();
}

int torrent_info::num_files()
{
    return info_->num_files();
}

System::String^ torrent_info::file_at(int index)
{
	ltnet::file_storage ^ fs = gcnew ltnet::file_storage(info_->files());
	return fs->at(index);
}

System::String^ torrent_info::info_hash() {
	return ltnet::interop::from_std_string(info_->info_hash().to_string());
}

bool torrent_info::is_valid()
{
    return info_->is_valid();
}

int torrent_info::piece_size(int index)
{
    return info_->piece_size(index);
}

System::String^ torrent_info::name()
{
    return ltnet::interop::from_std_string(info_->name());
}

System::String^ torrent_info::comment()
{
    return ltnet::interop::from_std_string(info_->comment());
}

System::String^ torrent_info::creator()
{
    return ltnet::interop::from_std_string(info_->creator());
}

int torrent_info::metadata_size()
{
    return info_->metadata_size();
}

libtorrent::torrent_info* torrent_info::ptr()
{
    return info_;
}