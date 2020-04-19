#pragma once

namespace libtorrent
{
    class file_storage;
}

namespace ltnet
{
    public ref class FileStorage
    {
    internal:
        FileStorage(const libtorrent::file_storage& storage);
        libtorrent::file_storage& ptr();

    public:
        FileStorage();
        ~FileStorage();
		!FileStorage();

        int num_files();
        long long file_size(int index);
        System::String^ file_path(int index, System::String^ save_path);

    private:
        libtorrent::file_storage* storage_;
    };
}
