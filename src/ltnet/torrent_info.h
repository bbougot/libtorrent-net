#pragma once

namespace libtorrent
{
    class torrent_info;
}

namespace ltnet
{
    ref class FileStorage;
    public ref class TorrentInfo
    {
    public:
        TorrentInfo(cli::array<System::Byte>^ buffer);
        TorrentInfo(System::String^ fileName);

        ~TorrentInfo();
		!TorrentInfo();

        long long total_size();
		FileStorage^ files();

    internal:
        TorrentInfo(const libtorrent::torrent_info& info);

        libtorrent::torrent_info* ptr();

    private:
        libtorrent::torrent_info* info_;
    };
}
