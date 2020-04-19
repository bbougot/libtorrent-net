#pragma once

namespace libtorrent
{
    inline namespace v1_2
	{
        struct torrent_status;
    }
}

namespace ltnet
{
    public ref class TorrentStatus
    {
    internal:
        TorrentStatus(libtorrent::v1_2::torrent_status& status);

    public:
        ~TorrentStatus();
		!TorrentStatus();

        property System::String^ save_path { System::String^ get(); }
        property System::String^ name { System::String^ get(); }
        property int download_rate { int get(); }
        property int upload_rate { int get(); }
        property int num_seeds { int get(); }
        property int num_peers { int get(); }
        property bool has_metadata { bool get(); }

    private:
        libtorrent::v1_2::torrent_status* status_;
    };
}
