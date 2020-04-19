#include "file_storage.h"

#include <libtorrent/file_storage.hpp>

#include "interop.h"

using namespace ltnet;

FileStorage::FileStorage(const libtorrent::file_storage& storage)
{
    storage_ = new libtorrent::file_storage(storage);
}

FileStorage::FileStorage()
{
    storage_ = new libtorrent::file_storage();
}

FileStorage::~FileStorage()
{
	this->!FileStorage();
}

FileStorage::!FileStorage()
{
	delete storage_;
}

libtorrent::file_storage& FileStorage::ptr()
{
    return *storage_;
}

int FileStorage::num_files()
{
    return storage_->num_files();
}

long long FileStorage::file_size(int index)
{
    return storage_->file_size(static_cast<libtorrent::file_index_t>(index));
}

System::String^ FileStorage::file_path(int index, System::String^ save_path)
{
    return interop::from_std_string(storage_->file_path(
        static_cast<libtorrent::file_index_t>(index),
        interop::to_std_string(save_path)));
}