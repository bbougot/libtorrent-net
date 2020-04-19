#pragma once

namespace libtorrent
{
    struct torrent_handle;
}

namespace ltnet
{
    ref class TorrentStatus;
    ref class TorrentInfo;
    public ref class TorrentHandle
    {
    internal:
        TorrentHandle(libtorrent::torrent_handle& handle);
        libtorrent::torrent_handle* ptr();

    public:
        ~TorrentHandle();
		!TorrentHandle();
        TorrentStatus^ status();
        cli::array<long long>^ file_progress(int flags);
        void pause();
        void file_priority(int index, int priority);
        TorrentInfo^ torrent_file();
        int upload_limit();
        int download_limit();
        void set_upload_limit(int limit);
        void set_download_limit(int limit);
        void set_sequential_download(bool s);

    private:
        libtorrent::torrent_handle* handle_;
    };
}
